#include "Hash.h"

#include "FNV1.h"
#include "xxHash.h"

PYBIND11_MODULE(_pyhash, m)
{
  m.doc() = "Python Non-cryptographic Hash Library";

#if defined(__SSE4_2__) && defined(__x86_64__)
  m.attr("build_with_sse42") = true;
#else
  m.attr("build_with_sse42") = false;
#endif

#ifdef SUPPORT_INT128
  m.attr("build_with_int128") = true;
#else
  m.attr("build_with_int128") = false;
#endif

#ifdef _MSC_VER
  m.attr("_MSC_VER") = _MSC_VER;
#endif

#ifdef __GNUC__
  m.attr("_GCC_VER") = __GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__;
#endif

#ifdef __clang__
  m.attr("_CLANG_VER") = __clang__ * 10000 + __clang_major__ * 100 + __clang_patchlevel__;
#endif

#ifdef __VERSION__
  m.attr("__VERSION__") = __VERSION__;
#endif

  fnv1_32_t::Export(m, "fnv1_32");
  fnv1a_32_t::Export(m, "fnv1a_32");
  fnv1_64_t::Export(m, "fnv1_64");
  fnv1a_64_t::Export(m, "fnv1a_64");

  xx_hash_32_t::Export(m, "xx_32");
  xx_hash_64_t::Export(m, "xx_64");
}
