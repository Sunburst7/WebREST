/*
 * @Author: HH
 * @Date: 2023-04-02 02:07:40
 * @LastEditTime: 2023-04-02 04:23:45
 * @LastEditors: HH
 * @Description: 一些自定义简短类型与函数
 * @FilePath: /WebREST/WebREST/util/util.h
 */

#ifndef WebREST_UTIL_H_
#define WebREST_UTIL_H_

namespace WebREST {

// Author: kenton@google.com (Kenton Varda) and others
//
// Contains basic types and utilities used by the rest of the library.

//
// Use implicit_cast as a safe version of static_cast or const_cast
// for upcasting in the type hierarchy (i.e. casting a pointer to Foo
// to a pointer to SuperclassOfFoo or casting a pointer to Foo to
// a const pointer to Foo).
// When you use implicit_cast, the compiler checks that the cast is safe.
// Such explicit implicit_casts are necessary in surprisingly many
// situations where C++ demands an exact type match instead of an
// argument type convertable to a target type.
//
// The From type can be inferred, so the preferred syntax for using
// implicit_cast is the same as for static_cast etc.:
//
//   implicit_cast<ToType>(expr)
//
// implicit_cast would have been part of the C++ standard library,
// but the proposal was submitted too late.  It will probably make
// its way into the language in the future.
template<typename To, typename From>
inline To implicit_cast(From const &f)
{
  return f;
}


} // namespace WebREST

#endif