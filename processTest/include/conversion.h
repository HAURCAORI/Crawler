#ifndef CONVERSION_H
#define CONVERSION_H
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "iconv.h"

#include <iostream>
/*
char szSrc[] = "대한민국";
char szDst[100];
ChangeCharset("utf-8", "euc-kr", szSrc, strlen(szSrc), szDst, sizeof(szDst)); 
*/
inline size_t ChangeCharset(const char *srcCharset, const char *dstCharset, char *src, int srcLength, char *dst, int dstLength)
{
  iconv_t it = iconv_open(dstCharset, srcCharset);
  if (it == (iconv_t)(-1)) {
    fprintf(stderr, "Fail to iconv_open() errorno : %d\n", errno);
    return 0;
  }
  
  bool success = true;

  char* dst0 = dst;
  size_t szOut = dstLength;
  size_t nSrcStrLen = srcLength;
  size_t nDstStrLen = dstLength;
  size_t cc = iconv(it, &src, &nSrcStrLen, &dst, &nDstStrLen);
  
  if (cc == (size_t)(-1)) {
    success = false;
    // iconv 에서 error 나면 errno 을 셋팅한다.
    // E2BIG *outbuf에 공간이 부족합니다
    // EILSEQ 부정확한 다중바이트 문자열이 입력값으로 들어왔습니다.
    // EINVAL 완료되지않은 다중바이트문자열이 입력값으로 들어왔습니다.
    char errmsg[10] = "";
    if (errno == E2BIG)
      sprintf(errmsg, "E2BIG");
    if (errno == EILSEQ)
      sprintf(errmsg, "EILSEQ");
    if (errno == EINVAL)
      sprintf(errmsg, "EINVAL");
    fprintf(stderr, "Fail to iconv() errorno : %s(%d)\n", errmsg, errno);
  }
    

  if (iconv_close(it) == -1) {
    success = false;
  }
  szOut = dst - dst0;

  return success ? szOut : 0;
}

inline std::string ChangeCharset(const char *srcCharset, const char *dstCharset, const std::string& src) {
  
  //ChangeCharset(srcCharset, dstCharset, )
}

#endif
