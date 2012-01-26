#ifndef __ACML_HPP__DXML__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_
#define __ACML_HPP__DXML__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_
#include"../acml.hpp"
#include"print.hpp"

namespace acml {
namespace xml {
namespace detail {
using std::string;

struct visitor {
    string &result;
    template<class T>
    void operator()(const T &, const string &)const ;
    visitor(string &result): result(result) {}
};

template<class T>
void print(string &result, const T &value, bool_<false>) {
    result += ::acml::print(value);
}

template<class T>
void print(string &result, const T &value, bool_<true>) {
    Reflector<T>::for_each(value, visitor(result));
}

template<class T>
void visitor::operator()(const T &value, const string &name) const {
    result += "<" + name + ">";
    print(result, value, bool_<Reflector<T>::defined>());
    result += "</" + name + ">";
}

template<class T>
string dumps(const T &value) {
    string result;
    print(result, value, bool_<Reflector<T>::defined>());
    return result;
}

} /* namespace detail */
} /* namespace xml */
} /* namespace acml */
#endif /* __ACML_HPP__XML___AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_ */
