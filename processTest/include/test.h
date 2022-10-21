std::string example = R"_(
<html lang="ko" data-useragent="Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.101 Safari/537.36"><head> 
  <title>네이버 금융</title> 
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8"> 
  <meta http-equiv="Content-Script-Type" content="text/javascript"> 
  <meta http-equiv="Content-Style-Type" content="text/css"> 
  <meta name="apple-mobile-web-app-title" content="네이버 금융"> 
  <meta property="og:title" content="네이버 금융"> 
  <meta property="og:image" content="https://ssl.pstatic.net/static/m/stock/im/2016/08/og_stock-200.png"> 
  <meta property="og:url" content="https://finance.naver.com"> 
  <meta property="og:description" content="국내 해외 증시 지수, 시장지표, 뉴스, 증권사 리서치 등 제공"> 
  <meta property="og:type" content="article"> 
  <meta property="og:article:thumbnailUrl" content=""> 
  <meta property="og:article:author" content="네이버금융"> 
  <meta property="og:article:author:url" content="http://FINANCE.NAVER.COM"> 
  <link rel="stylesheet" type="text/css" href="https://ssl.pstatic.net/imgstock/static.pc/20221019125813/css/finance_header.css"> 
  <link rel="stylesheet" type="text/css" href="https://ssl.pstatic.net/imgstock/static.pc/20221019125813/css/finance.css"> 
  <link rel="stylesheet" type="text/css" href="https://ssl.pstatic.net/imgstock/static.pc/20221019125813/css/newstock3.css"> 
  <script type="text/javascript" src="https://ssl.pstatic.net/imgstock/static.pc/20221019125813/js/jindo.min.ns.1.5.3.euckr.js"></script> 
  <script type="text/javascript" src="https://ssl.pstatic.net/imgstock/static.pc/20221019125813/js/release/common.js"></script> 
  <script type="text/javascript" src="https://ssl.pstatic.net/imgstock/static.pc/20221019125813/js/jindoComponent/jindo.Component.1.0.3.js"></script> 
  <script type="text/javascript" src="https://ssl.pstatic.net/imgstock/static.pc/20221019125813/js/nhn.autocomplete.stock.js"></script> 
  <script>
	var ieVersion = (function () {
        var version = -1;
        if (
          navigator.appName == 'Microsoft Internet Explorer' &&
          navigator.userAgent.toLowerCase().indexOf('msie') != -1 &&
          new RegExp('MSIE ([0-9]{1,}[\./0-9]{0,})').exec(navigator.userAgent) != null
        ) {
          version = parseInt(RegExp.$1);
        }
        return version;
      })();
</script> 
  <!-- smart channel 광고 --> 
  <script async="" src="https://ssl.pstatic.net/tveta/libs/glad/prod/gfp-core.js">
		</script> 
  <script type="text/javascript">
		(function(){
			if (ieVersion === -1 || ieVersion > 10) {
				window.gladsdk = window.gladsdk || { cmd: [] };

				gladsdk.cmd.push(function() {
						gladsdk.defineAdSlot({
							adUnitId: "p_stock",
							adSlotElementId: "_SmartChannelTopBanner",
							uct: "KR",
							customParam: {
								calp: 
									
									
									
									
									
									
									"home"
							},
						});



						gladsdk.addEventListener(gladsdk.event.AD_LOADED, function(ad) {
							//console.log(gladsdk.event.AD_LOADED);
						});
						gladsdk.addEventListener(gladsdk.event.AD_CLICKED, function(ad) {
							//console.log(gladsdk.event.AD_CLICKED);
						});
						gladsdk.addEventListener(gladsdk.event.AD_IMPRESSED, function(ad) {
							//console.log(gladsdk.event.AD_IMPRESSED);
						});
						gladsdk.addEventListener(gladsdk.event.ERROR, function(ad, error) {
							//TODO: 오류 로깅처리
							//console.log(gladsdk.event.ERROR);
						});
					});
			}
		})();
	</script> 
  <link rel="shortcut icon" href="https://ssl.pstatic.net/imgstock/favi/favicon.ico" type="image/x-icon"> 
  <script type="text/javascript">
    (function(){
		document.write(
				[
					'<link rel="apple-touch-icon-precomposed" href="https://ssl.pstatic.net/imgstock/favi/favicon-96x96.png"/>',
					'<link rel="apple-touch-icon-precomposed" sizes="180x180" href="https://ssl.pstatic.net/imgstock/favi/favicon-180x180.png"/>',
					'<link rel="apple-touch-icon-precomposed" sizes="192x192" href="https://ssl.pstatic.net/imgstock/favi/favicon-192x192.png"/>',
					'<link rel="icon" type="image/png" sizes="16x16" href="https://ssl.pstatic.net/imgstock/favi/favicon-16x16.png"/>',
					'<link rel="icon" type="image/png" sizes="32x32" href="https://ssl.pstatic.net/imgstock/favi/favicon-32x32.png"/>',
					'<link rel="icon" type="image/png" sizes="96x96" href="https://ssl.pstatic.net/imgstock/favi/favicon-96x96.png"/>',
					'<link rel="icon" type="image/png" sizes="192x192" href="https://ssl.pstatic.net/imgstock/favi/favicon-192x192.png"/>'
				]
			.join('\n')
		);
    })();
    </script><link rel="apple-touch-icon-precomposed" href="https://ssl.pstatic.net/imgstock/favi/favicon-96x96.png">
<link rel="apple-touch-icon-precomposed" sizes="180x180" href="https://ssl.pstatic.net/imgstock/favi/favicon-180x180.png">
<link rel="apple-touch-icon-precomposed" sizes="192x192" href="https://ssl.pstatic.net/imgstock/favi/favicon-192x192.png">
<link rel="icon" type="image/png" sizes="16x16" href="https://ssl.pstatic.net/imgstock/favi/favicon-16x16.png">
<link rel="icon" type="image/png" sizes="32x32" href="https://ssl.pstatic.net/imgstock/favi/favicon-32x32.png">
<link rel="icon" type="image/png" sizes="96x96" href="https://ssl.pstatic.net/imgstock/favi/favicon-96x96.png">
<link rel="icon" type="image/png" sizes="192x192" href="https://ssl.pstatic.net/imgstock/favi/favicon-192x192.png"> 
 <style id="gnb_style" type="text/css">@charset "UTF-8";
