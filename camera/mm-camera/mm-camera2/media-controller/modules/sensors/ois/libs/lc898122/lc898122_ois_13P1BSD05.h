/*============================================================================

  Copyright (c) 2014-2015 Qualcomm Technologies, Inc. All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.

============================================================================*/

/*FW version*/
#define    MDL_VER      0x03
#define    FW_VER       0x05

#define    MAXLMT       0x40000000
#define    MINLMT       0x3F8CCCCD
#define    CHGCOEF      0xBA4C71C7
#define    MINLMT_MOV   0x00000000
#define    CHGCOEF_MOV  0xB9700000

#define    BIAS_CUR_OIS  0x33
#define    AMP_GAIN_X    0x05
#define    AMP_GAIN_Y    0x05

/*AF Open para*/
#define    RWEXD1_L_AF    0x7FFF
#define    RWEXD2_L_AF    0x1094
#define    RWEXD3_L_AF    0x72BA
#define    FSTCTIME_AF    0xF1
#define    FSTMODE_AF     0x01

#define    A3_IEXP3    0x3EC0017F
#define    A1_IEXP1    0x3F180130

#define    SXQ_INI      0x3F800000
#define    SYQ_INI      0xBF800000

#define    GXGAIN_INI    0xBF147AE1
#define    GYGAIN_INI    0xBF147AE1

#define    GYROX_INI    0x43
#define    GYROY_INI    0x45

#define    GXHY_GYHX    0

#define    DIFIL_S2    0x3F7FFE00

