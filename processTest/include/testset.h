#pragma once
#include <string>
#include <fstream>
#include <sstream>

std::string readFile(std::string path) {
    std::ifstream inFile(path);
    if(!inFile.good()) {
        return "";
    }
    std::stringstream buffer;
    buffer << inFile.rdbuf();
    return buffer.str();
}

void writeFile(std::string path, const std::string& data) {
    std::ofstream outFile(path, std::ios_base::trunc);
    if(!outFile.good()) {
        return;
    }
    outFile << data;
}

std::string example = R"_(
<a href="#" role id="nautocomplete" tabindex="2" class="btn_arw _btn_arw fold"
                                aria-pressed="false" data-atcmp-element><span class="blind">자동완성 레이어</span><span
                                    class="ico_arr"></span></a>
)_";

std::string example1 = R"_(
<!doctype html>                          <html lang="ko" data-dark="false"> <head> <meta charset="utf-8"> <title>NAVER</title> <meta http-equiv="X-UA-Compatible" content="IE=edge"> <meta name="viewport" content="width=1190"> <meta name="apple-mobile-web-app-title" content="NAVER"/> <meta name="robots" content="index,nofollow"/> <meta name="description" content="네이버 메인에서 다양한 정보와 유용한 컨텐츠를 만나 보세요"/> <meta property="og:title" content="네이버"> <meta property="og:url" content="https://www.naver.com/"> <meta property="og:image" content="https://s.pstatic.net/static/www/mobile/edit/2016/0705/mobile_212852414260.png"> <meta property="og:description" content="네이버 메인에서 다양한 정보와 유용한 컨텐츠를 만나 보세요"/> <meta name="twitter:card" content="summary"> <meta name="twitter:title" content=""> <meta name="twitter:url" content="https://www.naver.com/"> <meta name="twitter:image" content="https://s.pstatic.net/static/www/mobile/edit/2016/0705/mobile_212852414260.png"> <meta name="twitter:description" content="네이버 메인에서 다양한 정보와 유용한 컨텐츠를 만나 보세요"/>  <link rel="stylesheet" href="https://pm.pstatic.net/dist/css/nmain.20220922.css"> <link rel="stylesheet" href="https://ssl.pstatic.net/sstatic/search/pc/css/sp_autocomplete_220526.css"> <link rel="shortcut icon" type="image/x-icon" href="/favicon.ico?1"/>  <link rel="apple-touch-icon" sizes="114x114" href="https://s.pstatic.net/static/www/u/2014/0328/mma_204243574.png"/> <link rel="apple-touch-icon" href="https://s.pstatic.net/static/www/u/2014/0328/mma_20432863.png"/> <script>window.nmain=window.nmain||{},window.nmain.supportFlicking=!1;var nsc="navertop.v4",ua=navigator.userAgent,useIeJSFlag="1";window.nmain.isIE="0"===useIeJSFlag,document.getElementsByTagName("html")[0].setAttribute("data-useragent",ua),window.nmain.isIE&&(Object.create=function(n){function e(){}return e.prototype=n,new e})</script> <script>var darkmode= false;window.naver_corp_da=window.naver_corp_da||{main:{}},window.naver_corp_da.main=window.naver_corp_da.main||{},window.naver_corp_da.main.darkmode=darkmode,window.gladsdk=window.gladsdk||{cmd:[]},window.gladsdk.cmd.push((function(){window.gladsdk.setHostMeta("theme",darkmode?"dark":"light")})),window.ndpsdk=window.ndpsdk||{cmd:[],polyfill:{cmd:[]}},window.ndpsdk.cmd.push((function(){window.ndpsdk.setHostMeta("theme",darkmode?"dark":"light")}))</script>  <script async src="https://ssl.pstatic.net/tveta/libs/glad/prod/gfp-core.js"></script> <script async src="https://ssl.pstatic.net/tveta/libs/ndpsdk/prod/ndp-loader.js"></script>  <script> window.nmain.gv = {  isLogin: false,
useId: null,   daInfo: {"BEAUTY":{"menu":"BEAUTY","childMenu":"","adType":"singleDom","multiDomAdUrl":"","multiDomUnit":"","infoList":[{"adposId":"1000163","singleDomAdUrl":"https://siape.veta.naver.com/fxshow","param":{"da_dom_id":"p_main_beauty_1","tb":"BEAUTY_1","unit":"SU10595","calp":"-"},"type":{"position":"abs","positionIndex":4,"subject":"contents"},"dom":null},{"adposId":"1000164","singleDomAdUrl":"https://siape.veta.naver.com/fxshow","param":{"da_dom_id":"p_main_beauty_2","tb":"BEAUTY_1","unit":"SU10596","calp":"-"},"type":{"position":"abs","positionIndex":8,"subject":"contents"},"dom":null}]},"LIVING":{"menu":"LIVING","childMenu":"","adType":"singleDom","multiDomAdUrl":"","multiDomUnit":"","infoList":[{"adposId":"1000183","singleDomAdUrl":"https://siape.veta.naver.com/fxshow","param":{"da_dom_id":"p_main_living_1","tb":"LIVING_1","unit":"SU10597","calp":"-"},"type":{"position":"abs","positionIndex":4,"subject":"contents"},"dom":null},{"adposId":"1000184","singleDomAdUrl":"https://siape.veta.naver.com/fxshow","param":{"da_dom_id":"p_main_living_2","tb":"LIVING_1","unit":"SU10606","calp":"-"},"type":{"position":"abs","positionIndex":8,"subject":"contents"},"dom":null}]},"LIVINGHOME":{"menu":"LIVINGHOME","childMenu":"","adType":"singleDom","multiDomAdUrl":"","multiDomUnit":"","infoList":[{"adposId":"1000185","singleDomAdUrl":"https://siape.veta.naver.com/fxshow","param":{"da_dom_id":"p_main_livinghome_1","tb":"LIVINGHOME_1","unit":"SU10571","calp":"-"},"type":{"position":"abs","positionIndex":4,"subject":"contents"},"dom":null},{"adposId":"1000186","singleDomAdUrl":"https://siape.veta.naver.com/fxshow","param":{"da_dom_id":"p_main_livinghome_2","tb":"LIVINGHOME_1","unit":"SU10572","calp":"-"},"type":{"position":"abs","positionIndex":8,"subject":"contents"},"dom":null}]}},
svt: 20221023120055,
}; </script> <script> window.nmain.newsstand = {
rcode: '12230250',
newsCastSubsInfo: '',
newsStandSubsInfo: ''
};
window.etc = {  };
window.svr = "<!--aweb23-->"; </script> <script src="https://ssl.pstatic.net/tveta/libs/assets/js/pc/main/min/pc.veta.core.min.js" defer="defer"></script>   <script src="https://pm.pstatic.net/dist/js/external.2961eaa5.js?o=www" type="text/javascript" crossorigin="anonymous" defer="defer"></script> <script src="https://pm.pstatic.net/dist/js/preload.5fe99fda.js?o=www" type="text/javascript" crossorigin="anonymous" defer="defer"></script> <script src="https://pm.pstatic.net/dist/js/polyfill.f3c68d2d.js?o=www" type="text/javascript" crossorigin="anonymous" defer="defer"></script>  <script src="https://pm.pstatic.net/dist/js/vendors~more~nmain~notice~search~sidebar_notice.40da85e0.js?o=www" type="text/javascript" crossorigin="anonymous" defer="defer"></script>   <script src="https://pm.pstatic.net/dist/js/search.31110d72.js?o=www" type="text/javascript" crossorigin="anonymous" defer="defer"></script>  <script src="https://pm.pstatic.net/dist/js/vendors~more~nmain~sidebar_notice.7aad5e27.js?o=www" type="text/javascript" crossorigin="anonymous" defer="defer"></script> <script src="https://pm.pstatic.net/dist/js/nmain.e31af4db.js?o=www" type="text/javascript" crossorigin="anonymous" defer="defer"></script> <style>:root{color-scheme:light}#_nx_kbd .setkorhelp a{display:none}</style> </head> <body> <div id="u_skip"> <a href="#newsstand"><span>뉴스스탠드 바로가기</span></a> <a href="#themecast"><span>주제별캐스트 바로가기</span></a> <a href="#timesquare"><span>타임스퀘어 바로가기</span></a> <a href="#shopcast"><span>쇼핑캐스트 바로가기</span></a> <a href="#account"><span>로그인 바로가기</span></a> </div> <div id="wrap">         
<style>._1syGnXOL{padding-right:18px;font-size:14px;line-height:0;letter-spacing:-.25px;color:#000}._1syGnXOL span,._1syGnXOL strong{line-height:49px}._1syGnXOL:before{display:inline-block;content:"";vertical-align:top;background-image:url(https://static-whale.pstatic.net/main/sprite-20220513@2x.png);background-repeat:no-repeat;background-size:141px 112px;width:18px;height:18px;margin:16px 8px 0 0;background-position:-98px 0}[data-useragent*="MSIE 8"] ._1syGnXOL:before{background-image:url(https://static-whale.pstatic.net/main/sprite-20220513.png)}._1syGnXOL._3dsvmZg2:before{background-position:-47px -85px}._1syGnXOL._1NBFx1WK:before{width:20px;height:20px;margin:15px 8px 0 0;background-position:-21px -89px}._1syGnXOL._2mcQEKCd:before{width:22px;height:22px;margin:14px 7px 0 0;background-position:-47px -63px}._1syGnXOL._36slsKuJ:before{width:21px;height:49px;margin:0 14px 0 0;background-position:0 -63px}._1syGnXOL._3qlJVWzR:before{width:24px;height:49px;margin:0 10px 0 0;background-position:-117px 0}._1syGnXOL._3di88A4c{padding-right:12px;font-size:17px}._1syGnXOL._3di88A4c:before{content:none}._1syGnXOL ._19K4X1CD{text-decoration:underline}._2aeXMlrb{display:inline-block;position:relative;font-size:12px;height:49px;width:78px;text-decoration:none;color:#fff;font-weight:700;letter-spacing:-.5px;vertical-align:top}._2aeXMlrb span{text-align:center;margin:9px 0;height:31px;display:block;line-height:31px;border-radius:15px}._2aeXMlrb span:before{display:inline-block;content:"";vertical-align:top;background-image:url(https://static-whale.pstatic.net/main/sprite-20220513@2x.png);background-repeat:no-repeat;background-size:141px 112px}[data-useragent*="MSIE 8"] ._2aeXMlrb span:before{background-image:url(https://static-whale.pstatic.net/main/sprite-20220513.png)}._2aeXMlrb.BMgpjddw{font-size:11px;width:94px}._2aeXMlrb.BMgpjddw span:before{margin:9px 3px 0 0;width:17px;height:13px;background-position:-89px -63px}._3h-N8T9V{position:absolute;top:0;left:0;right:0;bottom:0;background:rgba(0,0,0,0)}._1KncATpM{display:inline-block;content:"";vertical-align:top;background-image:url(https://static-whale.pstatic.net/main/sprite-20220513@2x.png);background-repeat:no-repeat;background-size:141px 112px;margin-top:14px;float:left;width:98px;height:21px;background-position:0 -21px}[data-useragent*="MSIE 8"] ._1KncATpM{background-image:url(https://static-whale.pstatic.net/main/sprite-20220513.png)}._1KncATpM._2v3uxv2x{background-position:0 0}._1KncATpM._1yl_Ow6o{background-position:0 -42px}._20PYt6lT{font-size:11px;height:49px;cursor:pointer;position:absolute;top:0;right:0;color:#666;opacity:.7}._20PYt6lT:after{width:15px;height:15px;margin-left:4px;background-position:-98px -33px;display:inline-block;content:"";vertical-align:top;background-image:url(https://static-whale.pstatic.net/main/sprite-20220513@2x.png);background-repeat:no-repeat;background-size:141px 112px}[data-useragent*="MSIE 8"] ._20PYt6lT:after{background-image:url(https://static-whale.pstatic.net/main/sprite-20220513.png)}._20PYt6lT._39oMCV2N:after{background-position:-98px -18px}._20PYt6lT._3MOWOORv{color:#c3c2c2}._20PYt6lT._3MOWOORv:after{background-position:-80px -85px}._20PYt6lT._3wm5EzmJ{color:#fff}._20PYt6lT._3wm5EzmJ:after{background-position:-65px -85px}._1hiMWemA{height:49px}._1hiMWemA .tY_u8r23{position:relative;width:1130px;margin:0 auto}._1hiMWemA .tY_u8r23 a{text-decoration:none}._1hiMWemA._23U_6TM_{position:relative}._1hiMWemA._23U_6TM_:after{position:absolute;z-index:1;content:"";display:block;width:100%;height:1px;bottom:0;background-color:rgba(0,0,0,.050980392156862744)}</style>
<div
id="NM_TOP_BANNER"
data-clk-prefix="top"
class="_1hiMWemA"
style="background-color: #21232b"
>
<div class="tY_u8r23">
<a
class="_3h-N8T9V"
href="https://whale.naver.com/banner/details/darkmode?=main&wpid=RydDy7"
data-clk="dropbanner1b"
></a
><i class="_1KncATpM _1yl_Ow6o"><span class="blind">NAVER whale</span></i
><img
src="https://static-whale.pstatic.net/main/img_darkmode_v12@2x.png"
width="200"
height="49"
alt=""
style="padding-left: 100px"
/><span
class="_1syGnXOL _3di88A4c"
data-clk="dropbanner1b"
style="padding-right: 20px; color: white; padding-left: 20px"
><span>눈부심 없는 편안~함 </span
><strong style="color: #22d4ad">내가 다크 모드 쓰는 이유</strong></span
><a
href="https://installer-whale.pstatic.net/downloads/banner/RydDy7/WhaleSetup.exe"
class="_2aeXMlrb BMgpjddw"
id="NM_whale_download_btn"
data-clk="dropdownload1b"
><span style="background-color: #03bc93">다운로드</span></a
><button
type="button"
data-ui-cookie-exp-days="3"
data-ui-cookie-key="NM_TOP_PROMOTION"
data-ui-cookie-value="1"
data-ui-hide-target="#NM_TOP_BANNER"
data-clk="dropclose1b"
class="_20PYt6lT _3wm5EzmJ"
>
3일 동안 보지 않기
</button>
</div>
</div>  <div id="header" role="banner">









<div class="special_bg">
<div class="group_flex">
<div class="logo_area">
<h1 class="logo_special">
<img
src="https://s.pstatic.net/static/www/mobile/edit/20221021/mobile_180635782115.gif"
width="415"
height="160"
class="special_img"
alt="상강"
/>
<a
href="https://search.naver.com/search.naver?where=nexearch&amp;sm=top_brd&amp;fbm=1&amp;ie=utf8&amp;query=%EC%83%81%EA%B0%95"
class="special_logo_link"
title="상강"
data-clk="top.spe"
>
<img
src="https://s.pstatic.net/static/www/mobile/edit/20221021/mobile_180652748293.png"
width="58"
height="60"
class="special_img_fold"
alt="상강"
/>
</a>
</h1>
</div>
<div class="service_area">
<a id="NM_set_home_btn" href="https://help.naver.com/support/welcomePage/guide.help" class="link_set" data-clk="top.mkhome">네이버를 시작페이지로</a>
<i class="sa_bar"></i>
<a href="https://jr.naver.com" class="link_jrnaver" data-clk="top.jrnaver"><i class="ico_jrnaver"></i><span class="blind">쥬니어네이버</span></a>
<a href="https://happybean.naver.com" class="link_happybin" data-clk="top.happybean"><i class="ico_happybin"></i><span class="blind">해피빈</span></a>
</div>

<div id="search" class="search_area" data-clk-prefix="sch">
<form id="sform" name="sform" action="https://search.naver.com/search.naver" method="get" role="search">
<fieldset>
<legend class="blind">검색</legend>
<select id="where" name="where" title="검색 범위 선택" class="blind">
<option value="nexearch" selected="selected">통합검색</option><option value="post">블로그</option><option value="cafeblog">카페</option><option value="cafe">- 카페명</option><option value="article">- 카페글</option><option value="kin">지식iN</option><option value="news">뉴스</option><option value="web">사이트</option><option value="category">- 카테고리</option><option value="site">- 사이트</option><option value="movie">영화</option><option value="webkr">웹문서</option><option value="dic">사전</option><option value="100">- 백과사전</option><option value="endic">- 영어사전</option><option value="eedic">- 영영사전</option><option value="krdic">- 국어사전</option><option value="jpdic">- 일본어사전</option><option value="hanja">- 한자사전</option><option value="terms">- 용어사전</option><option value="book">책</option><option value="music">음악</option><option value="doc">전문자료</option><option value="shop">쇼핑</option><option value="local">지역</option><option value="video">동영상</option><option value="image">이미지</option><option value="mypc">내PC</option><optgroup label="스마트 파인더"><option value="movie">영화</option><option value="auto">자동차</option><option value="game">게임</option><option value="health">건강</option><option value="people">인물</option></optgroup><optgroup label="네이버 랩"><option>긍정부정검색</option></optgroup>
</select>
<input type="hidden" id="sm" name="sm" value="top_hty" />
<input type="hidden" id="fbm" name="fbm" value="0" />
<input type="hidden" id="acr" name="acr" value="" disabled="disabled" />
<input type="hidden" id="acq" name="acq" value="" disabled="disabled" />
<input type="hidden" id="qdt" name="qdt" value="" disabled="disabled" />
<input type="hidden" id="ie" name="ie" value="utf8" />
<input type="hidden" id="acir" name="acir" value="" disabled="disabled" />
<input type="hidden" id="os" name="os" value="" disabled="disabled" />
<input type="hidden" id="bid" name="bid" value="" disabled="disabled" />
<input type="hidden" id="pkid" name="pkid" value="" disabled="disabled" />
<input type="hidden" id="eid" name="eid" value="" disabled="disabled" />
<input type="hidden" id="mra" name="mra" value="" disabled="disabled" />






<div class="green_window" style='border-color: #d7b965;'>
<!-- [AU] data-atcmp-element 에 해당하는 attribute를 추가해주세요. -->
<input id="query" name="query" type="text" title="검색어 입력" maxlength="255" class="input_text" tabindex="1" accesskey="s" style="ime-mode:active;" autocomplete="off"  placeholder="검색어를 입력해 주세요." onclick="document.getElementById('fbm').value=1;" value="" data-atcmp-element>
</div>
<button id="search_btn" type="submit" title="검색" tabindex="3" class="btn_submit" onclick="window.nclick(this,'sch.action','','',event);" style='background-color: #d7b965'>
<span class="blind">검색</span>
<span class="ico_search_submit"></span>
</button>
</fieldset>
</form>
<!-- 한글입력기 -->
<a href="#" id="ke_kbd_btn" role="button" class="btn_keyboard" onclick="return false;"><span class="blind">한글 입력기</span><span class="ico_keyboard"></span></a>
<div id="_nx_kbd" style="display:none;"></div>
<div class="autocomplete">
<!-- 자동완성 열린 경우 fold 클래스 추가, 딤드인 경우 dim 추가 -->
<a href="#" role="button" id="nautocomplete" tabindex="2" class="btn_arw _btn_arw fold" aria-pressed="false" data-atcmp-element><span class="blind">자동완성 레이어</span><span class="ico_arr"></span></a>
</div>
<!-- 자동완성레이어 -->
<div id="autoFrame" class="reatcmp" style="display: none;">
<!-- [AU] data-atcmp-element attribute를 추가해주세요. -->
<div class="ly_atcmp" data-atcmp-element>
<div class="api_atcmp_wrap">
<!-- 최근검색어 -->
<!-- [AU] _recent_layer 클래스를 추가해주세요. -->
<div class="atcmp_fixer _recent_layer" style="display:none;">
<!-- [AU] _recent_header 클래스를 추가해주세요. -->
<div class="atcmp_header _recent_header">
<strong class="tit">최근검색어</strong>
<div class="option">
<!-- [AU] _delAll 클래스를 추가해주세요. -->
<a role="button" href="#" class="item _delAll" aria-pressed="false">전체삭제</a>
</div>
</div>
<div class="atcmp_container">
<!-- [AU] _recent 클래스를 추가해주세요. -->
<ul class="kwd_lst _recent">
<!-- 최근검색어 템플릿 -->
<!-- [AU] _item 클래스를 추가해주세요. -->
<!-- [AU] data-template-type="history" data-keyword="@in_txt@" attribute를 추가해주세요. -->
<li class="item _item" data-rank="@rank@" data-template-type="history" data-keyword="@in_txt@">
<a href="#" class="kwd">
<span class="fix"><span class="common_ico_kwd"><i class="imsc ico_search"></i></span><span>@txt@</span></span>
</a>
<span class="etc">
<em class="date">@date@.</em>
<!-- [AU] _del 클래스를 추가해주세요. -->
<a href="#" role="button" class="bt_item _del" aria-pressed="false"><i class="imsc ico_del">삭제</i></a>
</span>
</li>
</ul>
<!-- [D] 검색어 저장 꺼진 경우 atcmp_fixer에 type_off 추가 -->
<!-- [AU] _offMsg 클래스를 추가해주세요. -->
<div class="kwd_info kwd_off _offMsg" style="display: none;">검색어 저장 기능이 꺼져 있습니다.<br><span class="kwd_dsc">설정이 초기화 된다면 <a href="https://help.naver.com/support/alias/search/word/word_29.naver" class="kwd_help" data-clk="sly.help" target="_blank">도움말</a>을 확인해주세요.</span></div>
<!-- [D] 검색어 내역 없는 경우 atcmp_fixer에 type_off 추가 -->
<!-- [AU] _recentNone 클래스를 추가해주세요. -->
<div class="kwd_info kwd_none _recentNone" style="display: none;">최근 검색어 내역이 없습니다.<br><span class="kwd_dsc">설정이 초기화 된다면 <a href="https://help.naver.com/support/alias/search/word/word_29.naver" class="kwd_help" data-clk="sly.help" target="_blank">도움말</a>을 확인해주세요.</span></div>
</div>
<div class="atcmp_footer">
<span class="side_opt_area">
<span class="opt_item"><a href="https://help.naver.com/support/service/main.help?serviceNo=605&amp;categoryNo=1991" data-clk="sly.help" target="_blank">도움말</a></span>
</span>
<span class="rside_opt_area">
<span class="opt_item">
<!-- [AU] _keywordOnOff 클래스를 추가해주세요. -->
<a href="#" class="close _keywordOnOff">자동저장 끄기</a>
</span>
</span>
</div>
</div>
<!-- 자동완성 -->
<!-- [AU] _atcmp_layer 클래스를 추가해주세요. -->
<div class="atcmp_fixer _atcmp_layer" style="display:none;">
<!-- [AU] _words 클래스를 추가해주세요. -->
<div class="atcmp_container _words">
<!-- 정답형 템플릿 : 로또당첨번호 -->
<!-- [AU] _answer 클래스를 추가해주세요. -->
<!-- [AU] data-template-type="answer_3" data-code="@code@" data-keyword="@1@" attribute를 추가해주세요. -->
<div class="atcmp_correct type_lotto _answer" data-template-type="answer_3" data-code="@code@" data-keyword="@1@">
<a href="#" class="link_item">
<span class="common_ico_kwd"><i class="imsc ico_search"></i></span>
<div class="dsc_area">
<span class="tit">@5@회차 당첨번호</span>
<span class="dsc">
<span class="item">추첨 @13@.</span><span class="item">지급기한 1년</span>
</span>
</div>
<span class="etc_area">
<span class="etc lotto">
<em class="n@6@">@6@</em><em class="n@7@">@7@</em><em class="n@8@">@8@</em><em class="n@9@">@9@</em><em class="n@10@">@10@</em><em class="n@11@">@11@</em><em class="imsc_bf bonus n@12@">@12@</em>
</span>
</span>
</a>
</div>
<!-- 정답형 템플릿 : 환율 -->
<!-- [AU] _answer 클래스를 추가해주세요. -->
<!-- [AU] data-template-type="answer_9" data-code="@code@" data-keyword="@1@" attribute를 추가해주세요. -->
<div class="atcmp_correct type_exchange _answer" data-template-type="answer_9" data-code="@code@" data-keyword="@1@">
<!-- [D] 상승 up, 하락 down 추가 -->
<a href="#" class="link_item @11@">
<!-- [D] 국가별 class 가나다순
ZAR 남아프리카 공화국
NPR 네팔
NOK 노르웨이
NZD 뉴질랜드
TWD 대만
DKK 덴마크
RUB 러시아
MOP 마카오
MYR 말레이시아
MXN 멕시코
MNT 몽골
USD 미국
BHD 바레인
BDT 방글라데시
VND 베트남
BRL 브라질
SAR 사우디아라비아
SEK 스웨덴
CHF 스위스
SGD 싱가포르
AED 아랍에미리트
GBP 영국
EUR 유럽연합
ILS 이스라엘
EGP 이집트
INR 인도
IDR 인도네시아
JPY 일본
CNY 중국
CZK 체코
CLP 칠레
KZT 카자흐스탄
QAR 카타르
CAD 캐나다
KWD 쿠웨이트
THB 태국
TRY 터키
PKR 파키스탄
PLN 폴란드
PHP 필리핀
HUF 헝가리
AUD 호주
HKD 홍콩
-->
<span class="common_ico_kwd"><i class="imsc ico @12@">@14@</i></span>
<div class="dsc_area">
<span class="tit">@txt@<span class="sub">@currency@</span></span>
<span class="dsc">
<span class="item"><i class="imsc ico_arr"></i>@8@(@9@%)</span>
</span>
</div>
<span class="etc_area">
<span class="etc"><em class="num">@6@</em>원</span>
</span>
</a>
</div>
<!-- 정답형 템플릿 : 날씨(국내11, 해외12) -->
<!-- [AU] _answer 클래스를 추가해주세요. -->
<!-- [AU] data-template-type="answer_11" data-code="@code@" data-keyword="@1@" attribute를 추가해주세요. -->
<div class="atcmp_correct type_weather _answer" data-template-type="answer_11" data-code="@code@" data-keyword="@1@">
<!-- [D] 상승 up, 하락 down 추가 -->
<a href="#" class="link_item @12@">
<span class="common_ico_kwd"><i class="imsc ico_search"></i></span>
<div class="dsc_area">
<span class="tit">@txt@</span>
<span class="dsc">
<span class="item">@7@, @message@</span>
</span>
</div>
<span class="etc_area">
<span class="etc">
<!-- [D] 날씨별 class
ico1 맑음(낮)
ico2 맑음(밤)
ico3 구름조금(낮)
ico4 구름조금(밤)
ico5 구름많음(낮)
ico6 구름많음(밤)
ico7 흐림
ico8 약한비
ico9 비
ico10 강한비
ico11 약한눈
ico12 눈
ico13 강한눈
ico14 진눈깨비
ico15 소나기
ico16 안개
ico17 소낙눈
ico18 번개뇌우
ico19 우박
ico20 황사
ico21 비또는눈
ico22 가끔비
ico23 가끔눈
ico24 가끔비또는눈
ico25 흐린후갬
ico26 뇌우후갬
ico27 비후갬
ico28 눈후갬
ico29 흐려져비
ico30 흐려져눈
-->
<span class="ico_weather"><i class="imsc ico ico@iconNo@">@7@</i></span>
<em class="degree">@8@<sup class="celsius">°</sup></em>
</span>
</span>
</a>
</div>
<!-- 정답형 템플릿 : 사이트 바로가기 -->
<!-- [AU] _answer 클래스를 추가해주세요. -->
<!-- [AU] data-template-type="answer_17" data-code="@code@" data-keyword="@1@" attribute를 추가해주세요. -->
<div class="atcmp_correct type_site _answer" data-template-type="answer_17" data-code="@code@" data-keyword="@1@">
<a href="@5@" class="link_item" target="_blank">
<span class="common_ico_kwd"><i class="imsc ico_url"></i></span>
<div class="dsc_area">
<span class="tit">@txt@</span>
<span class="dsc">
<span class="item">@5@</span>
</span>
</div>
<span class="etc_area">
<span class="etc">바로가기</span>
</span>
</a>
</div>
<!-- [AU] _kwd_list 클래스를 추가해주세요. -->
<ul class="kwd_lst _kwd_list">
<!-- [AU] 자동완성 검색어 템플릿 -->
<!-- [AU] _item 클래스를 추가해주세요. -->
<!-- [AU] data-rank="@rank@" data-template-type="suggestion" data-keyword="@in_txt@" attribute를 추가해주세요. -->
<li class="item _item" data-rank="@rank@" data-template-type="suggestion" data-keyword="@in_txt@">
<a href="#" class="kwd">
<span class="fix"><span class="common_ico_kwd"><i class="imsc ico_search"></i></span>@txt@</span>
</a>
<span class="etc">
<a href="#" role="button" class="bt_item _add" aria-pressed="false"><i class="imsc ico_insert">추가</i></a>
</span>
</li>
<!-- [AU] 최근검색어 템플릿 -->
<!-- [AU] _item 클래스를 추가해주세요. -->
<!-- [AU] data-rank="@rank@" data-template-type="history" data-keyword="@in_txt@" attribute를 추가해주세요. -->
<li class="item has_correct _item" data-rank="@rank@" data-template-type="history" data-keyword="@in_txt@">
<a href="#" class="kwd">
<span class="fix"><span class="common_ico_kwd"><i class="imsc ico_search"></i></span>@txt@</span>
</a>
<span class="etc">
<!-- 최근검색어 있으면 날짜 표시 -->
<em class="date">@date@.</em>
<a href="#" role="button" class="bt_item _add" aria-pressed="false"><i class="imsc ico_insert">추가</i></a>
</span>
</li>
</ul>
<!-- [AU] 문맥검색 템플릿 -->
<!-- [AU] _item 클래스를 추가해주세요. -->
<!-- [AU] data-rank="@rank@" data-template-type="intend" data-keyword="@transQuery@" attribute를 추가해주세요. -->
<li class="item has_correct _item" data-rank="@rank@" data-intend-rank="@intendRank@" data-template-type="intend" data-keyword="@transQuery@">
<a href="#" class="kwd">
<span class="fix"><span class="common_ico_kwd"><i class="imsc ico_search"></i></span>@query@ <span class="context">@intend@</span></span>
</a>
<span class="etc">
<a href="#" role="button" class="bt_item _add" aria-pressed="false"><i class="imsc ico_insert">추가</i></a>
</span>
</li>
<!-- [D] 선거안내문구 -->
<!-- [AU] _alert 클래스를 추가해주세요. -->
<div class="atcmp_alert _alert">
<div class="dsc_election">
<p class="dsc">
<i class="imsc ico_election"></i><span class="_alert_passage"></span>
</p>
<span class="dsc_inner">
<!-- [AU] _alert_passage2 클래스를 추가해주세요. -->
<span class="_alert_passage2"></span>
<!-- [AU] _alert_link 클래스를 추가해주세요. -->
<a href="#" class="link _alert_link" target="_blank">자세히보기</a>
</span>
</div>
</div>
<!-- [AU] _plus 클래스를 추가해주세요. -->
<div class="atcmp_plus _plus">
<div class="dsc_plus">
<a href="https://help.naver.com/support/alias/search/word/word_16.naver" class="link_dsc" data-clk="sug.cxhelp" target="_blank">관심사를 반영한 컨텍스트 자동완성<i class="imsc ico_help">도움말</i></a>
</div>
<div class="switch">
<!-- [D] 선택시 aria-pressed="ture/false" -->
<!-- [AU] _plus_btn 클래스를 추가해주세요. -->
<a role="button" href="#" class="bt_switch active _plus_btn" aria-pressed="false"><i class="imsc ico_option">컨텍스트 자동완성</i></a>
</div>
<!-- [AU] _plus_layer 클래스를 추가해주세요. -->
<div class="layer_plus _plus_layer">
<strong class="tit">컨텍스트 자동완성</strong>
<!-- [AU] _plus_layer_isloggedin 클래스를 추가해주세요. -->
<!-- [AU] style="display:none" 추가해주세요. -->
<div class="_plus_layer_isloggedin" style="display:none">
<p class="dsc">ON/OFF 설정은<br>해당기기(브라우저)에 저장됩니다.</p>
<div class="btn_area">
<a href="https://help.naver.com/support/alias/search/word/word_16.naver" class="btn btn_view" data-clk="sug.cxlink" target="_blank">자세히</a>
</div>
</div>
<!-- [AU] _plus_layer_isnotloggedin 클래스를 추가해주세요. -->
<!-- [AU] style="display:none" 추가해주세요. -->
<div class="_plus_layer_isnotloggedin" style="display:none">
<p class="dsc"><em class="txt">동일한 시간대/연령/남녀별</em> 사용자 그룹의<br>관심사에 맞춰 자동완성을 제공합니다.</p>
<div class="btn_area">
<a href="https://nid.naver.com/nidlogin.login" class="btn btn_login" data-clk="sug.cxlogin">로그인</a>
<a href="https://help.naver.com/support/alias/search/word/word_16.naver" class="btn btn_view" data-clk="sug.cxlink" target="_blank">자세히</a>
</div>
</div>
<!-- [AU] _plus_layer_close 클래스를 추가해주세요. -->
<a href="#" role="button" class="btn_close _plus_layer_close"><i class="imsc ico_close">컨텍스트 자동완성 레이어 닫기</i></a>
</div>
</div>
</div>
<div class="atcmp_footer">
<span class="side_opt_area">
<span class="opt_item"><a href="https://help.naver.com/alias/search/word/word_17.naver" data-clk="sug.help" target="_blank">도움말</a></span>
<span class="opt_item"><a href="https://help.naver.com/support/contents/contents.help?serviceNo=605&categoryNo=18215" class="report" data-clk="sug.report" target="_blank">신고</a></span>
</span>
<span class="rside_opt_area">
<span class="opt_item">
<!-- [AU] _suggestOnOff 클래스를 추가해주세요. -->
<a href="#" class="close _suggestOnOff">자동완성 끄기</a>
</span>
</span>
</div>
</div>
</div>
</div>
</div>
</div>

</div>
</div>

<!--EMPTY-->
<div id="gnb" role="navigation">
<div id="NM_FAVORITE" class="gnb_inner">
<div class="group_nav">
<ul class="list_nav type_fix">
<li class="nav_item">
<a href="https://mail.naver.com/" class="nav" data-clk="svc.mail"><i class="ico_mail"></i>메일</a>
</li>
<li class="nav_item"><a href="https://section.cafe.naver.com/" class="nav" data-clk="svc.cafe">카페</a></li>
<li class="nav_item"><a href="https://section.blog.naver.com/" class="nav" data-clk="svc.blog">블로그</a></li>
<li class="nav_item"><a href="https://kin.naver.com/" class="nav" data-clk="svc.kin">지식iN</a></li>
<li class="nav_item"><a href="https://shopping.naver.com/" class="nav shop" data-clk="svc.shopping"><span class="blind">쇼핑</span></a></li>
<li class="nav_item"><a href="https://shoppinglive.naver.com/home" class="nav shoplive"
data-clk="svc.shoppinglive"><span class="blind">쇼핑LIVE</span></a></li>
<li class="nav_item"><a href="https://order.pay.naver.com/home" class="nav" data-clk="svc.pay">Pay</a></li>
<li class="nav_item">
<a href="https://tv.naver.com/" class="nav" data-clk="svc.tvcast"><i class="ico_tv"></i>TV</a>
</li>
</ul>
<ul
class="list_nav NM_FAVORITE_LIST"
>
<li class="nav_item"><a href="https://dict.naver.com/" class="nav" data-clk="svc.dic">사전</a></li>
<li class="nav_item"><a href="https://news.naver.com/" class="nav" data-clk="svc.news">뉴스</a></li>
<li class="nav_item"><a href="https://finance.naver.com/" class="nav" data-clk="svc.stock">증권</a></li>
<li class="nav_item"><a href="https://land.naver.com/" class="nav" data-clk="svc.land">부동산</a></li>
<li class="nav_item"><a href="https://map.naver.com/" class="nav" data-clk="svc.map">지도</a></li>
<li class="nav_item"><a href="https://vibe.naver.com/" class="nav" data-clk="svc.vibe">VIBE</a></li>
<li class="nav_item"><a href="https://search.shopping.naver.com/book/home" class="nav" data-clk="svc.book">도서</a></li>
<li class="nav_item"><a href="https://comic.naver.com/" class="nav" data-clk="svc.webtoon">웹툰</a></li>

</ul>
<ul class="list_nav type_empty" style="display: none;"></ul>
<a href="#" role="button" class="btn_more" data-clk="svc.more">더보기</a>
<div class="ly_btn_area">
<a href="more.html" class="btn NM_FAVORITE_ALL" data-clk="map.svcmore">서비스 전체보기</a>
<a href="#" role="button" class="btn btn_set" data-clk="map.edit">메뉴설정</a>
<a href="#" role="button" class="btn btn_reset" data-clk="edt.reset">초기화</a>
<a href="#" role="button" class="btn btn_save" data-clk="edt.save">저장</a>
</div>
</div>
<div id="NM_WEATHER" class="group_weather">
<div>
<a data-clk="squ.weat" href="https://weather.naver.com/today/12230250?cpName=KMA" class="weather_area ico_w01">
<div class="current_box">
<strong class="current" aria-label="현재기온">20.3°</strong><strong class="state">맑음</strong>
</div>
<div class="degree_box">
<span class="min" aria-label="최저기온">12.0°</span><span class="max" aria-label="최고기온">21.0°</span>
</div>
<span class="location">광양읍</span>
</a>
</div>
<div>
<a data-clk="squ.dust" href="https://weather.naver.com/today/12230250?cpName=KMA" class="air_area">
<ul class="list_air">
<li class="air_item">미세<strong class="state state_normal">보통</strong></li>
<li class="air_item">초미세<strong class="state state_normal">보통</strong></li>
</ul>
<span class="location">광양읍</span>
</a>
</div>

</div>
</div>
<div class="ly_service">
<div class="group_service NM_FAVORITE_ALL_LY"></div>
<div class="group_service NM_FAVORITE_EDIT_LY" style="display: none;"></div>
</div>
</div>
</div>
 <div id="container" role="main"> <div style="position:relative;width:1130px;margin:0 auto;z-index:11"> <div id="da_top"></div> <div id="da_expwide"></div> </div> <div id="NM_INT_LEFT" class="column_left"> <div id="veta_top"> <div id="veta_top_inner" style="height:135px"> </div> <span class="veta_bd_t"></span> <span class="veta_bd_b"></span> <span class="veta_bd_l"></span> <span class="veta_bd_r"></span> </div> <div id="newsstand" class="sc_newscast"> <h2 class="blind">뉴스스탠드</h2> <div id="NM_NEWSSTAND_HEADER" class="group_issue" data-clk-prefix="ncy"> <div class="issue_area"> <a class="link_media" href="https://news.naver.com/main/list.naver?mode=LPOD&mid=sec&sid1=001&sid2=140&oid=001&isYeonhapFlash=Y" data-clk="newsflash">연합뉴스</a> <div id="NM_ONELINE_ROLLING" class="list_issue" data-nm-ui="rolling"> <div><a href="https://news.naver.com/main/list.naver?mode=LPOD&mid=sec&sid1=001&sid2=140&oid=001&isYeonhapFlash=Y&aid=0013522918" class="issue" data-clk="quickarticle">[자금경색 비상] ①내년 상반기까지 회사채 68조 만기…자금마련 비상</a></div>
<div><a href="https://news.naver.com/main/list.naver?mode=LPOD&mid=sec&sid1=001&sid2=140&oid=001&isYeonhapFlash=Y&aid=0013523264" class="issue" data-clk="quickarticle">SPC계열 샤니 제빵공장서 손 끼임 사고…평택참변 8일만</a></div>
<div><a href="https://news.naver.com/main/list.naver?mode=LPOD&mid=sec&sid1=001&sid2=140&oid=001&isYeonhapFlash=Y&aid=0013523047" class="issue" data-clk="quickarticle">집값 하락에 '깡통전세' 위험 더 커졌다…실거래 전세가율 껑충</a></div>
<div><a href="https://news.naver.com/main/list.naver?mode=LPOD&mid=sec&sid1=001&sid2=140&oid=001&isYeonhapFlash=Y&aid=0013523085" class="issue" data-clk="quickarticle">여가부 "'윤석열 퇴진 촛불집회' 주관 기관에 직접지원 안해"</a></div>
<div><a href="https://news.naver.com/main/list.naver?mode=LPOD&mid=sec&sid1=001&sid2=140&oid=001&isYeonhapFlash=Y&aid=0013523234" class="issue" data-clk="quickarticle">오세훈 "용산공원에 세계 정원 체험 공간 만들고파"</a></div>
<div><a href="https://news.naver.com/main/list.naver?mode=LPOD&mid=sec&sid1=001&sid2=140&oid=001&isYeonhapFlash=Y&aid=0013523111" class="issue" data-clk="quickarticle">삼천리 도시가스 이용자 카카오페이 가스요금 중복결제 오류</a></div>
<div><a href="https://news.naver.com/main/list.naver?mode=LPOD&mid=sec&sid1=001&sid2=140&oid=001&isYeonhapFlash=Y&aid=0013522924" class="issue" data-clk="quickarticle">李 겨눈 檢칼끝에 野 '대장동 특검' 총력전…가팔라진 대치정국</a></div>
<div><a href="https://news.naver.com/main/list.naver?mode=LPOD&mid=sec&sid1=001&sid2=140&oid=001&isYeonhapFlash=Y&aid=0013522926" class="issue" data-clk="quickarticle">중국 오늘 시진핑 3기 출범…권력 서열순 최고지도부 발표</a></div>
<div><a href="https://news.naver.com/main/list.naver?mode=LPOD&mid=sec&sid1=001&sid2=140&oid=001&isYeonhapFlash=Y&aid=0013522949" class="issue" data-clk="quickarticle">전세대출 금리도 7% 넘었다…"연말 8% 돌파 가능성"</a></div>
<div><a href="https://news.naver.com/main/list.naver?mode=LPOD&mid=sec&sid1=001&sid2=140&oid=001&isYeonhapFlash=Y&aid=0013522916" class="issue" data-clk="quickarticle">슬슬 다가오는 코로나19 겨울 재유행…"여름보다 규모 작을 것"</a></div> </div> </div> <div class="direct_area"> <a href="http://news.naver.com/" class="link_news" data-clk="newshome">뉴스홈</a>
<a href="http://entertain.naver.com/home" class="link_direct" data-clk="entertainment">연예</a>
<a href="http://sports.news.naver.com/" class="link_direct" data-clk="sports">스포츠</a>
<a href="http://news.naver.com/main/main.naver?mode=LSD&mid=shm&sid1=101" class="link_direct" data-clk="economy">경제</a> </div> </div>        <div id="NM_NEWSSTAND_TITLE" class="group_title" data-clk-prefix="nsd"> <a href="http://newsstand.naver.com/" class="link_newsstand" data-clk="title" target="_blank">뉴스스탠드</a> <div id="NM_NEWSSTAND_data_buttons" class="sort_area" role="tablist">  <a href="#" role="tab" data-type="my" data-clk="my" class="btn_sort" aria-controls="NM_NEWSSTAND_MY_LIST" aria-selected="false">구독한 언론사</a> <a href="#" role="tab" data-type="all" data-clk="all" class="btn_sort" aria-controls="NM_NEWSSTAND_DEFAULT_THUMB" aria-selected="true">전체언론사</a>  </div> <div id="NM_NEWSSTAND_view_buttons" class="set_area" role="tablist">  <a href="#" role="tab" data-type="list" data-clk="articleview" class="btn_set" aria-controls="NM_NEWSSTAND_DEFAULT_LIST" aria-selected="false"> <i class="ico_list"><span class="blind">리스트형</span></i></a> <a href="#" role="tab" data-type="thumb" data-clk="pressview" class="btn_set" aria-controls="NM_NEWSSTAND_DEFAULT_THUMB" aria-selected="true"> <i class="ico_tile"><span class="blind">썸네일형</span></i></a>  <a href="http://newsstand.naver.com/config.html" class="btn_set" data-clk="set" target="_blank"> <i class="ico_set"><span class="blind">설정</span></i></a> </div> </div> <div id="NM_NEWSSTAND_VIEW_CONTAINER" style="position:relative"> <div id="NM_NEWSSTAND_DEFAULT_LIST" class="group_news" role="tabpanel" style="display:none" data-clk-prefix="nsd_all"> <a href="#" role="button" class="pm_btn_prev_l _NM_NEWSSTAND_LIST_prev_btn" data-clk-custom="prev"><i class="ico_btn"><span class="blind">이전</span></i></a> <a href="#" role="button" class="pm_btn_next_l _NM_NEWSSTAND_LIST_next_btn" data-clk-custom="next"><i class="ico_btn"><span class="blind">다음</span></i></a> <div class="list_view"> <div class="option_area"> <div class="list_option_wrap"> <ul class="list_option"> <li class="option_item" data-cateid="ct2"><a href="#" class="option" data-clk="daei">종합/경제</a></li> <li class="option_item" data-cateid="ct3"><a href="#" class="option" data-clk="dtvcom">방송/통신</a></li> <li class="option_item" data-cateid="ct4"><a href="#" class="option" data-clk="dit">IT</a></li> <li class="option_item" data-cateid="ct5"><a href="#" class="option" data-clk="deng">영자지</a></li> <li class="option_item" data-cateid="ct6"><a href="#" class="option" data-clk="dsporent">스포츠/연예</a></li> <li class="option_item" data-cateid="ct7"><a href="#" class="option" data-clk="dmagtec">매거진/전문지</a></li> <li class="option_item" data-cateid="ct8"><a href="#" class="option" data-clk="dloc">지역</a></li> </ul> </div> </div> <div class="_NM_NEWSSTAND_ARTICLE_CONTAINER" data-clk-sub="*a"></div> </div> <div class="ly_popup NM_NEWSSTAND_POPUP NM_NEWSSTAND_invalid" style="display:none" data-clk-sub="*a"> <a href="#" role="button" class="btn_close NM_NEWSSTAND_POPUP_CLOSE"><i class="ico_close"></i><span class="blind">닫기</span></a> <p class="popup_msg">해당 언론사 사정으로 접근이 제한됩니다.</p> <div class="popup_btn"> <a href="#" role="button" class="btn_confirm NM_NEWSSTAND_POPUP_CLOSE">확인</a> </div> </div> <div class="ly_popup NM_NEWSSTAND_POPUP NM_NEWSSTAND_undescribe_confirm" style="display:none" data-clk-sub="*a"> <a href="#" role="button" class="btn_close NM_NEWSSTAND_POPUP_CLOSE" data-clk="usclose"><i class="ico_close"></i><span class="blind">닫기</span></a> <p class="popup_msg"><strong class="NM_NEWSSTAND_POPUP_PNAME"></strong>을(를)<br>구독해지 하시겠습니까?</p> <div class="popup_btn"> <a href="#" role="button" class="btn_confirm NM_NEWSSTAND_POPUP_CONFIRM" data-clk="usdone">확인</a> <a href="#" role="button" class="btn_confirm NM_NEWSSTAND_POPUP_CLOSE" data-clk="uscancel">취소</a> </div> </div> <div class="ly_toast NM_NEWSSTAND_TOAST" style="display:none"> <p class="toast_msg">구독한 언론사에 추가되었습니다.</p> </div> </div>   <div id="NM_NEWSSTAND_DEFAULT_THUMB" class="group_news" role="tabpanel" style="display:block" data-clk-prefix="nsd_all"> <a href="#" role="button" class="pm_btn_prev_l _NM_UI_PAGE_PREV" data-clk-custom="prev"><i class="ico_btn"><span class="blind">이전</span></i></a> <a href="#" role="button" class="pm_btn_next_l _NM_UI_PAGE_NEXT" data-clk-custom="next"><i class="ico_btn"><span class="blind">다음</span></i></a> <div class="_NM_UI_PAGE_CONTAINER" style="height:100%;overflow:hidden" data-clk-sub="*p">  <div style="width: 750px; float: left;">
<div class="tile_view">
<div class="frame_area">
<i class="line to_right1"></i>
<i class="line to_right2"></i>
<i class="line to_right3"></i>
<i class="line to_bottom1"></i>
<i class="line to_bottom2"></i>
<i class="line to_bottom3"></i>
<i class="line to_bottom4"></i>
<i class="line to_bottom5"></i>
</div>
<div class="thumb_area">
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="904"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/2020/logo/light/0604/904.png"
height="20"
alt="JTBC"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="904"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="904"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=904"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="904"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="081"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/up/2022/0208/nsd16121208.png"
height="20"
alt="서울신문"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="081"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="081"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=081"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="081"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="293"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/2020/logo/light/0604/293.png"
height="20"
alt="블로터"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="293"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="293"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=293"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="293"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="330"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/2020/logo/light/0604/330.png"
height="20"
alt="중앙데일리"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="330"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="330"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=330"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="330"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="076"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/2020/logo/light/0604/076.png"
height="20"
alt="스포츠조선"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="076"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="076"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=076"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="076"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="057"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/2020/logo/light/0604/057.png"
height="20"
alt="MBN"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="057"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="057"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=057"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="057"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="020"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/2020/logo/light/0604/020.png"
height="20"
alt="동아일보"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="020"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="020"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=020"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="020"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="029"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/2020/logo/light/0604/029.png"
height="20"
alt="디지털타임스"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="029"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="029"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=029"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="029"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="014"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/2020/logo/light/0604/014.png"
height="20"
alt="파이낸셜뉴스"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="014"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="014"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=014"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="014"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="032"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/2020/logo/light/0604/032.png"
height="20"
alt="경향신문"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="032"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="032"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=032"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="032"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="117"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/2020/logo/light/0604/117.png"
height="20"
alt="마이데일리"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="117"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="117"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=117"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="117"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="930"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/2020/logo/light/0604/930.png"
height="20"
alt="뉴스타파"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="930"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="930"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=930"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="930"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="044"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/2020/logo/light/0604/044.png"
height="20"
alt="코리아헤럴드"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="044"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="044"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=044"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="044"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="215"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/2020/logo/light/0604/215.png"
height="20"
alt="한국경제TV"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="215"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="215"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=215"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="215"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="023"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/up/2020/0903/nsd185255316.png"
height="20"
alt="조선일보"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="023"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="023"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=023"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="023"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="388"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/2020/logo/light/0604/388.png"
height="20"
alt="전남일보"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="388"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="388"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=388"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="388"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="976"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/2020/logo/light/0604/976.png"
height="20"
alt="무등일보"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="976"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="976"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=976"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="976"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="996"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/up/2022/0725/nsd1489290.png"
height="20"
alt="매경헬스"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="996"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="996"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=996"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="996"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="807"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/2020/logo/light/0604/807.png"
height="20"
alt="인사이트코리아"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="807"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="807"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=807"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="807"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="803"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/up/2021/0907/nsd9423633.png"
height="20"
alt="인더스트리뉴스"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="803"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="803"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=803"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="803"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="982"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/2020/logo/light/0604/982.png"
height="20"
alt="이코노미조선"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="982"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="982"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=982"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="982"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="243"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/2020/logo/light/0604/243.png"
height="20"
alt="이코노미스트"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="243"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="243"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=243"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="243"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="819"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/2020/logo/light/0604/819.png"
height="20"
alt="바이라인네트워크"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="819"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="819"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=819"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="819"
>기사보기</a
>
</div>
</div>
<div
class="thumb_box _NM_NEWSSTAND_THUMB _NM_NEWSSTAND_THUMB_press_valid"
data-pid="447"
>
<a href="#" class="thumb">
<img
src="https://s.pstatic.net/static/newsstand/2020/logo/light/0604/447.png"
height="20"
alt="뉴스엔"
class="news_logo"
/>
<span class="thumb_dim"></span
></a>
<div class="popup_wrap">
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_subscribe_press"
data-pid="447"
data-clk="sub"
>구독</a
>
<a
href="#"
role="button"
class="btn_popup _NM_NEWSSTAND_THUMB_unsubscribe_press"
data-pid="447"
data-clk="unsub"
>해지</a
>
<a
href="http://newsstand.naver.com/?list=&pcode=447"
target="_blank"
class="btn_popup"
data-clk="logo"
data-pid="447"
>기사보기</a
>
</div>
</div>
</div>
</div>
</div>
  </div> <div class="ly_popup NM_NEWSSTAND_POPUP NM_NEWSSTAND_invalid" style="display:none"> <a href="#" role="button" class="btn_close NM_NEWSSTAND_POPUP_CLOSE"><i class="ico_close"></i><span class="blind">닫기</span></a> <p class="popup_msg">해당 언론사 사정으로 접근이 제한됩니다.</p> <div class="popup_btn"> <a href="#" role="button" class="btn_confirm NM_NEWSSTAND_POPUP_CLOSE">확인</a> </div> </div> <div class="ly_popup NM_NEWSSTAND_POPUP NM_NEWSSTAND_undescribe_confirm" style="display:none" data-clk-sub="*a"> <a href="#" role="button" class="btn_close NM_NEWSSTAND_POPUP_CLOSE" data-clk="usclose"><i class="ico_close"></i><span class="blind">닫기</span></a> <p class="popup_msg"><strong class="NM_NEWSSTAND_POPUP_PNAME"></strong>을(를)<br/>구독해지 하시겠습니까?</p> <div class="popup_btn"> <a href="#" role="button" class="btn_confirm NM_NEWSSTAND_POPUP_CONFIRM" data-clk="usdone">확인</a> <a href="#" role="button" class="btn_confirm NM_NEWSSTAND_POPUP_CLOSE" data-clk="uscancel">취소</a> </div> </div> <div class="ly_toast NM_NEWSSTAND_TOAST" style="display:none"> <p class="toast_msg">구독한 언론사에 추가되었습니다.</p> </div> </div> <div id="NM_NEWSSTAND_MY_LIST" class="group_news" role="tabpanel" style="display:none" data-clk-prefix="nsd_myn"> <a href="#" role="button" class="pm_btn_prev_l _NM_NEWSSTAND_LIST_prev_btn" data-clk-custom="prev"><i class="ico_btn"></i><span class="blind">이전</span></a> <a href="#" role="button" class="pm_btn_next_l _NM_NEWSSTAND_LIST_next_btn" data-clk-custom="next"><i class="ico_btn"></i><span class="blind">다음</span><span class="blind">다음</span></a> <div class="list_view"> <div class="option_area"> <div class="list_option_wrap"> <ul class="list_option _NM_NEWSSTAND_MY_presslist"> <!-- nvpaperlist:empty --> </ul> </div> </div> <div class="_NM_NEWSSTAND_ARTICLE_CONTAINER" data-clk-sub="*a">  </div> </div> <div class="ly_popup NM_NEWSSTAND_POPUP NM_NEWSSTAND_invalid" style="display:none"> <a href="#" role="button" class="btn_close NM_NEWSSTAND_POPUP_CLOSE"><i class="ico_close"></i><span class="blind">닫기</span></a> <p class="popup_msg">해당 언론사 사정으로 접근이 일시 제한됩니다.</p> <div class="popup_btn"> <a href="#" role="button" class="btn_confirm NM_NEWSSTAND_POPUP_CLOSE">확인</a> </div> </div> <div class="ly_popup NM_NEWSSTAND_POPUP NM_NEWSSTAND_undescribe_confirm" style="display:none" data-clk-sub="*a"> <a href="#" role="button" class="btn_close NM_NEWSSTAND_POPUP_CLOSE" data-clk="usclose"><i class="ico_close"></i><span class="blind">닫기</span></a> <p class="popup_msg"><strong class="NM_NEWSSTAND_POPUP_PNAME"></strong>을(를)<br>구독해지 하시겠습니까?</p> <div class="popup_btn"> <a href="#" role="button" class="btn_confirm NM_NEWSSTAND_POPUP_CONFIRM" data-clk="usdone">확인</a> <a href="#" role="button" class="btn_confirm NM_NEWSSTAND_POPUP_CLOSE" data-clk="uscancel">취소</a> </div> </div> </div> <div id="NM_NEWSSTAND_MY_THUMB" class="group_news" role="tabpanel" style="display:none" data-clk-prefix="nsd_myn"> <a href="#" role="button" class="pm_btn_prev_l _NM_UI_PAGE_PREV" data-clk-custom="prev"><i class="ico_btn"><span class="blind">이전</span></i></a> <a href="#" role="button" class="pm_btn_next_l _NM_UI_PAGE_NEXT" data-clk-custom="next"><i class="ico_btn"><span class="blind">다음</span></i></a> <div class="_NM_UI_PAGE_CONTAINER" data-clk-sub="*p"></div> <div class="ly_popup NM_NEWSSTAND_POPUP NM_NEWSSTAND_invalid" style="display:none"> <a href="#" role="button" class="btn_close NM_NEWSSTAND_POPUP_CLOSE"><i class="ico_close"></i><span class="blind">닫기</span></a> <p class="popup_msg">해당 언론사 사정으로 접근이 제한됩니다.</p> <div class="popup_btn"> <a href="#" role="button" class="btn_confirm NM_NEWSSTAND_POPUP_CLOSE">확인</a> </div> </div> <div class="ly_popup NM_NEWSSTAND_POPUP NM_NEWSSTAND_undescribe_confirm" style="display:none" data-clk-sub="*a"> <a href="#" role="button" class="btn_close NM_NEWSSTAND_POPUP_CLOSE" data-clk="usclose"><i class="ico_close"></i><span class="blind">닫기</span></a> <p class="popup_msg"><strong class="NM_NEWSSTAND_POPUP_PNAME"></strong>을(를)<br>구독해지 하시겠습니까?</p> <div class="popup_btn"> <a href="#" role="button" class="btn_confirm NM_NEWSSTAND_POPUP_CONFIRM" data-clk="usdone">확인</a> <a href="#" role="button" class="btn_confirm NM_NEWSSTAND_POPUP_CLOSE" data-clk="uscancel">취소</a> </div> </div> </div> <div id="NM_NEWSSTAND_MY_EMPTY" class="group_news" role="tabpanel" style="display:none"> <div class="error_view"> <div class="error_area"> <strong class="error_msg">구독한 언론사가 없습니다.</strong> <p class="dsc_msg">언론사 구독 설정에서 관심있는 언론사를 구독하시면<br>언론사가 직접 편집한 뉴스들을 네이버 홈에서 바로 보실 수 있습니다.</p> <a href="http://newsstand.naver.com/config.html" class="link_redirect" target="_blank">언론사 구독 설정하기</a> </div> </div> </div> </div> </div> <!-- EMPTY -->  <div id="NM_THEMECAST_CONTENTS_CONTAINER"> <div id="themecast" class="sc_themecast id_culture" >
	<h2 class="blind">주제별 캐스트</h2>
	<div class="theme_head">
		<div class="group_title">
	<div class="title_area">
		<strong class="title">오늘 읽을만한 글</strong><span class="dsc">주제별로 분류된 다양한 글 모음</span>
	</div>
	<div class="info_area">
		
			<span class="info"><strong class="new">674</strong> 개의 글</span>
		
		<a id="NM_THEME_EDIT_SET" href="#" role="button" class="btn_set" data-clk="tca.like">관심주제 설정</a>
	</div>
</div>
<div id="NM_THEME_CATE_GROUPS" class="group_category" data-demo-key="default">
	<div class="main_category">
		<a href="#" role="button" class="pm_btn_prev NM_THEME_PREV" data-clk="tct.prev" style="display: none;">
			<i class="ico_btn"><span class="blind">이전</span></i>
		</a>
		<a href="#" role="button" class="pm_btn_next NM_THEME_NEXT" data-clk="tct.next" style="display: none;">
			<i class="ico_btn"><span class="blind">다음</span></i>
		</a>
		<div class="list_category_wrap">
			<ul id="NM_THEME_CATE_LIST" class="list_category" role="tablist" data-index="0">
				
					<li class="category_item" role="presentation">
						
						
						<a href="#" role="tab" class="_NM_THEME_CATE tab id_enter"
						   aria-selected="false"
						   aria-controls="NM_THEME_CONTAINER"
						   data-clk="tct.tvc" data-panel-code="ENTER">엔터</a>
					</li>
				
					<li class="category_item" role="presentation">
						
						
						<a href="#" role="tab" class="_NM_THEME_CATE tab id_sports"
						   aria-selected="false"
						   aria-controls="NM_THEME_CONTAINER"
						   data-clk="tct.spo" data-panel-code="SPORTS">스포츠</a>
					</li>
				
					<li class="category_item" role="presentation">
						
						
						<a href="#" role="tab" class="_NM_THEME_CATE tab id_cargame"
						   aria-selected="false"
						   aria-controls="NM_THEME_CONTAINER"
						   data-clk="tct.aut" data-panel-code="CARGAME">자동차</a>
					</li>
				
					<li class="category_item" role="presentation">
						
						
						<a href="#" role="tab" class="_NM_THEME_CATE tab id_bboom"
						   aria-selected="false"
						   aria-controls="NM_THEME_CONTAINER"
						   data-clk="tct.web" data-panel-code="BBOOM">웹툰</a>
					</li>
				
					<li class="category_item" role="presentation">
						
						
						<a href="#" role="tab" class="_NM_THEME_CATE tab id_finance"
						   aria-selected="false"
						   aria-controls="NM_THEME_CONTAINER"
						   data-clk="tct.fin" data-panel-code="FINANCE">경제</a>
					</li>
				
					<li class="category_item" role="presentation">
						
						
						<a href="#" role="tab" class="_NM_THEME_CATE tab id_myfeed"
						   aria-selected="false"
						   aria-controls="NM_THEME_CONTAINER"
						   data-clk="tct.sub" data-panel-code="MYFEED">추천<span class='ico_middot'></span>구독</a>
					</li>
				
					<li class="category_item" role="presentation">
						
						
						<a href="#" role="tab" class="_NM_THEME_CATE tab id_living"
						   aria-selected="false"
						   aria-controls="NM_THEME_CONTAINER"
						   data-clk="tct.fod" data-panel-code="LIVING">레시피</a>
					</li>
				
					<li class="category_item" role="presentation">
						
						
						<a href="#" role="tab" class="_NM_THEME_CATE tab id_livinghome"
						   aria-selected="false"
						   aria-controls="NM_THEME_CONTAINER"
						   data-clk="tct.lif" data-panel-code="LIVINGHOME">리빙</a>
					</li>
				
					<li class="category_item" role="presentation">
						
						
						<a href="#" role="tab" class="_NM_THEME_CATE tab id_culture"
						   aria-selected="true"
						   aria-controls="NM_THEME_CONTAINER"
						   data-clk="tct.bok" data-panel-code="CULTURE">책방</a>
					</li>
				
					<li class="category_item" role="presentation">
						
						
						<a href="#" role="tab" class="_NM_THEME_CATE tab id_beauty"
						   aria-selected="false"
						   aria-controls="NM_THEME_CONTAINER"
						   data-clk="tct.bty" data-panel-code="BEAUTY">패션뷰티</a>
					</li>
				
			</ul>
		</div>
	</div>
</div>

	</div>
	<div id="NM_THEME_CONTAINER" class="theme_cont" role="tabpanel" data-panel-code="CULTURE" data-parent-code="">
		
<div class="group_theme" data-block-id="" data-block-code="PC-THEME-CULTURE-MOBILE-RANKING-DEFAULT-0" data-block-type="MATERIALS" data-template-code="MOBILE-RANKING-LIST"

	 data-da="container"
	 data-index=""
     data-page="1"
	 >

	<div class="list_theme_wrap">
		<ul class="list_theme">
			
				<li class="theme_item" data-gdid="CAS_bd59b461-fba9-11ec-8edd-7b5f5d207d00" data-da-position="true">
					<a href="https://post.naver.com/viewer/postView.naver?volumeNo&#x3D;33952446&amp;memberNo&#x3D;5184&amp;navigationType&#x3D;push" class="theme_thumb" data-clk="tcc_bok.list1cont1" target="_blank">
						<img src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fstatic%2Fwww%2Fmobile%2Fedit%2F20220704_1095%2Fupload_1656946678254EVczd.jpg%22&amp;type&#x3D;nf340_228" data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fstatic%2Fwww%2Fmobile%2Fedit%2F20220704_1095%2Fupload_1656946678254EVczd.jpg%22&amp;type&#x3D;nf340_228" alt="출간 1년 만에 130만 부 판매, 52주 연속 베스트셀러" width="170" height="114" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
						<span class="thumb_bd"></span>
                        
					</a>
					<a href="https://post.naver.com/viewer/postView.naver?volumeNo&#x3D;33952446&amp;memberNo&#x3D;5184&amp;navigationType&#x3D;push" class="theme_info" data-clk="tcc_bok.list1cont1" target="_blank">
						<em class="theme_category"> 책방</em>
						<strong class="title elss">출간 1년 만에 130만 부 판매, 52주 연속 베스트셀러</strong>
                        <p class="desc">강렬한 첫 만남, 그리고 1년 뒤오언은 내가 물건을 잃어버리는 방식에 관해, 잃어버리는 행위를 내 나름의 예술로 승화해나가는 방식에 관해 이야기하면서 나를 놀리곤 했다. 나는 물건을 제자리에 두지 않았고, 딴 곳에 정신을 팔았고, 자주 잊어버렸다. 우리가 두 번째 데이트를 하던 날, 나는 저녁을 먹었던 곳에서 주차권을 잃어버렸다. 오언과 나는 각자 자기 차</p>
						<div class="source_box">
							<span class="date">4개월 전</span>
							<span class="source">
                                
                                <span class="source_inner">한경BP</span>
                            </span>
						</div>
					</a>
				</li>
			
				<li class="theme_item" data-gdid="CAS_bd59b460-fba9-11ec-8edd-ab2bca38650b" data-da-position="true">
					<a href="https://post.naver.com/viewer/postView.naver?volumeNo&#x3D;33931875&amp;memberNo&#x3D;6309726&amp;navigationType&#x3D;push" class="theme_thumb" data-clk="tcc_bok.list1cont2" target="_blank">
						<img src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fstatic%2Fwww%2Fmobile%2Fedit%2F20220705_1095%2Fupload_165694686574898chv.jpg%22&amp;type&#x3D;nf340_228" data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fstatic%2Fwww%2Fmobile%2Fedit%2F20220705_1095%2Fupload_165694686574898chv.jpg%22&amp;type&#x3D;nf340_228" alt="뮤지엄에서 마주한 고요와 아우성의 시간들" width="170" height="114" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
						<span class="thumb_bd"></span>
                        
					</a>
					<a href="https://post.naver.com/viewer/postView.naver?volumeNo&#x3D;33931875&amp;memberNo&#x3D;6309726&amp;navigationType&#x3D;push" class="theme_info" data-clk="tcc_bok.list1cont2" target="_blank">
						<em class="theme_category"> 책방</em>
						<strong class="title elss">뮤지엄에서 마주한 고요와 아우성의 시간들</strong>
                        <p class="desc">백 번의 전시는 백 번의 ‘케바케’ 내가 전시 기획이란 것을 처음 배운 곳은 책이다. 학예사 자격증을 받기 위해서 박물관학과 전시에 관한 책들을 읽고 교육을 받으면서 나는 전시 기획이 뭔지 알게 되었다. 그때 내가 배운 박물관 전시 기획이란 다음과 같다. 몇 년에 걸쳐서 소장품을 연구하고, 분류한다. 보존 상태가 좋지 않은 것들은 꼼꼼</p>
						<div class="source_box">
							<span class="date">4개월 전</span>
							<span class="source">
                                
                                <span class="source_inner">문학수첩</span>
                            </span>
						</div>
					</a>
				</li>
			
				<li class="theme_item" data-gdid="CAS_bd59b468-fba9-11ec-8edd-35e6a682c9b8" data-da-position="true">
					<a href="https://blog.naver.com/PostView.naver?blogId&#x3D;randomhouse1&amp;logNo&#x3D;222783727503&amp;proxyReferer&#x3D;" class="theme_thumb" data-clk="tcc_bok.list1cont3" target="_blank">
						<img src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fstatic%2Fwww%2Fmobile%2Fedit%2F20220705_1095%2Fupload_16569468455242nKp4.jpg%22&amp;type&#x3D;nf340_228" data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fstatic%2Fwww%2Fmobile%2Fedit%2F20220705_1095%2Fupload_16569468455242nKp4.jpg%22&amp;type&#x3D;nf340_228" alt="세계적인 신경학자의 기억을 따라 걷는 30년 임상 연구 기록" width="170" height="114" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
						<span class="thumb_bd"></span>
                        
					</a>
					<a href="https://blog.naver.com/PostView.naver?blogId&#x3D;randomhouse1&amp;logNo&#x3D;222783727503&amp;proxyReferer&#x3D;" class="theme_info" data-clk="tcc_bok.list1cont3" target="_blank">
						<em class="theme_category"> 책방</em>
						<strong class="title elss">세계적인 신경학자의 기억을 따라 걷는 30년 임상 연구 기록</strong>
                        <p class="desc">올리버 색스를 흥미롭게 읽은 사람이라면, 이 책을 집어들 이유는 그것만으로 충분하다. ★하지현 건국대학교병원 정신건강의학과 전문의 추천! ☆ 부커상 수상자 존 밴빌 추천☆ ☆ 아마존 과학 분야 베스트셀러☆ ☆ 하버드대·영국왕립연구소 명강의☆ ☆ 뉴욕타임스·옵서버·퍼블리셔스 위클리 극찬☆ 우리 내면을 완성하는 기억과 뇌과학의 세계 오래된 기억들의 방 아주 오</p>
						<div class="source_box">
							<span class="date">4개월 전</span>
							<span class="source">
                                
                                <span class="source_inner">알에이치코리아</span>
                            </span>
						</div>
					</a>
				</li>
			
				<li class="theme_item" data-gdid="CAS_f0a8311c-f7ad-11ec-8f87-970a7d291206" data-da-position="true">
					<a href="https://post.naver.com/viewer/postView.naver?volumeNo&#x3D;34003121&amp;memberNo&#x3D;856655&amp;vType&#x3D;VERTICAL" class="theme_thumb" data-clk="tcc_bok.list1cont4" target="_blank">
						<img src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fstatic%2Fwww%2Fmobile%2Fedit%2F20220629_1095%2Fupload_1656508738013LXUjh.jpg%22&amp;type&#x3D;nf340_228" data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fstatic%2Fwww%2Fmobile%2Fedit%2F20220629_1095%2Fupload_1656508738013LXUjh.jpg%22&amp;type&#x3D;nf340_228" alt="서양 문화로 읽는 매혹적인 꽃 이야기" width="170" height="114" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
						<span class="thumb_bd"></span>
                        
					</a>
					<a href="https://post.naver.com/viewer/postView.naver?volumeNo&#x3D;34003121&amp;memberNo&#x3D;856655&amp;vType&#x3D;VERTICAL" class="theme_info" data-clk="tcc_bok.list1cont4" target="_blank">
						<em class="theme_category"> 책방</em>
						<strong class="title elss">서양 문화로 읽는 매혹적인 꽃 이야기</strong>
                        <p class="desc">꽃말의 탄생 : 서양 문화로 읽는 매혹적인 꽃 이야기​신화, 역사, 문학에 숨겨진 꽃말의 유래 ‘사랑해’를 말하는 빨간 장미 애도를 표현하는 하얀 백합 많은 이들에게 사랑받는 50여 종의 꽃과 식물을 총망라! 국내에는 소개되지 않았던 꽃에 얽힌 신비로운 이야기 &lt;꽃말의 탄생: 서양 문화로 읽는 매혹적인 꽃 이야기&gt;는 우리에게</p>
						<div class="source_box">
							<span class="date">4개월 전</span>
							<span class="source">
                                
                                <span class="source_inner">동양북스</span>
                            </span>
						</div>
					</a>
				</li>
			
				<li class="theme_item" data-gdid="CAS_f0a8311d-f7ad-11ec-8f87-850d016d6eac" data-da-position="true">
					<a href="https://blog.naver.com/PostView.naver?blogId&#x3D;moonchusa&amp;logNo&#x3D;222782183958&amp;proxyReferer&#x3D;" class="theme_thumb" data-clk="tcc_bok.list1cont5" target="_blank">
						<img src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fstatic%2Fwww%2Fmobile%2Fedit%2F20220629_1095%2Fupload_1656508607435maiQK.jpg%22&amp;type&#x3D;nf340_228" data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fstatic%2Fwww%2Fmobile%2Fedit%2F20220629_1095%2Fupload_1656508607435maiQK.jpg%22&amp;type&#x3D;nf340_228" alt="2021년 서점대상 2위에 오른 작가 아오야마 미치코 데뷔작" width="170" height="114" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
						<span class="thumb_bd"></span>
                        
					</a>
					<a href="https://blog.naver.com/PostView.naver?blogId&#x3D;moonchusa&amp;logNo&#x3D;222782183958&amp;proxyReferer&#x3D;" class="theme_info" data-clk="tcc_bok.list1cont5" target="_blank">
						<em class="theme_category"> 책방</em>
						<strong class="title elss">2021년 서점대상 2위에 오른 작가 아오야마 미치코 데뷔작</strong>
                        <p class="desc">#목요일에는코코아를 #아오야마미치코 아오야마 미치코 지음 ㅣ 권남희 옮김 ㅣ 128*190 ㅣ 13,800원 ㅣ 192쪽 “‘좋아요’를 누르고 싶은 작가가 등장했다!” 세상의 모든 삶, 그리고 돌연한 사랑을 응원하는 코코아처럼 따뜻한 열두 빛깔 옴니버스! 작은 위로가 큰 힘이 될 때가 있다. 한 편의 소설에서 그 위로를 찾는다면 《목요일에는 코코아를》을 건</p>
						<div class="source_box">
							<span class="date">4개월 전</span>
							<span class="source">
                                
                                <span class="source_inner">문예춘추사</span>
                            </span>
						</div>
					</a>
				</li>
			
		</ul>
	</div>
</div>

    <div class="group_theme _NM_API_UI" data-ui-circular="true" data-block-id="62c3d948a10d300685d5d5c7" data-block-code="PC-THEME-CULTURE-SHOPPING-BOOK-BESTSELLER" data-block-type="PC-CULTURE-SHOPPING-BOOK-BESTSELLER-BLOCK" data-template-code="PC-THEME-CULTURE-SHOPPING-BOOK-BESTSELLER"

         data-page="1">
        <div class="theme_title">
            <strong class="title">베스트 셀러</strong>
            <span class="dsc">집계기간 2022.10.17 ~ 2022.10.23</span>
            <div class="right_box">
                <span class="dsc">제공</span><span class="dsc">인터넷 교보문고</span>
            </div>
        </div>

        <div class="poster_view_wrap">
            <a href="#" role="button" class="pm_btn_prev _NM_UI_PAGE_PREV" data-clk="tcc_bok.bestapiprev"><i class="ico_btn"><span class="blind">이전</span></i></a>
            <a href="#" role="button" class="pm_btn_next _NM_UI_PAGE_NEXT" data-clk="tcc_bok.bestapinext"><i class="ico_btn"><span class="blind">다음</span></i></a>
            <div class="_NM_UI_PAGE_CONTAINER" style="overflow: hidden;height: 341px;">

                
                    <div class="poster_view" style="width: 100%;">
                        
                            <a href="https://msearch.shopping.naver.com/book/catalog/34774839621" class="poster_area" data-gdid="2533309565235525" data-clk="tcc_bok.bestapi" target="_blank">
                                <div class="poster_thumb">
                                    <img src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fshopping.phinf%2Fmain_3477483%2F34774839621.20221017171955.jpg%22&amp;type&#x3D;nf240_366&amp;service&#x3D;navermain"" alt="" width="120" height="F183" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
                                    <span class="thumb_bd"></span>
                                </div>
                                <div class="poster_info">
                                    <strong class="title"><span class="rank">1<span class="blind">위</span></span>트렌드 코리아 2023</strong>
                                    <dl class="list_dsc">
                                        <dt class="dsc_tit">저자</dt>
                                        <dd class="dsc_data">김난도, 전미영, 최지혜, 이수진, 권정윤, 이준영, 이향은, 한다혜, 추예린</dd>
                                        <dt class="dsc_tit">출판</dt>
                                        <dd class="dsc_data">미래의창</dd>
                                        
                                            <dt class="dsc_tit">평점</dt>
                                            <dd class="dsc_data type_star">4.9</dd>
                                        
                                    </dl>
                                </div>
                            </a>
                        
                            <a href="https://msearch.shopping.naver.com/book/catalog/34926693619" class="poster_area" data-gdid="2533309717089523" data-clk="tcc_bok.bestapi" target="_blank">
                                <div class="poster_thumb">
                                    <img src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fshopping.phinf%2Fmain_3492669%2F34926693619.20221019101743.jpg%22&amp;type&#x3D;nf240_366&amp;service&#x3D;navermain"" alt="" width="120" height="F183" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
                                    <span class="thumb_bd"></span>
                                </div>
                                <div class="poster_info">
                                    <strong class="title"><span class="rank">3<span class="blind">위</span></span>반짝이는 하루, 그게 오늘이야</strong>
                                    <dl class="list_dsc">
                                        <dt class="dsc_tit">저자</dt>
                                        <dd class="dsc_data">레슬리 마샹</dd>
                                        <dt class="dsc_tit">출판</dt>
                                        <dd class="dsc_data">미디어숲</dd>
                                        
                                    </dl>
                                </div>
                            </a>
                        
                            <a href="https://msearch.shopping.naver.com/book/catalog/33684983664" class="poster_area" data-gdid="2533308475379568" data-clk="tcc_bok.bestapi" target="_blank">
                                <div class="poster_thumb">
                                    <img src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fshopping.phinf%2Fmain_3368498%2F33684983664.20221019120217.jpg%22&amp;type&#x3D;nf240_366&amp;service&#x3D;navermain"" alt="" width="120" height="F183" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
                                    <span class="thumb_bd"></span>
                                </div>
                                <div class="poster_info">
                                    <strong class="title"><span class="rank">4<span class="blind">위</span></span>하얼빈</strong>
                                    <dl class="list_dsc">
                                        <dt class="dsc_tit">저자</dt>
                                        <dd class="dsc_data">김훈</dd>
                                        <dt class="dsc_tit">출판</dt>
                                        <dd class="dsc_data">문학동네</dd>
                                        
                                            <dt class="dsc_tit">평점</dt>
                                            <dd class="dsc_data type_star">4.8</dd>
                                        
                                    </dl>
                                </div>
                            </a>
                        
                            <a href="https://msearch.shopping.naver.com/book/catalog/34294472620" class="poster_area" data-gdid="2533309084868524" data-clk="tcc_bok.bestapi" target="_blank">
                                <div class="poster_thumb">
                                    <img src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fshopping.phinf%2Fmain_3429447%2F34294472620.20221019145859.jpg%22&amp;type&#x3D;nf240_366&amp;service&#x3D;navermain"" alt="" width="120" height="F183" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
                                    <span class="thumb_bd"></span>
                                </div>
                                <div class="poster_info">
                                    <strong class="title"><span class="rank">6<span class="blind">위</span></span>아버지의 해방일지</strong>
                                    <dl class="list_dsc">
                                        <dt class="dsc_tit">저자</dt>
                                        <dd class="dsc_data">정지아</dd>
                                        <dt class="dsc_tit">출판</dt>
                                        <dd class="dsc_data">창비</dd>
                                        
                                            <dt class="dsc_tit">평점</dt>
                                            <dd class="dsc_data type_star">4.9</dd>
                                        
                                    </dl>
                                </div>
                            </a>
                        
                            <a href="https://msearch.shopping.naver.com/book/catalog/34799754622" class="poster_area" data-gdid="2533309590150526" data-clk="tcc_bok.bestapi" target="_blank">
                                <div class="poster_thumb">
                                    <img src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fshopping.phinf%2Fmain_3479975%2F34799754622.20221019150509.jpg%22&amp;type&#x3D;nf240_366&amp;service&#x3D;navermain"" alt="" width="120" height="F183" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
                                    <span class="thumb_bd"></span>
                                </div>
                                <div class="poster_info">
                                    <strong class="title"><span class="rank">7<span class="blind">위</span></span>세상에서 가장 쉬운 본질육아</strong>
                                    <dl class="list_dsc">
                                        <dt class="dsc_tit">저자</dt>
                                        <dd class="dsc_data">지나영</dd>
                                        <dt class="dsc_tit">출판</dt>
                                        <dd class="dsc_data">21세기북스</dd>
                                        
                                            <dt class="dsc_tit">평점</dt>
                                            <dd class="dsc_data type_star">4.9</dd>
                                        
                                    </dl>
                                </div>
                            </a>
                        
                    </div>
                
                    <div class="poster_view" style="width: 100%;">
                        
                            <a href="https://msearch.shopping.naver.com/book/catalog/34484911671" class="poster_area" data-gdid="2533309275307575" data-clk="tcc_bok.bestapi" target="_blank">
                                <div class="poster_thumb">
                                    <img data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fshopping.phinf%2Fmain_3448491%2F34484911671.20221019132411.jpg%22&amp;type&#x3D;nf240_366&amp;service&#x3D;navermain" alt="" width="120" height="F183" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
                                    <span class="thumb_bd"></span>
                                </div>
                                <div class="poster_info">
                                    <strong class="title"><span class="rank">8<span class="blind">위</span></span>나는 나를 바꾸기로 했다</strong>
                                    <dl class="list_dsc">
                                        <dt class="dsc_tit">저자</dt>
                                        <dd class="dsc_data">우즈훙</dd>
                                        <dt class="dsc_tit">출판</dt>
                                        <dd class="dsc_data">리드리드출판</dd>
                                        
                                            <dt class="dsc_tit">평점</dt>
                                            <dd class="dsc_data type_star">4.8</dd>
                                        
                                    </dl>
                                </div>
                            </a>
                        
                            <a href="https://msearch.shopping.naver.com/book/catalog/33684998621" class="poster_area" data-gdid="2533308475394525" data-clk="tcc_bok.bestapi" target="_blank">
                                <div class="poster_thumb">
                                    <img data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fshopping.phinf%2Fmain_3368499%2F33684998621.20221019114452.jpg%22&amp;type&#x3D;nf240_366&amp;service&#x3D;navermain" alt="" width="120" height="F183" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
                                    <span class="thumb_bd"></span>
                                </div>
                                <div class="poster_info">
                                    <strong class="title"><span class="rank">9<span class="blind">위</span></span>불편한 편의점 2</strong>
                                    <dl class="list_dsc">
                                        <dt class="dsc_tit">저자</dt>
                                        <dd class="dsc_data">김호연</dd>
                                        <dt class="dsc_tit">출판</dt>
                                        <dd class="dsc_data">나무옆의자</dd>
                                        
                                            <dt class="dsc_tit">평점</dt>
                                            <dd class="dsc_data type_star">4.8</dd>
                                        
                                    </dl>
                                </div>
                            </a>
                        
                            <a href="https://msearch.shopping.naver.com/book/catalog/32550285396" class="poster_area" data-gdid="2533307340681300" data-clk="tcc_bok.bestapi" target="_blank">
                                <div class="poster_thumb">
                                    <img data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fshopping.phinf%2Fmain_3255028%2F32550285396.20221004114149.jpg%22&amp;type&#x3D;nf240_366&amp;service&#x3D;navermain" alt="" width="120" height="F183" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
                                    <span class="thumb_bd"></span>
                                </div>
                                <div class="poster_info">
                                    <strong class="title"><span class="rank">10<span class="blind">위</span></span>역행자</strong>
                                    <dl class="list_dsc">
                                        <dt class="dsc_tit">저자</dt>
                                        <dd class="dsc_data">자청</dd>
                                        <dt class="dsc_tit">출판</dt>
                                        <dd class="dsc_data">웅진지식하우스</dd>
                                        
                                            <dt class="dsc_tit">평점</dt>
                                            <dd class="dsc_data type_star">4.7</dd>
                                        
                                    </dl>
                                </div>
                            </a>
                        
                            <a href="https://msearch.shopping.naver.com/book/catalog/32444990070" class="poster_area" data-gdid="2533307235385974" data-clk="tcc_bok.bestapi" target="_blank">
                                <div class="poster_thumb">
                                    <img data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fshopping.phinf%2Fmain_3244499%2F32444990070.20221019135743.jpg%22&amp;type&#x3D;nf240_366&amp;service&#x3D;navermain" alt="" width="120" height="F183" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
                                    <span class="thumb_bd"></span>
                                </div>
                                <div class="poster_info">
                                    <strong class="title"><span class="rank">11<span class="blind">위</span></span>불편한 편의점</strong>
                                    <dl class="list_dsc">
                                        <dt class="dsc_tit">저자</dt>
                                        <dd class="dsc_data">김호연</dd>
                                        <dt class="dsc_tit">출판</dt>
                                        <dd class="dsc_data">나무옆의자</dd>
                                        
                                            <dt class="dsc_tit">평점</dt>
                                            <dd class="dsc_data type_star">4.8</dd>
                                        
                                    </dl>
                                </div>
                            </a>
                        
                            <a href="https://msearch.shopping.naver.com/book/catalog/34106011618" class="poster_area" data-gdid="2533308896407522" data-clk="tcc_bok.bestapi" target="_blank">
                                <div class="poster_thumb">
                                    <img data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fshopping.phinf%2Fmain_3410601%2F34106011618.20221019134323.jpg%22&amp;type&#x3D;nf240_366&amp;service&#x3D;navermain" alt="" width="120" height="F183" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
                                    <span class="thumb_bd"></span>
                                </div>
                                <div class="poster_info">
                                    <strong class="title"><span class="rank">12<span class="blind">위</span></span>잘될 수밖에 없는 너에게</strong>
                                    <dl class="list_dsc">
                                        <dt class="dsc_tit">저자</dt>
                                        <dd class="dsc_data">최서영</dd>
                                        <dt class="dsc_tit">출판</dt>
                                        <dd class="dsc_data">북로망스</dd>
                                        
                                            <dt class="dsc_tit">평점</dt>
                                            <dd class="dsc_data type_star">4.7</dd>
                                        
                                    </dl>
                                </div>
                            </a>
                        
                    </div>
                
                    <div class="poster_view" style="width: 100%;">
                        
                            <a href="https://msearch.shopping.naver.com/book/catalog/34170700621" class="poster_area" data-gdid="2533308961096525" data-clk="tcc_bok.bestapi" target="_blank">
                                <div class="poster_thumb">
                                    <img data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fshopping.phinf%2Fmain_3417070%2F34170700621.20221019110522.jpg%22&amp;type&#x3D;nf240_366&amp;service&#x3D;navermain" alt="" width="120" height="F183" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
                                    <span class="thumb_bd"></span>
                                </div>
                                <div class="poster_info">
                                    <strong class="title"><span class="rank">14<span class="blind">위</span></span>마흔에 읽는 니체</strong>
                                    <dl class="list_dsc">
                                        <dt class="dsc_tit">저자</dt>
                                        <dd class="dsc_data">장재형</dd>
                                        <dt class="dsc_tit">출판</dt>
                                        <dd class="dsc_data">유노북스</dd>
                                        
                                            <dt class="dsc_tit">평점</dt>
                                            <dd class="dsc_data type_star">4.9</dd>
                                        
                                    </dl>
                                </div>
                            </a>
                        
                            <a href="https://msearch.shopping.naver.com/book/catalog/34350197624" class="poster_area" data-gdid="2533309140593528" data-clk="tcc_bok.bestapi" target="_blank">
                                <div class="poster_thumb">
                                    <img data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fshopping.phinf%2Fmain_3435019%2F34350197624.20221019104441.jpg%22&amp;type&#x3D;nf240_366&amp;service&#x3D;navermain" alt="" width="120" height="F183" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
                                    <span class="thumb_bd"></span>
                                </div>
                                <div class="poster_info">
                                    <strong class="title"><span class="rank">15<span class="blind">위</span></span>심리학이 분노에 답하다</strong>
                                    <dl class="list_dsc">
                                        <dt class="dsc_tit">저자</dt>
                                        <dd class="dsc_data">충페이충</dd>
                                        <dt class="dsc_tit">출판</dt>
                                        <dd class="dsc_data">미디어숲</dd>
                                        
                                            <dt class="dsc_tit">평점</dt>
                                            <dd class="dsc_data type_star">4.7</dd>
                                        
                                    </dl>
                                </div>
                            </a>
                        
                            <a href="https://msearch.shopping.naver.com/book/catalog/32456931752" class="poster_area" data-gdid="2533307247327656" data-clk="tcc_bok.bestapi" target="_blank">
                                <div class="poster_thumb">
                                    <img data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fshopping.phinf%2Fmain_3245693%2F32456931752.20220527050555.jpg%22&amp;type&#x3D;nf240_366&amp;service&#x3D;navermain" alt="" width="120" height="F183" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
                                    <span class="thumb_bd"></span>
                                </div>
                                <div class="poster_info">
                                    <strong class="title"><span class="rank">16<span class="blind">위</span></span>단순한 열정</strong>
                                    <dl class="list_dsc">
                                        <dt class="dsc_tit">저자</dt>
                                        <dd class="dsc_data">아니 에르노</dd>
                                        <dt class="dsc_tit">출판</dt>
                                        <dd class="dsc_data">문학동네</dd>
                                        
                                            <dt class="dsc_tit">평점</dt>
                                            <dd class="dsc_data type_star">5.0</dd>
                                        
                                    </dl>
                                </div>
                            </a>
                        
                            <a href="https://msearch.shopping.naver.com/book/catalog/33939827618" class="poster_area" data-gdid="2533308730223522" data-clk="tcc_bok.bestapi" target="_blank">
                                <div class="poster_thumb">
                                    <img data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fshopping.phinf%2Fmain_3393982%2F33939827618.20221019142920.jpg%22&amp;type&#x3D;nf240_366&amp;service&#x3D;navermain" alt="" width="120" height="F183" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
                                    <span class="thumb_bd"></span>
                                </div>
                                <div class="poster_info">
                                    <strong class="title"><span class="rank">17<span class="blind">위</span></span>파친코 2</strong>
                                    <dl class="list_dsc">
                                        <dt class="dsc_tit">저자</dt>
                                        <dd class="dsc_data">이민진</dd>
                                        <dt class="dsc_tit">출판</dt>
                                        <dd class="dsc_data">인플루엔셜</dd>
                                        
                                            <dt class="dsc_tit">평점</dt>
                                            <dd class="dsc_data type_star">4.8</dd>
                                        
                                    </dl>
                                </div>
                            </a>
                        
                            <a href="https://msearch.shopping.naver.com/book/catalog/34728550621" class="poster_area" data-gdid="2533309518946525" data-clk="tcc_bok.bestapi" target="_blank">
                                <div class="poster_thumb">
                                    <img data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fshopping.phinf%2Fmain_3472855%2F34728550621.20221019101610.jpg%22&amp;type&#x3D;nf240_366&amp;service&#x3D;navermain" alt="" width="120" height="F183" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
                                    <span class="thumb_bd"></span>
                                </div>
                                <div class="poster_info">
                                    <strong class="title"><span class="rank">19<span class="blind">위</span></span>이 책은 돈 버는 법에 관한 이야기</strong>
                                    <dl class="list_dsc">
                                        <dt class="dsc_tit">저자</dt>
                                        <dd class="dsc_data">고명환</dd>
                                        <dt class="dsc_tit">출판</dt>
                                        <dd class="dsc_data">라곰</dd>
                                        
                                            <dt class="dsc_tit">평점</dt>
                                            <dd class="dsc_data type_star">4.5</dd>
                                        
                                    </dl>
                                </div>
                            </a>
                        
                    </div>
                
                    <div class="poster_view" style="width: 100%;">
                        
                            <a href="https://msearch.shopping.naver.com/book/catalog/33435716826" class="poster_area" data-gdid="2533308226112730" data-clk="tcc_bok.bestapi" target="_blank">
                                <div class="poster_thumb">
                                    <img data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fshopping.phinf%2Fmain_3343571%2F33435716826.20221019123401.jpg%22&amp;type&#x3D;nf240_366&amp;service&#x3D;navermain" alt="" width="120" height="F183" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
                                    <span class="thumb_bd"></span>
                                </div>
                                <div class="poster_info">
                                    <strong class="title"><span class="rank">20<span class="blind">위</span></span>파친코 1</strong>
                                    <dl class="list_dsc">
                                        <dt class="dsc_tit">저자</dt>
                                        <dd class="dsc_data">이민진</dd>
                                        <dt class="dsc_tit">출판</dt>
                                        <dd class="dsc_data">인플루엔셜</dd>
                                        
                                            <dt class="dsc_tit">평점</dt>
                                            <dd class="dsc_data type_star">4.9</dd>
                                        
                                    </dl>
                                </div>
                            </a>
                        
                            <a href="https://msearch.shopping.naver.com/book/catalog/34906291630" class="poster_area" data-gdid="2533309696687534" data-clk="tcc_bok.bestapi" target="_blank">
                                <div class="poster_thumb">
                                    <img data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fshopping.phinf%2Fmain_3490629%2F34906291630.20221019132918.jpg%22&amp;type&#x3D;nf240_366&amp;service&#x3D;navermain" alt="" width="120" height="F183" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
                                    <span class="thumb_bd"></span>
                                </div>
                                <div class="poster_info">
                                    <strong class="title"><span class="rank">21<span class="blind">위</span></span>작은 땅의 야수들</strong>
                                    <dl class="list_dsc">
                                        <dt class="dsc_tit">저자</dt>
                                        <dd class="dsc_data">김주혜</dd>
                                        <dt class="dsc_tit">출판</dt>
                                        <dd class="dsc_data">다산책방</dd>
                                        
                                            <dt class="dsc_tit">평점</dt>
                                            <dd class="dsc_data type_star">4.8</dd>
                                        
                                    </dl>
                                </div>
                            </a>
                        
                            <a href="https://msearch.shopping.naver.com/book/catalog/32485979740" class="poster_area" data-gdid="2533307276375644" data-clk="tcc_bok.bestapi" target="_blank">
                                <div class="poster_thumb">
                                    <img data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fshopping.phinf%2Fmain_3248597%2F32485979740.20221019105110.jpg%22&amp;type&#x3D;nf240_366&amp;service&#x3D;navermain" alt="" width="120" height="F183" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
                                    <span class="thumb_bd"></span>
                                </div>
                                <div class="poster_info">
                                    <strong class="title"><span class="rank">22<span class="blind">위</span></span>부자 아빠 가난한 아빠 1 (20주년 특별 기념판)</strong>
                                    <dl class="list_dsc">
                                        <dt class="dsc_tit">저자</dt>
                                        <dd class="dsc_data">로버트 기요사키</dd>
                                        <dt class="dsc_tit">출판</dt>
                                        <dd class="dsc_data">민음인</dd>
                                        
                                            <dt class="dsc_tit">평점</dt>
                                            <dd class="dsc_data type_star">4.8</dd>
                                        
                                    </dl>
                                </div>
                            </a>
                        
                            <a href="https://msearch.shopping.naver.com/book/catalog/32473353629" class="poster_area" data-gdid="2533307263749533" data-clk="tcc_bok.bestapi" target="_blank">
                                <div class="poster_thumb">
                                    <img data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fshopping.phinf%2Fmain_3247335%2F32473353629.20221019105908.jpg%22&amp;type&#x3D;nf240_366&amp;service&#x3D;navermain" alt="" width="120" height="F183" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
                                    <span class="thumb_bd"></span>
                                </div>
                                <div class="poster_info">
                                    <strong class="title"><span class="rank">23<span class="blind">위</span></span>원씽(The One Thing)</strong>
                                    <dl class="list_dsc">
                                        <dt class="dsc_tit">저자</dt>
                                        <dd class="dsc_data">게리 켈러, 제이 파파산</dd>
                                        <dt class="dsc_tit">출판</dt>
                                        <dd class="dsc_data">비즈니스북스</dd>
                                        
                                            <dt class="dsc_tit">평점</dt>
                                            <dd class="dsc_data type_star">4.9</dd>
                                        
                                    </dl>
                                </div>
                            </a>
                        
                            <a href="https://msearch.shopping.naver.com/book/catalog/34905604623" class="poster_area" data-gdid="2533309696000527" data-clk="tcc_bok.bestapi" target="_blank">
                                <div class="poster_thumb">
                                    <img data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fshopping.phinf%2Fmain_3490560%2F34905604623.20221019101851.jpg%22&amp;type&#x3D;nf240_366&amp;service&#x3D;navermain" alt="" width="120" height="F183" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
                                    <span class="thumb_bd"></span>
                                </div>
                                <div class="poster_info">
                                    <strong class="title"><span class="rank">24<span class="blind">위</span></span>엄마의 말하기 연습(20만부 기념 스페셜 에디션) 양장본 Hardcover</strong>
                                    <dl class="list_dsc">
                                        <dt class="dsc_tit">저자</dt>
                                        <dd class="dsc_data">박재연</dd>
                                        <dt class="dsc_tit">출판</dt>
                                        <dd class="dsc_data">한빛라이프</dd>
                                        
                                            <dt class="dsc_tit">평점</dt>
                                            <dd class="dsc_data type_star">5.0</dd>
                                        
                                    </dl>
                                </div>
                            </a>
                        
                    </div>
                
            </div>
        </div>
    </div>

<div class="group_theme" data-block-id="" data-block-code="PC-THEME-CULTURE-MOBILE-RANKING-DEFAULT-1" data-block-type="MATERIALS" data-template-code="MOBILE-RANKING-LIST"

	 data-da="container"
	 data-index=""
     data-page="1"
	 >

	<div class="list_theme_wrap">
		<ul class="list_theme">
			
				<li class="theme_item" data-gdid="CAS_f0a8311b-f7ad-11ec-8f87-834319af14d7" data-da-position="true">
					<a href="https://post.naver.com/viewer/postView.naver?volumeNo&#x3D;34012883&amp;memberNo&#x3D;42610428&amp;searchKeyword&#x3D;%25EB%2582%25B4%25EB%25B0%2580%2520%25EC%2598%2588%25EC%25B0%25AC&amp;searchRank&#x3D;1" class="theme_thumb" data-clk="tcc_bok.list2cont1" target="_blank">
						<img src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fstatic%2Fwww%2Fmobile%2Fedit%2F20220629_1095%2Fupload_1656508579841iGQrF.jpg%22&amp;type&#x3D;nf340_228" data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fstatic%2Fwww%2Fmobile%2Fedit%2F20220629_1095%2Fupload_1656508579841iGQrF.jpg%22&amp;type&#x3D;nf340_228" alt="은둔과 거리를 사랑하는 어느 내향인의 소소한 기록" width="170" height="114" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
						<span class="thumb_bd"></span>
                        
					</a>
					<a href="https://post.naver.com/viewer/postView.naver?volumeNo&#x3D;34012883&amp;memberNo&#x3D;42610428&amp;searchKeyword&#x3D;%25EB%2582%25B4%25EB%25B0%2580%2520%25EC%2598%2588%25EC%25B0%25AC&amp;searchRank&#x3D;1" class="theme_info" data-clk="tcc_bok.list2cont1" target="_blank">
						<em class="theme_category"> 책방</em>
						<strong class="title elss">은둔과 거리를 사랑하는 어느 내향인의 소소한 기록</strong>
                        <p class="desc">소란스러운 세계를 살아가는 내향인의 비밀스러운 기쁨에 대하여은둔과 거리를 사랑하는 어느 내향인의 소소한 기록 “이제 내향형 인간의 시대가 왔다”   은둔과 거리를 사랑하는 어느 내향인의 소소한 기록이제 ‘내향형 인간’의 시대가 왔다. 첫 산문집 《우아한 가난의 시대》(2020년 문학나눔 선정도서)에서 MZ세대의 만성적인 빈곤감과 우아한 삶을 향한 욕망에 관</p>
						<div class="source_box">
							<span class="date">3개월 전</span>
							<span class="source">
                                
                                <span class="source_inner">한겨레출판</span>
                            </span>
						</div>
					</a>
				</li>
			
				<li class="theme_item" data-gdid="CAS_89d1bec9-f7ad-11ec-8f87-53ad1971d274" data-da-position="true">
					<a href="https://blog.naver.com/PostView.naver?blogId&#x3D;chungrimpub&amp;logNo&#x3D;222775839514&amp;proxyReferer&#x3D;" class="theme_thumb" data-clk="tcc_bok.list2cont2" target="_blank">
						<img src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fstatic%2Fwww%2Fmobile%2Fedit%2F20220629_1095%2Fupload_1656508391058kVeU8.jpg%22&amp;type&#x3D;nf340_228" data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fstatic%2Fwww%2Fmobile%2Fedit%2F20220629_1095%2Fupload_1656508391058kVeU8.jpg%22&amp;type&#x3D;nf340_228" alt=" 확증편향의 시대, 인간에 대한 새롭고 오래된 대답" width="170" height="114" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
						<span class="thumb_bd"></span>
                        
					</a>
					<a href="https://blog.naver.com/PostView.naver?blogId&#x3D;chungrimpub&amp;logNo&#x3D;222775839514&amp;proxyReferer&#x3D;" class="theme_info" data-clk="tcc_bok.list2cont2" target="_blank">
						<em class="theme_category"> 책방</em>
						<strong class="title elss"> 확증편향의 시대, 인간에 대한 새롭고 오래된 대답</strong>
                        <p class="desc">“갈수록 정보는 넘쳐나는데, 우리는 왜 두렵고 불안한가?” 거짓과 진실이 뒤엉킨 혼란스러운 시대에도 의심으로 일상의 평온을 지키는 회의주의의 길 저마다 ‘안다는 확신’으로 가득 찬 확증편향의 시대 ‘의심하는 인간Homo Dubitans’이 필요한 이유 미국의 한 18세 이민자 출신의 소년이 아버지를 살해한 혐의로 재판정에 섰다. 정황상 모든 증거가 소년이 </p>
						<div class="source_box">
							<span class="date">4개월 전</span>
							<span class="source">
                                
                                <span class="source_inner">청림출판</span>
                            </span>
						</div>
					</a>
				</li>
			
				<li class="theme_item" data-gdid="CAS_5e51e971-fa40-11ec-b72b-1d1d6541e7bf" data-da-position="true">
					<a href="https://blog.naver.com/seedboom00/222795518823" class="theme_thumb" data-clk="tcc_bok.list2cont3" target="_blank">
						<img src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fstatic%2Fwww%2Fmobile%2Fedit%2F20220703_1095%2Fupload_1656791576699MZUR0.jpg%22&amp;type&#x3D;nf340_228" data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fstatic%2Fwww%2Fmobile%2Fedit%2F20220703_1095%2Fupload_1656791576699MZUR0.jpg%22&amp;type&#x3D;nf340_228" alt="우리는 만족스럽지 않은 하루라고 투덜대면서 어제와 같은 오늘을 보내고는 한다. 언제까지 불평불만만 하면서 인생을 허비할 것인가?" width="170" height="114" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
						<span class="thumb_bd"></span>
                        
					</a>
					<a href="https://blog.naver.com/seedboom00/222795518823" class="theme_info" data-clk="tcc_bok.list2cont3" target="_blank">
						<em class="theme_category"> 책방</em>
						<strong class="title elss">우리는 만족스럽지 않은 하루라고 투덜대면서 어제와 같은 오늘을 보내고는 한다. 언제까지 불평불만만 하면서 인생을 허비할 것인가?</strong>
                        <p class="desc">도서명 : 아무것도 하지 않으면 아무것도 달라지지 않는다 저자 : 고윤(페이서스 코리아) 출판사명 : 마인드셋 분야 : 국내도서 &gt; 자기계발 페이지 : 204page 사양 : 128x188mm 판형 : 무선제본 발행일 : 2022년 6월 30일 가격 : 14,400원 ISBN : 979-11-91043-92-1(03190) 아무것도 하지 않으면 아무것도 달</p>
						<div class="source_box">
							<span class="date">3개월 전</span>
							<span class="source">
                                
                                <span class="source_inner">컬처블룸</span>
                            </span>
						</div>
					</a>
				</li>
			
				<li class="theme_item" data-gdid="CAS_89d1bec7-f7ad-11ec-8f87-1f4e247f85de" data-da-position="true">
					<a href="https://post.naver.com/viewer/postView.naver?volumeNo&#x3D;33954279&amp;memberNo&#x3D;1107410&amp;navigationType&#x3D;push" class="theme_thumb" data-clk="tcc_bok.list2cont4" target="_blank">
						<img src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fstatic%2Fwww%2Fmobile%2Fedit%2F20220629_1095%2Fupload_1656508356496wgHmt.jpg%22&amp;type&#x3D;nf340_228" data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fstatic%2Fwww%2Fmobile%2Fedit%2F20220629_1095%2Fupload_1656508356496wgHmt.jpg%22&amp;type&#x3D;nf340_228" alt="아픈 몸의 90%는 스트레칭으로 낫는다!" width="170" height="114" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
						<span class="thumb_bd"></span>
                        
					</a>
					<a href="https://post.naver.com/viewer/postView.naver?volumeNo&#x3D;33954279&amp;memberNo&#x3D;1107410&amp;navigationType&#x3D;push" class="theme_info" data-clk="tcc_bok.list2cont4" target="_blank">
						<em class="theme_category"> 책방</em>
						<strong class="title elss">아픈 몸의 90%는 스트레칭으로 낫는다!</strong>
                        <p class="desc">가볍고 상쾌한 몸을 위한 기적의 스트레칭굽은 어깨가 직각 어깨로, 거북목이 일자목이 되는 방법부터 허리 통증, 골반 뒤틀림, 하체 부종까지 완벽 해결! 틀어지고 망가진 몸의 균형을 바로 잡는 ‘순간 스트레칭’의 힘 ★ 쉽고 효과 빠른 스트레칭 37 ★당신은 지금 몸이 보내는 신호를 무시하고 있지 않나요? 묵직한 어깨와 목, 시큰한 손목</p>
						<div class="source_box">
							<span class="date">4개월 전</span>
							<span class="source">
                                
                                <span class="source_inner">북라이프</span>
                            </span>
						</div>
					</a>
				</li>
			
				<li class="theme_item" data-gdid="CAS_36dcd4c3-f88a-11ec-8f87-231bbf74b1c1" data-da-position="true">
					<a href="https://blog.naver.com/nsc2050/222786162926" class="theme_thumb" data-clk="tcc_bok.list2cont5" target="_blank">
						<img src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fstatic%2Fwww%2Fmobile%2Fedit%2F20220702_1095%2Fupload_1656733993996nfkFe.jpg%22&amp;type&#x3D;nf340_228" data-src="https://s.pstatic.net/dthumb.phinf/?src&#x3D;%22https%3A%2F%2Fs.pstatic.net%2Fstatic%2Fwww%2Fmobile%2Fedit%2F20220702_1095%2Fupload_1656733993996nfkFe.jpg%22&amp;type&#x3D;nf340_228" alt="역사, 철학, 과학, 의학, 예술 등 전국 대학 각 분야 최고 교수진의 명강의를 책으로 옮긴 인생명강 시리즈" width="170" height="114" onerror="this.outerHTML='<span class=\'pm_noimg\'><span class=\'noimg_text\'>이미지 준비중</span></span>'">
						<span class="thumb_bd"></span>
                        
					</a>
					<a href="https://blog.naver.com/nsc2050/222786162926" class="theme_info" data-clk="tcc_bok.list2cont5" target="_blank">
						<em class="theme_category"> 책방</em>
						<strong class="title elss">역사, 철학, 과학, 의학, 예술 등 전국 대학 각 분야 최고 교수진의 명강의를 책으로 옮긴 인생명강 시리즈</strong>
                        <p class="desc">&lt;내가 살인자의 마음을 읽는 이유&gt; - 권일용(21세기북스) &#x27;모두가 안전한 세상을 위한 권일용의 범죄심리 수업&#x27;의 책으로 최근에 나왔다. 저자는 경찰청 제1호 프로파일링 마스터로서, 2017년 퇴직한 후로 방송에 자주 얼굴을 비치며 사람들의 관심을 끌었고, 이 책은 총 네 번의 강연 내용을 수정, 보완한 결과물이다. 30년간 약 3천 건의 강력사건 범죄현</p>
						<div class="source_box">
							<span class="date">3개월 전</span>
							<span class="source">
                                
                                <span class="source_inner">프네우마</span>
                            </span>
						</div>
					</a>
				</li>
			
		</ul>
	</div>
</div>





<div class="NM_THEME_META" style="display: none" data-panel-code="CULTURE" data-parent-code=""></div>

	</div>
</div>
 </div> </div> <div id="NM_INT_RIGHT" class="column_right"> <div class="column_fix_wrap"> <div id="da_brand"></div> 





<div id="account" class="sc_login">
<h2 class="blind">Sign in</h2>
<p class="login_msg">Connect with people</p>
<a href="https://nid.naver.com/nidlogin.login?mode=form&url=https%3A%2F%2Fwww.naver.com" class="link_login" data-clk="log_off.login"><i class="ico_naver"><span class="blind">NAVER</span></i>Sign in</a>
<div class="sub_area">
<div class="look_box">
<a href="https://nid.naver.com/user/help.nhn?todo=idinquiry" class="link_look" data-clk="log_off.searchid">Forgot Username</a>
<a href="https://nid.naver.com/nidreminder.form" class="link_look" data-clk="log_off.searchpass">Password</a>
</div>
<a href="https://nid.naver.com/nidregister.form?url=https%3A%2F%2Fwww.naver.com" class="link_join" data-clk="log_off.registration">Sign up</a>
</div>
</div>



 <div id="timesquare" class="sc_timesquare"> <h2 class="blind">타임스퀘어</h2> <div class="card_wrap">
<div class="card_nav">
<a href="#" role="button" class="btn_nav btn_prev" data-clk="squ.pre"><span class="blind">이전</span></a>
<a href="#" role="button" class="btn_nav btn_next" data-clk="squ.next"><span class="blind">다음</span></a>
</div>
<div id="NM_TS_ROLLING_WRAP" style="height: 100%;">
<div>
<a href="https://search.naver.com/search.naver?sm=top_hty&amp;fbm=0&amp;ie=utf8&amp;query=%EC%BD%94%EB%A1%9C%EB%82%9819" class="card_news" data-clk="squ.line3"><i class="news_badge">이슈</i><span class="news">코로나바이러스감염증-19 현황</span></a>
</div>

</div>
</div> <!-- EMPTY --> </div> <div id="veta_branding"> <span class="blind"> <script id="veta_service_check"></script> </span> <div id="veta_branding_inner" style="width:350px;height:200px"> </div> <span class="veta_bd_t"></span> <span class="veta_bd_b"></span> <span class="veta_bd_l"></span> <span class="veta_bd_r"></span> </div> <div id="shopcast" class="sc_shopcast"> <iframe id="shopcast_iframe" data-iframe-src="/shoppingbox/shoppingboxnew/main.nhn?mode=plusdeal&domain=N" title="쇼핑캐스트" width="350" height="1809" marginheight="0" marginwidth="0" scrolling="no" frameborder="0"></iframe> </div> </div> </div> <a id="NM_scroll_top_btn" href="#wrap" class="content_top"><span class="blind">TOP</span></a> <button id="NM_darkmode_btn" type="button" role="button" class="btn_theme" aria-pressed="false"  > <span class="blind">라이트 모드로 보기</span> </button> </div> <div id="footer" role="contentinfo"> <div class="footer_inner"> <div id="NM-FOOTER-AD" class="banner_area"> <div class="da_box_wrap"> <div id="da_public_left"> </div> <div id="da_public_right"> </div> <div id="veta_time2"> </div> </div> </div> <div class="notice_area" data-clk-prefix="ntc"> <div class="notice_box"> <h3 class="title"><a href="https://www.naver.com/NOTICE">공지사항</a> </h3> <!-- EMPTY --> </div> <a href="more.html" class="link_all" data-clk="svcmap">서비스 전체보기</a> </div> <div class="aside_area"> <div class="partner_box_wrap"> <div class="partner_box" data-clk-prefix="crt"> <h3 class="title">Creators</h3> <a href="https://www.navercorp.com/service/creators" class="link_partner" data-clk="creator">크리에이터</a> <a href="https://www.navercorp.com/service/business" class="link_partner" data-clk="smbusiness">스몰비즈니스</a> </div> <div class="partner_box" data-clk-prefix="crt"> <h3 class="title">Partners</h3> <a href="https://campaign.naver.com/smefullcare/online/" class="link_partner" data-clk="sme">SME 풀케어 시스템</a> <a href="https://business.naver.com/service.html" class="link_partner" data-clk="service">비즈니스 · 광고</a> <a href="https://sell.storefarm.naver.com/#/home/about" class="link_partner" data-clk="store">스토어 개설</a> <a href="https://smartplace.naver.com" class="link_partner" data-clk="place">지역업체 등록</a> <a href="https://expert.naver.com/expert/introduction?tab=guide#join" class="link_partner" data-clk="expert">엑스퍼트 등록</a> </div> <div class="partner_box" data-clk-prefix="crt"> <h3 class="title">Developers</h3> <a href="https://developers.naver.com" class="link_partner" data-clk="center">네이버 개발자 센터</a> <a href="https://developers.naver.com/docs/common/openapiguide/#/apilist.md" class="link_partner" data-clk="openapi">오픈 API</a> <a href="https://naver.github.io" class="link_partner" data-clk="opensource">오픈소스</a> <a href="https://d2.naver.com" class="link_partner" data-clk="d2">네이버 D2</a> <a href="http://d2startup.com" class="link_partner" data-clk="naverD2SF">네이버 D2SF</a> <a href="https://www.naverlabs.com" class="link_partner" data-clk="labs">네이버 랩스</a> </div> </div> <div class="service_box_wrap"> <div class="service_box" data-clk-prefix="wbd"> <a href="http://whale.naver.com/" class="service_logo" data-clk="bt"> <img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGAAAABgCAMAAADVRocKAAAC91BMVEUAAACE1dAbf6jE1Nq/z9e82drQ3OG7ytOzws+6x9QNs7MeLpQSx60QrLAfL50gMakTxKyzwc8fMacSr6yywc8fMKIdLYzJ1d4KrrW6ydMJrrUbr6QgMKW2xNEcr6W7ydUfL5cIr7XBztgMtbMeL50fMaQQzrI0tK4cLIQUvqsVvqofMKLL0eGzxM+4xtIZuKcJr7XCyNt0xsILsLW1w9AdLYZwvL8gMaoeLY6CzMceLYyxz9fI1d0JwLMeLY4KrbXFzeAgMqvN2OEIrLUGsrVIurMfLpAcLIIIsbVWs7MeLpXIzt0UvakgMqwfL5x4wcEJsLYfMagWt6k6qqoil6DV2+UdK4EeMoEfLpOzws4/s7YgMacXvqoC27QcK38B17TE1dobKW0bKnID0bTP3OACzrQcKngcLIMbKXAD07QeLYfi6uzY4+YfLpDN2+DK2d0cK3zU4eTS3+IFzLQeL5ccKnXk7O7G19wgMJ3R3uHa5ejL2t7c5unI2Nzg6esBxrMfMKPp7vEeLYrr8fMNr7X2+PkeLYzt8vQE2LTx9fYfLpPz9/gHyLMOsrUHr7UCybQLs7YKu7UIuLUFvLQGwbUIxbQGw7QcKnTZ5OfV4uUJv67e5+rd5+rl7e8Ju6z3+vvm7vDp8PHs8vPw9fbv9PUgMaj6/PwgMqwJs6kNw7AFubULtrUGtbUJvrQEv7QAwq8MrqYKuKsKtqn+/v4Osaf7/P0K1rMHq6UeqKQNqKQhNoIgSH0Vvqoie5MhWIdV3cAcsaYhhZoglJkdLXnJ7+ia5tU61rgp1rceoKIhb4whZYgcM3fj9vJw3sdJx7xtd6sXt6hCT5AvPpAfPYQbKIMcJ34fP3q+8uSy49ux0tWd2NKYzM+A48yE08t6xchdv8FP0b1zfbcSpKIgToEbJ3nE5OG12Nmn19WM5tGKk8ehqMZlxcJJuLwgtLcbvbYc2bUTtaknNpA1Q4bZ7uuzuNuP3M9p0cNfbLUKtq5IVqk8Sp8jZpxaZZrUCA9eAAAAXXRSTlMABAj99BcO6IpfLhj9hPLp5ryyq6ZzXDnd2cuYkHtzbFFOQj0yJv76+ebc29fXx8TCuJuVlIqHgX5gPS0kEvn49/f08O3t6+fj2tLR0MzGeGNfWvbz7sXBpYN4PB4CDkIdAAAFcUlEQVRo3q3TdVwTYRjA8eeI0SKgYnd3d3d362tgO7u7Y4rd3d2K4pwwQkAQJUSxu7vbPzwYg9vufe+eO/neP9vtPr/n7t53gFMobxXPVu719pu4t/LM2a4gBwioeGZP9/0U9TyrFEyHepUSeyW45+wB/8GmXetZskpkdlGbz+w+CyVDThdV+QyT0FSMyFtikiIZMnOggIvnOMWaFwS0LBkkQj/q/mL8UpVDvv2ui6V89XvF+qm1C2rnNx8u6ferq8zfGlcHWdUbD/8PtbPI7p7aC5R49Mn6TFWZ5Z2jzKNPolOVJPtD04HEhLxFh6YH5lsqWHQQ1dVBCjFW2qUJo+8Xq3BAUeputenci27Qo6u9FGpC+8dV6pUODAZDQkKCwdAFRNz+s2wMiYwbQkwi7oWVBCvOHUep9yQkTkfMIsIv+/HygKVigaPoYuMFX+InGEQXJIS4kjRBN/b5JZutAaHcxDhQ3gVD7AWrU0a9TpgPO5OqnMUOciWJA9O8jh+IYwwmAhE39gnMrwFpchByQXCjn/kvCOf1ROil7z4LgnWuVZiQ8UpFh/gTgYs3tlvzFj4AiVbYN7oSoaDL20VaQAou6drE9UpcCCUWruyeL+ZbM3UL8Yw+YrHD4n2ozgdY9X3n05g3UnHCC6R0Xvv9pfaj/ImFoN3zqbQcJOlJkugpofWfafnoSGIp4rIvg5N5iXn+0aIS7vUQ/zBfFtMyFyPJogajXOpHrIQvYprNJf0JiEkAJu8TQqwF7VnE5mTaQyaX5PvRwUQkbLeEpH1UhqRw9ZHrP3ElInf3SOkEABmJWWhfaVG9iciHywulzNWAjY6kuiSV9wklFOELpeWHAsINZ2T3+d1JcXHrLmkVITcRGMJ8hsDehCZ8rozSkINYCKTmn8QRQn8AuQElwYtYCj4vyieG6gjdy51y6kMZYkUXmmj58kP9CcOHL7PlaKElEdEFR5031wPjCNvd2fKgOKHqF6CP1AeI7j1k+PA/aSfDdsiDjESBgDm8SJIiaCuCsgH6a7xAkuLmBASFA67zzAMuanEDdAoUHvX06dNgncldLQYU763Ex6hLkebPz7TaCfIHtOyt0kMtCpRROyAc1R8GXvy1Q1Qc/htmYNQFtyHqXEH1N2eD9ioH3NyM4gHO/VSJ2IKTC7ixqgZ8m4bjDVBMTb/waFx/IwfgNUCFK1NwHACgvZoBN5EDMgGAzRJWZSyz/3ADkjfwGo1V7PYwnPoc8MovZ2Dll18cjRzgAUnsDy5hYE24NwwpPyRrNJNuOcOSZxtx7MCk2kG6JQzfRyM5Qooix2lmsjxH9qdqIEX5TTRrGR6OQcoEZlwRSp/5BC/GjEYdI+whVfltYgfX0sXgH0CgiKh/fB3D7ck4thoQqHbS2kFGP2YyUi6w0OyUpW1rGG73x3HgwIJ98AGhU0cZ/Rhkf2oNsNLGYsC2YwwvkAMcQaTZ6TQfjzK8QfazcSDCdTiRajXD++cjUOzsgaKG3tz/uZLhHq4/PT9QVTt3NtmB1QwxI3EDnIChzeNzvLMrGd7fmoriCEyVH/P9Qyx3cP2KAJITDq9iuD8SxREkdT/C6j+Yjup3A0nOTQ8zPJiIyds6gaQCDY8wvJk4HcHOGyS1XbqC4f50jNL2IMWmwlKGd3cmItjmknn92VcwvL2F6ZeqKX37bszbv98HwU5mdfNlncfw4FYf3kSpg887aqQ3T1lW/u2dPnLk8/nKLmMoW9nDVjZfyomTzjdl1BtWcAYA+zylpGY4ONYEOc5u2evMs5a1QoHU+9I4ZXKwpcU98tgDDufc1s0re9YGdZYta5A1u5dbvlpgReOdp6JHNgc7fpCtnUO20ply5UfG/wEFXaai/lOVTwAAAABJRU5ErkJggg==" alt="웨일" width="48" height="48"> </a> <div class="service_info"> <strong class="title">웨일 브라우저</strong> <a href="http://whale.naver.com/" class="dsc" data-clk="bt">다운받기</a> </div> </div> <div class="service_box" data-clk-prefix="prj"> <a href="https://search.naver.com/search.naver?where=nexearch&sm=top_hty&fbm=1&ie=utf8&query=%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8%EA%BD%83" class="service_logo" data-clk="link"> <img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAF4AAABkCAMAAAA47XeXAAAAgVBMVEUAAADN5PdGm99Gm99Gm99Gm99Gm95Gm99Gm99Gm99Gm99Gm99Gm99Gm99Gm99Gm99Gm99Gm99Gm99Gm99Gm99Gm99Gm99Gmt9Gm99Gm99Gm99Gm95Gm99Gm99Gm95Gm99Hm99Gm99Gm9/////3+/5cp+LO5PfR5/fO5fdcp+P7/f/zv5GhAAAAInRSTlMA/v7vH9u5qJNgGwb6l8a9uqF9WFUyLxYMCtbVmLCwe4OCj8gzEgAAA0NJREFUaN7NmmFz4iAQhkkwMTHGWrWtWvWuq8mF+/8/8Ey2nb0OhSwQZnw+MHQ7pbjAy2s2gsuiLPJMLpcyy4tyISZltnmHbxw3MzEVr/MUNNL5q5iCt2ccXCN9fhPB7CQYkTsRRlWDlboSAexzGCHfC28OKxhldfDOzBMwePLNTw0sauHFFphshQcLCUwkaQRfXYBPSkrEUBdv3jezcXXhw1ciUhc+fCUidQlH7qzqEk5d2dQlnHxvU5dwVgdXdSGclaiGyamt6hLO1qIu4ZASzcFE092SBprk1jagulvXAAw/qb5N7m176xQYmOPoLymYaK/X65/PNhlagE6LGUhfRM8FjNzuf/73//bHmInzoJEpjMyeWpp9RzGz/PT6+QvMNO2Q+67PPeYZY5h7jDVg5OM+/BGikd13JfDAj/Ad1WLMyEyUwKPT00ypN1GKAljQJtFiFgqRe86eYhbWIvPPPR5d+9pKiIgUwKNJdHXBvW9jyRye1EWLWYfnJcd141Byspizz7gbUyWDuqiW0v15D9g3ZgF86JwyKUgUHJaATUmS5rsEdkkTZLjZS8Alw+skFr8Nl6H6uosShaKOp3Zo+/jgFTDe+wcSfv0yFGfQaLX7tDO0reXOPRuMCG4Q11Y3IiYblWgzS7R+h31qdRtlGB7zikeUckz+AB3a8FuMqD7Cd2nhUHLOEIkLubQIkEuLxIdwEwUy3HyXxsbgPMJcGuGox+TSIugxuTQ+KHIaAS5N92eIIuMT5tJoPfHy5q9yKoXLelLuKRri0mjMQdhwTPw6Sv8pzKXhFyhNilEwkSCXRrnAnaPnJdyl0UrqXircpeHVglnv+62K4NJo3lFcGmWd79KO7OQoXAE8XNO6tIQGxj7fpfHTwk8RubQLWEGvgTNGKzj01fixunCMCCYcvSSlaFwUyKVx86J3bczpUR3zimq1LqdosAUbJF54ar+uk5Gju436mPTk8ZAXFdO93HRYTesUVgf3B+y0XdxLfdVputmfKp/iBtNjyl3c0kzUwtJIWewIPvAL9LOyWLsV9WAps3VRzh6hJBm3oOqsRKfHLGYzS/GP+iLBuBKdqkd+iWPkFZTHf4Em4us/uhI5qss/6zK5u8+AXpwAAAAASUVORK5CYII=" alt="꽃" width="47" height="50"> </a> <div class="service_info"> <strong class="title">프로젝트 꽃</strong> <a href="https://search.naver.com/search.naver?where=nexearch&sm=top_hty&fbm=1&ie=utf8&query=%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8%EA%BD%83" class="dsc" data-clk="link">바로가기</a> </div> </div> </div> </div> <div class="corp_area" data-clk-prefix="plc"> <h3 class="blind">네이버 정책 및 약관</h3> <ul class="list_corp"> <li class="corp_item"><a href="https://www.navercorp.com" data-clk="intronhn">회사소개</a></li> <li class="corp_item"><a href="https://recruit.navercorp.com/" data-clk="recruit">인재채용</a></li> <li class="corp_item"><a href="https://www.navercorp.com/naver/proposalGuide" data-clk="contact">제휴제안</a></li> <li class="corp_item"><a href="/policy/service.html" data-clk="service">이용약관</a></li> <li class="corp_item"><a href="/policy/privacy.html" data-clk="privacy"><strong>개인정보처리방침</strong></a></li> <li class="corp_item"><a href="/policy/youthpolicy.html" data-clk="youth">청소년보호정책</a></li> <li class="corp_item"><a href="https://policy.naver.com/policy/service_group.html" data-clk="policy">네이버 정책</a></li> <li class="corp_item"><a href="https://help.naver.com/" data-clk="helpcenter">고객센터</a></li> </ul> <address class="addr"><a href="https://www.navercorp.com" target="_blank" data-clk="nhn">ⓒ NAVER Corp.</a></address> </div> </div> </div> </div> <div id="adscript" style="display:none"></div> </body> </html>

)_";