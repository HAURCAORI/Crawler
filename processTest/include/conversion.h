#include <errno.h>
#include "iconv.h"

bool ChangeCharset(char *szSrcCharset, char *szDstCharset, char *szSrc, int nSrcLength, char *szDst, int nDstLength)
{
  iconv_t it = iconv_open(szDstCharset, szSrcCharset);
  if (it == (iconv_t)(-1))
    return false;
    
  bool result = true;
  size_t nSrcStrLen = nSrcLength;
  size_t nDstStrLen = nDstLength;
  size_t cc = iconv(it, &szSrc, &nSrcStrLen, &szDst, &nDstStrLen);
  
  if (cc == (size_t)(-1))
    result = false;

  if (iconv_close(it) == -1)
    result = false;

  return result;
}
/*
// UTF-8 로 인코딩하여 저장하기 
 // UTF-8 의 크기는 EUC-KR 의 약 3배 정도이다.
 size_t szIn = strlen(pContents) + 10;
 size_t szOut = szIn * 3;

 char *pIn = new char[szIn];
 char *pOut = new char[szOut];

 memset(pIn, '\0', sizeof(char)*szIn);
 memset(pOut, '\0', sizeof(char)*szOut);
 strcpy(pIn, pContents);

 char *pIn2 = pIn;
 char *pOut2 = pOut;

 iconv_t cd;
 int ret;
 // EUC-KR 을 UTF-8 로
 // 변환될코드의 문자열에 "//IGNORE" 문자열을 추가하여 변환될수 없는 문자에 대해서는 무시하도록 한다.
 if ( (cd = iconv_open("UTF-8//IGNORE", "EUC-KR")) < 0 )
 {
  // iconv_open 에서 error 나면 errno 을 셋팅한다.
  fprintf(stderr, "Fail to iconv_open() errorno : %d\n", errno);
  exit(-1);
 }
 // 변환하기
 if ( (ret = iconv(cd, &pIn2, &szIn, &pOut2, &szOut)) < 0 )
 {
  // iconv 에서 error 나면 errno 을 셋팅한다.
  // E2BIG *outbuf에 공간이 부족합니다
  // EILSEQ 부정확한 다중바이트 문자열이 입력값으로 들어왔습니다.
  // EINVAL 완료되지않은 다중바이트문자열이 입력값으로 들어왔습니다. 
  char errmsg[10] = "";
  if (errno == E2BIG) sprintf(errmsg, "E2BIG");
  if (errno == EILSEQ) sprintf(errmsg, "EILSEQ");
  if (errno == EINVAL) sprintf(errmsg, "EINVAL");
  fprintf(stderr, "Fail to iconv() errorno : %s(%d)\n", errmsg, errno);
 }
 iconv_close(cd);

 // iconv() 처리 후 szOut 크기를 재계산해야 한다.
 // iconv() 는 pIn2 를 szIn 크기가 0이 될 때까지 처리한다.
 szOut = pOut2 - pOut;
 FILE *fp = fopen("test.txt", "wb");
 fwrite(pOut, 1, szOut, fp);
 delete[] pIn;
 delete[] pOut
 fcloe(fp);
 */