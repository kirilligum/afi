#include "../headers.hpp"

using namespace std;
using namespace boost;
//using namespace boost::fusion;
using std::cout;
using std::endl;

typedef std::array<double,2> point;
typedef int edge;
typedef std::vector<std::tuple<edge,point>> polygon;
typedef int edge;
typedef int type;
typedef const point& vertex;
typedef std::tuple<edge,type,vertex> event;
typedef std::tuple<std::set<event>::const_iterator,std::set<event>> event_queue;
typedef std::tuple<int,point,point> segment;
typedef std::tuple<segment,segment&,segment&> sweep_line_segment;
typedef std::tuple<int,polygon&,set<sweep_line_segment>> sweep_line;

bool xyorder(vertex a, vertex b) {
  if(a[0]>b[0]) return 1;
  if(a[0]<b[0]) return 0;
  if(a[1]>b[1]) return 1;
  if(a[1]<b[1]) return 0;
  return 0;
}

event_queue generate_event_queue(const polygon& p) {
  event_queue eq;
  get<0>(eq)=get<1>(eq).begin();
  for(auto i = std::begin(p); i!=std::end(p); ++(++i)){
    auto direction = xyorder(std::get<1>(*i),std::get<1>(*(i+1)));
    get<1>(eq).emplace(std::get<0>(*i),direction,std::get<1>(*i));
    get<1>(eq).emplace(std::get<0>(*(i+1)),direction,std::get<1>(*(i+1)));
  }
  return eq;
}

auto next(event_queue& eq) -> decltype(get<0>(eq)){
  auto it = get<0>(eq);
  auto next = get<1>(eq).upper_bound(*it);
  if(next!=get<1>(eq).end()) get<0>(eq)=next;
  else get<0>(eq)=get<1>(eq).begin();
  return get<0>(eq);
}

sweep_line generate_sweep_line(const polygon& p){
  sweep_line sl;
  get<0>(sl) = p.size();
  get<1>(sl) = p;
  return sl;
}

set<sweep_line_segment>::const_iterator add(sweep_line& sl, event e){
  sweep_line_segment s;
  get<0>(get<0>(s)) = get<0>(e);
  point v1 = get<1>(get<1>(sl)[get<0>(get<0>(s))]);
  point v2 = get<1>(get<1>(sl)[get<0>(get<0>(s))+1]);
  if(xyorder(v1,v2)) {
    get<1>(get<0>(s)) = v1;
    get<2>(get<0>(s)) = v2;
  }else {
    get<2>(get<0>(s)) = v1;
    get<1>(get<0>(s)) = v2;
  }
  get<1>(s) = segment();
  get<2>(s) = segment();
  return get<2>(sl).insert(s).first;
}

set<sweep_line_segment>::const_iterator find(sweep_line& sl, event e){
  sweep_line_segment s;
  get<0>(get<0>(s)) = get<0>(e);
  get<1>(s) = segment();
  get<2>(s) = segment();
  return get<2>(sl).find(s);
}

bool intersect(sweep_line& sl, sweep_line_segment& s1, sweep_line_segment& s2) {
  if( s1==sweep_line_segment()||s2 == sweep_line_segment()) return 0;
  edge e1 = get<0>(get<0>(s1));
  edge e2 = get<0>(get<0>(s2));
  if((e1+1)%get<1>(sl).size()==e2||e1==(e2+1)%get<1>(sl).size()) return 0;
  //double lsign, rsign;
  return 0;
}

bool is_simple(const polygon& p) {
  auto eq=generate_event_queue(p);
  auto sl=generate_sweep_line(p);
  auto e=get<0>(eq);
  sweep_line_segment seg;
  while(!get<1>(eq).empty()) {
    if(get<1>(*e)) { //left
      //seg = *add(sl,*e);
    } else {
      //seg = *find(sl,*e);
    }
    e = next(eq);
    return 0;
  }
  return 0;
}

int main() {
  polygon p(4);
  std::random_device rd; std::mt19937 gen(rd()); std::uniform_real_distribution<double> d;
  int ipoint = 0;
  generate( p ,[&]{ return std::make_tuple(ipoint++,std::array<double,2>{{d(gen),d(gen)}});});
  cout << p;
  cout << endl;
  cout << "simple: " << is_simple(p) << endl;
  return 0;
}
