#include<bits/stdc++.h>
using namespace std;
namespace detail{
    template<class Cont>typename enable_if<is_same<decltype(begin(declval<Cont>)),decltype(end(declval<Cont>))>::value,ostream&>::type operator<<(ostream&x,const Cont&y){auto first=begin(y),last=end(y);x.put('[');x<<*first;while(++first!=last){x.put(',');x<<*first;}x.put(']');return x;}
    template<class T,size_t N>ostream&operator<<(ostream&x,const T(&y)[N]){auto first=y,last=y+N;x.put('[');x<<*first;while(++first!=last){x.put(',');x<<*first;}x.put(']');return x;}
    template<class T1,class T2>ostream&operator<<(ostream&x,const pair<T1,T2>&y){x.put('(');x<<y.first;x.put(',');x<<y.second;x.put(')');return x;}
    template<int N,class T>typename enable_if<N+1==tuple_size<T>::value>::type tuple_helper(ostream&x,const T&y){x<<get<N>(y);}
    template<int N,class T>typename enable_if<N+1!=tuple_size<T>::value>::type tuple_helper(ostream&x,const T&y){x<<get<N>(y);x.put(',');tuple_helper<N+1,T>(x,y);}
    template<class...Args>ostream&operator<<(ostream&x,const tuple<Args...>&y){x.put('(');tuple_helper<0,tuple<Args...>>(x,y);x.put(')');return x;}
    template<class T>struct array_tag{T first,last;array_tag(const T&_first,const T&_last):first(_first),last(_last){}T begin(){return first;}T end(){return last;}};
    template<class T>ostream&operator<<(ostream&x,const array_tag<T>&y){auto first=y.first,last=y.last;x.put('[');x<<*first;while(++first!=last){x.put(',');x<<*first;}x.put(']');return x;}
    template<class T>void debug(const T&t){cerr<<t;}
    template<class T,class...Args>void debug(const T&t,const Args&...args){cerr<<t;cerr.put(',');debug(args...);}
    template<class T>constexpr string type_name_f(){string name=__PRETTY_FUNCTION__;return name.substr(54,name.size()-103);}
}
#define debug_color "\033[33m"
#ifdef ONLINE_JUDGE
#define debug(...)
#else
#ifdef debug_color
#define debug(...) {cerr<<debug_color#__VA_ARGS__"=";detail::debug(__VA_ARGS__);cerr<<"\033[0m\n";};
#else
#define debug(...) {cerr<<#__VA_ARGS__"=";detail::debug(__VA_ARGS__);cerr.put('\n');};
#endif // debug_color
#endif // ONLINE_JUDGE
#define debug_if(cond,...) {if(cond){debug(__VA_ARGS__)}};
#define debug_assert(cond,...) {if(!(cond)){cerr<<"Assertion failed["<<__LINE__<<"]:"#cond"\n";debug(__VA_ARGS__);abort();}};
#define arr detail::array_tag
#define type_name(A) detail::type_name_f<A>()
#define decltype_name(A) detail::type_name_f<decltype(A)>()
