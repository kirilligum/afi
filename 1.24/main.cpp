#include "../headers.hpp"

using namespace std;
using namespace boost;
//using namespace boost::fusion;
using std::cout;
using std::endl;

typedef std::array<double,2> point;
typedef std::vector<point> polygon;
typedef std::pair<point,point> segment;
typedef std::set<segment> edges;

double crossing_x(double x, const point& a, const point& b) {
  return (b[1]-a[1])/(b[0]-a[0])*(x-a[0])+a[1];
}

struct sweep_compare {
  double x;
  const edges& ee;
  sweep_compare(double x, const edges& ee) : x(x), ee(ee) {}
  bool operator() (const segment& a, const segment& b) const {
    return crossing_x(x,a.first,a.second)<crossing_x(x,b.first,b.second);
  }
};

std::pair<segment,segment> get_neighbors(const pair<point,point>& s, const set<pair<point,point>> &sl, const edges& ee) {
  std::set<pair<point,point>,sweep_compare> sweep_ordered(sweep_compare(s.second[0],ee));
  sweep_ordered.insert( std::begin(sl), std::end(sl));
  auto e = sweep_ordered.find(s);
  auto eh = e, el = e;
  if(e!=sweep_ordered.end()){
    if(eh!=std::begin(sweep_ordered)) --eh;
    if(el!=--sweep_ordered.end())  ++el;
  }
  return make_pair(*eh,*el);
}

double lines_intersect(const point& a1, const point& a2, const point& b1, const point& b2) {
  auto numerator =  (
      (a1[0]*a2[1]-a1[1]*a2[0])*(b1[0]-b2[0]) - (b1[0]*b2[1]-b1[1]*b2[0])*(a1[0]-a2[0])
      ) ;
  auto denominator = ( (a1[0]-a2[0])*(b1[1]-b2[1]) - (b1[0]-b2[0])*(a1[1]-a2[1]));
  auto ans = numerator / denominator;
  return ans;
}

bool segments_intersect(const segment& s1, const segment& s2) {
  auto a1 = s1.first, a2 = s1.second, b1=s2.first,b2=s2.second;
  auto ip = lines_intersect(a1,a2,b1,b2);
  //cout << "intersection  " <<  s1 << " x " << s2 << "  @  " << ip << endl;
  if( a1[0]<ip && b1[0]<ip && ip<a2[0] && ip<b2[0] ) return 1;
  else return 0;
}

void order_directions(edges& ee) {
  vector<segment> to_rev;
  for(auto it=std::begin(ee); it!=std::end(ee);++it) {
    if(it->first[0]>it->second[0]) {
      to_rev.push_back(*it);
      ee.erase(it);
    }
  }
  for(auto& i:to_rev) swap(i.first,i.second);
  ee.insert( std::begin(to_rev), std::end(to_rev));
}

void reverse_direction(edges& ee) {
  vector<segment> to_rev;
  for(auto it=std::begin(ee); it!=std::end(ee);++it) {
    to_rev.push_back(*it);
    ee.erase(it);
  }
  for(auto& i:to_rev) swap(i.first,i.second);
  ee.insert( std::begin(to_rev), std::end(to_rev));
}
//

bool is_simple(const polygon& p) {
  edges ee;
  for(auto it=std::begin(p);it!=std::end(p);++it){
    if(it==std::end(p)-1) {
      ee.insert(std::make_pair(*it,*std::begin(p)));
    } else {
      ee.insert(std::make_pair(*it,*(it+1)));
    }
  }
  order_directions(ee);
  auto ree = ee;
  reverse_direction(ree);
  ee.insert( std::begin(ree), std::end(ree));
  std::set<pair<point,point>> sweep_line;
  for(auto it=ee.begin();it!=ee.end();++it){
    if(it->first<it->second) {
      sweep_line.insert(*it);
    } else if (it->first>it->second){
      auto tmp = make_pair(it->second,it->first);
      auto nbs = get_neighbors(tmp,sweep_line,ee);
      if(nbs.first!=tmp){
        if(segments_intersect(nbs.first,tmp)) return 0;
      }
      if(nbs.second!=tmp){
        if(segments_intersect(nbs.second,tmp)) return 0;
      }
      sweep_line.erase(tmp);
    }
  }
  return 1;
}

int main() {
  polygon p(4);
  std::random_device rd; std::mt19937 gen(rd()); std::uniform_real_distribution<double> d;
  generate( p ,[&]{ return std::array<double,2>{{d(gen),d(gen)}};});
  cout << p;
  cout << endl;
  cout << "simple: " << is_simple(p) << endl;
  polygon p2 = { {{0.0,0.0}} , {{0.2,1.3}} , {{1.4,1.5}} , {{1.6,0.7}} };
  cout << p2;
  cout << endl;
  cout << "simple: " << is_simple(p2) << endl;
  polygon p3 = { {{0.0,0.0}} , {{0.2,1.3}} , {{1.4,0.5}} , {{1.6,1.7}} };
  cout << p3;
  cout << endl;
  cout << "simple: " << is_simple(p3) << endl;
  return 0;
}