/* NTS UIT Development Office YJH 140717 */
a.gnb_my, .gnb_icon, #gnb .gnb_my_interface, .gnb_my_li .gnb_my_content .gnb_membership, #gnb .gnb_my_membership, #gnb .gnb_ico_num .gnb_ico_new, #gnb .gnb_ico_num .gnb_ico_new .gnb_count, .gnb_lst .ico_arrow, a.gnb_my .filter_mask, .gnb_my_lyr, .gnb_my_li .gnb_my_content .gnb_mask, .gnb_my_li .gnb_my_content .gnb_change, .gnb_my_li .gnb_my_content .gnb_edit_lst li, .gnb_my_li .gnb_my_content .gnb_pay_check em, #gnb .gnb_my_li .gnb_my_community a.gnb_pay span, .gnb_notice_li .gnb_notice_lyr, .gnb_notice_li .svc_list .gnb_ico_mail, .gnb_notice_li .svc_list .gnb_btn_remove span, .gnb_notice_li .svc_list .gnb_btn_remove i, .gnb_notice_li .gnb_error .gnb_ico_error, .gnb_ly_alert .gnb_btn_close i, .gnb_first_visit, .gnb_search_box, .gnb_search_box .gnb_del_txt, .gnb_svc_more .gnb_svc_lstwrp li.gnb_event em.ic_gnb_new, .gnb_svc_more .svc_btnwrp button { background: url(https://ssl.pstatic.net/static/common/gnb/one/sp_gnb_v14.png) no-repeat -999px -999px;		background: url(https://ssl.pstatic.net/static/common/gnb/one/sp_gnb_v15.png?v=2006) no-repeat -999px -999px; /* background: url(../img/sp_gnb_v15.png) no-repeat -999px -999px; */}
.gnb_favorite_area, .gnb_search_area, .gnb_banner, .gnb_linkwrp{background:url(https://ssl.pstatic.net/static/common/gnb/2014/bg_svclyr2_v2.png) no-repeat -999px -999px}
#gnb .gnb_my_li .gnb_my_community a, .gnb_notice_li .gnb_notice_all, a.gnb_service_all, .gnb_svc_more .svc_btns{display:block;height:38px;border-top:1px solid #ebebeb;background-color:#f8f8f8;text-align:center;font-weight:bold;text-decoration:none;letter-spacing:-1px;line-height:38px}
#gnb .gnb_my_li .gnb_my_community a:visited, .gnb_notice_li .gnb_notice_all:visited, a.gnb_service_all:visited, .gnb_svc_more .svc_btns:visited{color:#444}
.gnb_login_li, .gnb_my_li, .gnb_notice_li, .mail_li, .gnb_service_li{float:left;margin-right:2px;overflow:visible}
.gnb_login_li a, .gnb_my_li a, .gnb_notice_li a, .mail_li a, .gnb_service_li a{position:relative;z-index:100}
a.gnb_my, .gnb_icon{position:relative}
#gnb{position:relative;z-index:2147483646;font-family:'나눔고딕',NanumGothic,'돋움',Dotum,'Apple SD Gothic Neo',Helvetica,Sans-serif !important;color:#444;font-size:12px;letter-spacing:0 !important;line-height:normal !important;text-align:left !important}
#gnb div, #gnb p, #gnb span, #gnb em, #gnb strong, #gnb h1, #gnb h2, #gnb h3, #gnb h4, #gnb h5, #gnb h6, #gnb ul, #gnb ol, #gnb li, #gnb dl, #gnb dt, #gnb dd, #gnb table, #gnb th, #gnb td, #gnb form, #gnb fieldset, #gnb legend, #gnb input, #gnb textarea, #gnb button, #gnb label{font-family:'나눔고딕',NanumGothic,'돋움',Dotum,'Apple SD Gothic Neo',Helvetica,Sans-serif !important}
#gnb a, #gnb label, #gnb button{cursor:pointer}
#gnb a, #gnb a:visited, #gnb a:active, #gnb a:focus{color:#444}
#gnb a:hover{color:#444;text-decoration:underline;vertical-align: baseline;}
#gnb input::-ms-clear{display:none}
#gnb em{font-style:normal}
#gnb ul{list-style:none}
#gnb .blind{display:block;overflow:hidden;position:absolute;top:-1000em;left:0;width:1px;height:1px;margin:0;padding:0;font-size:0;line-height:0}
#gnb .gnb_my_membership{padding: 0;display: block;width: 64px;height: 16px;background-position: -296px -359px;margin: 0;}
#gnb .gnb_my_interface{padding:5px;position:absolute;top:12px;right:8px;display:block;width:17px;height:16px;background-position:-90px 5px}
#gnb .gnb_my_interface:hover{background-position:-90px -20px}
#gnb .gnb_my_interface:focus{background-position:-90px -20px}
#gnb .gnb_pad_lyr{position:absolute}
#gnb .gnb_ico_num{display:block;position:absolute;top:1px;width:40px;text-align:center}
#gnb .gnb_ico_num .gnb_ico_new{height:15px;display:inline-block;background-position: -331px 0;zoom:1}
#gnb .gnb_ico_num .gnb_ico_new .gnb_count{position:relative;top:0;right:-5px;height:15px;margin:0;padding:0 4px 0 1px;display:inline-block;*display:inline;vertical-align:top;background-position: 100% 0;text-indent:-2px;font-family:tahoma !important;font-weight:bold;color:#fff;zoom:1}
#gnb .gnb_ico_num .gnb_ico_new .plus{margin:1px -1px 0 2px;font-size:8px;display:inline-block;color:#fff;vertical-align:top}
:root #gnb .gnb_pad_lyr{opacity:1 !important;/* background:#fff */}
.gnb_lst{margin:0;padding:0;zoom:1}
.gnb_lst:after{display:block;clear:both;content:''}
.gnb_lst ul{margin:0;padding:0}
.gnb_lst .ico_arrow{display:none;position:absolute;left:50%;top:27px;width:10px;height:8px;margin-left:-5px;background-position:-175px -10px}
.gnb_lyr_opened .gnb_my_lyr, .gnb_lyr_opened .gnb_service_lyr, .gnb_lyr_opened .gnb_notice_lyr, .gnb_lyr_opened .ico_arrow{display:block !important}
.gnb_login_li{height:23px;padding:5px 7px 0 0}
.gnb_btn_login, .gnb_bg, .gnb_bdr{display:inline-block;width:46px;height:20px;font-size:12px}
.gnb_btn_login{position:relative}
.gnb_bg{background-color: #fff;opacity: 0.05;filter: alpha(opacity=5);}
.gnb_bdr{position:absolute;top: -1px;left: -1px;width: 46px;height: 20px;border: 1px solid #000;opacity: 0.12;filter: alpha(opacity=12);}
.gnb_txt{position:absolute;top:0;left:0;width:45px;height:20px;padding-left:1px;line-height:21px;color:#666;text-align:center}
.gnb_btn_login:hover{text-decoration:none !important}
.gnb_account .gnb_btn_login{width:54px;margin:-1px 0 0 8px;vertical-align:top}
.gnb_account a.gnb_btn_login .gnb_txt {padding-left: 0;}
.gnb_account .gnb_bdr{width:52px}
.gnb_account .gnb_txt{width:53px}
.gnb_my_li{margin-right:7px}
.gnb_my_namebox{padding:2px 9px 0 0;background-repeat:no-repeat;background-position:100% 50%;zoom:1}
.gnb_my_namebox:after{display:block;clear:both;content:''}
a.gnb_my{float:left;display:block;font-size:12px;vertical-align:middle}
a.gnb_my .filter_mask {position: absolute; top: -1px; left: -1px; z-index: 1; width: 28px; height: 28px; background-position: -260px -60px;}
a.gnb_my img{vertical-align:top;border-radius:16px}
a.gnb_my .gnb_name{margin-right:-1px;padding-left:5px;display:inline-block;height:28px;line-height:28px;vertical-align:top;font-size:11px;color:#444}
a.gnb_my:visited{color:#444}
a.gnb_my:hover, a.gnb_my:active, a.gnb_my:visited, a.gnb_my:focus{text-decoration:none !important}
a.gnb_my:hover .gnb_name{text-decoration:underline}
a.gnb_my .ico_arrow{top:25px;margin-left:8px}
.gnb_my_namebox a.gnb_emp{float:left;display:inline-block;height:28px;margin-left:3px;line-height:28px;font-size:11px;color:#777 !important}
.gnb_my_lyr{display:none;position:absolute;top:26px;right:-8px;padding:9px 5px 4px 4px;width:316px;height:155px;background-position:-2px -1310px;z-index:10}
.gnb_my_lyr.gnb_groupid{height:144px;background-position:-2px -1500px}
.gnb_my_lyr.gnb_groupid .gnb_my_content{height:80px}
.gnb_my_lyr.gnb_groupid.gnb_longid1{height:144px;/*background-position:-2px -1664px*/}
.gnb_my_lyr.gnb_groupid.gnb_longid2{height:144px;background-position:-2px -1828px}
.gnb_my_lyr.gnb_longid1{/*width:318px;*/ /*background-position:-2px -1118px;*/}
.gnb_my_lyr.gnb_longid2{width:348px;background-position:-2px -926px}
.gnb_my_li .gnb_my_content{zoom:1;height:91px;padding:15px 0 10px 15px}
.gnb_my_li .gnb_my_content:after{display:block;clear:both;content:''}
.gnb_my_li .gnb_my_content .gnb_img_area{float:left;position:relative;display:block;width:80px;margin: 1px 0 0 1px;}
.gnb_my_li .gnb_my_content .gnb_img_area img{vertical-align:top}
.gnb_my_li .gnb_my_content .gnb_mask{position:absolute;top:0;left:0;display:block;width:80px;height:80px;background-position:-70px -60px}
.gnb_my_li .gnb_my_content .gnb_change{position:absolute;bottom:-2px;left:-2px;display:block;width:28px;height:28px;background-position:-140px 0px}
.gnb_my_li .gnb_my_content .gnb_change:hover{background-position:-140px -30px}
.gnb_my_li .gnb_my_content .gnb_txt_area{float:left;width:210px;margin:0 0 0 10px}
.gnb_longid1 .gnb_my_content .gnb_txt_area{/* width:210px; */}
.gnb_longid2 .gnb_my_content .gnb_txt_area{width:235px}
.gnb_my_li .gnb_my_content .gnb_account{margin-bottom:3px 0 1px;font-size:0}
.gnb_my_li .gnb_my_content .gnb_name{color:#666;font-size:14px;vertical-align: top}
.gnb_my_li .gnb_my_content .gnb_name a{display:inline-block;vertical-align:top;font-weight:bold;color:#222 !important}
.gnb_my_li .gnb_my_content a.gnb_mail_address{margin-left:1px;font-family:tahoma;color:#666 !important;font-size:12px}
.gnb_my_li .gnb_my_content .gnb_edit_lst{zoom:1;margin-top:7px !important}
.gnb_my_li .gnb_my_content .gnb_edit_lst:after{display:block;clear:both;content:''}
.gnb_my_li .gnb_my_content .gnb_edit_lst li{float:left;padding-left:6px;margin-left:5px;background-position:-290px -25px}
.gnb_my_li .gnb_my_content .gnb_edit_lst li.gnb_info{padding-left:0;margin-left:0;background:none}
.gnb_my_li .gnb_my_content .gnb_edit_lst a{color:#666 !important;letter-spacing:-1px}
.gnb_my_li .gnb_my_content .gnb_membership {display: inline-block;margin-right: 5px;margin-left: 1px;padding-right: 8px;background-position: -287px -403px;}
.gnb_my_li .gnb_my_content .gnb_pay_check{height:16px;margin:7px -4px 0 0 !important}
@media screen and (min-width: 0\0) { .gnb_my_li .gnb_my_content .gnb_pay_check{margin-top:17px} }
.gnb_my_li .gnb_my_content .gnb_pay_check em{display:inline-block;width:16px;height:16px;background-position:-300px -309px;margin:0 4px 0 0;overflow:hidden;font-size:0;line-height:0;vertical-align:top}
.gnb_my_li .gnb_my_content .gnb_pay_check a{font-size:14px;letter-spacing:-1px;line-height:16px;vertical-align:top}
.gnb_my_li .gnb_my_content .gnb_pay_check span{font-weight: bold;}
.gnb_my_li .gnb_my_content .gnb_pay_check strong{font-family:tahoma;letter-spacing:0;vertical-align:top;}
.gnb_my_li .gnb_my_content .gnb_pay_check a, .gnb_my_li .gnb_my_content .gnb_pay_check span, .gnb_my_li .gnb_my_content .gnb_pay_check strong{font-size:12px;color:#222 !important}
#gnb .gnb_my_li .gnb_my_community{clear:both;zoom:1}
#gnb .gnb_my_li .gnb_my_community:after{display:block;clear:both;content:''}
#gnb .gnb_my_li .gnb_my_community a{float:left;width:106px;margin-right: 0;border-right:1px solid #ebebeb}
#gnb .gnb_my_li .gnb_my_community a.gnb_pay{width:102px;border-right:0;line-height:0}
#gnb .gnb_my_li .gnb_my_community a.gnb_pay span{display:inline-block;width:41px;height:16px;background-position:-300px -334px;margin:11px auto 0;font-size:0;line-height:0}
#gnb .gnb_my_li .gnb_my_community a:active, #gnb .gnb_my_li .gnb_my_community a:focus, #gnb .gnb_my_li .gnb_my_community a:visited{text-decoration:none !important}
#gnb .gnb_my_li .gnb_my_community a:hover{text-decoration:underline !important}
#gnb .gnb_my_lyr.gnb_longid1 .gnb_my_community a{/*width:105px;*/}
#gnb .gnb_my_lyr.gnb_longid1 .gnb_my_community a.gnb_pay{/* width:106px;*/}
#gnb .gnb_my_lyr.gnb_longid2 .gnb_my_community a{width:115px}
#gnb .gnb_my_lyr.gnb_longid2 .gnb_my_community a.gnb_pay{width:116px}
#gnb.gnb_one .gnb_my_community a, #gnb.gnb_one_small .gnb_my_community a{margin-right: 0 !important;}
.gnb_notice_li a.gnb_notice{display:block;width:15px;height:17px;padding:7px 9px 4px;text-decoration:none !important}
.gnb_notice_li a.gnb_notice .gnb_ico_num{left:1px;top:0}
.gnb_notice_li a.gnb_notice .gnb_icon{display:block;width:15px;height:17px;background-position:-3px -60px}
.gnb_notice_li a.gnb_notice:hover .gnb_icon{background-position:-38px -60px;text-decoration:none !important}
.gnb_notice_li .gnb_notice_lyr{display:none;position:absolute;top:26px;right:-7px;width:297px;height:330px;padding:9px 4px 4px;background-position:-2px -584px;z-index:10;overflow:hidden}
.gnb_notice_li .svc_scroll{height:291px;overflow:scroll;overflow-x:hidden;position:relative;zoom:1}
.gnb_notice_li .svc_panel{width:100%;height:330px;overflow:hidden}
.gnb_notice_li .svc_head{position:relative;height:36px;padding-left:15px;line-height:20px;border-bottom:1px solid #eaeaea;zoom:1}
.gnb_notice_li .svc_head .gnb_tit{color:#6b6d70;margin-right:1px;line-height:36px}
.gnb_notice_li .svc_head .task_right{position:absolute;right:8px;top:8px;font-size:0}
.gnb_notice_li .svc_head .task_right button{height:20px;padding:0 6px;margin-left:4px;border:1px solid #ddd;color:#888;background-color:#fff;font-family:'나눔고딕', NanumGothic;font-size:12px;letter-spacing:-1px;line-height:18px;*line-height:16px;overflow:visible}
.gnb_notice_li .svc_list .gnb_btn_remove i, .gnb_notice_li .svc_list .gnb_btn_remove span, .gnb_notice_li .svc_noti .gnb_ico_mail, .gnb_notice_li .svc_blank .svc_msg_box, .gnb_notice_li .svc_blank .gnb_v_guide{display:inline-block;*display:inline;*zoom:1}
.gnb_notice_li .svc_list{margin-top:-1px}
.gnb_notice_li .svc_list li{position:relative;padding:7px 34px 7px 15px;border-top:1px solid #eaeaea;line-height:18px}
.gnb_notice_li .svc_list .gnb_new{background:#ffffd8}
.gnb_notice_li .svc_list .gnb_unread .gnb_subject{color:#444}
.gnb_notice_li .svc_list .gnb_unread .d_cnt{color:#ff630e}
.gnb_notice_li .svc_list .gnb_unread a:hover .gnb_subject, .gnb_notice_li .svc_list .gnb_unread .gnb_unread a:hover .d_cnt{color:#390}
.gnb_notice_li .svc_list .gnb_unread .svc_name{color:#444}
.gnb_notice_li .svc_list a.gnb_list_cover{text-decoration:none !important;display:block;position:relative;zoom:1}
.gnb_notice_li .svc_list a:hover .gnb_subject{text-decoration:underline}
.gnb_notice_li .svc_list .gnb_subject{overflow:hidden;text-overflow:ellipsis;white-space:nowrap;width:100%;color:#adadad}
.gnb_notice_li .svc_list .d_cnt{font-family:tahoma;font-size:10px}
.gnb_notice_li .svc_list .gnb_info{color:#adadad}
.gnb_notice_li .svc_list .svc_name{margin-right:3px;color:#adadad}
.gnb_notice_li .svc_list .cchr{margin-right:3px}
.gnb_notice_li .svc_list .dona{position:absolute;top:8px;right:34px;text-decoration:underline}
.gnb_notice_li .svc_list .dona a{color:#adadad}
.gnb_notice_li .svc_list .dona a:hover{color:#390}
.gnb_notice_li .svc_list .gnb_ico_mail{width:14px;height:15px;font-size:0;line-height:0;color:#fff;vertical-align:top}
.gnb_notice_li .svc_list .gnb_ico_mail.gnb_yes{background-position:-245px -17px}
.gnb_notice_li .svc_list .gnb_ico_mail.gnb_no{background-position:-245px 4px}
.gnb_notice_li .svc_list .gnb_btn_remove{position:absolute;right:4px;top:50%;z-index:100;margin-top:-13px;padding:10px;line-height:6px;font-size:0;background:none !important;border:0 !important}
.gnb_notice_li .svc_list .gnb_btn_remove span, .gnb_notice_li .svc_list .gnb_btn_remove i{display:block !important;width:7px;height:7px;font-size:0;line-height:0;color:transparent;white-space:nowrap;overflow:hidden;vertical-align:top;background-position:-175px 0}
.gnb_notice_li .svc_blank{position:absolute;top:104px;left:0;width:100%;white-space:nowrap;height:100px;font-size:0;text-align:center}
.gnb_notice_li .svc_blank .svc_msg_box{white-space:normal;font-size:12px;width:100%}
.gnb_notice_li .svc_blank .gnb_tit{display:block;color:#2f3743;font-size:14px;margin:0 0 15px}
.gnb_notice_li .svc_blank .gnb_tit strong{font-weight:normal;color:#390}
.gnb_notice_li .svc_blank .gnb_desc{line-height:19px;color:#2f3743;margin-bottom:7px}
.gnb_notice_li .svc_blank .gnb_desc a, .gnb_notice_li .svc_blank .gnb_link{color:#390;text-decoration:underline}
.gnb_notice_li .svc_blank .gnb_v_guide{vertical-align:middle;height:100%;width:0}
.gnb_notice_li .svc_blank .gnb_link_wrap{text-align:center}
.gnb_notice_li .svc_blank .gnb_link_wrap .gnb_link{display:block;width:40px;margin:0 auto !important;text-align:center}
.gnb_notice_li .svc_loading{background:url(https://ssl.pstatic.net/static/www/2014/loading.gif) no-repeat #fff center center;position:absolute;top:33px;left:0;width:100%;height:245px}
.gnb_notice_li .gnb_error{position:absolute;top:81px;left:2px;width:100%;color:#444;text-align:center}
.gnb_notice_li .gnb_error .gnb_ico_error{display:inline-block;width:57px;height:57px;background-position:-280px -190px}
.gnb_notice_li .gnb_error .gnb_tit{font-size:14px;margin:15px 0 11px}
.gnb_notice_li .gnb_error .gnb_desc{margin-bottom:13px;line-height:18px}
.gnb_notice_li .gnb_error .gnb_link{text-decoration:underline}
.gnb_ly_alert{position:absolute;top:110px;left:13px;background-color:#fff;border:1px solid #b7b9bc;width:260px;padding:34px 0 20px;zoom:1;z-index:100}
.gnb_ly_alert .gnb_msg{text-align:center;line-height:17px;margin-bottom:14px;color:#2f3743}
.gnb_.ly_alert .gnb_btn_close{position:absolute;right:2px;top:0;*overflow:visible}
.gnb_ly_alert .gnb_btns{text-align:center}
.gnb_ly_alert .gnb_btns button{height:27px;line-height:27px;*line-height:22px;font-weight:bold;font-size:12px;padding:0 8px;color:#2f3743;border:1px solid #ddd;background-color:white}
.gnb_ly_alert .gnb_btns button:first-child{margin-right:4px}
.gnb_ly_alert .gnb_btn_close{position:absolute;right:2px;top:0;width:35px;border:0;background:none;cursor:pointer;border-radius:0;padding:10px}
.gnb_ly_alert .gnb_btn_close i{display:block;width:15px;height:15px;font:0/0 a;color:transparent;white-space:nowrap;overflow:hidden;vertical-align:top;background-position:-240px -60px}
.mail_li a.gnb_mail{display:block;width:20px;height:15px;padding:7px 9px 6px;text-decoration:none !important}
.mail_li a.gnb_mail .gnb_icon{display:block;width:20px;height:15px;background-position:0px -95px}
.mail_li a.gnb_mail:hover .gnb_icon{background-position:-35px -95px;text-decoration:none !important}
.mail_li .gnb_ico_num{left:6px;top:0}
.gnb_service_li{margin-right:0}
.gnb_service_li a.gnb_service{display:block;width:16px;height:16px;padding:7px 9px 5px}
.gnb_service_li a.gnb_service .gnb_icon{display:block;width:16px;height:16px;background-position:-2px -130px}
.gnb_service_li a.gnb_service:hover .gnb_icon{background-position:-37px -130px;text-decoration:none !important}
.gnb_service_li .gnb_service_lyr{display:none;position:absolute;top:27px;right:-7px;z-index:10}
.gnb_favorite_search{width:301px;letter-spacing:-1px}
.gnb_response .gnb_favorite_search{display:none}
.gnb_favorite_area{height:93px;padding:8px 4px 0;background-position:0 0}
.gnb_favorite_lstwrp{position:relative;padding:22px 1px 15px 15px;border-bottom:1px solid #ebebeb}
.gnb_favorite_lstwrp .gnb_my_interface{top:3px !important;right:3px !important}
.gnb_first_visit{position:absolute;top:0;left:0;width:293px;height:92px;background-position:0 -310px;z-index:200}
.gnb_first_visit .gnb_close{position:absolute;top:0;right:0;display:block;width:32px;height:32px}
.gnb_favorite_lst{zoom:1}
.gnb_favorite_lst:after{display:block;clear:both;content:''}
.gnb_favorite_lst li{float:left;width:65px;text-align:center;white-space:nowrap}
.gnb_favorite_lst a{display:inline-block;text-align:center;font-weight:bold}
.gnb_favorite_lst .gnb_add a{display:block;test-align:center;}
.gnb_favorite_lst .gnb_add a span.ic_add{display:block;width:36px;height:36px;margin:0 auto 4px;background-image: url(https://ssl.pstatic.net/static/common/gnb/one/sp_gnb_4b16e6.png);background-position: 0px 0px;background-repeat: no-repeat;width: 36px;height: 36px;vertical-align: top;}
.gnb_favorite_lst .gnb_add a:hover span.ic_add{background-image: url(https://ssl.pstatic.net/static/common/gnb/one/sp_gnb_4b16e6.png);background-position: -42px 0px;background-repeat: no-repeat;width: 36px;height: 36px;vertical-align: top;}
.gnb_favorite_lst img{display:block;margin:0 auto 4px;vertical-align:top}
.gnb_search_area{position:relative;z-index:200;padding:18px 4px 17px;background-position:-301px 0;background-repeat:repeat-y}
.gnb_search_box{position:relative;z-index:101;margin:0 12px 16px 0;padding-left:10px;display:block;width:270px;height:35px;background-position:10px -190px}
.gnb_search_box.over{background-position:10px -230px}
.gnb_search_box.fcs{background-position:10px -270px}
.gnb_search_box.fcs input{width:200px;font-size:16px;font-weight:bold;color:#444;outline:0}
.gnb_search_box input{float:left;display:block;width:210px;height:22px;margin-top:6px;padding-left:10px;font-family:'나눔고딕',NamumGothic;letter-spacing:-1px;color:#adadad;font-size:13px;border:0;line-height:22px;background:transparent}
.gnb_search_box .gnb_del_txt{position:absolute;top:8px;right:32px;display:block;width:17px;height:17px;background-position:-190px 0px}
.gnb_search_box .gnb_del_txt:hover{background-position:-190px -20px}
.gnb_search_box .gnb_pop_input{position:absolute;top:34px;left:10px;width:268px;height:170px;*height:172px;border:1px solid #cbc5c5;border-top:0;background:#fff;overflow-x:hidden;overflow-y:scroll;z-index:110}
.gnb_search_box .gnb_pop_lst{padding:4px 0 2px}
.gnb_search_box .gnb_pop_lst a{display:block;padding:6px 0 6px 10px;font-weight:bold}
.gnb_search_box .gnb_pop_lst .on{background-color:#f5f5f5}
.gnb_search_lstwrp{zoom:1;height:118px;padding-left:12px}
.gnb_search_lstwrp:after{display:block;clear:both;content:''}
.gnb_search_lstwrp .gnb_search_lst{float:left;width:69px;border-left:1px solid #eaeaea}
.gnb_search_lstwrp .gnb_search_lst.gnb_first{width:64px;border:0}
.gnb_search_lstwrp li{padding:12px 0 0 8px}
.gnb_search_lstwrp li.gnb_first{font-weight:bold;padding-top:0}
.gnb_search_lstwrp li a{display:inline-block;vertical-align:top}
.gnb_banner{height:47px;margin:0;padding:0 18px;background-position:-301px 0;background-repeat:repeat-y}
.gnb_banner .gnb_service_event{display:inline-block;border-top:1px solid #ebebeb}
.gnb_linkwrp{padding:0 4px 4px;background-position:-602px 0}
a.gnb_service_all:hover, a.gnb_service_all:visited, a.gnb_service_all:active, a.gnb_service_all:focus{text-decoration:none}
.gnb_svc_more{display:none;position:absolute;top:4px;right:303px;width:589px;overflow:hidden;zoom:1;z-index:1000}
.gnb_svc_more:after{display:block;clear:both;content:''}
.gnb_response .gnb_svc_more{right:2px}
.gnb_bg_top{height:6px;background:url(https://ssl.pstatic.net/static/common/gnb/2014/bg_svclyr1_v2.png) no-repeat}
.gnb_bg_btm{position:relative;height:6px;background:url(https://ssl.pstatic.net/static/common/gnb/2014/bg_svclyr1_v2.png) no-repeat -1282px 0}
.gnb_svc_more .gnb_svc_hd{position:relative;padding:0 18px 2px 23px;letter-spacing:-1px;background:url(https://ssl.pstatic.net/static/common/gnb/2014/bg_svclyr1_v2.png) repeat-y -641px 0}
.gnb_svc_more .gnb_svc_hd .gnb_svc_tit{display:block;padding:12px 0 13px;border-bottom:1px solid #ebebeb;font-size:14px;color:#222}
.gnb_svc_more .gnb_svc_hd .link{position:absolute;top:14px;right:19px;font-size:12px;color:#444}
.gnb_svc_more .gnb_svc_hd .link a{color:#444 !important;line-height:16px !important}
.gnb_svc_more .gnb_svc_lstwrp{position:relative;height:283px;overflow:hidden;padding:15px 15px 0 20px;letter-spacing:-1px;background:url(https://ssl.pstatic.net/static/common/gnb/2014/bg_svclyr1_v2.png) repeat-y -641px 0;zoom:1}
.gnb_svc_more .gnb_svc_lstwrp:after{display:block;clear:both;content:''}
.gnb_svc_more .gnb_svc_lstwrp li{height:15px;margin-bottom:5px;color:#6b6d70;white-space:nowrap;line-height:15px}
.gnb_svc_more .gnb_svc_lstwrp li.gnb_event label{color:#444;font-weight:bold}
.gnb_svc_more .gnb_svc_lstwrp li.gnb_event em.ic_gnb_new{display:inline-block;width:11px;height:11px;background-position:-215px 0px;margin:2px 0 0 4px;font-size:0;line-height:0;vertical-align:top}
@media screen and (min-width: 0\0) { .gnb_svc_more .gnb_svc_lstwrp li.gnb_event em.ic{margin-top:3px} }
.gnb_svc_more .gnb_svc_lstwrp .gnb_input_check{width:13px;height:13px;margin:2px 3px 0 3px;padding:0;vertical-align:top;-webkit-appearance:checkbox;}
.gnb_svc_more .gnb_svc_lstwrp label{vertical-align:0px}
.gnb_svc_more .gnb_svc_lstwrp .gnb_disabled strong{color:#a8acb0}
.gnb_svc_more .gnb_svc_lstwrp .gnb_disabled li{color:#cbcbcb}
.gnb_svc_more .gnb_svc_lst1{float:left;width:328px;height:280px}
.gnb_svc_more .gnb_svc_lst1 ul{float:left;width:102px;min-height:260px;padding:5px 0 0 10px;border-left:1px solid #eee}
.gnb_svc_more .gnb_svc_lst1 ul.gnb_first{padding-left:0;border:0}
.gnb_svc_more .svc_lst2{float:left;position:relative;width:221px;border:1px solid #eee;background:#fbfbfb;zoom:1}
.gnb_svc_more .svc_lst2:after{display:block;clear:both;content:''}
.gnb_svc_more .svc_spc{float:left;position:relative;width:100px;min-height:254px;padding:9px 0 0 10px}
.gnb_svc_more .svc_spc.gnb_first{border-right:1px solid #eee}
.gnb_svc_more .svc_spc strong{height:20px;color:#2f3743;line-height:16px}
.gnb_svc_more .svc_spc a:visited{color:#2f3743}
.gnb_svc_more .svc_spc ul{padding:8px 0}
.gnb_svc_more .svc_spc li{margin-bottom:0;padding-bottom:5px;color:#848689}
.gnb_svc_more .svc_stroy{width:89px;margin-top:-5px;padding:12px 0 0;border-top:1px solid #eee}
.gnb_svc_more .svc_btns{position:relative;height:33px;overflow:hidden;padding-top:5px;line-height:normal}
.gnb_svc_more .svc_btnwrp{position:relative;*height:39px;background:url(https://ssl.pstatic.net/static/common/gnb/2014/bg_svclyr1_v2.png) repeat-y -641px 0;padding:0 2px 0 4px}
.gnb_svc_more .svc_btnwrp button{display:inline-block;width:60px;height:25px;border:0;vertical-align:top}
.gnb_svc_more .svc_btnwrp .gnb_save{background-position:0 -160px}
.gnb_svc_more .svc_btnwrp .gnb_close{margin-left:1px;background-position:-65px -160px}
.gnb_svc_more .svc_btnwrp .gnb_return{position:absolute;top:5px;left:15px;background-position:-130px -160px}
.gnb_type2 .gnb_notice_li a.gnb_notice .gnb_icon{background-position:-155px -120px}
.gnb_type2 .gnb_notice_li a.gnb_notice:hover .gnb_icon{background-position:-155px -140px}
.gnb_type2 .gnb_service_li .gnb_service .gnb_icon{background-position:-200px -120px}
.gnb_type2 .gnb_service_li .gnb_service:hover .gnb_icon{background-position:-200px -140px}
.gnb_type2 .mail_li a.gnb_mail .gnb_icon{background-position:-175px -120px}
.gnb_type2 .mail_li a.gnb_mail:hover .gnb_icon{background-position:-175px -140px}
.gnb_dark .gnb_my_li .gnb_my .gnb_name, .gnb_dark .gnb_login_li .gnb_btn_login .gnb_txt{color:#fff}
.gnb_dark .gnb_notice_li a.gnb_notice .gnb_icon{background-position:-220px -140px}
.gnb_dark .gnb_notice_li a.gnb_notice:hover .gnb_icon{background-position:-220px -120px}
.gnb_dark .mail_li a.gnb_mail .gnb_icon{background-position:-238px -141px}
.gnb_dark .mail_li a.gnb_mail:hover .gnb_icon{background-position:-238px -121px}
.gnb_dark .gnb_service_li .gnb_service .gnb_icon{background-position:-261px -140px}
.gnb_dark .gnb_service_li .gnb_service:hover .gnb_icon{background-position:-261px -120px}
.gnb_dark_type2 .gnb_my_li .gnb_my .gnb_name, .gnb_dark_type2 .gnb_login_li .gnb_btn_login .gnb_txt{color:#fff}
.gnb_dark_type2 .gnb_notice_li a.gnb_notice .gnb_icon{background-position:-220px -120px}
.gnb_dark_type2 .gnb_notice_li a.gnb_notice:hover .gnb_icon{background-position:-220px -140px}
.gnb_dark_type2 .mail_li a.gnb_mail .gnb_icon{background-position:-238px -121px}
.gnb_dark_type2 .mail_li a.gnb_mail:hover .gnb_icon{background-position:-238px -141px}
.gnb_dark_type2 .gnb_service_li .gnb_service .gnb_icon{background-position:-261px -120px}
.gnb_dark_type2 .gnb_service_li .gnb_service:hover .gnb_icon{background-position:-261px -140px;}
.gnb_dark .gnb_notice_li a.gnb_notice, .gnb_dark_type2 .gnb_notice_li a.gnb_notice {width: 17px;height: 19px;padding: 6px 8px 3px;}
.gnb_dark .gnb_notice_li a.gnb_notice .gnb_icon, .gnb_dark_type2 .gnb_notice_li a.gnb_notice .gnb_icon {width: 17px;height: 19px;}
.gnb_dark .mail_li a.gnb_mail, .gnb_dark_type2 .mail_li a.gnb_mail {width: 22px;height: 16px;padding: 7px 8px 4px;}
.gnb_dark .mail_li a.gnb_mail .gnb_icon, .gnb_dark_type2 .mail_li a.gnb_mail .gnb_icon {width: 22px;height: 16px;}
.gnb_dark .gnb_service_li a.gnb_service, .gnb_dark_type2 .gnb_service_li a.gnb_service {width: 18px;height: 18px;padding: 6px 8px 4px;}
.gnb_dark .gnb_service_li .gnb_service .gnb_icon, .gnb_dark_type2 .gnb_service_li .gnb_service .gnb_icon {width: 18px;height: 18px;}
#gnb.gnb_one .gnb_my_li .gnb_my .gnb_name, #gnb.gnb_one_small .gnb_my_li .gnb_my .gnb_name, #gnb.gnb_one .gnb_login_li .gnb_btn_login .gnb_txt, #gnb.gnb_one_small .gnb_login_li .gnb_btn_login .gnb_txt{color:#fff}
#gnb.gnb_one .gnb_login_li, #gnb.gnb_one_small .gnb_login_li {height: 28px;}
#gnb.gnb_one .gnb_login_li .gnb_btn_login, #gnb.gnb_one_small .gnb_login_li .gnb_btn_login, #gnb.gnb_one .gnb_login_li .gnb_bg, #gnb.gnb_one_small .gnb_login_li .gnb_bg, #gnb.gnb_one .gnb_login_li .gnb_bdr, #gnb.gnb_one_small .gnb_login_li .gnb_bdr, #gnb.gnb_one .gnb_login_li .gnb_txt, #gnb.gnb_one_small .gnb_login_li .gnb_txt {width: 53px;height: 23px;}
#gnb.gnb_one .gnb_login_li .gnb_btn_login .gnb_txt, #gnb.gnb_one_small .gnb_login_li .gnb_btn_login .gnb_txt {top: -1px;width: 53px;height: 23px;line-height: 28px;font-size: 11px;}
#gnb.gnb_one .gnb_login_li, #gnb.gnb_one_small .gnb_login_li, #gnb.gnb_one .gnb_my_li, #gnb.gnb_one_small .gnb_my_li, #gnb.gnb_one .gnb_notice_li, #gnb.gnb_one_small .gnb_notice_li, #gnb.gnb_one .mail_li, #gnb.gnb_one_small .mail_li, #gnb.gnb_one .gnb_service_li, #gnb.gnb_one_small .gnb_service_li{margin-right: 0;margin-left: 0; background: url(https://ssl.pstatic.net/static/common/gnb/bg_one_line.png) repeat-y right 0;}
#gnb.gnb_one .gnb_login_li a, #gnb.gnb_one_small .gnb_login_li a, #gnb.gnb_one .gnb_my_li a, #gnb.gnb_one_small .gnb_my_li a, #gnb.gnb_one .gnb_notice_li a, #gnb.gnb_one_small .gnb_notice_li a, #gnb.gnb_one .mail_li a, #gnb.gnb_one_small .mail_li a, #gnb.gnb_one .gnb_service_li a, #gnb.gnb_one_small .gnb_service_li a {margin-right: 1px;}
#gnb.gnb_one .gnb_login_li.hover .gnb_service, #gnb.gnb_one_small .gnb_login_li.hover .gnb_service, #gnb.gnb_one .gnb_login_li.hover .gnb_notice, #gnb.gnb_one_small .gnb_login_li.hover .gnb_notice, #gnb.gnb_one .gnb_login_li.hover .gnb_mail, #gnb.gnb_one_small .gnb_login_li.hover .gnb_mail, #gnb.gnb_one .gnb_login_li.hover .gnb_service, #gnb.gnb_one_small .gnb_login_li.hover .gnb_service, #gnb.gnb_one .gnb_my_li.hover .gnb_service, #gnb.gnb_one_small .gnb_my_li.hover .gnb_service, #gnb.gnb_one .gnb_my_li.hover .gnb_notice, #gnb.gnb_one_small .gnb_my_li.hover .gnb_notice, #gnb.gnb_one .gnb_my_li.hover .gnb_mail, #gnb.gnb_one_small .gnb_my_li.hover .gnb_mail, #gnb.gnb_one .gnb_my_li.hover .gnb_service, #gnb.gnb_one_small .gnb_my_li.hover .gnb_service, #gnb.gnb_one .gnb_notice_li.hover .gnb_service, #gnb.gnb_one_small .gnb_notice_li.hover .gnb_service, #gnb.gnb_one .gnb_notice_li.hover .gnb_notice, #gnb.gnb_one_small .gnb_notice_li.hover .gnb_notice, #gnb.gnb_one .gnb_notice_li.hover .gnb_mail, #gnb.gnb_one_small .gnb_notice_li.hover .gnb_mail, #gnb.gnb_one .gnb_notice_li.hover .gnb_service, #gnb.gnb_one_small .gnb_notice_li.hover .gnb_service, #gnb.gnb_one .mail_li.hover .gnb_service, #gnb.gnb_one_small .mail_li.hover .gnb_service, #gnb.gnb_one .mail_li.hover .gnb_notice, #gnb.gnb_one_small .mail_li.hover .gnb_notice, #gnb.gnb_one .mail_li.hover .gnb_mail, #gnb.gnb_one_small .mail_li.hover .gnb_mail, #gnb.gnb_one .mail_li.hover .gnb_service, #gnb.gnb_one_small .mail_li.hover .gnb_service, #gnb.gnb_one .gnb_service_li.hover .gnb_service, #gnb.gnb_one_small .gnb_service_li.hover .gnb_service, #gnb.gnb_one .gnb_service_li.hover .gnb_notice, #gnb.gnb_one_small .gnb_service_li.hover .gnb_notice, #gnb.gnb_one .gnb_service_li.hover .gnb_mail, #gnb.gnb_one_small .gnb_service_li.hover .gnb_mail, #gnb.gnb_one .gnb_service_li.hover .gnb_service, #gnb.gnb_one_small .gnb_service_li.hover .gnb_service {background: url(https://ssl.pstatic.net/static/common/gnb/bg_one_hover.png) repeat 0 0;}
#gnb.gnb_one .gnb_my_li .gnb_my .gnb_name, #gnb.gnb_one_small .gnb_my_li .gnb_my .gnb_name{margin:0 0 0 1px;}
#gnb.gnb_one .gnb_notice_li a.gnb_notice, #gnb.gnb_one_small .gnb_notice_li a.gnb_notice{width:17px;height:19px}
#gnb.gnb_one .gnb_notice_li a.gnb_notice .gnb_icon, #gnb.gnb_one_small .gnb_notice_li a.gnb_notice .gnb_icon{width:17px;height:19px;background-position:-284px -119px}
#gnb.gnb_one .gnb_notice_li a.gnb_notice:hover .gnb_icon, #gnb.gnb_one_small .gnb_notice_li a.gnb_notice:hover .gnb_icon{background-position:-284px -119px}
#gnb.gnb_one .mail_li a.gnb_mail, #gnb.gnb_one_small .mail_li a.gnb_mail{width:21px;height:17px}
#gnb.gnb_one .mail_li a.gnb_mail .gnb_icon, #gnb.gnb_one_small .mail_li a.gnb_mail .gnb_icon{width:21px;height:17px;background-position:-302px -120px}
#gnb.gnb_one .mail_li a.gnb_mail:hover .gnb_icon, #gnb.gnb_one_small .mail_li a.gnb_mail:hover .gnb_icon{background-position:-302px -120px}
#gnb.gnb_one .gnb_service_li .gnb_service, #gnb.gnb_one_small .gnb_service_li .gnb_service{width:17px;height:17px}
#gnb.gnb_one .gnb_service_li .gnb_service .gnb_icon, #gnb.gnb_one_small .gnb_service_li .gnb_service .gnb_icon{width:17px;height:17px;background-position:-324px -120px}
#gnb.gnb_one .gnb_service_li .gnb_service:hover .gnb_icon, #gnb.gnb_one_small .gnb_service_li .gnb_service:hover .gnb_icon{background-position:-324px -120px}
#gnb.gnb_one .gnb_my_lyr, #gnb.gnb_one_small .gnb_my_lyr, #gnb.gnb_one .gnb_notice_lyr, #gnb.gnb_one_small .gnb_notice_lyr, #gnb.gnb_one .gnb_service_lyr, #gnb.gnb_one_small .gnb_service_lyr {right: 7px;}
#gnb.gnb_one .gnb_ico_num, #gnb.gnb_one_small .gnb_ico_num{width:34px;top:10px;right:3px;left:auto;vertical-align:top}
#gnb.gnb_one .gnb_ico_num .gnb_ico_new, #gnb.gnb_one_small .gnb_ico_num .gnb_ico_new{vertical-align:top;height:13px;background-position:-332px -60px;}
#gnb.gnb_one .gnb_ico_num .gnb_count, #gnb.gnb_one_small .gnb_ico_num .gnb_count {height: 13px;padding: 0 6px 0 2px;background-position: 100% -60px;font-size: 10px;font-weight: normal;}
#gnb.gnb_one .gnb_ico_num .plus, #gnb.gnb_one_small .gnb_ico_num .plus{margin:1px 0 0 2px}
#gnb.gnb_one .ico_arrow{top:48px}
#gnb.gnb_one .gnb_my_lyr, #gnb.gnb_one .gnb_notice_lyr{top:47px}
#gnb.gnb_one .gnb_service_lyr{top:48px;}
#gnb.gnb_one .gnb_login_li{padding:16px 21px 10px 1px;}
#gnb.gnb_one .gnb_my_li{padding:12px 20px 12px 2px}
#gnb.gnb_one .gnb_my_li .ico_arrow{top:34px}
#gnb.gnb_one .gnb_notice_li a.gnb_notice{padding:18px 19px 17px 19px}
#gnb.gnb_one .mail_li a.gnb_mail{padding:19px 17px 18px 17px}
#gnb.gnb_one .gnb_service_li .gnb_service{padding:19px 19px 18px 19px}
#gnb.gnb_one_small .ico_arrow{top:33px}
#gnb.gnb_one_small .gnb_my_lyr, #gnb.gnb_one_small .gnb_notice_lyr{top:32px}
#gnb.gnb_one_small .gnb_service_lyr{top:33px}
#gnb.gnb_one_small .gnb_login_li{padding:7px 12px 4px 2px}
#gnb.gnb_one_small .gnb_my_li{padding:5px 20px 4px 2px}
#gnb.gnb_one_small .gnb_my_li .ico_arrow{top:27px}
#gnb.gnb_one_small .gnb_notice_li a.gnb_notice{padding:10px 11px 10px 12px}
#gnb.gnb_one_small .mail_li a.gnb_mail{padding:11px 10px 11px 9px}
#gnb.gnb_one_small .gnb_service_li .gnb_service{padding:11px 12px 11px 11px}
#gnb.gnb_one_small .gnb_ico_num{top:5px;right:6px;width:24px}
#gnb.gnb_one_flat .gnb_login_li,
#gnb.gnb_one_flat .gnb_my_li,
#gnb.gnb_one_flat .gnb_notice_li,
#gnb.gnb_one_flat .mail_li,
#gnb.gnb_one_flat .gnb_service_li {border-color: #e0e0e0;}
#gnb.gnb_one_flat .gnb_notice_li.hover,
#gnb.gnb_one_flat .mail_li.hover,
#gnb.gnb_one_flat .gnb_service_li.hover {background-color: rgba(0, 0, 0, 0.04);}
#gnb.gnb_one_flat .gnb_service_li .gnb_service .gnb_icon,
#gnb.gnb_one_flat .gnb_service_li .gnb_service:hover .gnb_icon {background-image: url(https://ssl.pstatic.net/static/common/gnb/one/sp_gnb_4b16e6.png);background-position: -84px -24px;background-repeat: no-repeat; width: 16px;height: 16px;vertical-align: top; margin: 0 1px;}
#gnb.gnb_one_flat .mail_li a.gnb_mail .gnb_icon,
#gnb.gnb_one_flat .mail_li a.gnb_mail:hover .gnb_icon {background-image: url(https://ssl.pstatic.net/static/common/gnb/one/sp_gnb_4b16e6.png);background-position: 0px -42px;background-repeat: no-repeat;width: 20px;height: 16px;vertical-align: top;margin: 0 1px;}
#gnb.gnb_one_flat .gnb_notice_li a.gnb_notice .gnb_icon,
#gnb.gnb_one_flat .gnb_notice_li a.gnb_notice:hover .gnb_icon {background-image: url(https://ssl.pstatic.net/static/common/gnb/one/sp_gnb_4b16e6.png);background-position: -84px 0px;background-repeat: no-repeat;width: 16px;height: 18px;vertical-align: top;margin: 0 1px;}
#gnb.gnb_one_flat .gnb_my_li .gnb_my .gnb_name,
#gnb.gnb_one_flat .gnb_login_li .gnb_btn_login .gnb_txt {color: #666;}
#gnb.gnb_one_pwe .gnb_my .filter_mask {box-sizing: border-box;background: none;border: 1px solid rgba(0,0,0,.1);border-radius: 100%;}
#gnb.gnb_one_pwe .gnb_my_namebox {background-image: url(https://ssl.pstatic.net/static/common/gnb/pwe/ico_arrow_wh.svg) !important;}
#gnb.gnb_one_pwe .gnb_notice_li a.gnb_notice .gnb_icon,
#gnb.gnb_one_pwe .gnb_notice_li a.gnb_notice:hover .gnb_icon {width: 17px;height: 19px;background: url(https://ssl.pstatic.net/static/common/gnb/pwe/gnb_notice.svg) no-repeat;}
#gnb.gnb_one_pwe .gnb_service_li .gnb_service .gnb_icon,
#gnb.gnb_one_pwe .gnb_service_li .gnb_service:hover .gnb_icon {width: 17px;height: 17px;background: url(https://ssl.pstatic.net/static/common/gnb/pwe/gnb_service.svg) no-repeat;}
#gnb.gnb_one_pwe .gnb_ico_num .gnb_ico_new,
#gnb.gnb_one_pwe .gnb_ico_num .gnb_count {background: #e1523a;}
#gnb.gnb_one_pwe .gnb_ico_num .gnb_ico_new {border-radius: 13px 0 0 13px;}
#gnb.gnb_one_pwe .gnb_ico_num .gnb_count {border-radius: 0 13px 13px 0;}</style><script type="text/javascript" src="https://ssl.pstatic.net/tveta/libs/glad/prod/2.4.1/gfp-sdk.js" async="" charset="utf-8"></script><script type="text/javascript" src="https://ssl.pstatic.net/tveta/libs/glad/prod/2.4.1/gfp-ext-nda.js" async="" charset="utf-8"></script><script src="https://ssl.pstatic.net/static.gn/js/clickcrD.js" id="gnb_clickcrD" charset="utf-8"></script></head> 
 <body onload="getGNB();"> 
  <script type="text/javascript">

	var nclk_evt = 3;
	nclk_do();
</script> 
  <script type="text/javascript">







var nsc="finance.home";


var ccsrv="cc.naver.com";


	
	
	var gnb_service='finance';
	


var gnb_logout=document.URL; //GNB에서 로그아웃 후 redirect 될 URL
var gnb_searchbox='off'; //미니 검색창을 on 할지 off 할지. default는 off
var gnb_shortnick='off'; //닉네임 말줄임(10자)을 on할지 off 할지. default는 off.


var gnb_naverme_layer_open_callback = function(){
	   var naverLayerSize = gnbNaverMeLayer.getLayerSize();
		
		var me_layers = document.getElementById("me_layers");
		me_layers.width=naverLayerSize.width;
		me_layers.height=naverLayerSize.height;};

var gnb_naverme_layer_close_callback = function(){
		
			var me_layers = document.getElementById("me_layers");
			me_layers.width="0";
			me_layers.height="0";};
</script> 
  <div id="u_skip"> 
   <a href="#menu" tabindex="1"><span>메인 메뉴로 바로가기</span></a> 
   <a href="#start" tabindex="2"><span>본문으로 바로가기</span></a> 
  </div> 
  <div id="header"> 
   <div class="snb_area"> 
    <div class="snb_inner"> 
     <div id="gnb_area"> 
      <div id="gnb" class="gnb_one"><strong class="blind">사용자 링크</strong><ul class="gnb_lst" id="gnb_lst" style="display: block;"><li class="gnb_login_li" id="gnb_login_layer" style="display: inline-block;"><a class="gnb_btn_login" href="https://nid.naver.com/nidlogin.login" id="gnb_login_button"><span class="gnb_bg"></span><span class="gnb_bdr"></span><span class="gnb_txt">로그인</span></a></li><li class="gnb_my_li" id="gnb_my_layer" style="display:none"><div class="gnb_my_namebox" id="gnb_my_namebox" style="background-image: url(&quot;https://ssl.pstatic.net/static/common/gnb/2014/ico_arrow_wh.gif&quot;);"><a href="javascript:;" class="gnb_my" onclick="gnbUserLayer.clickToggle(); return false;"><img id="gnb_profile_img" src="data:image/gif;base64,R0lGODlhAQABAAD/ACwAAAAAAQABAAACADs%3D" onerror="this.src='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAFAAAABQCAMAAAC5zwKfAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAADNQTFRF8PDw5ubm+vr6+/v76enp+Pj47e3t5+fn9/f37Ozs9PT08vLy7+/v6urq9fX15OTk/f39pqwodgAAAQNJREFUeNrs11EOgyAMgOEWUAF19f6n3cMeplJHoSZbsv4H+DIWaCNsNwcGGmiggQZ+D/Q5reuasr8H9ID0CsHfALpA74JTgwPSPnRK0Ac6FrwOXOjcogIdlTkNuDDgogGRAVEBDsQ19IMzC879ILAgGNgAZhbMP3RttonxJs1Lgea/sDYcyreHXjW+oPUHVid2MWC1K+A0sqsDW7CksGmlCNZoFt9pIfjYgY8bwMMexUENQuOtqYCxfHtT7AddYodDcp0gIPEh9IBxous+nBuaTis4Nw/OSLVwloN+JEmjGJR5FyIDRpIWZeAoBkcZGMRgkIEkz0D7GjXQQAMN/GvwKcAAEGGHJh0mmaAAAAAASUVORK5CYII='" width="26" height="26" alt="내 프로필 이미지"><span id="gnb_profile_filter_mask" class="filter_mask"></span> <span class="gnb_name" id="gnb_name1"></span><em class="blind">내정보 보기</em><span class="ico_arrow"></span></a><a href="#" class="gnb_emp" id="gnb_emp">(임직원혜택)</a></div><div class="gnb_my_lyr" id="gnb_my_lyr"><div class="gnb_my_content"><div class="gnb_img_area"><span class="gnb_mask"></span><img src="data:image/gif;base64,R0lGODlhAQABAAD/ACwAAAAAAQABAAACADs%3D" onerror="this.src='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAFAAAABQCAMAAAC5zwKfAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAADNQTFRF8PDw5ubm+vr6+/v76enp+Pj47e3t5+fn9/f37Ozs9PT08vLy7+/v6urq9fX15OTk/f39pqwodgAAAQNJREFUeNrs11EOgyAMgOEWUAF19f6n3cMeplJHoSZbsv4H+DIWaCNsNwcGGmiggQZ+D/Q5reuasr8H9ID0CsHfALpA74JTgwPSPnRK0Ac6FrwOXOjcogIdlTkNuDDgogGRAVEBDsQ19IMzC879ILAgGNgAZhbMP3RttonxJs1Lgea/sDYcyreHXjW+oPUHVid2MWC1K+A0sqsDW7CksGmlCNZoFt9pIfjYgY8bwMMexUENQuOtqYCxfHtT7AddYodDcp0gIPEh9IBxous+nBuaTis4Nw/OSLVwloN+JEmjGJR5FyIDRpIWZeAoBkcZGMRgkIEkz0D7GjXQQAMN/GvwKcAAEGGHJh0mmaAAAAAASUVORK5CYII='" width="80" height="80" alt="프로필 이미지"><a href="https://nid.naver.com/user2/api/naverProfile?m=checkIdType" class="gnb_change"><span class="blind">프로필 사진 변경</span></a></div><div class="gnb_txt_area"><p class="gnb_account"><span class="gnb_name" id="gnb_name2"><a class="gnb_nick" href="https://nid.naver.com/user2/api/naverProfile?m=checkIdType">_</a>님</span><a class="gnb_btn_login" href="https://nid.naver.com/nidlogin.logout?returl=https%3A%2F%2Ffinance.naver.com%2F" id="gnb_logout_button"><span class="gnb_bg"></span><span class="gnb_bdr"></span><span class="gnb_txt">로그아웃</span></a></p><a href="https://mail.naver.com" class="gnb_mail_address">@naver.com</a><ul class="gnb_edit_lst"><li class="gnb_info"><a href="https://nid.naver.com/user2/help/myInfo?menu=home">네이버ID</a></li><li class="gnb_secure" id="gnb_secure_lnk"><a href="https://nid.naver.com/user2/help/myInfo?m=viewSecurity&amp;menu=security">보안설정</a></li><li class="gnb_cert" id="gnb_cert_lnk"><a href="https://nid.naver.com/user2/eSign/v1/home/land">내인증서</a></li></ul><div class="gnb_pay_check" id="gnb_pay_check"><p class="gnb_membership" style="display: none;" id="gnb_membership"><a href="https://nid.naver.com/membership/my" class="gnb_my_membership"><i class="blind">네이버 멤버쉽</i></a></p><em>N Pay</em><a href="https://pay.naver.com" id="gnb_pay_point"><span style="display: none">내 페이포인트</span></a></div></div></div><div class="gnb_my_community"><a href="https://blog.naver.com/MyBlog.naver" class="gnb_blog">내 블로그</a><a href="https://section.cafe.naver.com" class="gnb_cafe">가입한 카페</a><a href="https://pay.naver.com" class="gnb_pay"><span>N Pay</span></a></div><a href="#" class="gnb_my_interface" style="display:none"><span class="blind">환경설정</span></a></div><iframe id="gnb_my_lyr_iframe" title="빈 프레임" class="gnb_pad_lyr" name="padding" width="0" height="0" scrolling="no" frameborder="0" style="top: 55px; right: 10px; width: 320px; height: 158px; display: none; opacity: 0;"></iframe></li><li class="gnb_notice_li" id="gnb_notice_layer" style="display:none"><a href="javascript:;" class="gnb_notice" onclick="gnbNaverMeLayer.clickToggle(); return false;"><span class="blind">알림</span><span class="gnb_icon"></span><em class="gnb_ico_num" id="gnb_me_menu" style="display:none"><span class="gnb_ico_new"><span class="gnb_count" id="gnb_me_count"></span></span></em><span class="ico_arrow"></span></a><div class="gnb_notice_lyr" id="gnb_notice_lyr"><div class="svc_noti svc_panel"><div class="svc_scroll"><div class="svc_head"><strong class="gnb_tit">전체 알림</strong><div class="task_right"><button onclick="gnbNaverMeLayer.deleteReadList(this, event);" id="gnb_btn_read_noti_del">읽은 알림 삭제</button><button onclick="gnbNaverMeLayer.showDeleteAlert();" id="gnb_btn_all_noti_del">모두 삭제</button></div></div><div class="svc_body" id="gnb_naverme_layer"></div></div><div class="gnb_ly_alert" id="gnb_ly_alert" style="display: none;"><p class="gnb_msg"><strong>알림을 모두 삭제하시겠습니까?</strong></p><div class="gnb_btns"><button id="ly_alert_confirm" onclick="gnbNaverMeLayer.deleteAllList(this, event);">확인</button><button onclick="gnbNaverMeLayer.hideDeleteAlert();">취소</button></div><button class="gnb_btn_close" onclick="gnbNaverMeLayer.hideDeleteAlert();"><i>레이어 닫기</i></button></div><a href="https://noti.naver.com/index.nhn" class="gnb_notice_all">내 알림 전체보기</a></div></div><iframe id="gnb_notice_lyr_iframe" title="빈 프레임" class="gnb_pad_lyr" name="padding" width="0" height="0" scrolling="no" frameborder="0" style="top: 55px; right: 10px; width: 299px; height: 332px; display: none; opacity: 0;"></iframe></li><li class="mail_li" id="gnb_mail_layer" style="display:none"><a href="https://mail.naver.com" class="gnb_mail"><span class="blind">메일</span><span class="gnb_icon"></span><em class="gnb_ico_num" id="gnb_mail_menu" style="display:none"><span class="gnb_ico_new"><span class="gnb_count" id="gnb_mail_count"></span></span></em></a></li><li class="gnb_service_li" id="gnb_service_layer" style="display: inline-block;"><a href="javascript:;" class="gnb_service" onclick="gnbMoreLayer.clickToggle(); return false;"><span class="blind">서비스 더보기</span><span class="gnb_icon"></span><span class="ico_arrow"></span></a><div class="gnb_service_lyr" id="gnb_service_lyr"><div class="gnb_favorite_search" id="gnb_favorite_search"><div class="gnb_favorite_area"><div class="gnb_favorite_lstwrp"><div class="gnb_first_visit" style="display:none"><span class="blind">나만의 즐겨찾기를 추가해 보세요!</span><a href="#" class="gnb_close"><span class="blind">닫기</span></a></div><strong class="blind">즐겨찾는 서비스</strong><ul class="gnb_favorite_lst" id="gnb_favorite_lst"><li class="gnb_add"><a href="#"><span class="ic_add"></span>추가</a></li><li class="gnb_add"><a href="#"><span class="ic_add"></span>추가</a></li><li class="gnb_add"><a href="#"><span class="ic_add"></span>추가</a></li><li class="gnb_add"><a href="#"><span class="ic_add"></span>추가</a></li></ul><a href="#" class="gnb_my_interface" onclick="gnbMoreLayer.clickToggleWhole(); return false;"><span class="blind">즐겨찾기 설정</span></a></div></div><div class="gnb_search_area"><div class="gnb_search_box" onmouseover="gnb_search.mouseOver(this);" onmouseout="gnb_search.mouseOut(this);"><input id="gnb_svc_search_input" type="text" title="서비스 검색" value="더 많은 서비스를 간편하게 시작하세요!" onfocus="gnb_search.clearInput(this);" onblur="gnb_search.resetInput(this);" onkeydown="gnb_search.keyDown(event);" onkeyup="gnb_search.keyUp(event);"><a href="#" class="gnb_del_txt" id="gnb_del_txt" style="display:none"><span class="blind">삭제</span></a><div class="gnb_pop_input" id="gnb_pop_input" tabindex="0" onfocus="gnb_search.searchPopOnMouse = true; return false;" onfocusout="gnb_search.searchPopOnMouse = false; return false;" onmouseover="gnb_search.searchPopOnMouse = true; return false;" onmouseout="gnb_search.searchPopOnMouse = false; return false;" style="display:none"><ul class="gnb_pop_lst"></ul></div></div><div id="gnb_search_lstwrp" class="gnb_search_lstwrp"><ul class="gnb_search_lst gnb_first"><li class="gnb_first"><a id="gnb_search_lst_first_item" href="https://cafe.naver.com/">카페</a></li><li><a href="https://news.naver.com/">뉴스</a></li><li><a href="https://map.naver.com/">지도</a></li><li><a href="https://sports.news.naver.com/">스포츠</a></li><li><a href="https://game.naver.com/">게임</a></li></ul><ul class="gnb_search_lst"><li class="gnb_first"><a href="https://section.blog.naver.com/">블로그</a></li><li><a href="https://post.naver.com/main.nhn">포스트</a></li><li><a href="https://dict.naver.com/">사전</a></li><li><a href="https://kin.naver.com/">지식iN</a></li><li><a href="https://weather.naver.com/">날씨</a></li></ul><ul class="gnb_search_lst"><li class="gnb_first"><a href="https://mail.naver.com/">메일</a></li><li><a href="https://stock.naver.com/">증권</a></li><li><a href="https://land.naver.com/">부동산</a></li><li><a href="https://vibe.naver.com/today/">VIBE</a></li><li><a href="https://book.naver.com">책</a></li></ul><ul class="gnb_search_lst"><li class="gnb_first"><a href="https://shopping.naver.com/">쇼핑</a></li><li><a href="https://comic.naver.com/">웹툰</a></li><li><a href="https://movie.naver.com/">영화</a></li><li><a href="https://mybox.naver.com/">MYBOX</a></li><li><a href="https://novel.naver.com/webnovel/weekday">웹소설</a></li></ul></div></div><div class="gnb_banner"><a href="https://campaign.naver.com/npay/rediret/index.nhn" class="gnb_service_event"><img id="gnb_promo" alt="N페이, 이벤트 참여하면 포인트 적립!" width="265" height="47" src="https://ssl.pstatic.net/static/common/gnb/banner/promo_npay_200108.png"></a></div><div class="gnb_linkwrp"><a href="https://www.naver.com/more.html" class="gnb_service_all" id="gnb_service_all">전체 서비스 보기</a></div></div><div class="gnb_svc_more" id="gnb_svc_more" style=""><strong class="blind">네이버 주요 서비스</strong><div class="gnb_bg_top"></div><div class="gnb_svc_hd" id="gnb_svc_hd" tabindex="0"><strong class="gnb_svc_tit">바로가기 설정</strong><span class="link"><a href="https://www.naver.com/more.html">전체 서비스 보기</a></span></div><div class="gnb_svc_lstwrp"><div class="gnb_svc_lst1"><ul class="gnb_first"><li><input type="checkbox" id="nsvc_game" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_game">게임</label></li><li><input type="checkbox" id="nsvc_weather" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_weather">날씨</label></li><li><input type="checkbox" id="nsvc_shopping" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_shopping">네이버쇼핑</label></li><li><input type="checkbox" id="nsvc_navercast" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_navercast">네이버캐스트</label></li><li class="gnb_event"><input type="checkbox" id="nsvc_naverpay" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_naverpay">네이버페이<em class="ic_gnb_new">New</em></label></li><li><input type="checkbox" id="nsvc_mybox" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_mybox">네이버 MYBOX</label></li><li><input type="checkbox" id="nsvc_news" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_news">뉴스</label></li><li><input type="checkbox" id="nsvc_comic" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_comic">웹툰</label></li><li><input type="checkbox" id="nsvc_memo" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_memo">메모</label></li><li><input type="checkbox" id="nsvc_mail" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_mail">메일</label></li><li><input type="checkbox" id="nsvc_land" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_land">부동산</label></li><li><input type="checkbox" id="nsvc_bookmark" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_bookmark">북마크</label></li><li><input type="checkbox" id="nsvc_blog" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_blog">블로그</label></li></ul><ul class=""><li><input type="checkbox" id="nsvc_dic" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_dic">사전</label></li><li><input type="checkbox" id="nsvc_smartboard" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_smartboard">스마트보드</label></li><li><input type="checkbox" id="nsvc_sports" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_sports">스포츠</label></li><li><input type="checkbox" id="nsvc_series" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_series">시리즈</label></li><li><input type="checkbox" id="nsvc_serieson" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_serieson">시리즈on</label></li><li><input type="checkbox" id="nsvc_movie" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_movie">영화</label></li><li><input type="checkbox" id="nsvc_office" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_office">오피스</label></li><li><input type="checkbox" id="nsvc_novel" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_novel">웹소설</label></li><li><input type="checkbox" id="nsvc_contact" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_contact">주소록</label></li><li><input type="checkbox" id="nsvc_finance" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_finance">증권(금융)</label></li><li><input type="checkbox" id="nsvc_map" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_map">지도</label></li><li><input type="checkbox" id="nsvc_kin" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_kin">지식iN</label></li><li><input type="checkbox" id="nsvc_terms" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_terms">지식백과</label></li></ul><ul class=""><li><input type="checkbox" id="nsvc_book" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_book">책</label></li><li><input type="checkbox" id="nsvc_cafe" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_cafe">카페</label></li><li><input type="checkbox" id="nsvc_calendar" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_calendar">캘린더</label></li><li><input type="checkbox" id="nsvc_navertv" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_navertv">네이버TV</label></li></ul></div><div class="svc_lst2"><div class="svc_spc gnb_first"><strong><a href="https://dict.naver.com/">어학사전</a></strong><ul class=""><li><input type="checkbox" id="nsvc_krdic" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_krdic">국어사전</label></li><li><input type="checkbox" id="nsvc_endic" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_endic">영어/영영사전</label></li><li><input type="checkbox" id="nsvc_hanja" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_hanja">한자사전</label></li><li><input type="checkbox" id="nsvc_jpdic" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_jpdic">일어사전</label></li><li><input type="checkbox" id="nsvc_cndic" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_cndic">중국어사전</label></li><li><input type="checkbox" id="nsvc_frdic" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_frdic">프랑스어사전</label></li><li><input type="checkbox" id="nsvc_dedic" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_dedic">독일어사전</label></li><li><input type="checkbox" id="nsvc_rudic" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_rudic">러시아어사전</label></li><li><input type="checkbox" id="nsvc_vndic" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_vndic">베트남어사전</label></li><li><input type="checkbox" id="nsvc_spdic" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_spdic">스페인어사전</label></li><li><input type="checkbox" id="nsvc_papago" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_papago">파파고</label></li></ul></div><div class="svc_spc"><strong>인기/신규서비스</strong><ul class=""><li><input type="checkbox" id="nsvc_grafolio" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_grafolio">그라폴리오</label></li><li><input type="checkbox" id="nsvc_post" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_post">포스트</label></li><li><input type="checkbox" id="nsvc_band" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_band">밴드</label></li><li><input type="checkbox" id="nsvc_line" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_line">라인</label></li><li class="gnb_event"><input type="checkbox" id="nsvc_vibe" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_vibe">VIBE<em class="ic_gnb_new">New</em></label></li><li><input type="checkbox" id="nsvc_pcontents" name="selmenu" class="gnb_input_check" value=""> <label for="nsvc_pcontents">프리미엄콘텐츠</label></li></ul></div></div></div><div class="svc_btnwrp"><div class="svc_btns"><button class="gnb_save" onclick="if(gnbFavorite.addService()){gnbMoreLayer.clickToggleWhole()} return false;"><strong class="blind">확인</strong></button><button class="gnb_close" onclick="gnbFavorite.cancel(); return false;"><span class="blind">취소</span></button><button class="gnb_return" onclick="gnbFavorite.resetService(); return false;"><span class="blind">초기 설정으로 변경</span></button></div></div><div class="gnb_bg_btm"></div></div></div><iframe id="gnb_service_lyr_iframe" title="빈 프레임" class="gnb_pad_lyr" name="padding" width="0" height="0" scrolling="no" frameborder="0" style="display: none; top: 55px; right: 311px; width: 585px; height: 385px; opacity: 0;"></iframe><iframe id="gnb_svc_more_iframe" title="빈 프레임" class="gnb_pad_lyr" name="padding" width="0" height="0" scrolling="no" frameborder="0" style="display: none; top: 55px; right: 10px; width: 295px; height: 385px; opacity: 0;"></iframe></li></ul> 
      </div> 
     </div> 
     <div class="sta"> 
      <h1 class="logo"> <a href="https://www.naver.com/" class="logo_naver" onclick="clickcr(this, 'STA.naver', '', '', event);"><span class="blind">네이버</span></a> <a href="/" class="logo_service" onclick="clickcr(this, 'STA.finance', '', '', event);"><span class="blind">금융</span></a> </h1> 
      <form name="search" action="/search/search.naver" method="get" onsubmit="return delayed_submit(this)" style="margin:0; padding:0;"> 
       <fieldset> 
        <legend>검색</legend> 
        <div class="snb_search_box"> 
         <div class="snb_search_box_sub"> 
          <input id="stock_items" type="text" title="검색" name="query" value="종목명·지수명 입력" accesskey="s" class="snb_search_text snb_default" autocomplete="off"> 
          <a id="nautocomplete" href="#" onclick="return false" class="btn_arrow"><span class="blind">자동완성 펼치기</span></a> 
         </div> 
         <div class="auto_area"> 
          <h2 class="blind">자동완성</h2> 
          <div id="autoFrame" style="display: none;"> 
           <div class="wrap" id="atcmp" style="display:none;"> 
            <div class="wrap_in"> 
             <div class="words"> 
              <ul class="_resultBox"> 
               <li> <a href="#" onclick="clickcr(this, 'AUT.list', '', '', event); return false;" class="_au_real_list"> <span class="num _au_real_list">@code@</span> <span class="_au_real_list">@txt@</span> <span class="type _au_real_list">@market@</span> </a> 
                <div style="display:none" class="_au_full">
                 @full_txt@
                </div> 
                <div style="display:none" class="_au_code">
                 @in_code@
                </div> 
                <div style="display:none" class="_au_name">
                 @in_name@
                </div> 
                <div style="display:none" class="_au_link">
                 @in_link@
                </div> 
                <div style="display:none" class="_au_market">
                 @in_market@
                </div> </li> 
              </ul> 
             </div> 
             <p class="func"> <span><a href="#" class="fire_event funoff" onclick="clickcr(this, 'AUT.x', '', '', event); smartSearch.unuse(); return false;">기능끄기</a></span> </p> 
            </div> 
           </div> 
           <!-- 현재 자동완성 기능을 사용하고 계십니다 --> 
           <div class="wrap" id="atcmpIng" style="display:none;"> 
            <div class="wrap_in"> 
             <div class="words"> 
              <p class="msg"> 현재 자동완성 기능을 사용하고 계십니다. </p> 
             </div> 
             <p class="func"> <span><a href="#" class="fire_event funoff" onclick="clickcr(this, 'AUT.x', '', '', event); smartSearch.unuse(); return false;">기능끄기</a></span> </p> 
            </div> 
           </div> 
           <!--// 현재 자동완성 기능을 사용하고 계십니다 --> 
           <!-- 자동완성 기능이 활성화 --> 
           <div class="wrap" id="atcmpStart" style="display:none;"> 
            <div class="wrap_in"> 
             <div class="words"> 
              <p class="msg"> 자동완성 기능이 활성화되었습니다. </p> 
             </div> 
             <p class="func"> <span><a href="#" class="fire_event funoff" onclick="clickcr(this, 'AUT.x', '', '', event); smartSearch.unuse(); return false;">기능끄기</a></span> </p> 
            </div> 
           </div> 
          </div> 
         </div> 
         <button type="submit" class="snb_search_btn" onclick="clickcr(this, 'STA.search', '', '', event);" alt="검색"><span class="blind">검색</span></button> 
         <a href="#" target="_blank" class="snb_search_btn-total" onclick="itegrationSearch();clickcr(this, 'STA.nx', '', '', event);return false;">통합검색</a> 
        </div> 
       </fieldset> 
      </form> 
     </div> 
    </div> 
   </div> 
   <div class="lnb_area "> 
    <div class="lnb_inner"> 
     <div id="menu"> 
      <ul class="menu"> 
       <li class="m1 first on"><a href="/" onclick="clickcr(this, 'LNB.home', '', '', event);"><span class="tx">금융 홈</span></a></li> 
       <li class="m2 "><a href="/sise/" onclick="clickcr(this, 'LNB.sise', '', '', event);"><span class="tx">국내증시</span></a></li> 
       <li class="m3 "><a href="/world/" onclick="clickcr(this, 'LNB.world', '', '', event);"><span class="tx">해외증시</span></a></li> 
       <li class="m4 "><a href="/marketindex/" onclick="clickcr(this, 'LNB.market', '', '', event);"><span class="tx">시장지표</span></a></li> 
       <li class="m6 "><a href="/research/" onclick="clickcr(this, 'LNB.research', '', '', event);"><span class="tx">리서치</span></a></li> 
       <li class="m7 "><a href="/news/"><span class="tx">뉴스</span></a></li> 
       <li class="m8 "><a href="/mystock/" onclick="clickcr(this, 'LNB.mystock', '', '', event);"><span class="tx">MY</span></a></li> 
      </ul> 
     </div> 
    </div> 
   </div> 
   <script type="text/JavaScript">
		/* lcs 집계 */
        ;(function(){
            var eventType = "onpageshow" in window ? "pageshow" : "load";
            jindo.$Fn(function(){
                lcs_do();
            }).attach(window, eventType);
        })();

		/* 검색 자동완성 [ 인자1 : 검색input의 ID, 인자2 : iframe 태그 ID ]   */
		// AutoComplete 생성
		var acDomain = "ac.finance.naver.com";
        if (location.hostname.indexOf("staging-") > -1) {
            acDomain = "staging-" + acDomain;
        } else if (location.hostname.indexOf("dev-") > -1 || location.hostname.indexOf("localhost") > -1 || location.hostname.indexOf("local-") > -1) {
			acDomain = "dev-" + acDomain;
		}

        var acUrl = "https://" + acDomain + "/ac";

		smartSearch = new nhn.Autocomplete(
			// InputManager 생성
			new nhn.AcInputManager(jindo.$("stock_items")),
			// DataManager 생성
			new nhn.AcDataManager(acUrl, "jsonp", "get", {
                    st: "111",
                    r_lt : "111",
                    q_enc : "euc-kr",
                    r_enc : "euc-kr",
                    frm: "stock"}),
			// ViewManager 생성
			new nhn.AcStockViewManager(jindo.$("autoFrame"), jindo.$("nautocomplete"), {
                                        strMax: 200,
                                        listMax: [7, 2, 2],
                                        aRedirectUrl : [
                            			"https://finance.naver.com",
                            			"https://finance.naver.com",
                            			"https://finance.naver.com"]}),
			// Autocomplete Option
            {formId:"search", cookieDomain:location.hostname, cookieName:"NaverCommonStock"});

			smartSearch.attach({
	            onFocus: function () {
	                var weInput = jindo.$Element('stock_items');
	                if (weInput && weInput.hasClass("snb_default")) {
	                        weInput.text("");
	                        weInput.removeClass('snb_default');
	                }
	            }
	        });

		/* 통합검색  start ----->  */
		//document.domain = 'naver.com';
		var sSearchHintText = '종목명·지수명·환율명·원자재명 입력';
		function itegrationSearch() {
			var query = jindo.$('stock_items').value;

			if ( query == ''  || encodeURIComponent(query) == encodeURIComponent(sSearchHintText))
			{
				alert ( '검색어를 입력해 주세요.' );
				return;
			}

            var url = location.protocol + "//search.naver.com/search.naver?sm=sta_hty.finance&where=nexearch&ie=UTF8&query=" + encodeURIComponent(query);
            window.open(url, "_blank");

			return false;
		}

		function delayed_submit(object) {
			if (navigator.userAgent.indexOf('MSIE') == -1) {
				window.setTimeout(function() {stock_search(object)}, 300);
			} else {
				stock_search(object);
			}
			return false;
		}

		function stock_search (object)
		{
			query = object.query.value.replace(/^\s*/,'').replace(/\s*$/,'');	// trim
			object.query.value=query;

			if ( query == '' || query == sSearchHintText.replace(/^\s*/,'').replace(/\s*$/,''))
			{
				alert ( '검색어를 입력해 주세요.' );
				return;
			}
			else {
				object.submit();
			}
		}
		/* <---------- 통합검색  end */

		function popup()
		{
			win = window.open('/template/group_limit_pop.jsp','finan_popup','width=569 height=278 scrollbars=no status=no');
			win.focus();
		}
	</script> 
   <iframe id="me_layers" name="test" title="네이버미 영역" width="0" height="0" scrolling="no" frameborder="0" style="display:block;top: 22px; right: 209px; position: absolute; z-index: 15;"></iframe> 
  </div> 
  <div id="wrap"> 
   <hr> 
   <div id="start" class="blind">
    <strong name="start">본문시작</strong>
   </div> 
   <dl class="blind"> 
    <dt>
     오늘의 코스피/코스닥 지수
    </dt> 
    <dd>
     2022년 10월 21일 장마감
    </dd> 
    <dd>
     코스피 지수 2,213.12 전일대비 하락 4.97 마이너스 0.22 퍼센트
    </dd> 
    <dd>
     코스닥 지수 674.48 전일대비 하락 5.96 마이너스 0.88 퍼센트
    </dd> 
   </dl> 
   <div class="home_spot view_off"> 
    <div class="bx_spot"> 
     <div class="tab_spot tab1" id="tab_search"> 
      <ul> 
       <li><a href="#" onclick="javascript:showMainRecentMyStockSearchStock('tab_search', 'tab_spot tab1', '000000', 'recent');clickcr(this, 'mys.recent', '', '', event);return false;"><span>최근조회종목</span></a></li> 
       <li><a href="#" onclick="javascript:showMainRecentMyStockSearchStock('tab_search', 'tab_spot tab2', '000000', 'mystock');clickcr(this, 'mys.interest', '', '', event);return false;"><span>MY STOCK</span></a></li> 
      </ul> 
     </div> 
     <div class="section_tab" id="recent_search_tab"> 
      <strong class="blind" id="recent_mystock_blind">최근 조회종목 리스트</strong> 
      <ul class="tab_list"><li class="first"><div class="nodata"><p class="search">최근조회 종목이 없습니다.</p></div></li></ul> 
     </div> 
     <input type="image" src="https://ssl.pstatic.net/static/nfinance/btn_spot_close.gif" class="btn_spot" alt="닫기" onclick="clickcr(this, (jindo.$Element('tab_search').hasClass('tab1') ? 'mys*r.close' : 'mys*i.close'), '', '', event);" style="display:none"> 
     <input type="image" src="https://ssl.pstatic.net/static/nfinance/btn_spot_open.gif" class="btn_spot" alt="펼치기" onclick="clickcr(this, (jindo.$Element('tab_search').hasClass('tab1') ? 'mys*r.open' : 'mys*i.open'), '', '', event);" style="display:none"> 
    </div> 
   </div> 
   <div id="container" class="home"> 
    <div id="content"> 
     <div class="article"> 
      <div class="section"> 
       <div class="news_area"> 
        <div class="section_strategy"> 
         <h2 class="h_strategy"><span>주요뉴스</span></h2> 
         <ul> 
          <li> <span><a href="/news/news_read.naver?mode=mainnews&amp;office_id=366&amp;article_id=0000849197" onclick="clickcr(this, 'tdn.list', '366_0000849197', '0', event);">[마켓뷰] 치솟는 채권 금리·강달러에 코스피·코스닥 3거래일 연속 하락</a></span> </li> 
          <li> <span><a href="/news/news_read.naver?mode=mainnews&amp;office_id=003&amp;article_id=0011490049" onclick="clickcr(this, 'tdn.list', '003_0011490049', '1', event);">[마감시황]코스피, 美 국채금리 상승에 하락…2210선 유지</a></span> </li> 
          <li> <span><a href="/news/news_read.naver?mode=mainnews&amp;office_id=277&amp;article_id=0005165288" onclick="clickcr(this, 'tdn.list', '277_0005165288', '2', event);">[유럽개장] 장 초반 하락세…유로스톡스 1%대↓</a></span> </li> 
          <li> <span><a href="/news/news_read.naver?mode=mainnews&amp;office_id=008&amp;article_id=0004808636" onclick="clickcr(this, 'tdn.list', '008_0004808636', '3', event);">'당대회 폐막 D-1' 中상하이, 나홀로 0.13% 상승 [Asia마감]</a></span> </li> 
          <li> <span><a href="/news/news_read.naver?mode=mainnews&amp;office_id=421&amp;article_id=0006408600" onclick="clickcr(this, 'tdn.list', '421_0006408600', '4', event);">[시황종합] 코스피, 美 국채금리 상승과 강달러 여파에 하락 마감</a></span> </li> 
          <li> <span><a href="/news/news_read.naver?mode=mainnews&amp;office_id=018&amp;article_id=0005346751" onclick="clickcr(this, 'tdn.list', '018_0005346751', '5', event);">[코스닥 마감]5거래일만에 680선 붕괴…신라젠 급락</a></span> </li> 
         </ul> 
         <a href="/news/mainnews.naver" class="btn_more" onclick="clickcr(this, 'tdn.more', '', '', event);"><em class="btn_more4"><span class="blind">주요뉴스 더보기</span></em></a> 
        </div> 
       </div> 
       <div class="section_sise_top"> 
        <h2 class="h_type"><span>TOP 종목</span></h2> 
        <ul class="tab_area sise_top1"> 
         <li class="tab1"><a href="#" onclick="clickcr(this, 'spe.sale', '', '', event);return false;" class="is_active"><span>거래상위</span></a></li> 
         <li class="tab2"><a href="#" onclick="clickcr(this, 'spe.ceiling', '', '', event);return false;"><span>상승</span></a></li> 
         <li class="tab3"><a href="#" onclick="clickcr(this, 'spe.bottom', '', '', event);return false;"><span>하락</span></a></li> 
         <li class="tab4"><a href="#" onclick="clickcr(this, 'spe.value', '', '', event);return false;"><span>시가총액 상위</span></a></li> 
        </ul> 
        <div class="group_type is_active"> 
         <table class="tbl_home"> 
          <caption>
           거래상위 TOP 종목
           <span>종목명에 대한 현재가, 전일대비, 등락률로 구분되어 있습니다.</span>
          </caption> 
          <colgroup> 
           <col width="40%"> 
           <col> 
          </colgroup> 
          <thead> 
           <tr> 
            <th scope="col">종목명</th> 
            <th scope="col">현재가</th> 
            <th scope="col">전일대비</th> 
            <th scope="col">등락률</th> 
           </tr> 
          </thead> 
          <tbody id="_topItems1"> 
           <tr class="up"><th><a href="/item/main.naver?code=096300" onclick="clickcr(this, &quot;spe.slist&quot;, &quot;096300&quot;, &quot;1&quot;, event);">베트남개발1</a></th><td>310</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 13</td><td>+4.38%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=252670" onclick="clickcr(this, &quot;spe.slist&quot;, &quot;252670&quot;, &quot;2&quot;, event);">KODEX 200선물인버스2X</a></th><td>3,665</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 10</td><td>-0.27%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=159910" onclick="clickcr(this, &quot;spe.slist&quot;, &quot;159910&quot;, &quot;3&quot;, event);">스킨앤스킨</a></th><td>270</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 1</td><td>+0.37%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=251340" onclick="clickcr(this, &quot;spe.slist&quot;, &quot;251340&quot;, &quot;4&quot;, event);">KODEX 코스닥150선물인버스</a></th><td>5,680</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 10</td><td>+0.18%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=900070" onclick="clickcr(this, &quot;spe.slist&quot;, &quot;900070&quot;, &quot;5&quot;, event);">글로벌에스엠</a></th><td>1,030</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 160</td><td>+18.39%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=002630" onclick="clickcr(this, &quot;spe.slist&quot;, &quot;002630&quot;, &quot;6&quot;, event);">오리엔트바이오</a></th><td>675</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 59</td><td>+9.58%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=233740" onclick="clickcr(this, &quot;spe.slist&quot;, &quot;233740&quot;, &quot;7&quot;, event);">KODEX 코스닥150레버리지</a></th><td>6,180</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 30</td><td>-0.48%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=089140" onclick="clickcr(this, &quot;spe.slist&quot;, &quot;089140&quot;, &quot;8&quot;, event);">넥스턴바이오</a></th><td>2,850</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 35</td><td>+1.24%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=013720" onclick="clickcr(this, &quot;spe.slist&quot;, &quot;013720&quot;, &quot;9&quot;, event);">CBI</a></th><td>374</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 21</td><td>+5.95%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=122630" onclick="clickcr(this, &quot;spe.slist&quot;, &quot;122630&quot;, &quot;10&quot;, event);">KODEX 레버리지</a></th><td>12,385</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 50</td><td>+0.41%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=074610" onclick="clickcr(this, &quot;spe.slist&quot;, &quot;074610&quot;, &quot;11&quot;, event);">이엔플러스</a></th><td>5,030</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 110</td><td>+2.24%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=114800" onclick="clickcr(this, &quot;spe.slist&quot;, &quot;114800&quot;, &quot;12&quot;, event);">KODEX 인버스</a></th><td>5,310</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 5</td><td>-0.09%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=001470" onclick="clickcr(this, &quot;spe.slist&quot;, &quot;001470&quot;, &quot;13&quot;, event);">삼부토건</a></th><td>1,500</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 100</td><td>+7.14%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=388050" onclick="clickcr(this, &quot;spe.slist&quot;, &quot;388050&quot;, &quot;14&quot;, event);">지투파워</a></th><td>7,970</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 420</td><td>+5.56%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=378800" onclick="clickcr(this, &quot;spe.slist&quot;, &quot;378800&quot;, &quot;15&quot;, event);">샤페론</a></th><td>9,290</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 2,140</td><td>+29.93%</td></tr> 
          </tbody> 
         </table> 
         <a href="/sise/sise_quant.naver" class="btn_more" onclick="clickcr(this, 'spe.more', '', '', event);"><em class="btn_more4"><span class="blind">거래상위 더보기</span></em></a> 
        </div> 
        <div class="group_type"> 
         <table class="tbl_home"> 
          <caption>
           상승 TOP 종목
           <span>종목명에 대한 현재가, 전일대비, 등락률로 구분되어 있습니다.</span>
          </caption> 
          <colgroup> 
           <col width="40%"> 
           <col> 
          </colgroup> 
          <thead> 
           <tr> 
            <th scope="col">종목명</th> 
            <th scope="col">현재가</th> 
            <th scope="col">전일대비</th> 
            <th scope="col">등락률</th> 
           </tr> 
          </thead> 
          <tbody id="_topItems2"> 
           <tr class="up"><th><a href="/item/main.naver?code=014970" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;014970&quot;, &quot;1&quot;, event);">삼륭물산</a></th><td>6,090</td><td><em class="bu_p bu_pup2"><span class="blind">상한가</span></em> 1,405</td><td>+29.99%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=012320" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;012320&quot;, &quot;2&quot;, event);">경동인베스트</a></th><td>48,800</td><td><em class="bu_p bu_pup2"><span class="blind">상한가</span></em> 11,250</td><td>+29.96%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=378800" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;378800&quot;, &quot;3&quot;, event);">샤페론</a></th><td>9,290</td><td><em class="bu_p bu_pup2"><span class="blind">상한가</span></em> 2,140</td><td>+29.93%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=273060" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;273060&quot;, &quot;4&quot;, event);">와이즈버즈</a></th><td>1,415</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 245</td><td>+20.94%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=000995" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;000995&quot;, &quot;5&quot;, event);">DB하이텍1우</a></th><td>87,900</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 14,600</td><td>+19.92%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=037230" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;037230&quot;, &quot;6&quot;, event);">한국팩키지</a></th><td>2,700</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 435</td><td>+19.21%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=376180" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;376180&quot;, &quot;7&quot;, event);">피코그램</a></th><td>40,750</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 6,550</td><td>+19.15%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=900070" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;900070&quot;, &quot;8&quot;, event);">글로벌에스엠</a></th><td>1,030</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 160</td><td>+18.39%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=243840" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;243840&quot;, &quot;9&quot;, event);">신흥에스이씨</a></th><td>51,300</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 6,850</td><td>+15.41%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=214270" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;214270&quot;, &quot;10&quot;, event);">FSN</a></th><td>3,770</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 470</td><td>+14.24%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=001080" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;001080&quot;, &quot;11&quot;, event);">만호제강</a></th><td>32,150</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 3,850</td><td>+13.60%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=067080" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;067080&quot;, &quot;12&quot;, event);">대화제약</a></th><td>12,050</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 1,350</td><td>+12.62%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=019570" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;019570&quot;, &quot;13&quot;, event);">리더스 기술투자</a></th><td>420</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 46</td><td>+12.30%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=294090" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;294090&quot;, &quot;14&quot;, event);">이오플로우</a></th><td>16,000</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 1,600</td><td>+11.11%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=091580" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;091580&quot;, &quot;15&quot;, event);">상신이디피</a></th><td>15,900</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 1,550</td><td>+10.80%</td></tr> 
          </tbody> 
         </table> 
         <a href="/sise/sise_rise.naver" class="btn_more" onclick="clickcr(this, 'spe.more', '', '', event);"><em class="btn_more4"><span class="blind">상승 더보기</span></em></a> 
        </div> 
        <div class="group_type"> 
         <table class="tbl_home"> 
          <caption>
           하락 TOP 종목
           <span>종목명에 대한 현재가, 전일대비, 등락률로 구분되어 있습니다.</span>
          </caption> 
          <colgroup> 
           <col width="40%"> 
           <col> 
          </colgroup> 
          <thead> 
           <tr> 
            <th scope="col">종목명</th> 
            <th scope="col">현재가</th> 
            <th scope="col">전일대비</th> 
            <th scope="col">등락률</th> 
           </tr> 
          </thead> 
          <tbody id="_topItems3"> 
           <tr class="down"><th><a href="/item/main.naver?code=096350" onclick="clickcr(this, &quot;spe.blist&quot;, &quot;096350&quot;, &quot;1&quot;, event);">대창솔루션</a></th><td>225</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 65</td><td>-22.41%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=405000" onclick="clickcr(this, &quot;spe.blist&quot;, &quot;405000&quot;, &quot;2&quot;, event);">플라즈맵</a></th><td>6,700</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 1,720</td><td>-20.43%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=272450" onclick="clickcr(this, &quot;spe.blist&quot;, &quot;272450&quot;, &quot;3&quot;, event);">진에어</a></th><td>12,000</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 2,900</td><td>-19.46%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=101670" onclick="clickcr(this, &quot;spe.blist&quot;, &quot;101670&quot;, &quot;4&quot;, event);">코리아에스이</a></th><td>10,300</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 2,200</td><td>-17.60%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=123840" onclick="clickcr(this, &quot;spe.blist&quot;, &quot;123840&quot;, &quot;5&quot;, event);">한일진공</a></th><td>495</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 87</td><td>-14.95%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=015020" onclick="clickcr(this, &quot;spe.blist&quot;, &quot;015020&quot;, &quot;6&quot;, event);">이스타코</a></th><td>1,035</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 155</td><td>-13.03%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=054180" onclick="clickcr(this, &quot;spe.blist&quot;, &quot;054180&quot;, &quot;7&quot;, event);">메디콕스</a></th><td>9,800</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 1,400</td><td>-12.50%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=36328K" onclick="clickcr(this, &quot;spe.blist&quot;, &quot;36328K&quot;, &quot;8&quot;, event);">티와이홀딩스우</a></th><td>9,950</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 1,400</td><td>-12.33%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=363260" onclick="clickcr(this, &quot;spe.blist&quot;, &quot;363260&quot;, &quot;9&quot;, event);">모비데이즈</a></th><td>958</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 127</td><td>-11.71%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=002990" onclick="clickcr(this, &quot;spe.blist&quot;, &quot;002990&quot;, &quot;10&quot;, event);">금호건설</a></th><td>6,060</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 790</td><td>-11.53%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=115610" onclick="clickcr(this, &quot;spe.blist&quot;, &quot;115610&quot;, &quot;11&quot;, event);">이미지스</a></th><td>2,110</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 275</td><td>-11.53%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=101730" onclick="clickcr(this, &quot;spe.blist&quot;, &quot;101730&quot;, &quot;12&quot;, event);">위메이드맥스</a></th><td>16,550</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 2,150</td><td>-11.50%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=016790" onclick="clickcr(this, &quot;spe.blist&quot;, &quot;016790&quot;, &quot;13&quot;, event);">카나리아바이오</a></th><td>16,550</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 2,150</td><td>-11.50%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=900120" onclick="clickcr(this, &quot;spe.blist&quot;, &quot;900120&quot;, &quot;14&quot;, event);">씨케이에이치</a></th><td>225</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 29</td><td>-11.42%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=008470" onclick="clickcr(this, &quot;spe.blist&quot;, &quot;008470&quot;, &quot;15&quot;, event);">부스타</a></th><td>5,110</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 650</td><td>-11.28%</td></tr> 
          </tbody> 
         </table> 
         <a href="/sise/sise_fall.naver" class="btn_more" onclick="clickcr(this, 'spe.more', '', '', event);"><em class="btn_more4"><span class="blind">하락 더보기</span></em></a> 
        </div> 
        <div class="group_type"> 
         <table class="tbl_home"> 
          <caption>
           시가총액 상위 TOP 종목
           <span>종목명에 대한 현재가, 전일대비, 등락률로 구분되어 있습니다.</span>
          </caption> 
          <colgroup> 
           <col> 
           <col width="40%"> 
           <col> 
          </colgroup> 
          <thead> 
           <tr> 
            <th scope="col">종목명</th> 
            <th scope="col">현재가</th> 
            <th scope="col">전일대비</th> 
            <th scope="col">등락률</th> 
           </tr> 
          </thead> 
          <tbody id="_topItems4"> 
           <tr class="up"><th><a href="/item/main.naver?code=005930" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;005930&quot;, &quot;1&quot;, event);">삼성전자</a></th><td>55,900</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 400</td><td>+0.72%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=373220" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;373220&quot;, &quot;2&quot;, event);">LG에너지솔루션</a></th><td>499,000</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 4,000</td><td>+0.81%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=000660" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;000660&quot;, &quot;3&quot;, event);">SK하이닉스</a></th><td>90,500</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 300</td><td>+0.33%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=207940" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;207940&quot;, &quot;4&quot;, event);">삼성바이오로직스</a></th><td>847,000</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 12,000</td><td>+1.44%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=006400" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;006400&quot;, &quot;5&quot;, event);">삼성SDI</a></th><td>627,000</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 38,000</td><td>+6.45%</td></tr> 
           <tr class="same"><th><a href="/item/main.naver?code=005935" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;005935&quot;, &quot;6&quot;, event);">삼성전자우</a></th><td>52,000</td><td><em class="bu_p bu_pn"><span class="blind">보합</span></em></td><td>0.00%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=051910" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;051910&quot;, &quot;7&quot;, event);">LG화학</a></th><td>568,000</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 1,000</td><td>-0.18%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=005380" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;005380&quot;, &quot;8&quot;, event);">현대차</a></th><td>167,000</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 1,500</td><td>-0.89%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=000270" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;000270&quot;, &quot;9&quot;, event);">기아</a></th><td>67,900</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 500</td><td>-0.73%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=035420" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;035420&quot;, &quot;10&quot;, event);">NAVER</a></th><td>166,000</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 2,500</td><td>-1.48%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=068270" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;068270&quot;, &quot;11&quot;, event);">셀트리온</a></th><td>174,000</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 2,500</td><td>+1.46%</td></tr> 
           <tr class="up"><th><a href="/item/main.naver?code=035720" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;035720&quot;, &quot;12&quot;, event);">카카오</a></th><td>48,850</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 1,100</td><td>+2.30%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=005490" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;005490&quot;, &quot;13&quot;, event);">POSCO홀딩스</a></th><td>249,000</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 3,000</td><td>-1.19%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=028260" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;028260&quot;, &quot;14&quot;, event);">삼성물산</a></th><td>109,500</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 1,000</td><td>-0.90%</td></tr> 
           <tr class="down"><th><a href="/item/main.naver?code=012330" onclick="clickcr(this, &quot;spe.clist&quot;, &quot;012330&quot;, &quot;15&quot;, event);">현대모비스</a></th><td>204,000</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 2,000</td><td>-0.97%</td></tr> 
          </tbody> 
         </table> 
         <a href="/sise/sise_market_sum.naver" class="btn_more" onclick="clickcr(this, 'spe.more', '', '', event);"><em class="btn_more4"><span class="blind">시가총액 상위 더보기</span></em></a> 
        </div> 
       </div> 
      </div> 
      <div class="section2"> 
       <div class="section_stock_market"> 
        <div class="group_heading"> 
         <h2 class="h_market"><span>오늘의 증시</span></h2> 
         <div class="ly_realtime"> 
          <span href="#" class="btn_realtime"> </span> 
          <span id="time">2022.10.21<span>장마감</span> </span> 
         </div> 
        </div> 
        <div class="section_stock"> 
         <div class="kospi_area group_quot quot_opn" style="height: 269px;"> 
          <div class="heading_area"> 
           <h4 class="h_opn"><a href="/sise/sise_index.naver?code=KOSPI" onclick="clickcr(this, 'tsc*k.title', '', '', event);" title="코스피지수 상세보기" class="_stock_section"><em><span class="blind">코스피</span></em></a></h4> 
           <a href="/sise/sise_index.naver?code=KOSPI" onclick="clickcr(this, 'tsc*k.title', '', '', event);" title="코스피지수 상세보기"> <span class="num_quot dn"><span class="num">2,213.12</span>
<span class="num2">4.97</span>
<span class="num3"><span class="blind">-</span>0.22<span class="per">%</span></span>
<span class="blind">하락</span></span> </a> 
           <span class="clse_bg"></span> 
          </div> 
          <div class="chart_area"> 
           <p class="blind">코스피 시세 차트</p> 
           <a href="/sise/sise_index.naver?code=KOSPI" onclick="clickcr(this, 'tsc*k.chart', '', '', event);" title="코스피지수 상세보기"><img src="https://ssl.pstatic.net/imgfinance/chart/main/KOSPI.png?sidcode=1666352280607" width="301" height="127" alt="코스피지수 상세보기"></a> 
          </div> 
          <div class="dsc_area"><dl class="dl">
<dt><a href="/sise/sise_trans_style.naver?sosok=01" onclick="clickcr(this, 'tsc*k.private', '', '', event);">개인</a></dt>
<dd class="dn"><a href="/sise/sise_trans_style.naver?sosok=01" onclick="clickcr(this, 'tsc*k.private', '', '', event);">-695</a><span class="blind">억원</span></dd>
<dt><a href="/sise/sise_trans_style.naver?sosok=01" onclick="clickcr(this, 'tsc*k.foreign', '', '', event);">외국인</a></dt>
<dd class="up"><a href="/sise/sise_trans_style.naver?sosok=01" onclick="clickcr(this, 'tsc*k.foreign', '', '', event);">+326</a><span class="blind">억원</span></dd>
<dt><a href="/sise/sise_trans_style.naver?sosok=01" onclick="clickcr(this, 'tsc*k.institutional', '', '', event);">기관</a></dt>
<dd class="up"><a href="/sise/sise_trans_style.naver?sosok=01" onclick="clickcr(this, 'tsc*k.institutional', '', '', event);">+89</a><span class="blind">억원</span></dd>
</dl>
<dl class="dl2">
<dt class="blind">상한종목수</dt>
<dd class="dd"><a href="/sise/sise_upper.naver?sosok=0" onclick="clickcr(this, 'tsc*k.ceiling', '', '', event);">1</a></dd>
<dt class="blind">상승종목수</dt>
<dd class="dd2"><a href="/sise/sise_rise.naver?sosok=0" onclick="clickcr(this, 'tsc*k.rise', '', '', event);">172</a></dd>
<dt class="blind">보합종목수</dt>
<dd class="dd3"><a href="/sise/sise_steady.naver?sosok=0" onclick="clickcr(this, 'tsc*k.steady', '', '', event);">48</a></dd>
<dt class="blind">하락종목수</dt>
<dd class="dd4"><a href="/sise/sise_fall.naver?sosok=0" onclick="clickcr(this, 'tsc*k.drop', '', '', event);">712</a></dd>
<dt class="blind">하한종목수</dt>
<dd class="dd5"><a href="/sise/sise_lower.naver?sosok=0" onclick="clickcr(this, 'tsc*k.floor', '', '', event);">0</a></dd>
</dl></div> 
         </div> 
         <div class="kosdaq_area group_quot" style="height: 40px;"> 
          <div class="heading_area"> 
           <h4 class=""><a href="/sise/sise_index.naver?code=KOSDAQ" onclick="clickcr(this, 'tsc*q.title', '', '', event);" title="코스닥지수 상세보기" class="_stock_section"><em><span class="blind">코스닥</span></em></a></h4> 
           <a href="/sise/sise_index.naver?code=KOSDAQ" onclick="clickcr(this, 'tsc*q.title', '', '', event);" title="코스닥지수 상세보기"> <span class="num_quot dn"><span class="num">674.48</span>
<span class="num2">5.96</span>
<span class="num3"><span class="blind">-</span>0.88<span class="per">%</span></span>
<span class="blind">하락</span></span> </a> 
           <span class="clse_bg"></span> 
          </div> 
          <div class="chart_area"> 
           <p class="blind">코스닥 시세 차트</p> 
           <a href="/sise/sise_index.naver?code=KOSDAQ" onclick="clickcr(this, 'tsc*q.chart', '', '', event);" title="코스닥지수 상세보기"><img src="https://ssl.pstatic.net/imgfinance/chart/main/KOSDAQ.png?sidcode=1666352280609" width="301" height="127" alt="코스닥지수 상세보기"></a> 
          </div> 
          <div class="dsc_area"><dl class="dl">
<dt><a href="/sise/sise_trans_style.naver?sosok=02" onclick="clickcr(this, 'tsc*k.private', '', '', event);">개인</a></dt>
<dd class="up"><a href="/sise/sise_trans_style.naver?sosok=02" onclick="clickcr(this, 'tsc*k.private', '', '', event);">+828</a><span class="blind">억원</span></dd>
<dt><a href="/sise/sise_trans_style.naver?sosok=02" onclick="clickcr(this, 'tsc*k.foreign', '', '', event);">외국인</a></dt>
<dd class="dn"><a href="/sise/sise_trans_style.naver?sosok=02" onclick="clickcr(this, 'tsc*k.foreign', '', '', event);">-414</a><span class="blind">억원</span></dd>
<dt><a href="/sise/sise_trans_style.naver?sosok=02" onclick="clickcr(this, 'tsc*k.institutional', '', '', event);">기관</a></dt>
<dd class="dn"><a href="/sise/sise_trans_style.naver?sosok=02" onclick="clickcr(this, 'tsc*k.institutional', '', '', event);">-285</a><span class="blind">억원</span></dd>
</dl>
<dl class="dl2">
<dt class="blind">상한종목수</dt>
<dd class="dd"><a href="/sise/sise_upper.naver?sosok=1" onclick="clickcr(this, 'tsc*k.ceiling', '', '', event);">2</a></dd>
<dt class="blind">상승종목수</dt>
<dd class="dd2"><a href="/sise/sise_rise.naver?sosok=1" onclick="clickcr(this, 'tsc*k.rise', '', '', event);">260</a></dd>
<dt class="blind">보합종목수</dt>
<dd class="dd3"><a href="/sise/sise_steady.naver?sosok=1" onclick="clickcr(this, 'tsc*k.steady', '', '', event);">78</a></dd>
<dt class="blind">하락종목수</dt>
<dd class="dd4"><a href="/sise/sise_fall.naver?sosok=1" onclick="clickcr(this, 'tsc*k.drop', '', '', event);">1194</a></dd>
<dt class="blind">하한종목수</dt>
<dd class="dd5"><a href="/sise/sise_lower.naver?sosok=1" onclick="clickcr(this, 'tsc*k.floor', '', '', event);">0</a></dd>
</dl></div> 
         </div> 
         <div class="kospi200_area group_quot" style="height: 40px;"> 
          <div class="heading_area"> 
           <h4 class=""><a href="/sise/sise_index.naver?code=KPI200" onclick="clickcr(this, 'tsc*f.title', '', '', event);" title="코스피200지수 상세보기" class="_stock_section"><em><span class="blind">코스피200</span></em></a></h4> 
           <a href="/sise/sise_index.naver?code=KPI200" onclick="clickcr(this,'tsc*o.title','','',event);" title="코스피200지수 상세보기"> <span class="num_quot dn"><span class="num">288.57</span>
<span class="num2">0.04</span>
<span class="num3"><span class="blind">-</span>0.01<span class="per">%</span></span>
<span class="blind">하락</span></span> </a> 
           <span class="clse_bg"></span> 
          </div> 
          <div class="chart_area"> 
           <p class="blind">코스피200 시세 차트</p> 
           <a href="/sise/sise_index.naver?code=KPI200" onclick="clickcr(this,'tsc*o.chart','','',event);" title="코스피200지수 상세보기"><img src="https://ssl.pstatic.net/imgfinance/chart/main/KPI200.png?sidcode=1666352280610" width="301" height="127" alt="코스피200지수 상세보기"></a> 
          </div> 
          <div class="dsc_area dsc_area2"><dl class="dl">
<dt>개인</dt>
<dd class="dn">-1,525<span class="blind">억원</span></dd>
<dt>외국인</dt>
<dd class="up">+617<span class="blind">억원</span></dd>
<dt>기관</dt>
<dd class="up">+655<span class="blind">억원</span></dd>
</dl></div> 
          <div class="basis_area"> 
           <dl> 
            <dt class="dt">
             <a href="/sise/sise_program.naver?sosok=01" title="프로그램매매 동향 상세보기"><span class="blind">프로그램</span></a>
            </dt> 
            <dd class="dd2 up" id="_kospiProgram"><a href="/sise/sise_program.naver?sosok=01" onclick="clickcr(this, &quot;tsc*o.program&quot;, &quot;&quot;, &quot;&quot;, event);">+634<span>억</span></a></dd> 
            <dt id="basis_name" class="blind">콘탱고</dt> 
            <dd id="basis_value" class="dd up"><span>+0.98<img src="https://ssl.pstatic.net/imgfinance/finance/btn_contango.gif" width="33" height="17" alt="콘탱고"></span></dd> 
           </dl> 
          </div> 
         </div> 
        </div> 
       </div> 
       <div class="section_top section_top_first"> 
        <h2 class="h_top"><span>업종상위</span></h2> 
        <ul class="list_rank"> 
         <li class="ranking1"><span class="info_num info_num1"><span class="blind">1</span></span><p class="item"><a href="/sise/sise_group_detail.naver?type=upjong&amp;no=283" onclick="clickcr(this, &quot;tos.cat1&quot;, &quot;upjong_283&quot;, &quot;&quot;, event);"><strong>전기제품</strong></a><em class="up">+2.13%</em></p><p><a href="/item/main.naver?code=243840" onclick="clickcr(this, &quot;tos.list0&quot;, &quot;243840&quot;, &quot;0&quot;, event);">신흥에스이..</a><em class="up">+15.41%</em></p><p><a href="/item/main.naver?code=393890" onclick="clickcr(this, &quot;tos.list1&quot;, &quot;393890&quot;, &quot;1&quot;, event);">더블유씨피</a><em class="up">+8.76%</em></p></li> 
         <li class="ranking2"><span class="info_num info_num2"><span class="blind">2</span></span><p class="item"><a href="/sise/sise_group_detail.naver?type=upjong&amp;no=290" onclick="clickcr(this, &quot;tos.cat2&quot;, &quot;upjong_290&quot;, &quot;&quot;, event);"><strong>교육서비스</strong></a><em class="up">+1.69%</em></p><p><a href="/item/main.naver?code=215200" onclick="clickcr(this, &quot;tos.list0&quot;, &quot;215200&quot;, &quot;0&quot;, event);">메가스터디..</a><em class="up">+6.84%</em></p><p><a href="/item/main.naver?code=035290" onclick="clickcr(this, &quot;tos.list1&quot;, &quot;035290&quot;, &quot;1&quot;, event);">골드앤에스</a><em class="up">+3.06%</em></p></li> 
         <li class="ranking3"><span class="info_num info_num3"><span class="blind">3</span></span><p class="item"><a href="/sise/sise_group_detail.naver?type=upjong&amp;no=332" onclick="clickcr(this, &quot;tos.cat3&quot;, &quot;upjong_332&quot;, &quot;&quot;, event);"><strong>문구류</strong></a><em class="up">+1.28%</em></p><p><a href="/item/main.naver?code=068290" onclick="clickcr(this, &quot;tos.list0&quot;, &quot;068290&quot;, &quot;0&quot;, event);">삼성출판사</a><em class="up">+2.30%</em></p><p><a href="/item/main.naver?code=005360" onclick="clickcr(this, &quot;tos.list1&quot;, &quot;005360&quot;, &quot;1&quot;, event);">모나미</a><em class="down">-2.94%</em></p></li> 
        </ul> 
        <a href="/sise/sise_group.naver?type=upjong" class="btn_more" onclick="clickcr(this, 'tos.more', '', '', event);"><em class="btn_more4"><span class="blind">업종상위 더보기</span></em></a> 
       </div> 
       <div class="section_top group_top"> 
        <h2 class="h_theme"><span>테마상위</span></h2> 
        <ul class="list_rank"> 
         <li class="ranking1"><span class="info_num info_num1"><span class="blind">1</span></span><p class="item"><a href="/sise/sise_group_detail.naver?type=theme&amp;no=449" onclick="clickcr(this, &quot;pol.type1&quot;, &quot;thema_449&quot;, &quot;&quot;, event);"><strong>2차전지(생산)</strong></a><em class="up">+1.93%</em></p><p><a href="/item/main.naver?code=006400" onclick="clickcr(this, &quot;tos.list0&quot;, &quot;006400&quot;, &quot;0&quot;, event);">삼성SDI</a><em class="up">+6.45%</em></p><p><a href="/item/main.naver?code=373220" onclick="clickcr(this, &quot;tos.list1&quot;, &quot;373220&quot;, &quot;1&quot;, event);">LG에너지솔..</a><em class="up">+0.81%</em></p></li> 
         <li class="ranking2"><span class="info_num info_num2"><span class="blind">2</span></span><p class="item"><a href="/sise/sise_group_detail.naver?type=theme&amp;no=486" onclick="clickcr(this, &quot;pol.type2&quot;, &quot;thema_486&quot;, &quot;&quot;, event);"><strong>크래프톤 관련주</strong></a><em class="up">+0.93%</em></p><p><a href="/item/main.naver?code=225570" onclick="clickcr(this, &quot;tos.list0&quot;, &quot;225570&quot;, &quot;0&quot;, event);">넥슨게임즈</a><em class="up">+5.69%</em></p><p><a href="/item/main.naver?code=246960" onclick="clickcr(this, &quot;tos.list1&quot;, &quot;246960&quot;, &quot;1&quot;, event);">이노테라피</a><em class="up">+2.06%</em></p></li> 
         <li class="ranking3"><span class="info_num info_num3"><span class="blind">3</span></span><p class="item"><a href="/sise/sise_group_detail.naver?type=theme&amp;no=173" onclick="clickcr(this, &quot;pol.type3&quot;, &quot;thema_173&quot;, &quot;&quot;, event);"><strong>IT 대표주</strong></a><em class="up">+0.87%</em></p><p><a href="/item/main.naver?code=006400" onclick="clickcr(this, &quot;tos.list0&quot;, &quot;006400&quot;, &quot;0&quot;, event);">삼성SDI</a><em class="up">+6.45%</em></p><p><a href="/item/main.naver?code=005930" onclick="clickcr(this, &quot;tos.list1&quot;, &quot;005930&quot;, &quot;1&quot;, event);">삼성전자</a><em class="up">+0.72%</em></p></li> 
        </ul> 
        <a href="/sise/theme.naver" class="btn_more" onclick="clickcr(this, 'pol.more', '', '', event);"><em class="btn_more4"><span class="blind">테마상위 더보기</span></em></a> 
       </div> 
      </div> 
     </div> 
     <div class="article2"> 
      <div class="section1"> 
       <div class="group1"> 
        <h2 class="h_exchange"><span>환전 고시 환율</span></h2> 
        <table class="tbl_home"> 
         <caption>
          환전 고시 환율
          <span>통화명에 대한 현재가,전일대비로 구분되어 있습니다.</span>
         </caption> 
         <colgroup> 
          <col> 
          <col width="50"> 
          <col width="50"> 
         </colgroup> 
         <thead> 
          <tr> 
           <th scope="col">구분</th> 
           <th scope="col">현재가</th> 
           <th scope="col">전일대비</th> 
          </tr> 
         </thead> 
         <tbody> 
          <tr class="up bold"> 
           <th scope="row"><a href="/marketindex/exchangeDetail.naver?marketindexCd=FX_USDKRW" onclick="clickcr(this, 'exr.list', 'FX_USDKRW', '1', event);">미국USD</a></th> 
           <td>1,443.00</td> 
           <td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 16.00</td> 
          </tr> 
          <tr class="up"> 
           <th scope="row"><a href="/marketindex/exchangeDetail.naver?marketindexCd=FX_JPYKRW" onclick="clickcr(this, 'exr.list', 'FX_JPYKRW', '2', event);">일본JPY (100엔)</a></th> 
           <td>953.32</td> 
           <td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 0.49</td> 
          </tr> 
          <tr class="up"> 
           <th scope="row"><a href="/marketindex/exchangeDetail.naver?marketindexCd=FX_EURKRW" onclick="clickcr(this, 'exr.list', 'FX_EURKRW', '3', event);">유럽연합EUR</a></th> 
           <td>1,406.85</td> 
           <td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 4.11</td> 
          </tr> 
          <tr class="up"> 
           <th scope="row"><a href="/marketindex/exchangeDetail.naver?marketindexCd=FX_CNYKRW" onclick="clickcr(this, 'exr.list', 'FX_CNYKRW', '4', event);">중국CNY</a></th> 
           <td>198.54</td> 
           <td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 1.16</td> 
          </tr> 
         </tbody> 
        </table> 
        <p class="dec_exchange"><em>2022.10.21 20:00</em> 하나은행 기준</p> 
        <a href="/marketindex/?tabSel=exchange#tab_section" class="btn_more" onclick="clickcr(this, 'exr.more', '', '', event);"><em class="btn_more4"><span class="blind">환전 고시 환율 더보기</span></em></a> 
       </div> 
       <div class="group2"> 
        <h2 class="h_foreign"><span>국제 시장 환율</span></h2> 
        <table class="tbl_home"> 
         <caption>
          국제 시장 환율
          <span>통화명에 대한 현재가,전일대비로 구분되어 있습니다.</span>
         </caption> 
         <colgroup> 
          <col> 
          <col width="53"> 
          <col width="50"> 
         </colgroup> 
         <thead> 
          <tr> 
           <th scope="col">구분</th> 
           <th scope="col">현재가</th> 
           <th scope="col">전일대비</th> 
          </tr> 
         </thead> 
         <tbody> 
          <tr class="down"> 
           <th scope="row"><a href="/marketindex/worldExchangeDetail.naver?marketindexCd=FX_USDJPY" onclick="clickcr(this, 'wmc.list', 'FX_USDJPY', '1', event);">달러/일본 엔(10.20)</a></th> 
           <td>149.5700</td> 
           <td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 0.14</td> 
          </tr> 
          <tr class="up"> 
           <th scope="row"><a href="/marketindex/worldExchangeDetail.naver?marketindexCd=FX_EURUSD" onclick="clickcr(this, 'wmc.list', 'FX_EURUSD', '2', event);"> 유로/달러(10.20)</a></th> 
           <td>0.9844</td> 
           <td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 0.01</td> 
          </tr> 
          <tr class="up"> 
           <th scope="row"><a href="/marketindex/worldExchangeDetail.naver?marketindexCd=FX_GBPUSD" onclick="clickcr(this, 'wmc.list', 'FX_GBPUSD', '3', event);"> 파운드/달러(10.20)</a></th> 
           <td>1.1322</td> 
           <td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 0.01</td> 
          </tr> 
          <tr class="down bold"> 
           <th scope="row"><a href="/marketindex/worldExchangeDetail.naver?marketindexCd=FX_USDX" onclick="clickcr(this, 'wmc.list', 'FX_USDX', '4', event);"> 달러인덱스(10.20)</a></th> 
           <td>112.8100</td> 
           <td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 0.06</td> 
          </tr> 
         </tbody> 
        </table> 
        <a href="/marketindex/?tabSel=worldExchange#tab_section" class="btn_more" onclick="clickcr(this, 'wmc.more', '', '', event);"><em class="btn_more4"><span class="blind">국제 시장 환율 더보기</span></em></a> 
       </div> 
       <div class="group3"> 
        <h2 class="h_interest"><span>금리</span></h2> 
        <table class="tbl_home"> 
         <caption>
          금리
          <span>종류에 대한 현재가,전일대비로 구분되어 있습니다.</span>
         </caption> 
         <colgroup> 
          <col> 
          <col width="50"> 
          <col width="52"> 
         </colgroup> 
         <thead> 
          <tr> 
           <th scope="col">구분</th> 
           <th scope="col">현재가</th> 
           <th scope="col">전일대비</th> 
          </tr> 
         </thead> 
         <tbody> 
          <tr class="up bold"> 
           <th scope="row"><a href="/marketindex/interestDetail.naver?marketindexCd=IRR_CD91" onclick="clickcr(this, 'int.list', 'IRR_CD91', '1', event);">CD(91일)(10.21)</a></th> 
           <td>3.90</td> 
           <td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 0.05</td> 
          </tr> 
          <tr class="up"> 
           <th scope="row"><a href="/marketindex/interestDetail.naver?marketindexCd=IRR_CALL" onclick="clickcr(this, 'int.list', 'IRR_CALL', '2', event);">콜금리(10.20)</a></th> 
           <td>3.13</td> 
           <td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 0.06</td> 
          </tr> 
          <tr class="up"> 
           <th scope="row"><a href="/marketindex/interestDetail.naver?marketindexCd=IRR_GOVT03Y" onclick="clickcr(this, 'int.list', 'IRR_GOVT03Y', '3', event);">국고채(3년)(10.21)</a></th> 
           <td>4.49</td> 
           <td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 0.14</td> 
          </tr> 
          <tr class="up"> 
           <th scope="row"><a href="/marketindex/interestDetail.naver?marketindexCd=IRR_CORP03Y" onclick="clickcr(this, 'int.list', 'IRR_CORP03Y', '4', event);">회사채(3년)(10.21)</a></th> 
           <td>5.73</td> 
           <td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 0.15</td> 
          </tr> 
         </tbody> 
        </table> 
        <a href="/marketindex/interestMain.naver" class="btn_more" onclick="clickcr(this, 'int.more', '', '', event);"><em class="btn_more4"><span class="blind">금리 더보기</span></em></a> 
       </div> 
      </div> 
      <div class="section2"> 
       <div class="group1"> 
        <h2 class="h_oil"><span>유가</span></h2> 
        <table class="tbl_home"> 
         <caption>
          유가
          <span>종류에 대한 현재가,전일대비로 구분되어 있습니다.</span>
         </caption> 
         <colgroup> 
          <col> 
          <col width="50"> 
          <col width="50"> 
         </colgroup> 
         <thead> 
          <tr> 
           <th scope="col">구분</th> 
           <th scope="col">현재가</th> 
           <th scope="col">전일대비</th> 
          </tr> 
         </thead> 
         <tbody> 
          <tr class="up"> 
           <th scope="row"><a href="/marketindex/worldOilDetail.naver?fdtc=2&amp;marketindexCd=OIL_DU" onclick="clickcr(this, 'oil.list', 'OIL_DU', '1', event);">두바이유(10.20)</a></th> 
           <td>90.54</td> 
           <td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 0.02</td> 
          </tr> 
          <tr class="down bold"> 
           <th scope="row"><a href="/marketindex/worldOilDetail.naver?fdtc=2&amp;marketindexCd=OIL_CL" onclick="clickcr(this, 'oil.list', 'OIL_CL', '2', event);"> WTI(10.20)</a></th> 
           <td>84.51</td> 
           <td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 0.01</td> 
          </tr> 
          <tr class="down"> 
           <th scope="row"><a href="/marketindex/oilDetail.naver?marketindexCd=OIL_GSL" onclick="clickcr(this, 'oil.list', 'OIL_GSL', '3', event);"> 휘발유(10.21)</a></th> 
           <td>1,664.56</td> 
           <td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 0.65</td> 
          </tr> 
          <tr class="down"> 
           <th scope="row"><a href="/marketindex/oilDetail.naver?marketindexCd=OIL_HGSL" onclick="clickcr(this, 'oil.list', 'OIL_HGSL', '4', event);"> 고급휘발유(10.21)</a></th> 
           <td>1,952.03</td> 
           <td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 0.83</td> 
          </tr> 
         </tbody> 
        </table> 
        <p class="dec_exchange2">단위<span class="bar">|</span><span class="txt">국제:달러/배럴, </span> 국내:원/리터 </p> 
        <a href="/marketindex/oilMain.naver" class="btn_more" onclick="clickcr(this, 'oil.more', '', '', event);"><em class="btn_more4"><span class="blind">유가 더보기</span></em></a> 
       </div> 
       <div class="group2"> 
        <h2 class="h_gold"><span>금 시세</span></h2> 
        <table class="tbl_home"> 
         <caption>
          금 시세
          <span>종류에 대한 현재가,전일대비로 구분되어 있습니다.</span>
         </caption> 
         <colgroup> 
          <col> 
          <col width="58"> 
          <col width="65"> 
         </colgroup> 
         <thead> 
          <tr> 
           <th scope="col">구분</th> 
           <th scope="col">현재가</th> 
           <th scope="col">전일대비</th> 
          </tr> 
         </thead> 
         <tbody> 
          <tr class="up bold"> 
           <th scope="row"><a href="/marketindex/worldGoldDetail.naver?marketindexCd=CMDT_GC&amp;fdtc=2" onclick="clickcr(this, 'gol.list', 'CMDT_GC', '1', event);">국제금(10.20)</a></th> 
           <td>1,636.80</td> 
           <td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 2.60</td> 
          </tr> 
          <tr class="up"> 
           <th scope="row"><a href="/marketindex/goldDetail.naver" onclick="clickcr(this, 'gol.list', 'CMDT_GD', '2', event);"> 국내금(10.21)</a></th> 
           <td>75,395.06</td> 
           <td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 266.56</td> 
          </tr> 
         </tbody> 
        </table> 
        <p class="dec_exchange2">단위<span class="bar">|</span><span class="txt">국제:달러/트로이온스, </span> 국내:원/g</p> 
        <a href="/marketindex/goldMain.naver" class="btn_more" onclick="clickcr(this, 'gol.more', '', '', event);"><em class="btn_more4"><span class="blind">금 시세 더보기</span></em></a> 
       </div> 
       <div class="group3"> 
        <h2 class="h_metal"><span>원자재</span></h2> 
        <table class="tbl_home"> 
         <caption>
          원자재
          <span>종류에 대한 현재가,전일대비로 구분되어 있습니다.</span>
         </caption> 
         <colgroup> 
          <col> 
          <col width="50"> 
          <col width="52"> 
         </colgroup> 
         <thead> 
          <tr> 
           <th scope="col">구분</th> 
           <th scope="col">현재가</th> 
           <th scope="col">전일대비</th> 
          </tr> 
         </thead> 
         <tbody> 
          <tr class="up bold"> 
           <th scope="row"><a href="/marketindex/materialDetail.naver?marketindexCd=CMDT_CDY" onclick="clickcr(this, 'mat.list', 'CMDT_CDY', '1', event);">구리(10.20)</a></th> 
           <td>7,585.50</td> 
           <td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 165.50</td> 
          </tr> 
          <tr class="down"> 
           <th scope="row"><a href="/marketindex/materialDetail.naver?marketindexCd=CMDT_PDY" onclick="clickcr(this, 'mat.list', 'CMDT_PDY', '2', event);">납(10.20)</a></th> 
           <td>1,989.00</td> 
           <td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 18.00</td> 
          </tr> 
          <tr class="down"> 
           <th scope="row"><a href="/marketindex/materialDetail.naver?marketindexCd=CMDT_NG" onclick="clickcr(this, 'mat.list', 'CMDT_NG', '3', event);">천연가스(10.20)</a></th> 
           <td>5.36</td> 
           <td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 0.10</td> 
          </tr> 
          <tr class="up"> 
           <th scope="row"><a href="/marketindex/materialDetail.naver?marketindexCd=CMDT_C" onclick="clickcr(this, 'mat.list', 'CMDT_C', '4', event);">옥수수(10.20)</a></th> 
           <td>684.00</td> 
           <td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 5.75</td> 
          </tr> 
         </tbody> 
        </table> 
        <p class="dec_exchange2">단위<span class="bar">|</span><span class="txt">구리·납:달러/톤 </span><br><span class="txt">천연가스: 달러/MMBtu, 옥수수: 센트/부셸</span></p> 
        <a href="/marketindex/materialMain.naver" class="btn_more" onclick="clickcr(this, 'mat.more', '', '', event);"><em class="btn_more4"><span class="blind">원자재 더보기</span></em></a> 
       </div> 
      </div> 
     </div> 
    </div> 
    <div class="aside"> 
     <div class="group_aside"> 
      <div class="aside_area aside_stock"> 
       <h3 class="h_stock"><span>해외 증시</span></h3> 
       <table class="tbl_home"> 
        <caption>
         해외 증시
         <span>종류에 대한 현재가,전일대비로 구분되어 있습니다.</span>
        </caption> 
        <colgroup> 
         <col> 
         <col width="60"> 
         <col width="59"> 
        </colgroup> 
        <thead> 
         <tr> 
          <th scope="col">구분</th> 
          <th scope="col">현재가</th> 
          <th scope="col">전일대비</th> 
         </tr> 
        </thead> 
        <tbody> 
         <tr class="down"> 
          <th scope="row"><a href="/world/sise.naver?symbol=DJI@DJI&amp;fdtc=0" onclick="clickcr(this, 'wst.dow', '', '', event);">다우산업(10.20)</a></th> 
          <td>30,333.59</td> 
          <td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 90.22</td> 
         </tr> 
         <tr class="down"> 
          <th scope="row"><a href="/world/sise.naver?symbol=NAS@IXIC&amp;fdtc=0" onclick="clickcr(this, 'wst.nasdaq', '', '', event);"> 나스닥(10.20)</a></th> 
          <td>10,614.84</td> 
          <td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 65.67</td> 
         </tr> 
         <tr class="up"> 
          <th scope="row"><a href="/world/sise.naver?symbol=HSI@HSCE&amp;fdtc=0" onclick="clickcr(this, 'wst.hsce', '', '', event);"> 홍콩H(10.21)</a></th> 
          <td>5,517.44</td> 
          <td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 5.14</td> 
         </tr> 
         <tr class="up"> 
          <th scope="row"><a href="/world/sise.naver?symbol=SHS@000001&amp;fdtc=0" onclick="clickcr(this, 'wst.shs', '', '', event);"> 상해종합(10.21)</a></th> 
          <td>3,038.93</td> 
          <td><em class="bu_p bu_pup"><span class="blind">상승</span></em> 3.88</td> 
         </tr> 
         <tr class="down"> 
          <th scope="row"><a href="/world/sise.naver?symbol=NII@NI225&amp;fdtc=0" onclick="clickcr(this, 'wst.ni225', '', '', event);"> 니케이225(10.21)</a></th> 
          <td>26,890.58</td> 
          <td><em class="bu_p bu_pdn"><span class="blind">하락</span></em> 116.38</td> 
         </tr> 
        </tbody> 
       </table> 
       <a href="/world/" class="btn_more" onclick="clickcr(this, 'wst.more', '', '', event);"><em class="btn_more4"><span class="blind">해외 증시 더보기</span></em></a> 
      </div> 
      <script>
						if (ieVersion === -1 || ieVersion > 10) {
							window.gladsdk = window.gladsdk || { cmd: [] };

							gladsdk.cmd.push(function() {
								gladsdk.defineAdSlot({
									adUnitId: "p_stock_sidebox",
									adSlotElementId: "_IframeBannerMain",
									uct: "KR",
									customParam: {
										calp: "home"
									},
								});
							})
						}
					</script> 
      <div class="ad"> 
       <div id="addiv" name="addiv"> 
        <h2 class="blind">광고</h2> 
        <div id="_IframeBannerMain"> 
         <script>
									if (ieVersion === -1 || ieVersion > 10) {
										gladsdk.cmd.push(function() {
											gladsdk.displayAd("_IframeBannerMain");
										});
									}
								</script> 
        <div style="width: 100%; height: auto; margin: 0px auto;"><iframe id="_IframeBannerMain_tgtLREC" frameborder="no" scrolling="no" tabindex="-1" name="" title="AD" style="width: 100%; height: 240px; visibility: inherit; display: block; border: 0px; vertical-align: bottom;"></iframe></div></div> 
       </div> 
      </div> 
      <div class="aside_area aside_popular"> 
       <h3 class="h_popular"><span>인기 검색 종목</span></h3> 
       <table class="tbl_home"> 
        <caption>
         인기 검색 종목표
         <span>종목명에 대한 현재가,전일대비로 구분되어 있습니다.</span>
        </caption> 
        <colgroup> 
         <col> 
         <col width="60"> 
         <col width="65"> 
        </colgroup> 
        <thead> 
         <tr> 
          <th scope="col">구분</th> 
          <th scope="col">현재가</th> 
          <th scope="col">전일대비</th> 
         </tr> 
        </thead> 
        <tbody> 
         <tr class="up"><th scope="row"><em>1.</em><a href="/item/main.naver?code=005930" onclick="clickcr(this, &quot;boa.list&quot;, &quot;005930&quot;, &quot;1&quot;, event);">삼성전자</a></th><td>55,900</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em><span class="tah p11 red02"> 400 </span></td></tr> 
         <tr class="up"><th scope="row"><em>2.</em><a href="/item/main.naver?code=035720" onclick="clickcr(this, &quot;boa.list&quot;, &quot;035720&quot;, &quot;2&quot;, event);">카카오</a></th><td>48,850</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em><span class="tah p11 red02"> 1,100 </span></td></tr> 
         <tr class="down"><th scope="row"><em>3.</em><a href="/item/main.naver?code=009540" onclick="clickcr(this, &quot;boa.list&quot;, &quot;009540&quot;, &quot;3&quot;, event);">한국조선해양</a></th><td>71,500</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em><span class="tah p11 nv01"> 1,400 </span></td></tr> 
         <tr class="down"><th scope="row"><em>4.</em><a href="/item/main.naver?code=035420" onclick="clickcr(this, &quot;boa.list&quot;, &quot;035420&quot;, &quot;4&quot;, event);">NAVER</a></th><td>166,000</td><td><em class="bu_p bu_pdn"><span class="blind">하락</span></em><span class="tah p11 nv01"> 2,500 </span></td></tr> 
         <tr class="up"><th scope="row"><em>5.</em><a href="/item/main.naver?code=000660" onclick="clickcr(this, &quot;boa.list&quot;, &quot;000660&quot;, &quot;5&quot;, event);">SK하이닉스</a></th><td>90,500</td><td><em class="bu_p bu_pup"><span class="blind">상승</span></em><span class="tah p11 red02"> 300 </span></td></tr> 
        </tbody> 
       </table> 
       <a href="/sise/lastsearch2.naver" class="btn_more" onclick="clickcr(this, 'boa.more', '', '', event);"><em class="btn_more4"><span class="blind">인기 검색 종목 더보기</span></em></a> 
      </div> 
      <div class="aside_area aside_notice"> 
       <h3 class="h_notice"><span>공지사항</span></h3> 
       <ul class="list_report"> 
        <li><a href="https://finance.naver.com/notice.naver?noticeId=7471" onclick="clickcr(this, 'not.list', '', '', event)">[서울경찰청] 수익률 300%보장...</a></li> 
       </ul> 
       <a href="/notice.naver" class="btn_more" onclick="clickcr(this, 'not.more', '', '', event)"><em class="btn_more4"><span class="blind">공지사항 더보기</span></em></a> 
      </div> 
     </div> 
    </div> 
   </div> 
   <hr> 
   <div id="footer"> 
    <ul> 
     <li class="first"> <a href="https://www.naver.com/rules/service.html" onclick="clickcr(this, 'fot.service', '', '', event);" target="_blank">이용약관</a> </li> 
     <li> <a href="https://finance.naver.com/rules.naver" onclick="clickcr(this, 'fot.policy', '', '', event);" target="_blank">금융게시판 운영원칙</a> </li> 
     <li> <a href="https://www.naver.com/rules/privacy.html" onclick="clickcr(this, 'fot.privacy', '', '', event);" target="_blank"><strong>개인정보처리방침</strong></a> </li> 
     <li> <a href="https://www.naver.com/rules/disclaimer.html" onclick="clickcr(this, 'fot.limit', '', '', event);" target="_blank">책임의 한계와 법적고지</a> </li> 
     <li> <a href="https://help.naver.com/service/5617/category/bookmark?lang=ko" onclick="clickcr(this, 'fot.help', '', '', event);" target="_blank">금융 고객센터</a> </li> 
    </ul> 
    <p class="desc">네이버(주)가 제공하는 금융 정보는 각 콘텐츠 제공업체<a href="javascript:;" onclick="togglePanelFooter('footerPanel0');" class="desc_help"><img src="https://ssl.pstatic.net/static/nfinance/2018/06/29/btn_help.png" width="17" height="17" alt="제공업체 상세설명"></a>로부터 받는 투자 참고사항이며, 오류가 발생하거나 지연될 수 있습니다.<br>네이버(주)와 콘텐츠 제공업체는 제공된 정보에 의한 투자 결과에 법적인 책임을 지지 않습니다. 게시된 정보는 무단으로 배포할 수 없습니다.</p> 
    <div id="footerPanel0" class="provider_layer" style="display:none" tabindex="0" onblur="hidePannel('footerPanel0')"> 
     <strong class="provider_layer__tit">콘텐츠 제공업체</strong> 
     <div class="provider_layer__txt"> 
      <p><span>코스콤 : </span>실시간 주가정보 및 국내시세정보</p> 
      <p><span>에프앤가이드 : </span>기업 및 재무정보</p> 
      <p><span>KG제로인 : </span>해외 시세, 시장지표 및 펀드 정보</p> 
      <p><span>한국예탁결제원 : </span>주주총회일 및 전자투표 정보</p> 
      <p><span>인포스탁 : </span>국내 테마 정보</p> 
     </div> 
     <span class="arrow"></span> 
    </div> 
    <address> <a href="https://www.navercorp.com/" target="_blank" class="logo" onclick="clickcr(this, 'fot.nhn', '', '', event);"><img src="https://ssl.pstatic.net/static/nfinance/2019/02/22/ci_naver.png" width="58" height="11" alt="NAVER"></a> <em>Copyright ©</em> <a href="https://www.navercorp.com/" target="_blank" onclick="clickcr(this, 'fot.nhn', '', '', event);">NAVER Corp.</a> <span>All Rights Reserved.</span> </address> 
   </div> 
   <script type="text/javascript">
function isVisible(obj) {
    if (obj == document) return true
 
    if (!obj) return false
    if (!obj.parentNode) return false
    if (obj.style) {
        if (obj.style.display == 'none') return false
        if (obj.style.visibility == 'hidden') return false
    }
 
    if (window.getComputedStyle) {
        var style = window.getComputedStyle(obj, "")
        if (style.display == 'none') return false
        if (style.visibility == 'hidden') return false
    }
 
    var style = obj.currentStyle
    if (style) {
        if (style['display'] == 'none') return false
        if (style['visibility'] == 'hidden') return false
    }
 
    return isVisible(obj.parentNode)
}

function isChildOf(myobj, containerObj) {
	while(myobj != undefined) {
		if (myobj == document.body) {
			break;
		} 
		if (myobj == containerObj) {
			return true;
		}
		myobj = myobj.parentElement;
	}
	return false;	
}

function gnbLayerClose(e){
	var target = e.target ? e.target : e.srcElement;
	if (isVisible(document.getElementById('gnb_service_lyr')) || isVisible(document.getElementById('gnb_notice_lyr')) ||isVisible(document.getElementById('gnb_my_lyr')) ) {
		if (!isChildOf(target, document.getElementById('gnb'))) {
			gnbAllLayerClose();
		}
	}	
}

var isIE = (navigator.userAgent.toLowerCase().indexOf("msie")!=-1 && window.document.all) ? true:false;
if (isIE) {
	document.attachEvent('onmousedown', gnbLayerClose);
} else {
	window.addEventListener('mousedown', gnbLayerClose);
}

function showPannel(layerId){
    var layer = jindo.$(layerId);
    layer.style.display='block';

    if (layerId == "summary_lyr") {
        var layerHeight = jindo.$Element(layer).height();
        jindo.$Element("summary_ifr").height(layerHeight);
    }
}

function hidePannel(layerId){
    var layer = jindo.$(layerId);
    layer.style.display='none';
}

function togglePanelFooter(layerId) {
    var elTargetLayer = jindo.$Element(jindo.$$.getSingle("#" + layerId));

    if (elTargetLayer != null) {
        if (elTargetLayer.visible()) {
            hidePannel(layerId);
        } else {
            showPannel(layerId);
        }
    }
}

// add data-useragent
document.documentElement.setAttribute('data-useragent',navigator.userAgent);
</script> 
  </div> 
  <script type="text/javascript" src="/js/JSUtility.ns.js" charset="EUC-KR"></script> 
  <script type="text/javascript" src="/js/stock.js" charset="EUC-KR"></script> 
  <script type="text/javascript" src="/js/util.js" charset="EUC-KR"></script> 
  <script type="text/template" id="todayIndexItemTemplate">
<dl class="dl">
<dt><a href="{=_todayIndexDealTrendLink}" onClick="clickcr(this, 'tsc*k.private', '', '', event);">개인</a></dt>
<dd class="{js setUpDnClass(=_personalValue)}"><a href="{=_todayIndexDealTrendLink}" onClick="clickcr(this, 'tsc*k.private', '', '', event);">{js printChangeRate(=_personalValue)}</a><span class="blind">억원</span></dd>
<dt><a href="{=_todayIndexDealTrendLink}" onClick="clickcr(this, 'tsc*k.foreign', '', '', event);">외국인</a></dt>
<dd class="{js setUpDnClass(=_foreignValue)}"><a href="{=_todayIndexDealTrendLink}" onClick="clickcr(this, 'tsc*k.foreign', '', '', event);">{js printChangeRate(=_foreignValue)}</a><span class="blind">억원</span></dd>
<dt><a href="{=_todayIndexDealTrendLink}" onClick="clickcr(this, 'tsc*k.institutional', '', '', event);">기관</a></dt>
<dd class="{js setUpDnClass(=_institutionalValue)}"><a href="{=_todayIndexDealTrendLink}" onClick="clickcr(this, 'tsc*k.institutional', '', '', event);">{js printChangeRate(=_institutionalValue)}</a><span class="blind">억원</span></dd>
</dl>
<dl class="dl2">
<dt class="blind">상한종목수</dt>
<dd class="dd"><a href="{=_todayIndexItemUpperLink}" onClick="clickcr(this, 'tsc*k.ceiling', '', '', event);">{=_indexItemUpperCnt}</a></dd>
<dt class="blind">상승종목수</dt>
<dd class="dd2"><a href="{=_todayIndexItemRiseLink}" onClick="clickcr(this, 'tsc*k.rise', '', '', event);">{=_indexItemRiseCnt}</a></dd>
<dt class="blind">보합종목수</dt>
<dd class="dd3"><a href="{=_todayIndexItemSteadyLink}" onClick="clickcr(this, 'tsc*k.steady', '', '', event);">{=_indexItemSteadyCnt}</a></dd>
<dt class="blind">하락종목수</dt>
<dd class="dd4"><a href="{=_todayIndexItemFallLink}" onClick="clickcr(this, 'tsc*k.drop', '', '', event);">{=_indexItemFallCnt}</a></dd>
<dt class="blind">하한종목수</dt>
<dd class="dd5"><a href="{=_todayIndexItemLowerLink}" onClick="clickcr(this, 'tsc*k.floor', '', '', event);">{=_indexItemLowerCnt}</a></dd>
</dl>
</script> 
  <script type="text/template" id="todayKpi200Template">
<dl class="dl">
<dt>개인</dt>
<dd class="{js setUpDnClass(=_personalValue)}">{js printChangeRate(=_personalValue)}<span class="blind">억원</span></dd>
<dt>외국인</dt>
<dd class="{js setUpDnClass(=_foreignValue)}">{js printChangeRate(=_foreignValue)}<span class="blind">억원</span></dd>
<dt>기관</dt>
<dd class="{js setUpDnClass(=_institutionalValue)}">{js printChangeRate(=_institutionalValue)}<span class="blind">억원</span></dd>
</dl>
</script> 
  <script language="javascript">
var currentType = "recent";
var prevPage = 0;
var nextPage = 0;

jindo.$Fn(function(){
	
	var topTabList = jindo.$A(jindo.$$('.tab_area li'));
	var topLayerList = jindo.$A(jindo.$$('.section_sise_top .group_type'));

	jindo.$Fn(function(e){
		var el = jindo.$Element(e.currentElement);

		for (var i = 0; i < topTabList.length(); i++) {
			el.parent().removeClass("sise_top" + (i+1));
			jindo.$Element(topLayerList.get(i)).removeClass("is_active");
			if (jindo.$Element(topTabList.get(i)).className() == el.className()) {
				el.parent().addClass("sise_top" + (i+1));
				jindo.$Element(topLayerList.get(i)).addClass("is_active");
			}
		}
	}).attach(jindo.$$('.tab_area li'), "click");

	
	jindo.$Element(jindo.$A(jindo.$$(".bx_spot input")).get(0)).hide();

	
	selectMyStockRowSize('recent');

	
	jindo.$Fn(function(e) {
		toggleRecentMyStockLayer();
	}).attach(jindo.$$(".bx_spot input"), "click");

	jindo.$A(jindo.$$(".foreign_news a")).forEach(function(oElement) {
		jindo.$Element(oElement).ellipsis();
	});
}).attach(document,"domready");


jindo.$Fn(function(){
	var ua = window.navigator.userAgent;
	var referrer = document.referrer;

	if (ua != null && isMobileDevice(ua)) {
		var welService = jindo.$Element(jindo.$$.getSingle("a.service"));
	    if (isSafari(ua) && welService) {
	        var href = welService.attr("href");
	        welService.attr("href", href + "?mobile");

			if (document.URL.indexOf("mobile") > -1) {
				jindo.$Element("footer").append(jindo.$Element("<div class=\"gomobile\"><a href=\"https://m.stock.naver.com/\"><img src=\"https://ssl.pstatic.net/imgstock/images5/btn_gomobile.gif\" alt=\"모바일 버전으로 보기\" width=\"820\" height=\"110\"></a></div>"));
			} else {
				document.location.href = "https://m.stock.naver.com/";
			}
		}

		if (getReferrerType(ua, referrer) != "p" && isNotStockMobileReferrer(referrer)) {
			document.location.href = "https://m.stock.naver.com/";
		} else {
			jindo.$Element("footer").append(jindo.$Element("<div class=\"gomobile\"><a href=\"https://m.stock.naver.com/\"><img src=\"https://ssl.pstatic.net/imgstock/images5/btn_gomobile.gif\" alt=\"모바일 버전으로 보기\" width=\"820\" height=\"110\"></a></div>"));
		}
	}

	if (ua != null && isPadDevice(ua) && !document.getElementById("isPadMobileVersionUrl")) {
		jindo.$Element("footer").append(jindo.$Element("<p style=\"clear:both;margin:50px 0 -50px;\"> <a href=\"https://m.stock.naver.com/\" style=\"display:block;padding:20px 0;border-top:1px solid #e7e7e7;background:#f3f3f3;text-align:center;text-decoration:none\"> <span style=\"font-family:AppleSDGothicNeo-SemiBold;vertical-align:middle;font-size:18px;\">모바일 버전으로 보기<img src=\"https://ssl.pstatic.net/static/nfinance/2014/ico_version_arrow.png\" style=\"vertical-align:middle;margin:-3px 0 0 7px;*margin-top:-1px;\" alt=\"모바일 버전으로 이동\"></span></a></p>"));
	}
}).attach(document, "domready");

function isSafari(uaString) {
	var userAgentString = uaString.toLowerCase();

	if (userAgentString.indexOf("safari") > -1) {
		return true;
	} else {
		return false;
	}

}

function isPadDevice(uaString) {
	var userAgentString = uaString.toLowerCase();

	var isPad = false;

	if (userAgentString.indexOf("ipad") > -1) {
		isPad = true;
	} else if (userAgentString.indexOf("android") > -1) {
		if (userAgentString.match(".*shw-m18(0|5)(s|k|l).*")) {
			isPad = true;
		} else if (isAndroidPad(userAgentString)) {
			isPad = true;
		}
	}

	return isPad;
}

function isMobileDevice(uaString) {
	var userAgentString = uaString.toLowerCase();

	var isMobile = false;

	if (userAgentString.indexOf("windows ce") > -1 && userAgentString.indexOf("polar") > -1) {
		isMobile = true;
	} else if (userAgentString.indexOf("mozilla") == 0 && userAgentString.indexOf("polar") > -1) {
		isMobile = true;
	} else if (userAgentString.indexOf("mozilla") > -1 && userAgentString.indexOf("natebrowser") > -1) {
		isMobile = true;
	} else if (userAgentString.indexOf("opera") > -1
		&& (userAgentString.indexOf("skt") > -1 || userAgentString.indexOf("windows ce") > -1)) {
		isMobile = true;
	} else if (userAgentString.indexOf("ipad") > -1) {
		isMobile = false;
	} else if (userAgentString.indexOf("iphone") > -1|| userAgentString.indexOf("ipod") > -1) {
		isMobile = true;
	} else if (userAgentString.indexOf("tizen") > -1 && userAgentString.indexOf("familyhub") > -1) {
		isMobile = true;
	} else if (userAgentString.indexOf("android") > -1) {
		if (userAgentString.match(".*shw-m18(0|5)(s|k|l).*")) {
			isMobile = false;
		} else if (isAndroidPad(userAgentString)) {
			isMobile = false;
		} else {
			isMobile = true;
		}
	} else if (userAgentString.indexOf("dolfin") > -1) {
		isMobile = true;
	} else if (userAgentString.match("^mozilla.*wv[0-9]+.*lgtelecom.*")) {
		isMobile = true;
	} else {
		isMobile = false;
	}

	return isMobile;
}

function isAndroidPad(userAgentString) {
	var pattern = /android+\s+((\d)\.(\d))(?:\.(\d))?/igm;
	var result = pattern.exec(userAgentString);

	if (result != null && result.length > 0) {
		var osVersion = result[1];
		if(osVersion >= 3.0 && osVersion < 4.0) {	// 안드로이드 3.0 허니콤
			return true;
		} else if (osVersion >= 4.0 && !(userAgentString.indexOf("mobile") > -1)) {
			return true;
		} else {
			return false;
		}
	}
}

function getReferrerType(ua, referrer) {
	var userAgentString = (typeof ua === 'function')? ua(): ua;

	if (referrer != null && referrer.length != 0) {

        if (referrer.match("(http:|https:)//m\\.(.*?)(\\.)?naver\\.com.*") ||
             referrer.match("(http:|https:)//m\\.wingspoon\\.com/.*") ||
             referrer.match("(http:|https:)//me2day\\.net/n/.*") ||
             referrer.match("(http:|https:)//.*\\.naver\\.com/m/.*")
        ) {
             return "m";
        } else if (referrer.match("(http:|https:)//.*\\.naver\\.com.*") && userAgentString.contains("safari")) {
   			var queryString = window.location.search;
   			if (queryString == "?mobile") {
   				return "p";
   			} else {
   				return "m";
   			}
   		} else if (referrer.match("(http:|https:)//.*\\.naver\\.com.*") ||
             referrer.match("(http:|https:)//wingspoon\\.com/.*") ||
             referrer.match("(http:|https:)//me2day\\.net.*")
        ) {
             return "p";
        }
    }

	return "o";
}

function isNotStockMobileReferrer(referrer) {
	var financeReferer = "(.*)m.stock.naver.com(.*)";

	if (!referrer) {
		return true;
	}

	if (referrer != null && referrer.length != 0) {
		if (!referrer.match(financeReferer)) {
			return true;
		}
	}

	return false;
}


var rowSize = 0;
var itemListSize = 0;


var isOpened = false;


function selectMyStockRowSize(type) {
	var url = "/item/item_right_ajax.naver?type=mystock&code=000000&page=1&pageSize=30";
	var ajax = new jindo.$Ajax(url , {
		onerror : function() {
				emptyInnerHtml(type);
			},
		onload : function(res) {
			var data = res.json();
			var itemListSize = jindo.$A(data.item_list).length();
			rowSize = parseInt((itemListSize - 1) / 5);

			
			showMainRecentMyStockSearchStock('tab_search', 'tab_spot tab1', '000000', 'recent');
		}
	});

	ajax.request();
}


var recentMyStockLayer_viewMode = "hide";


function toggleRecentMyStockLayer() {
	
	if (isOpened) {
		isOpened = false;
	} else {
		isOpened = true;
	}

	toggleShowHideBtn();
	toggleSpotViewOnOff();
	toggleItemLayer();
}


function toggleItemLayer() {
	jindo.$A(jindo.$$(".tab_list > li")).forEach(function(oElement, index, value) {
		
		if (index > 0) {
			jindo.$Element(oElement).toggle();
		}
	});

	
	if (itemListSize <= 5 && recentMyStockLayer_viewMode == 'hide') {
		jindo.$A(jindo.$$(".bx_spot input")).forEach(function(inputElement) {
			jindo.$Element(inputElement).hide();
		});
	}
}


function toggleShowHideBtn() {
	var hideBtn = jindo.$A(jindo.$$(".bx_spot input")).get(0);
	var showBtn = jindo.$A(jindo.$$(".bx_spot input")).get(1);

	if (recentMyStockLayer_viewMode == "hide") {
		jindo.$Element(hideBtn).show();
		jindo.$Element(showBtn).hide();

		recentMyStockLayer_viewMode = "show";
	} else if (recentMyStockLayer_viewMode == "show") {
		jindo.$Element(showBtn).show();
		jindo.$Element(hideBtn).hide();
		recentMyStockLayer_viewMode = "hide";
	}
}


function toggleSpotViewOnOff() {
	var spotElement = jindo.$Element(jindo.$$.getSingle(".home_spot"))
	spotElement.toggleClass("view_on", "view_off");
}


function moveToItemMainPage(code) {
	document.location.href = "/item/main.naver?code=" + code;
}


function deleteRecentCode(groupId, code, type) {
	
	var cookieName = "stock";
	codeList_cookie = getCookie("naver_" + cookieName + "_codeList");
	codeList = codeList_cookie.split("|");
	copyCodeList(code, codeList, cookieName);

	
	selectMyStockRowSize('recent');
}


function showMainRecentMyStockSearchStock(tabId, tabClassName, itemcode, type) {
	if (tabId != null && tabId != '') {
		jindo.$(tabId).className = tabClassName;
		if (tabClassName == "tab_spot tab1") {
			jindo.$Element("recent_mystock_blind").html("최근 조회종목 리스트");
		} else if (tabClassName == "tab_spot tab2") {
			jindo.$Element("recent_mystock_blind").html("MY STOCK 리스트");
		}
	}

	getRecentData(itemcode, type, '1');
}

function getRecentData(itemcode, type, page) {
    var url = "/item/item_right_ajax.naver?type=" + type + "&code=" + itemcode + "&page=" + page + "&pageSize=30";
    updatePage(url, type);
}

function updatePage(url, type) {
	var ajax = new jindo.$Ajax(url, {
		onerror : function() {
			emptyInnerHtml(type);
		},
		onload : loadRecentInnerHtml
	});

	ajax.request();
}

function emptyInnerHtml(type) {
	if (type == 'mystock') {
		jindo.$('tab_search').className = 'tab_spot tab2';
	} else {
		jindo.$('tab_search').className = 'tab_spot tab1';
	}

	var divObj = jindo.$Element("recent_search_tab");

	
	var oTabList = jindo.$$.getSingle(".tab_list");

	
	jindo.$Element(oTabList).empty();

	
	var spotElement = jindo.$Element(jindo.$$.getSingle(".home_spot"));

	
	jindo.$Element(oTabList).empty();

	
	if (type == 'mystock') {
		
		jindo.$Element(oTabList).append(jindo.$("<li class='first'><div class='nodata'><p class='regist'>MY STOCK에 관심종목을 등록하시면 시세가 제공됩니다.</p><a href='/mystock/index.naver'>MY STOCK 바로가기</a></div></li>"));
	} else {
		jindo.$Element(oTabList).append(jindo.$("<li class='first'><div class='nodata'><p class='search'>최근조회 종목이 없습니다.</p></div></li>"));
	}

	
	jindo.$ElementList(jindo.$$(".bx_spot input")).hide();

	
	recentMyStockLayer_viewMode = "hide";

	
	spotElement.removeClass("view_on");
	spotElement.addClass("view_off");

	return;
}

function loadRecentInnerHtml(res) {
	var divObj = jindo.$Element("recent_search_tab");

	var data = res.json();

	
	var itemList = jindo.$A(data.item_list);

	
	var oTabList = jindo.$$.getSingle(".tab_list");

	
	jindo.$Element(oTabList).empty();

	
	itemListSize = itemList.length();

	
	var spotElement = jindo.$Element(jindo.$$.getSingle(".home_spot"));

	
	var tempRowSize = parseInt((itemListSize - 1) / 5);

	if (rowSize < tempRowSize) {
		rowSize = tempRowSize;
	}

	
	if (itemList.length() == 0) {
		
		jindo.$Element(oTabList).empty();

		
		if (data.type == 'recent') {
			jindo.$Element(oTabList).append(jindo.$("<li class='first'><div class='nodata'><p class='search'>최근조회 종목이 없습니다.</p></div></li>"));
		} else if (data.type == 'mystock') {
			
			if (data.login == "true") {
				jindo.$Element(oTabList).append(jindo.$("<li class='first'><div class='nodata'><p class='regist'>MY STOCK에 관심종목을 등록하시면 시세가 제공됩니다.</p><a href='/mystock/index.naver'>MY STOCK 바로가기</a></div></li>"));
			} else {
				jindo.$Element(oTabList).append(jindo.$("<li class='first'><div class='nodata'><p class='login'>로그인하시면 등록하신 종목의 시세가 제공됩니다.</p><a href='/mystock/index.naver'>MY STOCK 로그인</a></div></li>"));
			}
		}

		
		jindo.$ElementList(jindo.$$(".bx_spot input")).hide();

		
		recentMyStockLayer_viewMode = "hide";

		
		spotElement.removeClass("view_on");
		spotElement.addClass("view_off");

		return;
	}

	
	for (i=0; i<=rowSize; i++) {
		var li;
		if (i == 0) {
			
			li = jindo.$('<li class="first"><ul></ul></li>');
		} else if (i == 1 || i == 3) {
			li = jindo.$('<li class="even_num"><ul></ul></li>');
		} else if (i == 5) {
			li = jindo.$('<li class="last even_num"><ul></ul></li>');
		} else {
			li = jindo.$('<li><ul></ul></li>');
		}

		
		if (recentMyStockLayer_viewMode == 'hide') {
			
			if (i != 0) {
				jindo.$Element(li).hide();
			} else {
				
				spotElement.removeClass("view_on");
				spotElement.addClass("view_off");
			}
		} else if (recentMyStockLayer_viewMode == 'show') {
			
			spotElement.removeClass("view_off");
			spotElement.addClass("view_on");
		}

		jindo.$Element(oTabList).append(li);
	}

	
	if (rowSize == 0) {
		spotElement.removeClass("view_on");
		spotElement.addClass("view_off");
	} else {
		var hideBtn = jindo.$Element(jindo.$A(jindo.$$(".bx_spot input")).get(0));
		var showBtn = jindo.$Element(jindo.$A(jindo.$$(".bx_spot input")).get(1));

		if (recentMyStockLayer_viewMode == 'hide') {
			
			showBtn.show();
			hideBtn.hide();
		} else {
			
			hideBtn.show();
			showBtn.hide();
		}
	}

	
	if (itemListSize <= 5 && isOpened == false) {
		jindo.$A(jindo.$$(".bx_spot input")).forEach(function(inputElement) {
			jindo.$Element(inputElement).hide();
		});
	}

	
	var row = 0;
	itemcodes = "";
	itemList.forEach(function(item, index, value) {
		if (index != 0) {
			itemcodes += ",";
		}
		itemcodes += item.itemcode;

		row = parseInt(index / 5);

		var oTabListElement = jindo.$A(jindo.$$("ul", oTabList)).get(row);
		var spanElement;
		var changeRate = Math.abs(Number(item.change_rate));
		changeRate = changeRate.toFixed(2);

		
		if (item.risefall == 1) {
			spanElement = "<span class='up'>" + item.now_val + " <em><img src='https://ssl.pstatic.net/static/nfinance/ico_up2.gif' width='7' height='11' alt='상한'>" + changeRate + "%</em></span>";
		} else if (item.risefall == 2) {
			spanElement = "<span class='up'>" + item.now_val + " <em><img src='https://ssl.pstatic.net/static/nfinance/ico_up.gif' width='7' height='6' alt='상승'>" + changeRate + "%</em></span>";
		} else if (item.risefall == 5) {
			spanElement = "<span class='down'>" + item.now_val + " <em><img src='https://ssl.pstatic.net/static/nfinance/ico_down.gif' width='7' height='6' alt='하락'>" + changeRate + "%</em></span>";
		} else if (item.risefall == 4) {
			spanElement = "<span class='down'>" + item.now_val + " <em><img src='https://ssl.pstatic.net/static/nfinance/ico_down2.gif' width='7' height='11' alt='하한'>" + changeRate + "%</em></span>";
		} else {
			spanElement = "<span class='same'>" + item.now_val + " <em><img src='https://ssl.pstatic.net/static/nfinance/ico_same2.gif' width='10' height='6' alt='보합'>" + changeRate + "%</em></span>";
		}

		var clickcrAreaCode;

		if (data.type == 'recent') {
			clickcrAreaCode = "mys*r.stock";
		} else {
			clickcrAreaCode = "mys*i.stock";
		}

		var pElement = "<p><a href='/item/main.naver?code=" + item.itemcode + "' class='tit_item' onClick=\"clickcr(this, '" + clickcrAreaCode + "', '"+item.itemcode+"', '', event);\"><strong>" + item.itemname + "</strong></a>";

		if (data.type == 'recent') {
				pElement += "<a href='javascript:deleteRecentCode(\"" + data.sel_cid + "\", \""  + item.itemcode + "\", \"" + data.type + "\");' onClick=\"clickcr(this, 'mys*r.delete', '', '', event);\" class=\"btn_item_del\"><img src='https://ssl.pstatic.net/static/nfinance/2018/06/25/btn_delete.gif' width='17' height='17' alt='삭제'></a>";
		}

		pElement += "</p>";


		
		var liElement;
		if (index % 5 == 0) {
			liElement = jindo.$(jindo.$S("<li class='first_item'>" + pElement + spanElement) + "</li>");
		} else {
			liElement = jindo.$(jindo.$S("<li>" + pElement + spanElement) + "</li>");
		}

		
		if (data.type == 'recent') {
			jindo.$Element(oTabListElement).append(liElement);
		} else {
			if (index < 29) {
				jindo.$Element(oTabListElement).append(liElement);
			}
		}

		
		if (index == 28 && data.type == 'mystock' && data.itemTotalCnt > 29) {
			jindo.$Element(oTabListElement).append(jindo.$("<li><p class='my_stock'><strong>MY STOCK (총<em>" + data.itemTotalCnt + "</em>건)</strong></p><a href='/mystock/index.naver' class='btn_more' onClick=\"clickcr(this, 'mys*i.more', '', '', event);\">더보기</a></li>"));
		}
	});

	Polling.clearTimer();
	Polling.call();
}


function checkUpDown(y3EarningRate) {
	if (y3EarningRate > 0) {
		return 'up';
	} else if (y3EarningRate < 0) {
		return 'down';
	} else {
		return 'same2';
	}
}


function openChartPopup() {
	window.open("/world/market_index_popup.naver", "charPopup","location=0,status=1, scrollbars=1,width=756,height=745");
}

var itemcodes = null;
var dateTime = "20221021185900";
var closeDate = dateTime.substring(0,4) + "." + dateTime.substring(4,6) + "." + dateTime.substring(6,8);

// 오늘의 증시 아코디언 방식으로 구현
jindo.$Fn(function() {
	jindo.$Fn(function(e) {
		var el = jindo.$Element(e.currentElement);
		var indexList = jindo.$A(jindo.$$(".group_quot"));
		for (var i = 0, n = indexList.length(); i < n; i++) {
			var index = jindo.$Element(indexList.get(i));
			index.removeClass("quot_opn");
			index.css({height:40});
			jindo.$Element(jindo.$$.getSingle("h4", indexList.get(i))).removeClass("h_opn");
		}

		el.parent().addClass("quot_opn");
		el.parent().css({height:269});
		jindo.$Element(jindo.$$.getSingle("h4", e.currentElement)).addClass("h_opn");

	}, this).attach(jindo.$$(".heading_area"), "mouseover");

}, this).attach(document, "domready");

//실시간 버튼 마우스 오버, 아웃시 말풍선 구현
jindo.$Fn(function() {

	jindo.$Fn(function() {
		var spotDivEl = jindo.$Element(jindo.$$.getSingle(".home_spot"));

		if (spotDivEl.hasClass("view_off")) {
			var homeDivEl = jindo.$Element(jindo.$$.getSingle(".home"));
			homeDivEl.css("zIndex", 80);
		}

	}, this).attach(jindo.$$(".btn_realtime"), "mouseover");

	jindo.$Fn(function() {

		var homeDivEl = jindo.$Element(jindo.$$.getSingle(".home"));
		homeDivEl.css("zIndex", 0);

	}, this).attach(jindo.$$(".btn_realtime"), "mouseout");

	jindo.$Fn(function(oEvent) {
		oEvent.stop();
	}, this).attach(jindo.$$(".btn_realtime"), "click");

}, this).attach(document, "domready");

// 웹 접근성 대응 (키보드 이벤트 추가)
jindo.$Fn(function() {

    // 오늘의 증시
    jindo.$Fn(function(e) {
        e.stop();
        var indexList = jindo.$A(jindo.$$(".group_quot"));
        for (var i = 0, n = indexList.length(); i < n; i++) {
            var index = jindo.$Element(indexList.get(i));
            index.removeClass("quot_opn");
            index.css({height:40});
            jindo.$Element(jindo.$$.getSingle("h4", indexList.get(i))).removeClass("h_opn");
        }

        var targetEl = jindo.$Element(e.currentElement).parent().parent().parent();
        targetEl.addClass("quot_opn");
        targetEl.css({height:269});
        jindo.$Element(targetEl.query("h4")).addClass("h_opn");
    }, this).attach(jindo.$$("._stock_section"), "focus");

}, this).attach(document, "domready");

//실시간 시세 조회처리 모듈
var Polling = {
	_nInterval : 100,
	_oTimer : null,
	_oAjax : null,
	_sAjaxQuery : "SERVICE_INDEX:KOSPI,KOSDAQ,KPI200",
	_welBasisName : jindo.$Element(jindo.$$.getSingle(".basis_area #basis_name")),
	_welBasisValue : jindo.$Element(jindo.$$.getSingle(".basis_area #basis_value")),
	_aElQuot : jindo.$A(jindo.$$(".num_quot")),
	_elTime : jindo.$("time"),
	_oTemplate : {  // 템플릿
		market : jindo.$Template("<span class='num'>{=NUM1}</span>\n<span class='num2'>{=NUM2}</span>\n<span class='num3'><span class='blind'>{=SIGN}</span>{=NUM3}<span class='per'>%</span></span>\n<span class='blind'>{=SIGN_TEXT}</span>"),
		rf : {
			1 : jindo.$Template("<span class='up'>{=NV} <em><img src='https://ssl.pstatic.net/static/nfinance/ico_up2.gif' width='7' height='11' alt='상한'>{=RATE}%</em></span>"),
			2 : jindo.$Template("<span class='up'>{=NV} <em><img src='https://ssl.pstatic.net/static/nfinance/ico_up.gif' width='7' height='6' alt='상승'>{=RATE}%</em></span>"),
			3 : jindo.$Template("<span class='same'>{=NV} <em><img src='https://ssl.pstatic.net/static/nfinance/ico_same2.gif' width='10' height='6' alt='보합'>{=RATE}%</em></span>"),
			4 : jindo.$Template("<span class='down'>{=NV} <em><img src='https://ssl.pstatic.net/static/nfinance/ico_down2.gif' width='7' height='11' alt='하한'>{=RATE}%</em></span>"),
			5 : jindo.$Template("<span class='down'>{=NV} <em><img src='https://ssl.pstatic.net/static/nfinance/ico_down.gif' width='7' height='6' alt='하락'>{=RATE}%</em></span>")
		},
		basisValue : [
			["<span>", "<img src='https://ssl.pstatic.net/imgfinance/finance/btn_contango.gif' width='33' height='17' alt='콘탱고'></span>"],
			["<span>", "<img src='https://ssl.pstatic.net/imgfinance/finance/btn_backwar.gif' width='49' height='17' alt='백워데이션'></span>"],
			["<span>", "</span>"]
		]
	},

	/**
	 * Polling 모듈 초기화
	 */
	init : function() {
		var sApiUrl = "https://polling.finance.naver.com/api/realtime";

		this._oAjax = jindo.$Ajax(sApiUrl, {
			type : "jsonp",
			jsonp_charset : "euc-kr",
			onload : jindo.$Fn(function(response) {
				if(response != null && response.readyState() == 4) {
					try {
						this.refreshQuote(response.json());
					} catch(e) {
					} finally {
						response = null;
					}
						this._startTimer();
					}
				}, this).bind(),
				timeout : 2,
				ontimeout : jindo.$Fn(function() {
					this._startTimer();
				}, this).bind()
			});
		this.call();
		},

		/**
		 * 시세처리 타이머 시작
		 */
		_startTimer : function() {
			this.clearTimer();
			this._oTimer = setInterval(jindo.$Fn(function() {
				this.call();
			}, this).bind(), this._nInterval);
		},

		/**
		 * 시세처리 타이머 종료
		 */
		clearTimer : function() {
			if(this._oAjax && !this._oAjax.isIdle()) {
				this._oAjax.abort();
			}

			clearInterval(this._oTimer);
		},

		/**
		 * Ajax 요청
		 */
		call : function() {
			this.clearTimer();
			this._oAjax.request({
				"query" : this._sAjaxQuery + (itemcodes != null && itemcodes != "" ? "|SERVICE_ITEM:" + itemcodes : "")
			});
		},

		/**
		 * 전달받는 data를 지표영역에 반영한다.
		 * @param {Object} res AJAX 반환값
		 */
		refreshQuote : function(res) {
			var oResult = res.result;
			if(res != null && res.resultCode == 'success') {
				if(oResult != null) {
					this._nInterval = oResult.pollingInterval;
					for(var i = 0, el; el = oResult.areas[i]; i++) {
						if(el.name == "SERVICE_INDEX") {
							this._elTime.innerHTML = displayTime(el.datas[0].ms, el.datas[0].aq, oResult.time);
							this._aElQuot.forEach(jindo.$Fn(function(oElement, dataIndex) {
								var cvClass = "",
									sign = "",
									signText = "",
									cv = el.datas[dataIndex].cv,
									cr = el.datas[dataIndex].cr,
									nv = el.datas[dataIndex].nv,
									wel = jindo.$Element(oElement);

								if (cv > 0) {
									cvClass = "num_quot up";
									sign = "+";
									signText = "상승";
								} else if (cv < 0) {
									cvClass = "num_quot dn";
									sign = "-";
									signText = "하락";
									cv = cv * -1;
									cr = cr * -1;
								} else {
									cvClass = "num_quot";
									signText = "보합";
								}

								wel.className(cvClass);
								wel.html(this._oTemplate.market.process({
									NUM1 : changeNumberFormat((nv/100).toFixed(2)),
									NUM2 : (cv/100).toFixed(2),
									NUM3 : cr.toFixed(2),
									SIGN : sign,
									SIGN_TEXT : signText
								}));

							}, this).bind());

							// 베이시스 추가
							// 선물 - 코스피200
							var nBasis = el.datas[2].bs,
								nBasisFixed = (nBasis/100).toFixed(2),
								sBasisText = "",
								sBasisClassName = "dd",
								nBasisTemplateIndex = 2;
								sBasisSign = "";

							// 예상지수인 경우 베이시스는 0으로 초기화한다. 예상지수로 베이시스를 구할수는 없기때문이다.
							if (el.datas[2].ms == 'PREOPEN') {
								nBasis = 0;
								nBasisFixed = 0;
							}

							if(nBasis > 0) {
								sBasisText = "콘탱고";
								sBasisClassName += " up";
								nBasisTemplateIndex = 0;
								sBasisSign = "+";
							} else if (nBasis < 0){
								sBasisText = "백워데이션";
								sBasisClassName += " dn";
								nBasisTemplateIndex = 1;
							}

							this._welBasisName.html(sBasisText);
							this._welBasisValue.className(sBasisClassName);
							this._welBasisValue.html(this._oTemplate.basisValue[nBasisTemplateIndex].join(sBasisSign+nBasisFixed));

						} else if (el.name == "SERVICE_ITEM") {
							for(var j=0, elArea; elArea = el.datas[j]; j++) {
							    var _elTabElement = jindo.$A(jindo.$$("ul", jindo.$$.getSingle(".tab_list"))).get(parseInt(j / 5)),
									nChangeRate = (Math.abs(Number(elArea.cr))).toFixed(2),
									nChangeNV = changeNumberFormat(elArea.nv),
									welTabList = jindo.$Element(_elTabElement).child()[j % 5];

								if(j < 29) {
									welTabList.last().leave();
									welTabList.append(this._oTemplate.rf[elArea.rf].process({
										NV : nChangeNV,
										RATE : nChangeRate
									}));
								}
							}
						}
					}
				}
			}
		}
};

// 1분마다 정보 업데이트
var updateInformationInterval = 60000;
var informationTimer = null;
var oUpdateAjax = null;

var startInformationTimer = function() {
	clearInformationTimer();
	informationTimer = setInterval('doUpdateInformation()', updateInformationInterval);
}

var clearInformationTimer = function() {
	if (oUpdateAjax) {
		oUpdateAjax.abort();
		oUpdateAjax = null;
	}

	informationTimer = window.clearInterval(informationTimer);
}

var doUpdateInformation = function() {
	var sApiUrl = "https://api.finance.naver.com/service/mainSummary.naver";

	oUpdateAjax = jindo.$Ajax(sApiUrl, {
		type : "jsonp",
		jsonp_charset : "utf-8",
		onload : function(oRes) {
			if(oRes != null && oRes.readyState() == 4) {
				var result = oRes.json().message.result;
				if(result != null) {
					var todayIndexDealTrendList = result.todayIndexDealTrendList; // 투자매매동향
					var todayIndexItemList = result.todayIndexItemList; // 등락종목 개수
					var kospiTrendProgram = result.kospiTrendProgram; // 프로그램
					var groupTopList = result.groupTopList; // 업종상위
					var themeTopList = result.themeTopList; // 테마상위
					var topItems = result.topItems; // TOP종목 (거래상위, 상한, 하한, 시가총액상위)
					var searchList = result.searchList; // 인기 검색 종목

					// 오늘의 증시 코스피, 코스닥 투자매매동향 등락종목 개수
					jindo.$A(jindo.$$(".dsc_area")).forEach(function(value, index) {
						if ( index < 2 ) {
							var todayIndexDealTrend = todayIndexDealTrendList[index];
							var todayIndexItem = todayIndexItemList[index];
							var todayIndexDealTrendLink = new Array("/sise/sise_trans_style.naver?sosok=01", "/sise/sise_trans_style.naver?sosok=02");

							var oTemplate = jindo.$Template("todayIndexItemTemplate");
							var values = jindo.$H(getDealTrendTemplateValues(todayIndexDealTrend));
							var tmpMap1 = jindo.$H(getFluctuationTemplateValues(todayIndexItem));
							var tmpMap2 = jindo.$H(getIndexItemLinkTemplateValues(todayIndexDealTrendLink, index));

							tmpMap1.forEach(function(v, k, o) {
								values.add(k, v);
							});

							tmpMap2.forEach(function(v, k, o) {
								values.add(k, v);
							});

							jindo.$Element(value).html(oTemplate.process(values.$value()));
						}
					}, this);

					// 오늘의 증시 코스피200 투자매매동향
					jindo.$Element(jindo.$$.getSingle(".dsc_area2")).html(jindo.$Template("todayKpi200Template").process(getDealTrendTemplateValues(todayIndexDealTrendList[2])));

					// 오늘의 증시 코스피200 프로그램
					var trendProgram = new TrendProgram(kospiTrendProgram);
					var kospiDifferenceReal = trendProgram.getDifferenceReal();
					var kospiBiDifferenceReal = trendProgram.getBiDifferenceReal();
					var kospiTotalReal = trendProgram.getTotalReal()

					var kospiProgramClass = "dd2 " + setUpDnClass(kospiTotalReal);

					kospiTotalReal = changeNumberFormat(Math.round(kospiTotalReal/100000000));
					kospiTotalReal = (kospiBiDifferenceReal + kospiDifferenceReal > 0) ? "+" + kospiTotalReal : "" + kospiTotalReal;

					var elKospiProgram = jindo.$Element(jindo.$$.getSingle("#_kospiProgram"));
					elKospiProgram.className(kospiProgramClass);

					var sHtml = "";
					sHtml = "<a href='/sise/sise_program.naver?sosok=01' onClick='clickcr(this, \"tsc*o.program\", \"\", \"\", event);'>" + kospiTotalReal + "<span>억</span></a>";
					elKospiProgram.html(sHtml);

					// 업종상위
					jindo.$A(jindo.$$(".section_top_first .list_rank li")).forEach(function(oElement, index) {
						var groupTopItem = groupTopList[index];
						var uiCount = index + 1;
						var typeNo = groupTopItem.typeNo;
						var typeChangeRate = groupTopItem.typeChangeRate;

						var sHtml = "";

						sHtml += "<span class='info_num info_num" + uiCount + "'><span class='blind'>" + uiCount + "</span></span><p class='item'><a href='/sise/sise_group_detail.naver?type=upjong&no=" + typeNo + "' onClick='clickcr(this, \"tos.cat" + uiCount + "\", \"upjong_" + typeNo +"\", \"\", event);'>";
						sHtml += "<strong>" + cutStringByByte(groupTopItem.typeName, 15, "..") + "</strong></a>";

						if (typeChangeRate > 0) {
							sHtml += "<em class='up'>+" + changeNumberFormat(typeChangeRate.toFixed(2)) + "%</em>";
						} else if (typeChangeRate < 0) {
							sHtml += "<em class='down'>" + changeNumberFormat(typeChangeRate.toFixed(2)) + "%</em>";
						} else {
							sHtml += "<em class='steady'>" + changeNumberFormat(typeChangeRate.toFixed(2)) + "%</em>";
						}
						sHtml += "</p>";

						for (i = 0; i < groupTopItem.itemList.length; i++) {
							var groupTopDetailItem = groupTopItem.itemList[i];
							var code = groupTopDetailItem.code;
							var changeRate = groupTopDetailItem.changeRate;

							sHtml += "<p>";
							sHtml += "<a href='/item/main.naver?code=" + code + "' onClick='clickcr(this, \"tos.list" + i + "\", \""+ code + "\", \"" + i + "\", event);'>";
							sHtml += cutStringByByte(groupTopDetailItem.name, 10, "..") + "</a>";

							if (changeRate > 0) {
								sHtml += "<em class='up'>+" + changeNumberFormat(changeRate.toFixed(2)) + "%</em>";
							} else if (changeRate < 0) {
								sHtml += "<em class='down'>" + changeNumberFormat(changeRate.toFixed(2)) + "%</em>";
							} else {
								sHtml += "<em class='steady'>" + changeNumberFormat(changeRate.toFixed(2)) + "%</em>";
							}
							sHtml += "</p>";
						}

						jindo.$Element(oElement).html(sHtml);

					}, this);

					// 테마상위
					jindo.$A(jindo.$$(".group_top .list_rank li")).forEach(function(value, index) {
						var themeTopItem = themeTopList[index];
						var uiCount = index + 1;

						var sHtml = "";
						sHtml += "<span class='info_num info_num" + uiCount + "'><span class='blind'>" + uiCount + "</span></span><p class='item'><a href='/sise/sise_group_detail.naver?type=theme&no=" + themeTopItem.typeNo + "' onClick='clickcr(this, \"pol.type" + uiCount + "\", \"thema_" + themeTopItem.typeNo +"\", \"\", event);'>";
						sHtml += "<strong>" + cutStringByByte(themeTopItem.typeName, 15, "..") + "</strong></a>";

						if (themeTopItem.typeChangeRate > 0) {
							sHtml += "<em class='up'>+" + changeNumberFormat(themeTopItem.typeChangeRate.toFixed(2)) + "%</em>";
						} else if (themeTopItem.typeChangeRate < 0) {
							sHtml += "<em class='down'>" + changeNumberFormat(themeTopItem.typeChangeRate.toFixed(2)) + "%</em>";
						} else {
							sHtml += "<em class='steady'>" + changeNumberFormat(themeTopItem.typeChangeRate.toFixed(2)) + "%</em>";
						}
						sHtml += "</p>";

						for (i = 0; i < themeTopItem.itemList.length; i++) {
							var themeTopDetailItem = themeTopItem.itemList[i];

							sHtml += "<p>";
							sHtml += "<a href='/item/main.naver?code=" + themeTopDetailItem.code + "' onClick='clickcr(this, \"tos.list" + i + "\", \""+ themeTopDetailItem.code + "\", \"" + i + "\", event);'>";
							sHtml += cutStringByByte(themeTopDetailItem.name, 10, "..") + "</a>";

							if (themeTopDetailItem.changeRate > 0) {
								sHtml += "<em class='up'>+" + changeNumberFormat(themeTopDetailItem.changeRate.toFixed(2)) + "%</em>";
							} else if (themeTopDetailItem.changeRate < 0) {
								sHtml += "<em class='down'>" + changeNumberFormat(themeTopDetailItem.changeRate.toFixed(2)) + "%</em>";
							} else {
								sHtml += "<em class='steady'>" + changeNumberFormat(themeTopDetailItem.changeRate.toFixed(2)) + "%</em>";
							}
							sHtml += "</p>";
						}

						jindo.$Element(value).html(sHtml);

					});

					// 거래상위
					jindo.$A(jindo.$$("#_topItems1 tr")).forEach(function(value, index) {
						var topItem = topItems[0][index];
						var changeVal = topItem.changeVal;
						var changeRate = topItem.changeRate;
						var uiCount = index + 1;
						var itemcode = topItem.code;

						setUpDownClass(changeVal, value);

						var sHtml = "";
						sHtml += "<th><a href='/item/main.naver?code=" + itemcode + "' onClick='clickcr(this, \"spe.slist\", \"" + itemcode + "\", \"" + uiCount + "\", event);'>";
						sHtml += topItem.name + "</a></th>";
						sHtml += "<td>" + changeNumberFormat(topItem.nowVal) + "</td>";

						if (changeRate> 0) {
							sHtml += "<td><em class='bu_p bu_pup'><span class='blind'>상승</span></em> " + changeNumberFormat(changeVal) + "</td>";
							sHtml += "<td>+" + changeRate.toFixed(2)+ "%</td>";
						} else if (changeRate < 0) {
							changeRate = changeRate * -1;
							changeVal = changeVal * -1;
							sHtml += "<td><em class='bu_p bu_pdn'><span class='blind'>하락</span></em> " + changeNumberFormat(changeVal) + "</td>";
							sHtml += "<td>-" + changeRate.toFixed(2) + "%</td>";
						} else {
							sHtml += "<td><em class='bu_p bu_pn'><span class='blind'>보합</span></em></td>";
							sHtml += "<td>" + changeRate.toFixed(2) + "%</td>";
						}

						jindo.$Element(value).html(sHtml);
					});

					// 상승
					jindo.$A(jindo.$$("#_topItems2 tr")).forEach(function(value, index) {
						var topItem = topItems[1][index];

						if (topItem) {
							var changeVal = topItem.changeVal;
							var changeRate = topItem.changeRate;
							var risefall = topItem.risefall;
							var uiCount = index + 1;
							var itemcode = topItem.code;

							setUpDownClass(changeVal, value);

							var sHtml = "";
							sHtml += "<th><a href='/item/main.naver?code=" + itemcode + "' onClick='clickcr(this, \"spe.clist\", \"" + itemcode + "\", \"" + uiCount + "\", event);'>";
							sHtml += topItem.name + "</a></th>";
							sHtml += "<td>" + changeNumberFormat(topItem.nowVal) + "</td>";


							if (changeVal != 0) {
								if (risefall == '1') {
									sHtml += "<td><em class='bu_p bu_pup2'><span class='blind'>상한가</span></em> " + changeNumberFormat(changeVal) + "</td>";
								} else {
									sHtml += "<td><em class='bu_p bu_pup'><span class='blind'>상승</span></em> " + changeNumberFormat(changeVal) + "</td>";
								}
								sHtml += "<td>+" + changeRate.toFixed(2)+ "%</td>";
							} else {
								sHtml += "<td><em class='bu_p bu_pn'><span class='blind'>보합</span></em></td>";
								sHtml += "<td>" + changeRate.toFixed(2) + "%</td>";
							}

							jindo.$Element(value).html(sHtml);
						}
					});

					// 하락
					jindo.$A(jindo.$$("#_topItems3 tr")).forEach(function(value, index) {
						var topItem = topItems[2][index];

						if (topItem) {
							var changeVal = topItem.changeVal;
							var changeRate = topItem.changeRate;
							var risefall = topItem.risefall;
							var uiCount = index + 1;
							var itemcode = topItem.code;

							setUpDownClass(changeVal, value);

							var sHtml = "";
							sHtml += "<th><a href='/item/main.naver?code=" + itemcode + "' onClick='clickcr(this, \"spe.blist\", \"" + itemcode + "\", \"" + uiCount + "\", event);'>";
							sHtml += topItem.name + "</a></th>";
							sHtml += "<td>" + changeNumberFormat(topItem.nowVal) + "</td>";

							if (changeVal != 0) {
								changeRate = changeRate * -1;
								changeVal = changeVal * -1;
								if (risefall == '4') {
									sHtml += "<td><em class='bu_p bu_pdn2'><span class='blind'>하한가</span></em> " + changeNumberFormat(changeVal) + "</td>";
								} else {
									sHtml += "<td><em class='bu_p bu_pdn'><span class='blind'>하락</span></em> " + changeNumberFormat(changeVal) + "</td>";
								}
								sHtml += "<td>-" + changeRate.toFixed(2) + "%</td>";
							} else {
								sHtml += "<td><em class='bu_p bu_pn'><span class='blind'>보합</span></em></td>";
								sHtml += "<td>" + changeRate.toFixed(2) + "%</td>";
							}

							jindo.$Element(value).html(sHtml);
						}
					});


					// 시가총액 상위
					jindo.$A(jindo.$$("#_topItems4 tr")).forEach(function(value, index) {
						var topItem = topItems[3][index];
						var changeVal = topItem.changeVal;
						var changeRate = topItem.changeRate;
						var uiCount = index + 1;
						var itemcode = topItem.code;

						setUpDownClass(changeVal, value);

						var sHtml = "";
						sHtml += "<th><a href='/item/main.naver?code=" + itemcode + "' onClick='clickcr(this, \"spe.clist\", \"" + itemcode + "\", \"" + uiCount + "\", event);'>";
						sHtml += topItem.name + "</a></th>";
						sHtml += "<td>" + changeNumberFormat(topItem.nowVal) + "</td>";

						if (changeRate> 0) {
							sHtml += "<td><em class='bu_p bu_pup'><span class='blind'>상승</span></em> " + changeNumberFormat(changeVal) + "</td>";
							sHtml += "<td>+" + changeRate.toFixed(2)+ "%</td>";
						} else if (changeRate < 0) {
							changeRate = changeRate * -1;
							changeVal = changeVal * -1;
							sHtml += "<td><em class='bu_p bu_pdn'><span class='blind'>하락</span></em> " + changeNumberFormat(changeVal) + "</td>";
							sHtml += "<td>-" + changeRate.toFixed(2) + "%</td>";
						} else {
							sHtml += "<td><em class='bu_p bu_pn'><span class='blind'>보합</span></em></td>";
							sHtml += "<td>" + changeRate.toFixed(2) + "%</td>";
						}

						jindo.$Element(value).html(sHtml);
					});

					// 인기 검색 종목
					jindo.$A(jindo.$$(".aside_popular tbody tr")).forEach(function(value, index) {
						var popularItem = searchList[index];
						var uiCount = index + 1;
						var changeVal = popularItem.changeVal;
						var itemcode = popularItem.itemcode;

						setUpDownClass(changeVal, value);

						var sHtml = "";
						sHtml += "<th scope=\'row\'><em>" + uiCount + ".</em><a href=\'/item/main.naver?code=" + itemcode + "\' onClick='clickcr(this, \"boa.list\", \"" + itemcode + "\", \"" + uiCount + "\", event);'>";
						sHtml += cutStringByByte(popularItem.itemname, 12, "..") + "</a></th>";
						sHtml += "<td>" + changeNumberFormat(popularItem.nowVal) + "</td>";

						if (popularItem.risefall == 1) {
							sHtml += "<td><em class=\'bu_p bu_pup2\'><span class=\'blind\'>상한가</span></em><span class=\'tah p11 red02\'> " + changeNumberFormat(changeVal) + " </span></td>";
						} else if (popularItem.risefall == 2) {
							sHtml += "<td><em class=\'bu_p bu_pup'><span class=\'blind\'>상승</span></em><span class=\'tah p11 red02\'> " + changeNumberFormat(changeVal) + " </span></td>";
						} else if (popularItem.risefall == 3) {
							sHtml += "<td><span class=\'tah p11\'> 0 </span></td>";
						} else if (popularItem.risefall == 4) {
							changeVal = changeVal * -1;
							sHtml += "<td><em class=\'bu_p bu_pdn2\'><span class=\'blind\'>하한가</span></em><span class=\'tah p11 nv01\'> " + changeNumberFormat(changeVal) + " </span></td>";
						} else{
							changeVal = changeVal * -1;
							sHtml += "<td><em class=\'bu_p bu_pdn'\><span class=\'blind\'>하락</span></em><span class=\'tah p11 nv01\'> " + changeNumberFormat(changeVal) + " </span></td>";
						}

						jindo.$Element(value).html(sHtml);

					});

					startInformationTimer();
				}
			}
		},
		timeout : 2,
		ontimeout : function() {
			startInformationTimer();
		},
		async : true
	});
	oUpdateAjax.request();
}

function getIndexItemLinkTemplateValues(todayIndexDealTrendLink, index) {
	values = {
			_todayIndexDealTrendLink : todayIndexDealTrendLink[index],
			_todayIndexItemUpperLink : "/sise/sise_upper.naver?sosok=" + index,
			_todayIndexItemRiseLink : "/sise/sise_rise.naver?sosok=" + index,
			_todayIndexItemSteadyLink : "/sise/sise_steady.naver?sosok=" + index,
			_todayIndexItemFallLink : "/sise/sise_fall.naver?sosok=" + index,
			_todayIndexItemLowerLink : "/sise/sise_lower.naver?sosok=" + index
	};

	return values;
}

// up, down, same 클래스 생성 기능
function setUpDownClass(sChangeVal, eValue) {
	if (sChangeVal > 0) {
		jindo.$Element(eValue).className("up");
	} else if (sChangeVal < 0) {
		jindo.$Element(eValue).className("down");
	} else {
		jindo.$Element(eValue).className("same");
	}
}

function setUpDnClass(value){
	var className = "";
	if (value > 0){
		className = "up";
	} else if(value < 0){
		className = "dn";
	}

	return className;
}

function mainPageDomReadyFn() {
	doUpdateInformation();
	Polling.init();
}

function togglePannel(layerId) {
    var elTargetLayer = jindo.$Element(jindo.$$.getSingle("#" + layerId));

    if (elTargetLayer != null) {
        if (elTargetLayer.visible()) {
            hidePannel(layerId);
        } else {
            showPannel(layerId);
        }
    }
}

function showPannel(layerId){
	var layer = jindo.$(layerId);
	layer.style.display='block';
}

function hidePannel(layerId){
	var layer = jindo.$(layerId);
	layer.style.display='none';
}

// 1분 리플레시, 실시간 시세 폴링, 이미지 리플레시
jindo.$Fn(mainPageDomReadyFn).attach(document, "domready");

</script>   
 
</body></html>

)_";