/*servo equalizer X*/
#define  fvWH_DWNSMP1    0x00
#define  fvSXRIA      0x3f800000
#define  fvSXRIB      0x00000000
#define  fvSXRIC      0x00000000
#define  fvSXGGF      0x00000000
#define  fvSXAG      0x3f353c00
#define  fvSXDA      0x3f944ec0
#define  fvSXDB      0xbf925540
#define  fvSXDC      0x3f5414c0
#define  fvSXEA      0x3f800000
#define  fvSXEB      0x00000000
#define  fvSXEC      0x00000000
#define  fvSXFA      0x3fff64c0
#define  fvSXFB      0x00000000
#define  fvSXUA      0x3d506f00
#define  fvSXUB      0x3d506f00
#define  fvSXUC      0x3f65f240
#define  fvSXIA      0x3c208400
#define  fvSXIB      0x3c208400
#define  fvSXIC      0x3f7fe940
#define  fvSXJA      0x3e1d2100
#define  fvSXJB      0xbe1c0980
#define  fvSXJC      0x3f7f5080
#define  fvSXFC      0x3f800000
#define  fvSXG      0x3f800000
#define  fvSXG2      0x3f800000
#define  fvSXSA      0x41fcfb80
#define  fvSXSB      0x00000000
#define  fvSXSC      0x00000000
#define  fvSXOA      0x3f614dc0
#define  fvSXOB      0xbfc6aa80
#define  fvSXOC      0x3fc6aa80
#define  fvSXOD      0x3f44e940
#define  fvSXOE      0xbf263740
#define  fvSXPA      0x3dd17800
#define  fvSXPB      0x3dd17800
#define  fvSXPC      0x3f4ba200
#define  fvSXPD      0x00000000
#define  fvSXPE      0x00000000
#define  fvSXQ      0x3f800000
#define  fvSMXA      0x00000000
#define  fvSMXB      0x00000000
#define  fvSMXGB      0x00000000
#define  fvSMXGA      0x3f800000
/*servo equalizer Y*/
#define  fvSYRIA      0x3f800000
#define  fvSYRIB      0x00000000
#define  fvSYRIC      0x00000000
#define  fvSYGGF      0x00000000
#define  fvSYAG      0x3f353c00
#define  fvSYDA      0x3f944ec0
#define  fvSYDB      0xbf925540
#define  fvSYDC      0x3f5414c0
#define  fvSYEA      0x3f800000
#define  fvSYEB      0x00000000
#define  fvSYEC      0x00000000
#define  fvSYFA      0x3fff64c0
#define  fvSYFB      0x00000000
#define  fvSYUA      0x3d506f00
#define  fvSYUB      0x3d506f00
#define  fvSYUC      0x3f65f240
#define  fvSYIA      0x3c208400
#define  fvSYIB      0x3c208400
#define  fvSYIC      0x3f7fe940
#define  fvSYJA      0x3e1d2100
#define  fvSYJB      0xbe1c0980
#define  fvSYJC      0x3f7f5080
#define  fvSYFC      0x3f800000
#define  fvSYG      0x3f800000
#define  fvSYG2      0x3f800000
#define  fvSYSA      0x41fcfb80
#define  fvSYSB      0x00000000
#define  fvSYSC      0x00000000
#define  fvSYOA      0x3f614dc0
#define  fvSYOB      0xbfc6aa80
#define  fvSYOC      0x3fc6aa80
#define  fvSYOD      0x3f44e940
#define  fvSYOE      0xbf263740
#define  fvSYPA      0x3dd17800
#define  fvSYPB      0x3dd17800
#define  fvSYPC      0x3f4ba200
#define  fvSYPD      0x00000000
#define  fvSYPE      0x00000000
#define  fvSYQ      0x3f800000
#define  fvSMYA      0x00000000
#define  fvSMYB      0x00000000
#define  fvSMYGB      0x00000000
#define  fvSMYGA      0x3f800000
/*gyro equalizer X*/
#define  fvWG_DWNSMP1    0x00
#define  fvWG_DWNSMP3    0x00
#define  fvGXGYRO    0x3f800000
#define  fvGXIA      0x3828a700
#define  fvGXIB      0x3828a700
#define  fvGXIC      0x3f7ffac0
#define  fvGXGGAIN    0x3f800000
#define  fvGXIGAIN    0xbf800000
#define  fvGX2X4XF    0x3f800000
#define  fvGXADJ      0x3f800000
#define  fvGXGAIN    0x3f800000
#define  fvGXH1A      0x3da2ad80
#define  fvGXH1B      0x00000000
#define  fvGXH1C      0x3f7ffe00
#define  fvGXH2A      0x3fb26dc0
#define  fvGXH2B      0xbfb00dc0
#define  fvGXH2C      0x3f75e8c0
#define  fvGXH3A      0x3f2000c0
#define  fvGXH3B      0xbf1ffd40
#define  fvGXH3C      0x3f7ffc80
#define  fvGXHGAIN    0x3f800000
#define  fvGXMA      0x3f800000
#define  fvGXMB      0x00000000
#define  fvGXMC      0x00000000
#define  fvGXMG      0x00000000
#define  fvGXHCTMP    0x3f800000
#define  fvGXLA      0x3f800000
#define  fvGXLB      0x00000000
#define  fvGXLC      0x00000000
#define  fvGXLGAIN    0x00000000
#define  fvGXZOOM    0x3f800000
#define  fvGX2X4XB    0x3f800000
#define  fvGXLENS    0x3f800000
#define  fvGXTA      0x3f800000
#define  fvGXTB      0x00000000
#define  fvGXTC      0x00000000
#define  fvGXTD      0x00000000
#define  fvGXTE      0x00000000
/*gyro equalizer Y*/
#define  fvGYGYRO    0x3f800000
#define  fvGYIA      0x3828a700
#define  fvGYIB      0x3828a700
#define  fvGYIC      0x3f7ffac0
#define  fvGYGGAIN    0x3f800000
#define  fvGYIGAIN    0xbf800000
#define  fvGY2X4XF    0x3f800000
#define  fvGYADJ      0x3f800000
#define  fvGYGAIN    0x3f800000
#define  fvGYH1A      0x3da2ad80
#define  fvGYH1B      0x00000000
#define  fvGYH1C      0x3f7ffe00
#define  fvGYH2A      0x3fb26dc0
#define  fvGYH2B      0xbfb00dc0
#define  fvGYH2C      0x3f75e8c0
#define  fvGYH3A      0x3f2000c0
#define  fvGYH3B      0xbf1ffd40
#define  fvGYH3C      0x3f7ffc80
#define  fvGYHGAIN    0x3f800000
#define  fvGYMA      0x3f800000
#define  fvGYMB      0x00000000
#define  fvGYMC      0x00000000
#define  fvGYMG      0x00000000
#define  fvGYHCTMP    0x3f800000
#define  fvGYLA      0x3f800000
#define  fvGYLB      0x00000000
#define  fvGYLC      0x00000000
#define  fvGYLGAIN    0x00000000
#define  fvGYZOOM    0x3f800000
#define  fvGY2X4XB    0x3f800000
#define  fvGYLENS    0x3f800000
#define  fvGYTA      0x3f800000
#define  fvGYTB      0x00000000
#define  fvGYTC      0x00000000
#define  fvGYTD      0x00000000
#define  fvGYTE      0x00000000
/*closedaf equalizer*/
#define  fvWAF_DWNSMP2    0x00
#define  fvWAF_DWNSMP1    0x00
#define  fvAFING      0x3f800000
#define  fvAFSTMG    0x3f800000
#define  fvAFSTMC    0x3f800000
#define  fvAFSTMB    0x3f800000
#define  fvAFSTMA    0x3f800000
#define  fvAFAG      0x3f800000
#define  fvAFDA      0x3f800000
#define  fvAFDB      0x00000000
#define  fvAFDC      0x00000000
#define  fvAFEA      0x3f800000
#define  fvAFEB      0x00000000
#define  fvAFEC      0x00000000
#define  fvAFFA      0x3f800000
#define  fvAFFB      0x3f800000
#define  fvAFUA      0x3f800000
#define  fvAFUB      0x00000000
#define  fvAFUC      0x00000000
#define  fvAFIA      0x3f800000
#define  fvAFIB      0x00000000
#define  fvAFIC      0x00000000
#define  fvAFJA      0x3f800000
#define  fvAFJB      0x00000000
#define  fvAFJC      0x00000000
#define  fvAFFC      0x3f800000
#define  fvAFG      0x3f800000
#define  fvAFG2      0x3f800000
#define  fvAFPA      0x00000000
#define  fvAFPB      0x00000000
#define  fvAFPC      0x00000000
#define  fvAFPD      0x00000000
#define  fvAFPE      0x00000000
/*angleconv equalizer*/
#define  fvWG_DWNSMP4    0x00
#define  fvGX45G      0x3f800000
#define  fvGX45X      0x3f800000
#define  fvGY45G      0x3f800000
#define  fvGY45Y      0x3f800000
#define  fvSYINY      0x3f800000
#define  fvSXGX      0x3f800000
#define  fvSYGY      0x3f800000
#define  fvSXINY      0x00000000
#define  fvSYINX      0x00000000
#define  fvGX45Y      0x00000000
#define  fvGY45X      0x00000000
#define  fvSXGY      0x00000000
#define  fvSYGX      0x00000000
#define  fvSXINX      0x3f800000
/*measure equalizer*/
#define  fvMES1AA    0x3f800000
#define  fvMES1AB    0x00000000
#define  fvMES1AC    0x00000000
#define  fvMES1AD    0x00000000
#define  fvMES1AE    0x00000000
#define  fvMES1BA    0x3f800000
#define  fvMES1BB    0x00000000
#define  fvMES1BC    0x00000000
#define  fvMES1BD    0x00000000
#define  fvMES1BE    0x00000000
#define  fvMES2AA    0x3f800000
#define  fvMES2AB    0x00000000
#define  fvMES2AC    0x00000000
#define  fvMES2AD    0x00000000
#define  fvMES2AE    0x00000000
#define  fvMES2BA    0x3f800000
#define  fvMES2BB    0x00000000
#define  fvMES2BC    0x00000000
#define  fvMES2BD    0x00000000
#define  fvMES2BE    0x00000000
/*sineamp equalizer*/
#define  fvSXSIN      0x3f800000
#define  fvSYSIN      0x3f800000
#define  fvAFSIN      0x00000000
/*gyroLD equalizer*/
#define  fvGXLEVA    0x3bda2580
#define  fvGXLEVB    0x3bda2580
#define  fvGXLEVC    0x3f7c9780
#define  fvGYLEVA    0x3bda2580
#define  fvGYLEVB    0x3bda2580
#define  fvGYLEVC    0x3f7c9780
/*gyroTVJ equalizer*/
#define  fvPXMAA      0x3c58b440
#define  fvPXMAB      0x3c58b440
#define  fvPXMAC      0x3f793a40
#define  fvPXMBA      0x3c58b440
#define  fvPXMBB      0x3c58b440
#define  fvPXMBC      0x3f793a40
#define  fvPYMAA      0x3c58b440
#define  fvPYMAB      0x3c58b440
#define  fvPYMAC      0x3f793a40
#define  fvPYMBA      0x3c58b440
#define  fvPYMBB      0x3c58b440
#define  fvPYMBC      0x3f793a40
#define  fvST1MEAN    0x3f800000
#define  fvST2MEAN    0x3f800000
#define  fvST3MEAN    0x3f800000
#define  fvST4MEAN    0x3f800000
/*gyroxVPT equalizer*/
#define  fvGXIGAINSTP  0x3f800000
#define  fvGXJ1A      0x3f800000
#define  fvGXJ1B      0x00000000
#define  fvGXJ1C      0x00000000
#define  fvGXJ2A      0x3f800000
#define  fvGXJ2B      0x00000000
#define  fvGXJ2C      0x00000000
#define  fvGXIGAIN2    0x3f800000
#define  fvGXK1A      0x3f800000
#define  fvGXK1B      0x00000000
#define  fvGXK1C      0x00000000
#define  fvGXK2A      0x3f800000
#define  fvGXK2B      0x00000000
#define  fvGXK2C      0x00000000
#define  fvGXOA      0x3f800000
#define  fvGXOB      0x00000000
#define  fvGXOC      0x00000000
#define  fvGXOG1      0x3f800000
#define  fvGXOG2      0x3f800000
#define  fvGXOG3      0x3f800000
/*gyroyVPT equalizer*/
#define  fvGYIGAINSTP  0x3f800000
#define  fvGYJ1A      0x3f800000
#define  fvGYJ1B      0x00000000
#define  fvGYJ1C      0x00000000
#define  fvGYJ2A      0x3f800000
#define  fvGYJ2B      0x00000000
#define  fvGYJ2C      0x00000000
#define  fvGYIGAIN2    0x3f800000
#define  fvGYK1A      0x3f800000
#define  fvGYK1B      0x00000000
#define  fvGYK1C      0x00000000
#define  fvGYK2A      0x3f800000
#define  fvGYK2B      0x00000000
#define  fvGYK2C      0x00000000
#define  fvGYOA      0x3f800000
#define  fvGYOB      0x00000000
#define  fvGYOC      0x00000000
#define  fvGYOG1      0x3f800000
#define  fvGYOG2      0x3f800000
#define  fvGYOG3      0x3f800000
/*gyroxDPT equalizer*/
#define  fvGXGYRO1    0x3f800000
#define  fvGXGYROA    0x3f800000
#define  fvGXGYROB    0x3f800000
#define  fvGXGYROC    0x3f800000
#define  fvGXIA1      0x39d2bd40
#define  fvGXIB1      0x39d2bd40
#define  fvGXIC1      0x3f7fcb40
#define  fvGXIAA      0x388c8a40
#define  fvGXIBA      0x388c8a40
#define  fvGXICA      0x3f7ff740
#define  fvGXIAB      0x390c87c0
#define  fvGXIBB      0x390c87c0
#define  fvGXICB      0x3f7fee80
#define  fvGXIAC      0x398c8300
#define  fvGXIBC      0x398c8300
#define  fvGXICC      0x3f7fdcc0
#define  fvGXGAIN1    0x00000000
#define  fvGXGAINA    0x3f800000
#define  fvGXGAINB    0x3f800000
#define  fvGXGAINC    0x3f800000
#define  fvGXISTP    0x00000000
#define  fvGXISTP1    0x38d1b700
#define  fvGXISTPA    0x00000000
#define  fvGXISTPB    0x00000000
#define  fvGXISTPC    0x00000000
#define  fvGXLA1      0x3f800000
#define  fvGXLB1      0x00000000
#define  fvGXLC1      0x00000000
#define  fvGXLAA      0x3f800000
#define  fvGXLBA      0x00000000
#define  fvGXLCA      0x00000000
#define  fvGXLAB      0x3f800000
#define  fvGXLBB      0x00000000
#define  fvGXLCB      0x00000000
#define  fvGXLAC      0x3f800000
#define  fvGXLBC      0x00000000
#define  fvGXLCC      0x00000000
/*gyroyDPT equalizer*/
#define  fvGYGYRO1    0x3f800000
#define  fvGYGYROA    0x3f800000
#define  fvGYGYROB    0x3f800000
#define  fvGYGYROC    0x3f800000
#define  fvGYIA1      0x39d2bd40
#define  fvGYIB1      0x39d2bd40
#define  fvGYIC1      0x3f7fcb40
#define  fvGYIAA      0x388c8a40
#define  fvGYIBA      0x388c8a40
#define  fvGYICA      0x3f7ff740
#define  fvGYIAB      0x390c87c0
#define  fvGYIBB      0x390c87c0
#define  fvGYICB      0x3f7fee80
#define  fvGYIAC      0x398c8300
#define  fvGYIBC      0x398c8300
#define  fvGYICC      0x3f7fdcc0
#define  fvGYGAIN1    0x00000000
#define  fvGYGAINA    0x3f800000
#define  fvGYGAINB    0x3f800000
#define  fvGYGAINC    0x3f800000
#define  fvGYISTP    0x00000000
#define  fvGYISTP1    0x38d1b700
#define  fvGYISTPA    0x00000000
#define  fvGYISTPB    0x00000000
#define  fvGYISTPC    0x00000000
#define  fvGYLA1      0x3f800000
#define  fvGYLB1      0x00000000
#define  fvGYLC1      0x00000000
#define  fvGYLAA      0x3f800000
#define  fvGYLBA      0x00000000
#define  fvGYLCA      0x00000000
#define  fvGYLAB      0x3f800000
#define  fvGYLBB      0x00000000
#define  fvGYLCB      0x00000000
#define  fvGYLAC      0x3f800000
#define  fvGYLBC      0x00000000
#define  fvGYLCC      0x00000000
