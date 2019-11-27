;----------------------------------------------------------------------
;
;			**  kapa.hex  **
;
;----------------------------------------------------------------------


L0000:	LD   A,(M3230)   		;0000 3A3032	<M3230>
	JR   NC,L0035    		;0003 3030	<L0035>
	JR   NC,L0037    		;0005 3030	<L0037>
	JR   NC,L003B    		;0007 3032	<L003B>
	JR   NC,L003B    		;0009 3030	<L003B>
	JR   NC,L003D    		;000B 3030	<L003D>
	LD   B,(HL)  			;000D 46
	LD   B,E     			;000E 43

	DEC  C       			;000F 0D

	LD   A,(BC)  			;0010 0A
	LD   A,(M3032)   		;0011 3A3230	<M3032>
	JR   NC,L0046    		;0014 3030	<L0046>
	JR   NC,L0048    		;0016 3030	<L0048>
	JR   NC,L004A    		;0018 3030	<L004A>
	INC  SP      			;001A 33
	LD   SP,M3038    		;001B 313830	<M3038>
	JR   C,L0051     		;001E 3831	<L0051>
	LD   B,L     			;0020 45
	LD   B,H     			;0021 44
	INC  (HL)    			;0022 34
	LD   (HL),43H  			;0023 3643	<43H>
	INC  SP      			;0025 33
	SCF          			;0026 37
	LD   B,E     			;0027 43
	JR   NC,L005C    		;0028 3032	<L005C>
	JR   C,L0061     		;002A 3835	<L0061>
	LD   (HL),46H  			;002C 3646	<46H>
	LD   B,H     			;002E 44
	JR   NC,L0063    		;002F 3032	<L0063>
	INC  (HL)    			;0031 34
	LD   B,E     			;0032 43
	ADD  HL,SP   			;0033 39
	JR   NC,L0066    		;0034 3030	<L0066>
	JR   NC,L0068    		;0036 3030	<L0068>
	JR   NC,L006A    		;0038 3030	<L006A>
	INC  SP      			;003A 33
L003B:	LD   B,C     			;003B 41
	JR   NC,L0070    		;003C 3032	<L0070>
	JR   C,L0070     		;003E 3830	<L0070>
	LD   B,C     			;0040 41
	JR   NC,L0086    		;0041 3043	<L0086>
	ADD  HL,SP   			;0043 39
	JR   NC,L0076    		;0044 3030	<L0076>
L0046:	JR   NC,L0078    		;0046 3030	<L0078>
L0048:	JR   NC,L007A    		;0048 3030	<L007A>
L004A:	DEC  (HL)    			;004A 35
	LD   B,L     			;004B 45
	LD   (M3533),A   		;004C 323335	<M3533>
	LD   (HL),32H  			;004F 3632	<32H>
L0051:	INC  SP      			;0051 33
	INC  (HL)    			;0052 34
	LD   (HL),32H  			;0053 3632	<32H>
	INC  SP      			;0055 33
	LD   SP,M3238    		;0056 313832	<M3238>
	INC  (HL)    			;0059 34
	LD   B,E     			;005A 43
	DEC  (HL)    			;005B 35
L005C:	DEC  C       			;005C 0D
	LD   A,(BC)  			;005D 0A
	LD   A,(M3032)   		;005E 3A3230	<M3032>
L0061:	JR   NC,L0093    		;0061 3030	<L0093>
L0063:	LD   (M3030),A   		;0063 323030	<M3030>
L0066:	JR   NC,L00AD    		;0066 3045	<L00AD>
L0068:	DEC  (HL)    			;0068 35
	LD   (M3231),A   		;0069 323132	<M3231>
	INC  SP      			;006C 33
	JR   C,L009F     		;006D 3830	<L009F>
	LD   B,E     			;006F 43
L0070:	LD   B,D     			;0070 42
	LD   B,C     			;0071 41
	LD   (HL),31H  			;0072 3631	<31H>
	JR   C,L00A8     		;0074 3832	<L00A8>
L0076:	LD   B,D     			;0076 42
	LD   B,L     			;0077 45
L0078:	DEC  (HL)    			;0078 35
	LD   (M3231),A   		;0079 323132	<M3231>
	INC  SP      			;007C 33
	JR   C,L00AF     		;007D 3830	<L00AF>
	LD   B,E     			;007F 43
	LD   B,D     			;0080 42
	LD   B,L     			;0081 45
	LD   (HL),31H  			;0082 3631	<31H>
	JR   C,L00B8     		;0084 3832	<L00B8>
L0086:	ADD  HL,SP   			;0086 39
	LD   B,L     			;0087 45
	DEC  (HL)    			;0088 35
	LD   (M3231),A   		;0089 323132	<M3231>
	LD   (M4646),A   		;008C 324646	<M4646>
	INC  SP      			;008F 33
	LD   (HL),30H  			;0090 3630	<30H>
	JR   NC,L00C5    		;0092 3031	<L00C5>
	JR   C,L00C8     		;0094 3832	<L00C8>
	SCF          			;0096 37
	LD   B,L     			;0097 45
	DEC  (HL)    			;0098 35
	LD   B,H     			;0099 44
	DEC  (HL)    			;009A 35
	LD   B,E     			;009B 43
	DEC  (HL)    			;009C 35
	LD   B,(HL)  			;009D 46
	INC  SP      			;009E 33
L009F:	LD   B,E     			;009F 43
	LD   B,H     			;00A0 44
	LD   (M3034),A   		;00A1 323430	<M3034>
	LD   SP,M4246    		;00A4 314642	<M4246>
	LD   B,E     			;00A7 43
L00A8:	LD   B,H     			;00A8 44
	DEC  C       			;00A9 0D
	LD   A,(BC)  			;00AA 0A
	LD   A,(M3032)   		;00AB 3A3230	<M3032>
	JR   NC,L00E0    		;00AE 3030	<L00E0>
	INC  (HL)    			;00B0 34
	JR   NC,L00E3    		;00B1 3030	<L00E3>
	JR   NC,L00F8    		;00B3 3043	<L00F8>
	LD   SP,M3144    		;00B5 314431	<M3144>
L00B8:	LD   B,L     			;00B8 45
	LD   SP,M3943    		;00B9 314339	<M3943>
	INC  (HL)    			;00BC 34
	LD   B,L     			;00BD 45
	SCF          			;00BE 37
	JR   C,L0102     		;00BF 3841	<L0102>
	SCF          			;00C1 37
	LD   (M3038),A   		;00C2 323830	<M3038>
L00C5:	LD   (M4330),A   		;00C5 323043	<M4330>
L00C8:	LD   B,C     			;00C8 41
	LD   B,(HL)  			;00C9 46
	LD   SP,M3132    		;00CA 313231	<M3132>
	INC  SP      			;00CD 33
	LD   SP,M4630    		;00CE 313046	<M4630>
	LD   B,E     			;00D1 43
	JR   NC,L0118    		;00D2 3044	<L0118>
	LD   (M4630),A   		;00D4 323046	<M4630>
	ADD  HL,SP   			;00D7 39
	LD   B,E     			;00D8 43
	ADD  HL,SP   			;00D9 39
	LD   (M3245),A   		;00DA 324532	<M3245>
	ADD  HL,SP   			;00DD 39
	LD   B,E     			;00DE 43
	LD   B,D     			;00DF 42
L00E0:	LD   B,D     			;00E0 42
	LD   (HL),45H  			;00E1 3645	<45H>
L00E3:	LD   SP,M3943    		;00E3 314339	<M3943>
	LD   (M3245),A   		;00E6 324532	<M3245>
	ADD  HL,SP   			;00E9 39
	LD   B,E     			;00EA 43
	LD   B,D     			;00EB 42
	LD   B,(HL)  			;00EC 46
	LD   (HL),45H  			;00ED 3645	<45H>
	LD   SP,M3943    		;00EF 314339	<M3943>
	INC  SP      			;00F2 33
	LD   (HL),37H  			;00F3 3637	<37H>
	JR   C,L0104     		;00F5 380D	<L0104>
	LD   A,(BC)  			;00F7 0A
L00F8:	LD   A,(M3032)   		;00F8 3A3230	<M3032>
	JR   NC,L012D    		;00FB 3030	<L012D>
	LD   (HL),30H  			;00FD 3630	<30H>
	JR   NC,L0131    		;00FF 3030	<L0131>
	JR   C,L0133     		;0101 3830	<L0133>
	LD   B,L     			;0103 45
L0104:	LD   SP,M3943    		;0104 314339	<M3943>
	JR   NC,L0139    		;0107 3030	<L0139>
	JR   NC,L013B    		;0109 3030	<L013B>
	JR   NC,L013D    		;010B 3030	<L013D>
	LD   B,(HL)  			;010D 46
	DEC  (HL)    			;010E 35
	LD   B,C     			;010F 41
	LD   B,(HL)  			;0110 46
	INC  SP      			;0111 33
	LD   (M3232),A   		;0112 323232	<M3232>
	LD   B,(HL)  			;0115 46
	LD   B,(HL)  			;0116 46
	INC  SP      			;0117 33
L0118:	LD   (M3033),A   		;0118 323330	<M3033>
	LD   B,(HL)  			;011B 46
	LD   B,(HL)  			;011C 46
	LD   B,L     			;011D 45
	LD   B,H     			;011E 44
	DEC  (HL)    			;011F 35
	SCF          			;0120 37
	LD   B,(HL)  			;0121 46
	DEC  (HL)    			;0122 35
	LD   B,E     			;0123 43
	DEC  (HL)    			;0124 35
	LD   B,H     			;0125 44
	DEC  (HL)    			;0126 35
	LD   B,L     			;0127 45
	DEC  (HL)    			;0128 35
	LD   B,H     			;0129 44
	ADD  HL,SP   			;012A 39
	LD   B,E     			;012B 43
	DEC  (HL)    			;012C 35
L012D:	LD   B,H     			;012D 44
	DEC  (HL)    			;012E 35
	LD   B,L     			;012F 45
	DEC  (HL)    			;0130 35
L0131:	LD   B,L     			;0131 45
	LD   B,H     			;0132 44
L0133:	SCF          			;0133 37
	INC  SP      			;0134 33
	DEC  (HL)    			;0135 35
	LD   B,E     			;0136 43
	JR   C,L0169     		;0137 3830	<L0169>
L0139:	LD   (M3031),A   		;0139 323130	<M3031>
	LD   SP,M3038    		;013C 313830	<M3038>
	LD   B,E     			;013F 43
	LD   B,D     			;0140 42
	INC  (HL)    			;0141 34
	DEC  (HL)    			;0142 35
	DEC  C       			;0143 0D
	LD   A,(BC)  			;0144 0A
	LD   A,(M3032)   		;0145 3A3230	<M3032>
	JR   NC,L017A    		;0148 3030	<L017A>
	JR   C,L017C     		;014A 3830	<L017C>
	JR   NC,L017E    		;014C 3030	<L017E>
	LD   B,(HL)  			;014E 46
	LD   (HL),41H  			;014F 3641	<41H>
	LD   B,(HL)  			;0151 46
	LD   SP,M3531    		;0152 313135	<M3531>
	LD   B,D     			;0155 42
	JR   C,L0188     		;0156 3830	<L0188>
	LD   SP,M3232    		;0158 313232	<M3232>
	LD   SP,M3030    		;015B 313030	<M3030>
	JR   C,L0190     		;015E 3830	<L0190>
	JR   NC,L0193    		;0160 3031	<L0193>
	JR   NC,L0196    		;0162 3032	<L0196>
	JR   NC,L0196    		;0164 3030	<L0196>
	JR   C,L019E     		;0166 3836	<L019E>
	LD   (M3133),A   		;0168 323331	<M3133>
	JR   NC,L01B3    		;016B 3046	<L01B3>
	LD   B,E     			;016D 43
	JR   NC,L01B4    		;016E 3044	<L01B4>
	LD   (M4630),A   		;0170 323046	<M4630>
	ADD  HL,SP   			;0173 39
	LD   B,L     			;0174 45
	LD   B,H     			;0175 44
	INC  (HL)    			;0176 34
	INC  (HL)    			;0177 34
	LD   SP,M3332    		;0178 313233	<M3332>
	LD   B,L     			;017B 45
L017C:	JR   NC,L01AF    		;017C 3031	<L01AF>
L017E:	INC  SP      			;017E 33
	LD   (M3431),A   		;017F 323134	<M3431>
	LD   B,(HL)  			;0182 46
	LD   B,(HL)  			;0183 46
	LD   SP,M4638    		;0184 313846	<M4638>
	LD   B,L     			;0187 45
L0188:	JR   NC,L01BA    		;0188 3030	<L01BA>
	JR   NC,L01BC    		;018A 3030	<L01BC>
	JR   NC,L01BE    		;018C 3030	<L01BE>
	LD   (HL),31H  			;018E 3631	<31H>
L0190:	DEC  C       			;0190 0D
	LD   A,(BC)  			;0191 0A
	LD   A,(M3032)   		;0192 3A3230	<M3032>
	JR   NC,L01C7    		;0195 3030	<L01C7>
	LD   B,C     			;0197 41
	JR   NC,L01CA    		;0198 3030	<L01CA>
	JR   NC,L01CC    		;019A 3030	<L01CC>
	JR   NC,L01CE    		;019C 3030	<L01CE>
L019E:	JR   NC,L01D0    		;019E 3030	<L01D0>
	JR   NC,L01D2    		;01A0 3030	<L01D2>
	JR   NC,L01D5    		;01A2 3031	<L01D5>
	LD   B,L     			;01A4 45
	INC  (HL)    			;01A5 34
	LD   B,(HL)  			;01A6 46
	LD   SP,M3438    		;01A7 313834	<M3438>
	ADD  HL,SP   			;01AA 39
	LD   B,(HL)  			;01AB 46
	DEC  (HL)    			;01AC 35
	LD   B,E     			;01AD 43
	DEC  (HL)    			;01AE 35
L01AF:	LD   B,H     			;01AF 44
	DEC  (HL)    			;01B0 35
	LD   B,L     			;01B1 45
	DEC  (HL)    			;01B2 35
L01B3:	LD   (M3031),A   		;01B3 323130	<M3031>
	JR   C,L01E8     		;01B6 3830	<L01E8>
	JR   NC,L01ED    		;01B8 3033	<L01ED>
L01BA:	ADD  HL,SP   			;01BA 39
	DEC  (HL)    			;01BB 35
L01BC:	LD   B,L     			;01BC 45
	LD   (M3533),A   		;01BD 323335	<M3533>
	LD   (HL),32H  			;01C0 3632	<32H>
	LD   SP,M4230    		;01C2 313042	<M4230>
	LD   B,(HL)  			;01C5 46
	JR   NC,L01F9    		;01C6 3031	<L01F9>
	ADD  HL,SP   			;01C8 39
	INC  SP      			;01C9 33
L01CA:	JR   NC,L01FC    		;01CA 3030	<L01FC>
L01CC:	INC  (HL)    			;01CC 34
	LD   SP,M3445    		;01CD 314534	<M3445>
L01D0:	LD   B,(HL)  			;01D0 46
	LD   SP,M3338    		;01D1 313833	<M3338>
	INC  (HL)    			;01D4 34
L01D5:	LD   B,E     			;01D5 43
	LD   B,H     			;01D6 44
	SCF          			;01D7 37
	SCF          			;01D8 37
	JR   NC,L020C    		;01D9 3031	<L020C>
	DEC  (HL)    			;01DB 35
	LD   B,L     			;01DC 45
	DEC  C       			;01DD 0D
	LD   A,(BC)  			;01DE 0A
	LD   A,(M3032)   		;01DF 3A3230	<M3032>
	JR   NC,L0214    		;01E2 3030	<L0214>
	LD   B,E     			;01E4 43
	JR   NC,L0217    		;01E5 3030	<L0217>
	JR   NC,L022C    		;01E7 3043	<L022C>
	LD   B,H     			;01E9 44
	ADD  HL,SP   			;01EA 39
	LD   B,H     			;01EB 44
	JR   NC,L021F    		;01EC 3031	<L021F>
	JR   NC,L0235    		;01EE 3045	<L0235>
	JR   NC,L0225    		;01F0 3033	<L0225>
	LD   (M3331),A   		;01F2 323133	<M3331>
	LD   (HL),38H  			;01F5 3638	<38H>
	JR   NC,L0230    		;01F7 3037	<L0230>
L01F9:	ADD  HL,SP   			;01F9 39
	JR   C,L0233     		;01FA 3837	<L0233>
L01FC:	JR   C,L0235     		;01FC 3837	<L0235>
	JR   C,L0237     		;01FE 3837	<L0237>
	LD   B,E     			;0200 43
	LD   B,(HL)  			;0201 46
	LD   B,E     			;0202 43
	LD   B,H     			;0203 44
	LD   B,D     			;0204 42
	LD   B,E     			;0205 43
	JR   NC,L0239    		;0206 3031	<L0239>
	JR   NC,L024E    		;0208 3044	<L024E>
	LD   (M4630),A   		;020A 323046	<M4630>
	LD   (M4443),A   		;020D 324344	<M4443>
	DEC  (HL)    			;0210 35
	LD   B,C     			;0211 41
	JR   NC,L0246    		;0212 3032	<L0246>
L0214:	LD   B,E     			;0214 43
	LD   B,H     			;0215 44
	LD   B,E     			;0216 43
L0217:	LD   B,L     			;0217 45
	JR   NC,L025E    		;0218 3044	<L025E>
	LD   (M3231),A   		;021A 323132	<M3231>
	LD   B,C     			;021D 41
	JR   C,L0250     		;021E 3830	<L0250>
	JR   NC,L0253    		;0220 3031	<L0253>
	JR   C,L025C     		;0222 3838	<L025C>
	JR   NC,L025F    		;0224 3039	<L025F>
	SCF          			;0226 37
	LD   B,L     			;0227 45
	ADD  HL,SP   			;0228 39
	LD   B,D     			;0229 42
	DEC  C       			;022A 0D
	LD   A,(BC)  			;022B 0A
L022C:	LD   A,(M3032)   		;022C 3A3230	<M3032>
	JR   NC,L0261    		;022F 3030	<L0261>
	LD   B,L     			;0231 45
	JR   NC,L0264    		;0232 3030	<L0264>
	JR   NC,L027B    		;0234 3045	<L027B>
	LD   B,H     			;0236 44
L0237:	SCF          			;0237 37
	ADD  HL,SP   			;0238 39
L0239:	LD   (M3042),A   		;0239 324230	<M3042>
	LD   B,H     			;023C 44
	LD   SP,M4630    		;023D 313046	<M4630>
	ADD  HL,SP   			;0240 39
	LD   B,L     			;0241 45
	LD   SP,M3144    		;0242 314431	<M3144>
	LD   B,E     			;0245 43
L0246:	LD   SP,M4533    		;0246 313345	<M4533>
	JR   NC,L027C    		;0249 3031	<L027C>
	INC  SP      			;024B 33
	LD   (M3433),A   		;024C 323334	<M3433>
	LD   B,(HL)  			;024F 46
L0250:	LD   B,(HL)  			;0250 46
	LD   B,(HL)  			;0251 46
	LD   SP,M4246    		;0252 314642	<M4246>
	LD   B,E     			;0255 43
	ADD  HL,SP   			;0256 39
	LD   B,(HL)  			;0257 46
	INC  SP      			;0258 33
	LD   B,C     			;0259 41
	LD   B,(HL)  			;025A 46
	JR   NC,L028E    		;025B 3031	<L028E>
	JR   C,L028F     		;025D 3830	<L028F>
L025F:	JR   NC,L029A    		;025F 3039	<L029A>
L0261:	LD   B,L     			;0261 45
	LD   B,H     			;0262 44
	SCF          			;0263 37
L0264:	ADD  HL,SP   			;0264 39
	JR   NC,L02AA    		;0265 3043	<L02AA>
	LD   SP,M4630    		;0267 313046	<M4630>
	LD   B,D     			;026A 42
	INC  SP      			;026B 33
	LD   B,L     			;026C 45
	JR   NC,L02A0    		;026D 3031	<L02A0>
	INC  SP      			;026F 33
	LD   (M3831),A   		;0270 323138	<M3831>
	LD   B,(HL)  			;0273 46
	LD   B,(HL)  			;0274 46
	DEC  (HL)    			;0275 35
	LD   B,E     			;0276 43
	DEC  C       			;0277 0D
	LD   A,(BC)  			;0278 0A
	LD   A,(M3032)   		;0279 3A3230	<M3032>
L027C:	JR   NC,L02AF    		;027C 3031	<L02AF>
	JR   NC,L02B0    		;027E 3030	<L02B0>
	JR   NC,L02B2    		;0280 3030	<L02B2>
	INC  SP      			;0282 33
	LD   B,L     			;0283 45
	JR   C,L02B6     		;0284 3830	<L02B6>
	LD   B,H     			;0286 44
	INC  SP      			;0287 33
	JR   C,L02BE     		;0288 3834	<L02BE>
	LD   B,C     			;028A 41
	LD   B,(HL)  			;028B 46
	LD   B,H     			;028C 44
	INC  SP      			;028D 33
L028E:	JR   C,L02C4     		;028E 3834	<L02C4>
	LD   SP,M3736    		;0290 313637	<M3736>
	ADD  HL,SP   			;0293 39
	LD   (M3031),A   		;0294 323130	<M3031>
	LD   SP,M3230    		;0297 313032	<M3230>
L029A:	JR   NC,L02E1    		;029A 3045	<L02E1>
	JR   C,L02D2     		;029C 3834	<L02D2>
	LD   B,L     			;029E 45
	LD   B,H     			;029F 44
L02A0:	SCF          			;02A0 37
	ADD  HL,SP   			;02A1 39
	JR   NC,L02E8    		;02A2 3044	<L02E8>
	LD   B,L     			;02A4 45
	LD   B,H     			;02A5 44
	DEC  (HL)    			;02A6 35
	LD   SP,M4330    		;02A7 313043	<M4330>
L02AA:	LD   B,L     			;02AA 45
	LD   B,H     			;02AB 44
	LD   (HL),31H  			;02AC 3631	<31H>
	LD   SP,M4630    		;02AE 313046	<M4630>
	LD   B,L     			;02B1 45
L02B2:	LD   B,L     			;02B2 45
	LD   B,H     			;02B3 44
	SCF          			;02B4 37
	ADD  HL,SP   			;02B5 39
L02B6:	JR   NC,L02FC    		;02B6 3044	<L02FC>
	LD   B,L     			;02B8 45
	LD   B,H     			;02B9 44
	DEC  (HL)    			;02BA 35
	ADD  HL,SP   			;02BB 39
	JR   NC,L0301    		;02BC 3043	<L0301>
L02BE:	LD   B,L     			;02BE 45
	LD   B,H     			;02BF 44
	LD   (HL),39H  			;02C0 3639	<39H>
	INC  (HL)    			;02C2 34
	LD   B,D     			;02C3 42
L02C4:	DEC  C       			;02C4 0D
	LD   A,(BC)  			;02C5 0A
	LD   A,(M3032)   		;02C6 3A3230	<M3032>
	JR   NC,L02FC    		;02C9 3031	<L02FC>
	LD   (M3030),A   		;02CB 323030	<M3030>
	JR   NC,L0301    		;02CE 3031	<L0301>
	JR   NC,L0318    		;02D0 3046	<L0318>
L02D2:	LD   B,L     			;02D2 45
	LD   SP,M4538    		;02D3 313845	<M4538>
	LD   B,C     			;02D6 41
	LD   B,C     			;02D7 41
	SCF          			;02D8 37
	LD   B,E     			;02D9 43
	JR   C,L030E     		;02DA 3832	<L030E>
	LD   SP,M3239    		;02DC 313932	<M3239>
	LD   SP,M3839    		;02DF 313938	<M3839>
	SCF          			;02E2 37
	JR   C,L031C     		;02E3 3837	<L031C>
	LD   B,E     			;02E5 43
	LD   B,(HL)  			;02E6 46
	LD   B,L     			;02E7 45
L02E8:	LD   B,D     			;02E8 42
	LD   SP,M4141    		;02E9 314141	<M4141>
	SCF          			;02EC 37
	LD   (M3038),A   		;02ED 323830	<M3038>
	JR   C,L0324     		;02F0 3832	<L0324>
	LD   SP,M3046    		;02F2 314630	<M3046>
	LD   SP,M3039    		;02F5 313930	<M3039>
	LD   B,L     			;02F8 45
	JR   NC,L0340    		;02F9 3045	<L0340>
	LD   B,E     			;02FB 43
L02FC:	LD   B,H     			;02FC 44
	LD   (HL),36H  			;02FD 3636	<36H>
	JR   NC,L0332    		;02FF 3031	<L0332>
L0301:	LD   SP,M3133    		;0301 313331	<M3133>
	LD   B,C     			;0304 41
	LD   B,C     			;0305 41
	SCF          			;0306 37
	LD   (M3038),A   		;0307 323830	<M3038>
	JR   C,L033E     		;030A 3832	<L033E>
	LD   SP,M3541    		;030C 314135	<M3541>
	SCF          			;030F 37
	SCF          			;0310 37
	DEC  C       			;0311 0D
	LD   A,(BC)  			;0312 0A
	LD   A,(M3032)   		;0313 3A3230	<M3032>
	JR   NC,L0349    		;0316 3031	<L0349>
L0318:	INC  (HL)    			;0318 34
	JR   NC,L034B    		;0319 3030	<L034B>
	JR   NC,L034E    		;031B 3031	<L034E>
	LD   B,C     			;031D 41
	JR   NC,L0365    		;031E 3045	<L0365>
	LD   SP,M4333    		;0320 313343	<M4333>
	LD   B,H     			;0323 44
L0324:	LD   (HL),36H  			;0324 3636	<36H>
	JR   NC,L0359    		;0326 3031	<L0359>
	LD   SP,M3133    		;0328 313331	<M3133>
	LD   B,C     			;032B 41
	LD   B,C     			;032C 41
	SCF          			;032D 37
	LD   (M3038),A   		;032E 323830	<M3038>
	JR   C,L0365     		;0331 3832	<L0365>
	LD   SP,M3933    		;0333 313339	<M3933>
	LD   SP,M3042    		;0336 314230	<M3042>
	LD   B,L     			;0339 45
	LD   SP,M4338    		;033A 313843	<M4338>
	LD   B,H     			;033D 44
L033E:	LD   (HL),36H  			;033E 3636	<36H>
L0340:	JR   NC,L0373    		;0340 3031	<L0373>
	LD   SP,M3133    		;0342 313331	<M3133>
	LD   B,C     			;0345 41
	LD   B,C     			;0346 41
	SCF          			;0347 37
	LD   B,E     			;0348 43
L0349:	JR   C,L037E     		;0349 3833	<L037E>
L034B:	LD   (M3831),A   		;034B 323138	<M3831>
L034E:	LD   B,(HL)  			;034E 46
	LD   B,(HL)  			;034F 46
	INC  SP      			;0350 33
	LD   B,C     			;0351 41
	LD   (M3836),A   		;0352 323638	<M3836>
	JR   NC,L039A    		;0355 3043	<L039A>
	LD   B,D     			;0357 42
	LD   B,(HL)  			;0358 46
L0359:	LD   B,(HL)  			;0359 46
	LD   B,H     			;035A 44
	INC  SP      			;035B 33
	LD   B,(HL)  			;035C 46
	LD   B,D     			;035D 42
	DEC  C       			;035E 0D
	LD   A,(BC)  			;035F 0A
	LD   A,(M3032)   		;0360 3A3230	<M3032>
	JR   NC,L0396    		;0363 3031	<L0396>
L0365:	LD   (HL),30H  			;0365 3630	<30H>
	JR   NC,L0399    		;0367 3030	<L0399>
	JR   C,L039F     		;0369 3834	<L039F>
	LD   B,E     			;036B 43
	LD   B,D     			;036C 42
	LD   B,D     			;036D 42
	LD   B,(HL)  			;036E 46
	LD   B,H     			;036F 44
	INC  SP      			;0370 33
	JR   C,L03A7     		;0371 3834	<L03A7>
L0373:	LD   B,E     			;0373 43
	ADD  HL,SP   			;0374 39
	JR   NC,L03AD    		;0375 3036	<L03AD>
	JR   C,L03A9     		;0377 3830	<L03A9>
	JR   NC,L03AD    		;0379 3032	<L03AD>
	JR   C,L03B4     		;037B 3837	<L03B4>
	LD   B,E     			;037D 43
L037E:	LD   B,(HL)  			;037E 46
	JR   NC,L03B4    		;037F 3033	<L03B4>
	INC  SP      			;0381 33
	LD   B,L     			;0382 45
	JR   NC,L03B6    		;0383 3031	<L03B6>
	JR   NC,L03B9    		;0385 3032	<L03B9>
	JR   NC,L03BC    		;0387 3033	<L03BC>
	SCF          			;0389 37
	LD   B,L     			;038A 45
	JR   NC,L03BF    		;038B 3032	<L03BF>
	JR   NC,L03C2    		;038D 3033	<L03C2>
	LD   (M3733),A   		;038F 323337	<M3733>
	LD   B,L     			;0392 45
	JR   NC,L03C7    		;0393 3032	<L03C7>
	LD   B,E     			;0395 43
L0396:	ADD  HL,SP   			;0396 39
	LD   (M3031),A   		;0397 323130	<M3031>
L039A:	LD   (M3038),A   		;039A 323830	<M3038>
	JR   NC,L03D0    		;039D 3031	<L03D0>
L039F:	JR   C,L03D1     		;039F 3830	<L03D1>
	LD   B,(HL)  			;03A1 46
	LD   B,(HL)  			;03A2 46
	LD   B,E     			;03A3 43
	LD   B,H     			;03A4 44
	JR   C,L03ED     		;03A5 3846	<L03ED>
L03A7:	JR   NC,L03DA    		;03A7 3031	<L03DA>
L03A9:	LD   B,D     			;03A9 42
	LD   B,H     			;03AA 44
	DEC  C       			;03AB 0D
	LD   A,(BC)  			;03AC 0A
L03AD:	LD   A,(M3032)   		;03AD 3A3230	<M3032>
	JR   NC,L03E3    		;03B0 3031	<L03E3>
	JR   C,L03E4     		;03B2 3830	<L03E4>
L03B4:	JR   NC,L03E6    		;03B4 3030	<L03E6>
L03B6:	SCF          			;03B6 37
	LD   B,C     			;03B7 41
	LD   B,C     			;03B8 41
L03B9:	INC  SP      			;03B9 33
	SCF          			;03BA 37
	SCF          			;03BB 37
L03BC:	LD   (M3033),A   		;03BC 323330	<M3033>
L03BF:	LD   (HL),30H  			;03BF 3630	<30H>
	LD   B,(HL)  			;03C1 46
L03C2:	LD   B,E     			;03C2 43
	LD   B,H     			;03C3 44
	JR   C,L040C     		;03C4 3846	<L040C>
	JR   NC,L03F9    		;03C6 3031	<L03F9>
	JR   NC,L0400    		;03C8 3036	<L0400>
	JR   NC,L03FC    		;03CA 3030	<L03FC>
	LD   B,E     			;03CC 43
	LD   B,H     			;03CD 44
	JR   C,L0416     		;03CE 3846	<L0416>
L03D0:	JR   NC,L0403    		;03D0 3031	<L0403>
	LD   B,E     			;03D2 43
	ADD  HL,SP   			;03D3 39
	LD   B,L     			;03D4 45
	LD   B,H     			;03D5 44
	SCF          			;03D6 37
	JR   C,L040E     		;03D7 3835	<L040E>
	LD   (HL),37H  			;03D9 3637	<37H>
	SCF          			;03DB 37
	LD   B,C     			;03DC 41
	LD   B,C     			;03DD 41
	DEC  (HL)    			;03DE 35
	LD   B,(HL)  			;03DF 46
	SCF          			;03E0 37
	LD   B,C     			;03E1 41
	LD   B,C     			;03E2 41
L03E3:	JR   C,L0426     		;03E3 3841	<L0426>
	INC  SP      			;03E5 33
L03E6:	LD   (M3733),A   		;03E6 323337	<M3733>
	SCF          			;03E9 37
	LD   (M3033),A   		;03EA 323330	<M3033>
L03ED:	LD   B,E     			;03ED 43
	LD   B,E     			;03EE 43
	ADD  HL,SP   			;03EF 39
	LD   (M3231),A   		;03F0 323132	<M3231>
	LD   B,D     			;03F3 42
	JR   C,L0426     		;03F4 3830	<L0426>
	LD   B,C     			;03F6 41
	LD   B,E     			;03F7 43
	DEC  C       			;03F8 0D
L03F9:	LD   A,(BC)  			;03F9 0A
	LD   A,(M3032)   		;03FA 3A3230	<M3032>
	JR   NC,L0430    		;03FD 3031	<L0430>
	LD   B,C     			;03FF 41
L0400:	JR   NC,L0432    		;0400 3030	<L0432>
	JR   NC,L0434    		;0402 3030	<L0434>
	LD   (HL),30H  			;0404 3630	<30H>
	DEC  (HL)    			;0406 35
	DEC  (HL)    			;0407 35
	LD   B,L     			;0408 45
	LD   (M3533),A   		;0409 323335	<M3533>
L040C:	LD   (HL),37H  			;040C 3637	<37H>
L040E:	LD   B,C     			;040E 41
	LD   B,D     			;040F 42
	INC  SP      			;0410 33
	LD   (M3038),A   		;0411 323830	<M3038>
	DEC  (HL)    			;0414 35
	LD   SP,M3742    		;0415 314237	<M3742>
	LD   (M4232),A   		;0418 323242	<M4232>
	SCF          			;041B 37
	INC  SP      			;041C 33
	LD   (M3233),A   		;041D 323332	<M3233>
	INC  SP      			;0420 33
	LD   SP,M4630    		;0421 313046	<M4630>
	LD   SP,M3630    		;0424 313036	<M3630>
	JR   NC,L0462    		;0427 3039	<L0462>
	SCF          			;0429 37
	LD   B,L     			;042A 45
	LD   B,C     			;042B 41
	SCF          			;042C 37
	LD   (M3038),A   		;042D 323830	<M3038>
L0430:	LD   SP,M3533    		;0430 313335	<M3533>
	LD   (M3133),A   		;0433 323331	<M3133>
	JR   NC,L047E    		;0436 3046	<L047E>
	JR   C,L047D     		;0438 3843	<L047D>
	ADD  HL,SP   			;043A 39
	DEC  (HL)    			;043B 35
	INC  (HL)    			;043C 34
	DEC  (HL)    			;043D 35
	LD   B,H     			;043E 44
	SCF          			;043F 37
	LD   B,L     			;0440 45
	LD   B,C     			;0441 41
	SCF          			;0442 37
	INC  SP      			;0443 33
	DEC  (HL)    			;0444 35
	DEC  C       			;0445 0D
	LD   A,(BC)  			;0446 0A
	LD   A,(M3032)   		;0447 3A3230	<M3032>
	JR   NC,L047D    		;044A 3031	<L047D>
	LD   B,E     			;044C 43
	JR   NC,L047F    		;044D 3030	<L047F>
	JR   NC,L0494    		;044F 3043	<L0494>
	JR   C,L0486     		;0451 3833	<L0486>
	LD   B,H     			;0453 44
	LD   (M3130),A   		;0454 323031	<M3130>
	ADD  HL,SP   			;0457 39
	LD   (M3333),A   		;0458 323333	<M3333>
	DEC  (HL)    			;045B 35
	LD   B,E     			;045C 43
	JR   NC,L0491    		;045D 3032	<L0491>
	LD   B,D     			;045F 42
	LD   B,E     			;0460 43
	LD   B,H     			;0461 44
L0462:	INC  (HL)    			;0462 34
	LD   SP,M3230    		;0463 313032	<M3230>
	LD   (M3233),A   		;0466 323332	<M3233>
	INC  SP      			;0469 33
	INC  SP      			;046A 33
	DEC  (HL)    			;046B 35
	LD   (M3038),A   		;046C 323830	<M3038>
	ADD  HL,SP   			;046F 39
	SCF          			;0470 37
	LD   B,L     			;0471 45
	LD   (M3531),A   		;0472 323135	<M3531>
	LD   (M3031),A   		;0475 323130	<M3031>
	LD   B,E     			;0478 43
	LD   B,(HL)  			;0479 46
	SCF          			;047A 37
	LD   B,L     			;047B 45
	LD   SP,M3133    		;047C 313331	<M3133>
L047F:	LD   (M3943),A   		;047F 324339	<M3943>
	INC  SP      			;0482 33
	LD   B,L     			;0483 45
	JR   NC,L04B8    		;0484 3032	<L04B8>
L0486:	LD   SP,M4332    		;0486 313243	<M4332>
	ADD  HL,SP   			;0489 39
	INC  SP      			;048A 33
	LD   B,H     			;048B 44
	LD   (M3130),A   		;048C 323031	<M3130>
	LD   B,(HL)  			;048F 46
	JR   NC,L04D8    		;0490 3046	<L04D8>
	DEC  C       			;0492 0D
	LD   A,(BC)  			;0493 0A
L0494:	LD   A,(M3032)   		;0494 3A3230	<M3032>
	JR   NC,L04CA    		;0497 3031	<L04CA>
	LD   B,L     			;0499 45
	JR   NC,L04CC    		;049A 3030	<L04CC>
	JR   NC,L04E1    		;049C 3043	<L04E1>
	LD   B,H     			;049E 44
	INC  (HL)    			;049F 34
	LD   SP,M3230    		;04A0 313032	<M3230>
	INC  SP      			;04A3 33
	LD   B,C     			;04A4 41
	JR   NC,L04DF    		;04A5 3038	<L04DF>
	JR   C,L04D9     		;04A7 3830	<L04D9>
	INC  (HL)    			;04A9 34
	LD   SP,M4630    		;04AA 313046	<M4630>
	LD   SP,M4630    		;04AD 313046	<M4630>
	LD   B,H     			;04B0 44
	LD   (M3233),A   		;04B1 323332	<M3233>
	INC  SP      			;04B4 33
	LD   (M3333),A   		;04B5 323333	<M3333>
L04B8:	JR   NC,L04EA    		;04B8 3030	<L04EA>
	JR   C,L04EF     		;04BA 3833	<L04EF>
	LD   (HL),46H  			;04BC 3646	<46H>
	LD   B,(HL)  			;04BE 46
	LD   (M3333),A   		;04BF 323333	<M3333>
	LD   (HL),31H  			;04C2 3631	<31H>
	INC  (HL)    			;04C4 34
	LD   (M3733),A   		;04C5 323337	<M3733>
	JR   NC,L050D    		;04C8 3043	<L050D>
L04CA:	ADD  HL,SP   			;04CA 39
	LD   (M3333),A   		;04CB 323333	<M3333>
	DEC  (HL)    			;04CE 35
	LD   B,E     			;04CF 43
	JR   NC,L0505    		;04D0 3033	<L0505>
	LD   (HL),31H  			;04D2 3631	<31H>
	INC  SP      			;04D4 33
	LD   (M3333),A   		;04D5 323333	<M3333>
L04D8:	INC  (HL)    			;04D8 34
L04D9:	LD   B,E     			;04D9 43
	ADD  HL,SP   			;04DA 39
	INC  SP      			;04DB 33
	LD   B,H     			;04DC 44
	SCF          			;04DD 37
	INC  SP      			;04DE 33
L04DF:	DEC  C       			;04DF 0D
	LD   A,(BC)  			;04E0 0A
L04E1:	LD   A,(M3032)   		;04E1 3A3230	<M3032>
	JR   NC,L0518    		;04E4 3032	<L0518>
	JR   NC,L0518    		;04E6 3030	<L0518>
	JR   NC,L051A    		;04E8 3030	<L051A>
L04EA:	LD   (M3330),A   		;04EA 323033	<M3330>
	LD   SP,M4443    		;04ED 314344	<M4443>
	INC  (HL)    			;04F0 34
	LD   SP,M3230    		;04F1 313032	<M3230>
	INC  SP      			;04F4 33
	LD   B,L     			;04F5 45
	JR   NC,L052C    		;04F6 3034	<L052C>
	LD   B,E     			;04F8 43
	LD   B,(HL)  			;04F9 46
	LD   B,L     			;04FA 45
	DEC  (HL)    			;04FB 35
	INC  SP      			;04FC 33
	DEC  (HL)    			;04FD 35
	LD   (M3030),A   		;04FE 323030	<M3030>
	LD   B,L     			;0501 45
	INC  SP      			;0502 33
	LD   (HL),31H  			;0503 3631	<31H>
L0505:	INC  SP      			;0505 33
	LD   (M3333),A   		;0506 323333	<M3333>
	INC  (HL)    			;0509 34
	SCF          			;050A 37
	LD   B,L     			;050B 45
	LD   B,H     			;050C 44
L050D:	LD   (HL),31H  			;050D 3631	<31H>
	DEC  (HL)    			;050F 35
	INC  SP      			;0510 33
	JR   C,L0543     		;0511 3830	<L0543>
	DEC  (HL)    			;0513 35
	SCF          			;0514 37
	SCF          			;0515 37
	LD   (M3030),A   		;0516 323030	<M3030>
	LD   (M4232),A   		;0519 323242	<M4232>
	INC  SP      			;051C 33
	INC  (HL)    			;051D 34
	LD   B,L     			;051E 45
	LD   SP,M4537    		;051F 313745	<M4537>
	LD   B,(HL)  			;0522 46
	LD   B,L     			;0523 45
	LD   SP,M4431    		;0524 313144	<M4431>
	JR   NC,L055B    		;0527 3032	<L055B>
	INC  SP      			;0529 33
	JR   C,L0561     		;052A 3835	<L0561>
L052C:	DEC  C       			;052C 0D
	LD   A,(BC)  			;052D 0A
	LD   A,(M3032)   		;052E 3A3230	<M3032>
	JR   NC,L0565    		;0531 3032	<L0565>
	LD   (M3030),A   		;0533 323030	<M3030>
	JR   NC,L056F    		;0536 3037	<L056F>
	LD   B,L     			;0538 45
	LD   (M4233),A   		;0539 323342	<M4233>
	LD   B,L     			;053C 45
	LD   B,E     			;053D 43
	JR   NC,L0572    		;053E 3032	<L0572>
	LD   B,L     			;0540 45
	LD   (M3731),A   		;0541 323137	<M3731>
	ADD  HL,SP   			;0544 39
	LD   B,E     			;0545 43
	LD   B,(HL)  			;0546 46
	SCF          			;0547 37
	LD   B,L     			;0548 45
	LD   B,(HL)  			;0549 46
	LD   (HL),30H  			;054A 3630	<30H>
	LD   B,(HL)  			;054C 46
	SCF          			;054D 37
	SCF          			;054E 37
	LD   B,L     			;054F 45
	LD   B,D     			;0550 42
	INC  SP      			;0551 33
	LD   (HL),30H  			;0552 3630	<30H>
	INC  (HL)    			;0554 34
	LD   (M3333),A   		;0555 323333	<M3333>
	LD   (HL),44H  			;0558 3644	<44H>
	LD   (HL),43H  			;055A 3643	<43H>
	ADD  HL,SP   			;055C 39
	LD   (M3333),A   		;055D 323333	<M3333>
	DEC  (HL)    			;0560 35
L0561:	LD   B,E     			;0561 43
	JR   NC,L0596    		;0562 3032	<L0596>
	LD   B,L     			;0564 45
L0565:	LD   (M3731),A   		;0565 323137	<M3731>
	ADD  HL,SP   			;0568 39
	LD   B,E     			;0569 43
	LD   B,(HL)  			;056A 46
	SCF          			;056B 37
	LD   B,L     			;056C 45
	LD   B,L     			;056D 45
	LD   (HL),46H  			;056E 3646	<46H>
	JR   NC,L05A9    		;0570 3037	<L05A9>
L0572:	SCF          			;0572 37
	LD   B,C     			;0573 41
	LD   B,(HL)  			;0574 46
	LD   SP,M4232    		;0575 313242	<M4232>
	LD   (HL),0DH  			;0578 360D	<0DH>
	LD   A,(BC)  			;057A 0A
	LD   A,(M3032)   		;057B 3A3230	<M3032>
	JR   NC,L05B2    		;057E 3032	<L05B2>
	INC  (HL)    			;0580 34
	JR   NC,L05B3    		;0581 3030	<L05B3>
	JR   NC,L05C8    		;0583 3043	<L05C8>
	ADD  HL,SP   			;0585 39
	LD   B,L     			;0586 45
	DEC  (HL)    			;0587 35
	INC  SP      			;0588 33
	LD   B,L     			;0589 45
	JR   NC,L05C3    		;058A 3037	<L05C3>
	LD   B,E     			;058C 43
	LD   B,(HL)  			;058D 46
	INC  SP      			;058E 33
	INC  (HL)    			;058F 34
	SCF          			;0590 37
	LD   B,L     			;0591 45
	LD   B,L     			;0592 45
	LD   (HL),30H  			;0593 3630	<30H>
	SCF          			;0595 37
L0596:	LD   (M3431),A   		;0596 323134	<M3431>
	LD   B,D     			;0599 42
	LD   SP,M4330    		;059A 313043	<M4330>
	LD   B,(HL)  			;059D 46
	INC  (HL)    			;059E 34
	LD   (HL),32H  			;059F 3632	<32H>
	LD   SP,M3132    		;05A1 313231	<M3132>
	JR   C,L05D6     		;05A4 3830	<L05D6>
	SCF          			;05A6 37
	ADD  HL,SP   			;05A7 39
	LD   B,E     			;05A8 43
L05A9:	LD   B,(HL)  			;05A9 46
	SCF          			;05AA 37
	LD   B,L     			;05AB 45
	LD   B,L     			;05AC 45
	LD   (HL),46H  			;05AD 3646	<46H>
	JR   NC,L05F3    		;05AF 3042	<L05F3>
	JR   NC,L05EA    		;05B1 3037	<L05EA>
L05B3:	SCF          			;05B3 37
	LD   B,L     			;05B4 45
	LD   SP,M3943    		;05B5 314339	<M3943>
	LD   (M3331),A   		;05B8 323133	<M3331>
	LD   (HL),38H  			;05BB 3638	<38H>
	JR   NC,L05F6    		;05BD 3037	<L05F6>
	LD   B,L     			;05BF 45
	LD   B,C     			;05C0 41
	SCF          			;05C1 37
	LD   B,E     			;05C2 43
L05C3:	JR   NC,L0608    		;05C3 3043	<L0608>
	LD   SP,M0A0D    		;05C5 310D0A	<M0A0D>
L05C8:	LD   A,(M3032)   		;05C8 3A3230	<M3032>
	JR   NC,L05FF    		;05CB 3032	<L05FF>
	LD   (HL),30H  			;05CD 3630	<30H>
	JR   NC,L0601    		;05CF 3030	<L0601>
	INC  SP      			;05D1 33
	LD   (HL),33H  			;05D2 3633	<33H>
	LD   (HL),30H  			;05D4 3630	<30H>
L05D6:	LD   SP,M3030    		;05D6 313030	<M3030>
	JR   NC,L060D    		;05D9 3032	<L060D>
	LD   (M3545),A   		;05DB 324535	<M3545>
	LD   (HL),37H  			;05DE 3637	<37H>
	LD   B,L     			;05E0 45
	LD   B,C     			;05E1 41
	SCF          			;05E2 37
	LD   (M3038),A   		;05E3 323830	<M3038>
	INC  SP      			;05E6 33
	INC  SP      			;05E7 33
	DEC  (HL)    			;05E8 35
	LD   B,E     			;05E9 43
L05EA:	LD   B,D     			;05EA 42
	LD   B,(HL)  			;05EB 46
	LD   SP,M4243    		;05EC 314342	<M4243>
	JR   NC,L062A    		;05EF 3039	<L062A>
	LD   (M3133),A   		;05F1 323331	<M3133>
	JR   NC,L063C    		;05F4 3046	<L063C>
L05F6:	INC  (HL)    			;05F6 34
	LD   (M3245),A   		;05F7 324532	<M3245>
	LD   (M3937),A   		;05FA 323739	<M3937>
	LD   B,(HL)  			;05FD 46
	LD   (HL),43H  			;05FE 3643	<43H>
	LD   B,(HL)  			;0600 46
L0601:	LD   B,C     			;0601 41
	LD   (HL),41H  			;0602 3641	<41H>
	ADD  HL,SP   			;0604 39
	SCF          			;0605 37
	SCF          			;0606 37
	LD   B,E     			;0607 43
L0608:	ADD  HL,SP   			;0608 39
	LD   B,C     			;0609 41
	LD   B,(HL)  			;060A 46
	LD   (M3031),A   		;060B 323130	<M3031>
	JR   NC,L0640    		;060E 3030	<L0640>
	JR   NC,L0648    		;0610 3036	<L0648>
	LD   (M0A0D),A   		;0612 320D0A	<M0A0D>
	LD   A,(M3032)   		;0615 3A3230	<M3032>
	JR   NC,L064C    		;0618 3032	<L064C>
	JR   C,L064C     		;061A 3830	<L064C>
	JR   NC,L064E    		;061C 3030	<L064E>
	JR   NC,L0651    		;061E 3031	<L0651>
	LD   SP,M3043    		;0620 314330	<M3043>
	JR   NC,L065D    		;0623 3038	<L065D>
	LD   (HL),32H  			;0625 3632	<32H>
	INC  SP      			;0627 33
	LD   SP,M4630    		;0628 313046	<M4630>
	LD   B,E     			;062B 43
	JR   NC,L0672    		;062C 3044	<L0672>
	LD   (M4630),A   		;062E 323046	<M4630>
	ADD  HL,SP   			;0631 39
	LD   B,C     			;0632 41
	SCF          			;0633 37
	LD   (M3038),A   		;0634 323830	<M3038>
	LD   (M3831),A   		;0637 323138	<M3831>
	LD   B,(HL)  			;063A 46
	LD   B,L     			;063B 45
L063C:	LD   (M3031),A   		;063C 323130	<M3031>
	JR   NC,L0672    		;063F 3031	<L0672>
	JR   NC,L0673    		;0641 3030	<L0673>
	LD   (HL),31H  			;0643 3631	<31H>
	LD   B,H     			;0645 44
	LD   SP,M4636    		;0646 313646	<M4636>
	LD   B,(HL)  			;0649 46
	DEC  (HL)    			;064A 35
	LD   B,L     			;064B 45
L064C:	LD   (M3733),A   		;064C 323337	<M3733>
	LD   B,L     			;064F 45
	LD   (M3133),A   		;0650 323331	<M3133>
	LD   (M3031),A   		;0653 323130	<M3031>
	LD   B,(HL)  			;0656 46
	ADD  HL,SP   			;0657 39
	INC  SP      			;0658 33
	LD   B,L     			;0659 45
	JR   NC,L068D    		;065A 3031	<L068D>
	INC  SP      			;065C 33
L065D:	LD   (M3836),A   		;065D 323638	<M3836>
	DEC  C       			;0660 0D
	LD   A,(BC)  			;0661 0A
	LD   A,(M3032)   		;0662 3A3230	<M3032>
	JR   NC,L0699    		;0665 3032	<L0699>
	LD   B,C     			;0667 41
	JR   NC,L069A    		;0668 3030	<L069A>
	JR   NC,L069D    		;066A 3031	<L069D>
	JR   C,L06B4     		;066C 3846	<L06B4>
	LD   B,(HL)  			;066E 46
	INC  SP      			;066F 33
	LD   B,L     			;0670 45
	JR   C,L06A3     		;0671 3830	<L06A3>
L0673:	LD   B,H     			;0673 44
	INC  SP      			;0674 33
	JR   C,L06AB     		;0675 3834	<L06AB>
	LD   B,C     			;0677 41
	LD   B,(HL)  			;0678 46
	LD   B,H     			;0679 44
	INC  SP      			;067A 33
	JR   C,L06B1     		;067B 3834	<L06B1>
	LD   B,H     			;067D 44
	LD   B,D     			;067E 42
	JR   C,L06B1     		;067F 3830	<L06B1>
	LD   B,E     			;0681 43
	LD   B,D     			;0682 42
	SCF          			;0683 37
	SCF          			;0684 37
	LD   (M3238),A   		;0685 323832	<M3238>
	JR   NC,L06BD    		;0688 3033	<L06BD>
	LD   SP,M3030    		;068A 313030	<M3030>
L068D:	JR   C,L06C1     		;068D 3832	<L06C1>
	LD   (M3031),A   		;068F 323130	<M3031>
	JR   NC,L06CC    		;0692 3038	<L06CC>
	JR   NC,L06CD    		;0694 3037	<L06CD>
	LD   B,L     			;0696 45
	INC  SP      			;0697 33
	LD   B,H     			;0698 44
L0699:	LD   B,(HL)  			;0699 46
L069A:	LD   B,L     			;069A 45
	JR   NC,L06D3    		;069B 3036	<L06D3>
L069D:	INC  SP      			;069D 33
	JR   C,L06D0     		;069E 3830	<L06D0>
	INC  (HL)    			;06A0 34
	INC  SP      			;06A1 33
	LD   B,C     			;06A2 41
L06A3:	INC  SP      			;06A3 33
	LD   B,C     			;06A4 41
	LD   SP,M3730    		;06A5 313037	<M3730>
	SCF          			;06A8 37
	LD   B,E     			;06A9 43
	LD   B,H     			;06AA 44
L06AB:	LD   SP,M0D30    		;06AB 31300D	<M0D30>
	LD   A,(BC)  			;06AE 0A
	LD   A,(M3032)   		;06AF 3A3230	<M3032>
	JR   NC,L06E6    		;06B2 3032	<L06E6>
L06B4:	LD   B,E     			;06B4 43
	JR   NC,L06E7    		;06B5 3030	<L06E7>
	JR   NC,L06FF    		;06B7 3046	<L06FF>
	LD   (M3330),A   		;06B9 323033	<M3330>
	LD   B,E     			;06BC 43
L06BD:	LD   B,H     			;06BD 44
	LD   SP,M3038    		;06BE 313830	<M3038>
L06C1:	INC  (HL)    			;06C1 34
	LD   B,(HL)  			;06C2 46
	LD   B,D     			;06C3 42
	LD   B,E     			;06C4 43
	LD   B,H     			;06C5 44
	LD   (M3031),A   		;06C6 323130	<M3031>
	INC  (HL)    			;06C9 34
	LD   B,(HL)  			;06CA 46
	INC  SP      			;06CB 33
L06CC:	LD   B,E     			;06CC 43
L06CD:	LD   B,H     			;06CD 44
	LD   B,(HL)  			;06CE 46
	LD   (M3330),A   		;06CF 323033	<M3330>
	LD   SP,M3138    		;06D2 313831	<M3138>
	LD   (M4244),A   		;06D5 324442	<M4244>
	JR   C,L070B     		;06D8 3831	<L070B>
	LD   B,E     			;06DA 43
	LD   B,D     			;06DB 42
	DEC  (HL)    			;06DC 35
	LD   B,(HL)  			;06DD 46
	LD   (M3138),A   		;06DE 323831	<M3138>
	INC  SP      			;06E1 33
	INC  SP      			;06E2 33
	LD   SP,M3030    		;06E3 313030	<M3030>
L06E6:	JR   C,L071A     		;06E6 3832	<L071A>
	LD   B,E     			;06E8 43
	LD   B,H     			;06E9 44
	DEC  (HL)    			;06EA 35
	LD   B,H     			;06EB 44
	JR   NC,L0722    		;06EC 3034	<L0722>
	LD   B,E     			;06EE 43
	LD   B,H     			;06EF 44
	LD   B,(HL)  			;06F0 46
	LD   (M3330),A   		;06F1 323033	<M3330>
	LD   B,E     			;06F4 43
	LD   B,H     			;06F5 44
	LD   SP,M3238    		;06F6 313832	<M3238>
	LD   B,D     			;06F9 42
	DEC  C       			;06FA 0D
	LD   A,(BC)  			;06FB 0A
	LD   A,(M3032)   		;06FC 3A3230	<M3032>
L06FF:	JR   NC,L0733    		;06FF 3032	<L0733>
	LD   B,L     			;0701 45
	JR   NC,L0734    		;0702 3030	<L0734>
	JR   NC,L0736    		;0704 3030	<L0736>
	INC  (HL)    			;0706 34
	LD   B,(HL)  			;0707 46
	LD   B,D     			;0708 42
	LD   B,E     			;0709 43
	LD   B,H     			;070A 44
L070B:	LD   (HL),39H  			;070B 3639	<39H>
	JR   NC,L0743    		;070D 3034	<L0743>
	LD   B,E     			;070F 43
	INC  SP      			;0710 33
	INC  (HL)    			;0711 34
	JR   C,L0744     		;0712 3830	<L0744>
	INC  SP      			;0714 33
	INC  SP      			;0715 33
	LD   B,C     			;0716 41
	JR   NC,L074A    		;0717 3031	<L074A>
	JR   C,L074B     		;0719 3830	<L074B>
	LD   B,L     			;071B 45
	LD   (HL),34H  			;071C 3634	<34H>
	JR   NC,L0752    		;071E 3032	<L0752>
	JR   C,L0757     		;0720 3835	<L0757>
L0722:	INC  (HL)    			;0722 34
	LD   (M3541),A   		;0723 324135	<M3541>
	LD   B,E     			;0726 43
	JR   C,L0759     		;0727 3830	<L0759>
	LD   SP,M4331    		;0729 313143	<M4331>
	LD   (M3138),A   		;072C 323831	<M3138>
	LD   B,L     			;072F 45
	LD   B,H     			;0730 44
	DEC  (HL)    			;0731 35
	LD   (M3833),A   		;0732 323338	<M3833>
	INC  (HL)    			;0735 34
L0736:	LD   B,C     			;0736 41
	LD   B,C     			;0737 41
	LD   B,(HL)  			;0738 46
	LD   (M3031),A   		;0739 323130	<M3031>
	JR   NC,L0776    		;073C 3038	<L0776>
	JR   NC,L0770    		;073E 3030	<L0770>
	LD   SP,M3230    		;0740 313032	<M3230>
L0743:	JR   NC,L0775    		;0743 3030	<L0775>
	LD   B,L     			;0745 45
	LD   B,E     			;0746 43
	DEC  C       			;0747 0D
	LD   A,(BC)  			;0748 0A
	LD   A,(M3032)   		;0749 3A3230	<M3032>
	JR   NC,L0781    		;074C 3033	<L0781>
	JR   NC,L0780    		;074E 3030	<L0780>
	JR   NC,L0782    		;0750 3030	<L0782>
L0752:	JR   C,L078A     		;0752 3836	<L078A>
	LD   (M3133),A   		;0754 323331	<M3133>
L0757:	JR   NC,L079F    		;0757 3046	<L079F>
L0759:	LD   B,E     			;0759 43
	JR   NC,L07A0    		;075A 3044	<L07A0>
	LD   (M4630),A   		;075C 323046	<M4630>
	ADD  HL,SP   			;075F 39
	LD   B,C     			;0760 41
	SCF          			;0761 37
	LD   (M3330),A   		;0762 323033	<M3330>
	ADD  HL,SP   			;0765 39
	LD   B,L     			;0766 45
	LD   B,H     			;0767 44
	SCF          			;0768 37
	LD   B,D     			;0769 42
	DEC  (HL)    			;076A 35
	LD   B,E     			;076B 43
	JR   C,L079E     		;076C 3830	<L079E>
	LD   B,E     			;076E 43
	LD   B,H     			;076F 44
L0770:	DEC  (HL)    			;0770 35
	LD   B,H     			;0771 44
	JR   NC,L07A8    		;0772 3034	<L07A8>
	LD   (M3331),A   		;0774 323133	<M3331>
	LD   B,D     			;0777 42
	LD   SP,M4430    		;0778 313044	<M4430>
	LD   B,(HL)  			;077B 46
	LD   B,E     			;077C 43
	LD   B,H     			;077D 44
	LD   SP,M3038    		;077E 313830	<M3038>
L0781:	INC  (HL)    			;0781 34
L0782:	LD   B,E     			;0782 43
	LD   B,H     			;0783 44
	LD   (HL),39H  			;0784 3639	<39H>
	JR   NC,L07BC    		;0786 3034	<L07BC>
	LD   B,H     			;0788 44
	LD   B,D     			;0789 42
L078A:	JR   C,L07BC     		;078A 3830	<L07BC>
	INC  SP      			;078C 33
	LD   (M3230),A   		;078D 323032	<M3230>
	JR   C,L07C2     		;0790 3830	<L07C2>
	LD   SP,M0D33    		;0792 31330D	<M0D33>
	LD   A,(BC)  			;0795 0A
	LD   A,(M3032)   		;0796 3A3230	<M3032>
	JR   NC,L07CE    		;0799 3033	<L07CE>
	LD   (M3030),A   		;079B 323030	<M3030>
L079E:	JR   NC,L07E4    		;079E 3044	<L07E4>
L07A0:	LD   B,D     			;07A0 42
	JR   C,L07D4     		;07A1 3831	<L07D4>
	INC  SP      			;07A3 33
	LD   (M3530),A   		;07A4 323035	<M3530>
	JR   C,L07D9     		;07A7 3830	<L07D9>
	LD   B,H     			;07A9 44
	LD   B,D     			;07AA 42
	JR   C,L07DF     		;07AB 3832	<L07DF>
	INC  SP      			;07AD 33
	LD   (M3730),A   		;07AE 323037	<M3730>
	JR   C,L07E3     		;07B1 3830	<L07E3>
	LD   (M3031),A   		;07B3 323130	<M3031>
	LD   SP,M3038    		;07B6 313830	<M3038>
	LD   B,E     			;07B9 43
	LD   B,D     			;07BA 42
	LD   B,E     			;07BB 43
L07BC:	LD   B,L     			;07BC 45
	LD   B,E     			;07BD 43
	LD   B,D     			;07BE 42
	LD   B,D     			;07BF 42
	LD   (HL),45H  			;07C0 3645	<45H>
L07C2:	LD   SP,M3144    		;07C2 314431	<M3144>
	LD   B,E     			;07C5 43
	LD   SP,M3944    		;07C6 314439	<M3944>
	LD   B,L     			;07C9 45
	LD   SP,M3144    		;07CA 314431	<M3144>
	LD   B,E     			;07CD 43
L07CE:	LD   SP,M3146    		;07CE 314631	<M3146>
	LD   B,L     			;07D1 45
	LD   (M3034),A   		;07D2 323430	<M3034>
	JR   NC,L080A    		;07D5 3033	<L080A>
	LD   B,(HL)  			;07D7 46
	LD   SP,M4246    		;07D8 314642	<M4246>
	LD   B,L     			;07DB 45
	LD   B,H     			;07DC 44
	INC  (HL)    			;07DD 34
	DEC  (HL)    			;07DE 35
L07DF:	LD   B,L     			;07DF 45
	DEC  (HL)    			;07E0 35
	DEC  C       			;07E1 0D
	LD   A,(BC)  			;07E2 0A
L07E3:	LD   A,(M3032)   		;07E3 3A3230	<M3032>
	JR   NC,L081B    		;07E6 3033	<L081B>
	INC  (HL)    			;07E8 34
	JR   NC,L081B    		;07E9 3030	<L081B>
	JR   NC,L0833    		;07EB 3046	<L0833>
	LD   SP,M4445    		;07ED 314544	<M4445>
	INC  (HL)    			;07F0 34
	DEC  (HL)    			;07F1 35
	LD   SP,M3045    		;07F2 314530	<M3045>
	LD   (HL),43H  			;07F5 3643	<43H>
	INC  SP      			;07F7 33
	LD   B,(HL)  			;07F8 46
	LD   SP,M3030    		;07F9 313030	<M3030>
	JR   NC,L0834    		;07FC 3036	<L0834>
	INC  SP      			;07FE 33
	JR   C,L0844     		;07FF 3843	<L0844>
	LD   B,H     			;0801 44
	JR   NC,L0845    		;0802 3041	<L0845>
	JR   NC,L084C    		;0804 3046	<L084C>
	LD   (M4631),A   		;0806 323146	<M4631>
	LD   (HL),37H  			;0809 3637	<37H>
	LD   B,E     			;080B 43
	LD   (M3332),A   		;080C 323233	<M3332>
	INC  SP      			;080F 33
	JR   C,L0842     		;0810 3830	<L0842>
	LD   (M3331),A   		;0812 323133	<M3331>
	LD   B,(HL)  			;0815 46
	LD   SP,M4430    		;0816 313044	<M4430>
	LD   B,(HL)  			;0819 46
	LD   B,(HL)  			;081A 46
L081B:	INC  SP      			;081B 33
	LD   (M4531),A   		;081C 323145	<M4531>
	LD   B,C     			;081F 41
	JR   C,L0853     		;0820 3831	<L0853>
	JR   NC,L0855    		;0822 3031	<L0855>
	JR   NC,L0856    		;0824 3030	<L0856>
	LD   SP,M3736    		;0826 313637	<M3736>
	LD   SP,M3332    		;0829 313233	<M3332>
	ADD  HL,SP   			;082C 39
	LD   B,H     			;082D 44
	DEC  C       			;082E 0D
	LD   A,(BC)  			;082F 0A
	LD   A,(M3032)   		;0830 3A3230	<M3032>
L0833:	JR   NC,L0868    		;0833 3033	<L0868>
	LD   (HL),30H  			;0835 3630	<30H>
	JR   NC,L0869    		;0837 3030	<L0869>
	LD   SP,M4630    		;0839 313046	<M4630>
	LD   B,E     			;083C 43
	LD   B,(HL)  			;083D 46
	LD   B,D     			;083E 42
	LD   B,E     			;083F 43
	LD   B,H     			;0840 44
	SCF          			;0841 37
L0842:	SCF          			;0842 37
	JR   NC,L0879    		;0843 3034	<L0879>
L0845:	LD   B,E     			;0845 43
	LD   B,H     			;0846 44
	ADD  HL,SP   			;0847 39
	ADD  HL,SP   			;0848 39
	JR   NC,L087F    		;0849 3034	<L087F>
	LD   B,E     			;084B 43
L084C:	LD   B,H     			;084C 44
	LD   SP,M3041    		;084D 314130	<M3041>
	LD   B,(HL)  			;0850 46
	INC  SP      			;0851 33
	LD   B,C     			;0852 41
L0853:	DEC  (HL)    			;0853 35
	LD   B,(HL)  			;0854 46
L0855:	JR   C,L0887     		;0855 3830	<L0887>
	JR   NC,L089F    		;0857 3046	<L089F>
	INC  SP      			;0859 33
	JR   C,L088F     		;085A 3833	<L088F>
	JR   NC,L08A3    		;085C 3045	<L08A3>
	LD   B,(HL)  			;085E 46
	INC  SP      			;085F 33
	LD   B,C     			;0860 41
	LD   SP,M3838    		;0861 313838	<M3838>
	JR   NC,L08AC    		;0864 3046	<L08AC>
	LD   B,L     			;0866 45
	JR   NC,L089B    		;0867 3032	<L089B>
L0869:	LD   (M3038),A   		;0869 323830	<M3038>
	LD   B,C     			;086C 41
	LD   (M3341),A   		;086D 324133	<M3341>
	INC  SP      			;0870 33
	JR   C,L08A3     		;0871 3830	<L08A3>
	SCF          			;0873 37
	LD   B,E     			;0874 43
	LD   B,D     			;0875 42
	DEC  (HL)    			;0876 35
	LD   (M3130),A   		;0877 323031	<M3130>
	LD   B,H     			;087A 44
	DEC  C       			;087B 0D
	LD   A,(BC)  			;087C 0A
	LD   A,(M3032)   		;087D 3A3230	<M3032>
	JR   NC,L08B5    		;0880 3033	<L08B5>
	JR   C,L08B4     		;0882 3830	<L08B4>
	JR   NC,L08B6    		;0884 3030	<L08B6>
	JR   NC,L08BB    		;0886 3033	<L08BB>
	INC  SP      			;0888 33
	LD   B,L     			;0889 45
	JR   NC,L08BD    		;088A 3031	<L08BD>
	LD   B,(HL)  			;088C 46
	LD   B,(HL)  			;088D 46
	LD   B,E     			;088E 43
L088F:	LD   B,H     			;088F 44
	INC  SP      			;0890 33
	LD   B,H     			;0891 44
	JR   NC,L08DA    		;0892 3046	<L08DA>
	LD   B,(HL)  			;0894 46
	SCF          			;0895 37
	LD   B,E     			;0896 43
	LD   B,H     			;0897 44
	LD   B,L     			;0898 45
	LD   B,D     			;0899 42
	JR   NC,L08D0    		;089A 3034	<L08D0>
	LD   B,E     			;089C 43
	LD   B,H     			;089D 44
	INC  SP      			;089E 33
L089F:	LD   B,C     			;089F 41
	JR   NC,L08D7    		;08A0 3035	<L08D7>
	LD   B,E     			;08A2 43
L08A3:	LD   B,H     			;08A3 44
	JR   NC,L08EA    		;08A4 3044	<L08EA>
	JR   NC,L08DE    		;08A6 3036	<L08DE>
	LD   B,E     			;08A8 43
	LD   B,H     			;08A9 44
	ADD  HL,SP   			;08AA 39
	LD   B,D     			;08AB 42
L08AC:	JR   NC,L08E4    		;08AC 3036	<L08E4>
	INC  SP      			;08AE 33
	LD   B,C     			;08AF 41
	DEC  (HL)    			;08B0 35
	JR   C,L08EB     		;08B1 3838	<L08EB>
	JR   NC,L08F6    		;08B3 3041	<L08F6>
L08B5:	SCF          			;08B5 37
L08B6:	LD   (M4438),A   		;08B6 323844	<M4438>
	ADD  HL,SP   			;08B9 39
	LD   B,E     			;08BA 43
L08BB:	LD   B,H     			;08BB 44
	INC  SP      			;08BC 33
L08BD:	LD   B,H     			;08BD 44
	JR   NC,L08F7    		;08BE 3037	<L08F7>
	INC  SP      			;08C0 33
	JR   NC,L0908    		;08C1 3045	<L0908>
	JR   C,L090A     		;08C3 3845	<L090A>
	SCF          			;08C5 37
	LD   (M0D43),A   		;08C6 32430D	<M0D43>
	LD   A,(BC)  			;08C9 0A
	LD   A,(M3032)   		;08CA 3A3230	<M3032>
	JR   NC,L0902    		;08CD 3033	<L0902>
	LD   B,C     			;08CF 41
L08D0:	JR   NC,L0902    		;08D0 3030	<L0902>
	JR   NC,L0905    		;08D2 3031	<L0905>
	JR   C,L0906     		;08D4 3830	<L0906>
	LD   B,E     			;08D6 43
L08D7:	LD   B,E     			;08D7 43
	LD   B,H     			;08D8 44
	LD   B,C     			;08D9 41
L08DA:	SCF          			;08DA 37
	JR   NC,L0914    		;08DB 3037	<L0914>
	LD   B,(HL)  			;08DD 46
L08DE:	SCF          			;08DE 37
	LD   B,E     			;08DF 43
	LD   B,H     			;08E0 44
	LD   B,L     			;08E1 45
	LD   B,D     			;08E2 42
	JR   NC,L0919    		;08E3 3034	<L0919>
	LD   B,E     			;08E5 43
	LD   B,H     			;08E6 44
	INC  SP      			;08E7 33
	LD   B,H     			;08E8 44
	JR   NC,L0922    		;08E9 3037	<L0922>
L08EB:	INC  SP      			;08EB 33
	JR   NC,L0934    		;08EC 3046	<L0934>
	SCF          			;08EE 37
	LD   B,E     			;08EF 43
	LD   B,H     			;08F0 44
	LD   B,E     			;08F1 43
	JR   NC,L0924    		;08F2 3030	<L0924>
	SCF          			;08F4 37
	LD   B,E     			;08F5 43
L08F6:	LD   B,H     			;08F6 44
L08F7:	DEC  (HL)    			;08F7 35
	LD   B,H     			;08F8 44
	JR   NC,L092F    		;08F9 3034	<L092F>
	LD   B,E     			;08FB 43
	LD   B,H     			;08FC 44
	LD   B,H     			;08FD 44
	LD   B,L     			;08FE 45
	JR   NC,L0942    		;08FF 3041	<L0942>
	LD   B,(HL)  			;0901 46
L0902:	SCF          			;0902 37
	LD   B,E     			;0903 43
	LD   B,H     			;0904 44
L0905:	LD   B,H     			;0905 44
L0906:	LD   B,(HL)  			;0906 46
	JR   NC,L0940    		;0907 3037	<L0940>
	INC  SP      			;0909 33
L090A:	JR   NC,L0952    		;090A 3046	<L0952>
	LD   B,C     			;090C 41
	LD   B,E     			;090D 43
	LD   B,H     			;090E 44
	LD   B,(HL)  			;090F 46
	LD   B,L     			;0910 45
	JR   NC,L094A    		;0911 3037	<L094A>
	ADD  HL,SP   			;0913 39
L0914:	LD   (HL),0DH  			;0914 360D	<0DH>
	LD   A,(BC)  			;0916 0A
	LD   A,(M3032)   		;0917 3A3230	<M3032>
	JR   NC,L094F    		;091A 3033	<L094F>
	LD   B,E     			;091C 43
	JR   NC,L094F    		;091D 3030	<L094F>
	JR   NC,L0954    		;091F 3033	<L0954>
	LD   B,L     			;0921 45
L0922:	LD   B,L     			;0922 45
	JR   NC,L0968    		;0923 3043	<L0968>
	LD   B,H     			;0925 44
	LD   SP,M3038    		;0926 313830	<M3038>
	JR   C,L095B     		;0929 3830	<L095B>
	LD   (HL),33H  			;092B 3633	<33H>
	JR   C,L0972     		;092D 3843	<L0972>
L092F:	LD   B,H     			;092F 44
	JR   NC,L0973    		;0930 3041	<L0973>
	JR   NC,L097A    		;0932 3046	<L097A>
L0934:	LD   B,(HL)  			;0934 46
	SCF          			;0935 37
	LD   B,E     			;0936 43
	LD   B,H     			;0937 44
	DEC  (HL)    			;0938 35
	LD   B,E     			;0939 43
	JR   NC,L0982    		;093A 3046	<L0982>
	LD   B,E     			;093C 43
	LD   B,H     			;093D 44
	JR   C,L0985     		;093E 3845	<L0985>
L0940:	JR   NC,L0988    		;0940 3046	<L0988>
L0942:	LD   B,E     			;0942 43
	LD   B,H     			;0943 44
	INC  SP      			;0944 33
	LD   B,D     			;0945 42
	JR   NC,L0980    		;0946 3038	<L0980>
	INC  SP      			;0948 33
	JR   C,L0990     		;0949 3845	<L0990>
	LD   B,E     			;094B 43
	LD   B,E     			;094C 43
	LD   B,H     			;094D 44
	DEC  (HL)    			;094E 35
L094F:	LD   B,E     			;094F 43
	JR   NC,L098A    		;0950 3038	<L098A>
L0952:	INC  SP      			;0952 33
	JR   NC,L099A    		;0953 3045	<L099A>
	LD   B,(HL)  			;0955 46
	LD   B,E     			;0956 43
	LD   B,H     			;0957 44
	LD   (HL),41H  			;0958 3641	<41H>
	JR   NC,L0994    		;095A 3038	<L0994>
	LD   B,H     			;095C 44
	LD   B,E     			;095D 43
	JR   C,L09A6     		;095E 3846	<L09A6>
	LD   (M0D37),A   		;0960 32370D	<M0D37>
	LD   A,(BC)  			;0963 0A
	LD   A,(M3032)   		;0964 3A3230	<M3032>
	JR   NC,L099C    		;0967 3033	<L099C>
	LD   B,L     			;0969 45
	JR   NC,L099C    		;096A 3030	<L099C>
	JR   NC,L099E    		;096C 3030	<L099E>
	LD   B,D     			;096E 42
	LD   B,E     			;096F 43
	LD   B,H     			;0970 44
	LD   B,L     			;0971 45
L0972:	LD   (M3830),A   		;0972 323038	<M3830>
	LD   (M4530),A   		;0975 323045	<M4530>
	INC  (HL)    			;0978 34
	LD   B,E     			;0979 43
L097A:	LD   B,H     			;097A 44
	LD   B,L     			;097B 45
	LD   B,L     			;097C 45
	JR   NC,L09B7    		;097D 3038	<L09B7>
	LD   B,E     			;097F 43
L0980:	LD   B,H     			;0980 44
	SCF          			;0981 37
L0982:	SCF          			;0982 37
	JR   NC,L09BE    		;0983 3039	<L09BE>
L0985:	LD   B,E     			;0985 43
	LD   B,H     			;0986 44
	LD   B,(HL)  			;0987 46
L0988:	LD   B,D     			;0988 42
	JR   NC,L09C4    		;0989 3039	<L09C4>
	LD   B,E     			;098B 43
	INC  SP      			;098C 33
	INC  (HL)    			;098D 34
	JR   C,L09C0     		;098E 3830	<L09C0>
L0990:	INC  SP      			;0990 33
	LD   B,H     			;0991 44
	LD   SP,M3132    		;0992 313231	<M3132>
	JR   NC,L09C8    		;0995 3031	<L09C8>
	JR   C,L09C9     		;0997 3830	<L09C9>
	JR   NC,L09CC    		;0999 3031	<L09CC>
	LD   B,(HL)  			;099B 46
L099C:	LD   B,(HL)  			;099C 46
	JR   NC,L09D0    		;099D 3031	<L09D0>
	INC  SP      			;099F 33
	LD   B,L     			;09A0 45
	DEC  (HL)    			;09A1 35
	DEC  (HL)    			;09A2 35
	SCF          			;09A3 37
	SCF          			;09A4 37
	LD   B,D     			;09A5 42
L09A6:	LD   B,L     			;09A6 45
	LD   (M3130),A   		;09A7 323031	<M3130>
	INC  (HL)    			;09AA 34
	LD   (M4146),A   		;09AB 324641	<M4146>
	ADD  HL,SP   			;09AE 39
	DEC  C       			;09AF 0D
	LD   A,(BC)  			;09B0 0A
	LD   A,(M3032)   		;09B1 3A3230	<M3032>
	JR   NC,L09EA    		;09B4 3034	<L09EA>
	JR   NC,L09E8    		;09B6 3030	<L09E8>
	JR   NC,L09EA    		;09B8 3030	<L09EA>
	SCF          			;09BA 37
	SCF          			;09BB 37
	ADD  HL,SP   			;09BC 39
	LD   (HL),32H  			;09BD 3632	<32H>
	JR   NC,L09F1    		;09BF 3030	<L09F1>
	LD   B,(HL)  			;09C1 46
	SCF          			;09C2 37
	SCF          			;09C3 37
L09C4:	LD   (M3033),A   		;09C4 323330	<M3033>
	LD   B,D     			;09C7 42
L09C8:	SCF          			;09C8 37
L09C9:	JR   C,L0A0D     		;09C9 3842	<L0A0D>
	LD   SP,M3032    		;09CB 313230	<M3032>
	LD   B,L     			;09CE 45
	LD   B,L     			;09CF 45
L09D0:	LD   B,H     			;09D0 44
	DEC  (HL)    			;09D1 35
	LD   (M4631),A   		;09D2 323146	<M4631>
	LD   B,(HL)  			;09D5 46
	JR   NC,L0A1E    		;09D6 3046	<L0A1E>
	LD   (M3032),A   		;09D8 323230	<M3032>
	LD   B,C     			;09DB 41
	JR   C,L0A0E     		;09DC 3830	<L0A0E>
	LD   B,E     			;09DE 43
	ADD  HL,SP   			;09DF 39
	LD   SP,M3545    		;09E0 314535	<M3545>
	LD   B,D     			;09E3 42
	LD   B,E     			;09E4 43
	INC  SP      			;09E5 33
	LD   B,(HL)  			;09E6 46
	LD   SP,M3030    		;09E7 313030	<M3030>
L09EA:	INC  SP      			;09EA 33
	LD   B,L     			;09EB 45
	JR   C,L0A1E     		;09EC 3830	<L0A1E>
	INC  SP      			;09EE 33
	LD   (M3232),A   		;09EF 323232	<M3232>
	LD   B,(HL)  			;09F2 46
	LD   B,(HL)  			;09F3 46
	INC  SP      			;09F4 33
	LD   (M3033),A   		;09F5 323330	<M3033>
	LD   B,(HL)  			;09F8 46
	LD   B,(HL)  			;09F9 46
	LD   B,C     			;09FA 41
	LD   B,E     			;09FB 43
	DEC  C       			;09FC 0D
	LD   A,(BC)  			;09FD 0A
	LD   A,(M3032)   		;09FE 3A3230	<M3032>
	JR   NC,L0A37    		;0A01 3034	<L0A37>
	LD   (M3030),A   		;0A03 323030	<M3030>
	JR   NC,L0A4B    		;0A06 3043	<L0A4B>
	ADD  HL,SP   			;0A08 39
	LD   SP,M3031    		;0A09 313130	<M3031>
	LD   B,E     			;0A0C 43
L0A0D:	JR   C,L0A3F     		;0A0D 3830	<L0A3F>
	INC  SP      			;0A0F 33
	LD   B,L     			;0A10 45
	LD   B,(HL)  			;0A11 46
	LD   B,(HL)  			;0A12 46
	LD   SP,M3232    		;0A13 313232	<M3232>
	LD   SP,M3030    		;0A16 313030	<M3030>
	JR   C,L0A4B     		;0A19 3830	<L0A4B>
	INC  (HL)    			;0A1B 34
	LD   (HL),31H  			;0A1C 3631	<31H>
L0A1E:	INC  SP      			;0A1E 33
	LD   (M3045),A   		;0A1F 324530	<M3045>
	LD   (HL),37H  			;0A22 3637	<37H>
	JR   C,L0A6C     		;0A24 3846	<L0A6C>
	LD   (HL),46H  			;0A26 3646	<46H>
	JR   NC,L0A5B    		;0A28 3031	<L0A5B>
	LD   (M3746),A   		;0A2A 324637	<M3746>
	INC  SP      			;0A2D 33
	LD   B,C     			;0A2E 41
	JR   NC,L0A64    		;0A2F 3033	<L0A64>
	JR   C,L0A63     		;0A31 3830	<L0A63>
	LD   B,E     			;0A33 43
	LD   B,D     			;0A34 42
	LD   (HL),46H  			;0A35 3646	<46H>
L0A37:	LD   (M3130),A   		;0A37 323031	<M3130>
	JR   NC,L0A7F    		;0A3A 3043	<L0A7F>
	LD   B,D     			;0A3C 42
	DEC  (HL)    			;0A3D 35
	LD   B,L     			;0A3E 45
L0A3F:	LD   (M4638),A   		;0A3F 323846	<M4638>
	INC  (HL)    			;0A42 34
	LD   B,E     			;0A43 43
	LD   B,D     			;0A44 42
	ADD  HL,SP   			;0A45 39
	LD   B,L     			;0A46 45
	ADD  HL,SP   			;0A47 39
	LD   B,H     			;0A48 44
	DEC  C       			;0A49 0D
	LD   A,(BC)  			;0A4A 0A
L0A4B:	LD   A,(M3032)   		;0A4B 3A3230	<M3032>
	JR   NC,L0A84    		;0A4E 3034	<L0A84>
	INC  (HL)    			;0A50 34
	JR   NC,L0A83    		;0A51 3030	<L0A83>
	JR   NC,L0A85    		;0A53 3030	<L0A85>
	INC  (HL)    			;0A55 34
	INC  SP      			;0A56 33
	LD   B,L     			;0A57 45
	JR   NC,L0A90    		;0A58 3036	<L0A90>
	LD   B,D     			;0A5A 42
L0A5B:	JR   C,L0A90     		;0A5B 3833	<L0A90>
	JR   NC,L0AA4    		;0A5D 3045	<L0AA4>
	JR   C,L0A91     		;0A5F 3830	<L0A91>
	LD   (HL),30H  			;0A61 3630	<30H>
L0A63:	LD   SP,M3831    		;0A63 313138	<M3831>
	LD   B,L     			;0A66 45
	INC  (HL)    			;0A67 34
	INC  SP      			;0A68 33
	LD   B,L     			;0A69 45
	LD   B,(HL)  			;0A6A 46
	JR   NC,L0A9E    		;0A6B 3031	<L0A9E>
	LD   (M3746),A   		;0A6D 324637	<M3746>
	INC  SP      			;0A70 33
	LD   B,C     			;0A71 41
	JR   NC,L0AA8    		;0A72 3034	<L0AA8>
	JR   C,L0AA6     		;0A74 3830	<L0AA6>
	LD   B,E     			;0A76 43
	LD   B,D     			;0A77 42
	SCF          			;0A78 37
	SCF          			;0A79 37
	LD   (M4638),A   		;0A7A 323846	<M4638>
	JR   C,L0AB1     		;0A7D 3832	<L0AB1>
L0A7F:	LD   B,L     			;0A7F 45
	JR   NC,L0AB2    		;0A80 3030	<L0AB2>
	SCF          			;0A82 37
L0A83:	JR   NC,L0AC6    		;0A83 3041	<L0AC6>
L0A85:	LD   B,(HL)  			;0A85 46
	LD   SP,M3132    		;0A86 313231	<M3132>
	LD   B,D     			;0A89 42
	LD   SP,M4332    		;0A8A 313243	<M4332>
	ADD  HL,SP   			;0A8D 39
	INC  SP      			;0A8E 33
	LD   B,C     			;0A8F 41
L0A90:	JR   NC,L0AC2    		;0A90 3030	<L0AC2>
	JR   C,L0AC4     		;0A92 3830	<L0AC4>
	LD   SP,M0D42    		;0A94 31420D	<M0D42>
	LD   A,(BC)  			;0A97 0A
	LD   A,(M3032)   		;0A98 3A3230	<M3032>
	JR   NC,L0AD1    		;0A9B 3034	<L0AD1>
	LD   (HL),30H  			;0A9D 3630	<30H>
	JR   NC,L0AD1    		;0A9F 3030	<L0AD1>
	INC  SP      			;0AA1 33
	LD   B,H     			;0AA2 44
	LD   B,(HL)  			;0AA3 46
L0AA4:	LD   B,L     			;0AA4 45
	JR   NC,L0ADD    		;0AA5 3036	<L0ADD>
	LD   B,H     			;0AA7 44
L0AA8:	JR   C,L0ADB     		;0AA8 3831	<L0ADB>
	LD   B,L     			;0AAA 45
	SCF          			;0AAB 37
	LD   B,H     			;0AAC 44
	LD   B,E     			;0AAD 43
	INC  SP      			;0AAE 33
	LD   B,(HL)  			;0AAF 46
	LD   SP,M3030    		;0AB0 313030	<M3030>
	LD   B,H     			;0AB3 44
	LD   B,D     			;0AB4 42
	JR   C,L0AE8     		;0AB5 3831	<L0AE8>
	LD   B,L     			;0AB7 45
	LD   (HL),30H  			;0AB8 3630	<30H>
	DEC  (HL)    			;0ABA 35
	INC  (HL)    			;0ABB 34
	SCF          			;0ABC 37
	LD   (M3031),A   		;0ABD 323130	<M3031>
	LD   SP,M3038    		;0AC0 313830	<M3038>
	SCF          			;0AC3 37
L0AC4:	LD   B,L     			;0AC4 45
	LD   B,L     			;0AC5 45
L0AC6:	LD   (HL),46H  			;0AC6 3646	<46H>
	LD   B,C     			;0AC8 41
	LD   B,D     			;0AC9 42
	JR   NC,L0B03    		;0ACA 3037	<L0B03>
	SCF          			;0ACC 37
	LD   B,E     			;0ACD 43
	ADD  HL,SP   			;0ACE 39
	JR   NC,L0B02    		;0ACF 3031	<L0B02>
L0AD1:	JR   NC,L0B16    		;0AD1 3043	<L0B16>
	JR   NC,L0B05    		;0AD3 3030	<L0B05>
	LD   (M3231),A   		;0AD5 323132	<M3231>
	ADD  HL,SP   			;0AD8 39
	LD   SP,M3131    		;0AD9 313131	<M3131>
	LD   SP,M4437    		;0ADC 313744	<M4437>
	JR   C,L0B11     		;0ADF 3830	<L0B11>
	LD   (M0D30),A   		;0AE1 32300D	<M0D30>
	LD   A,(BC)  			;0AE4 0A
	LD   A,(M3032)   		;0AE5 3A3230	<M3032>
L0AE8:	JR   NC,L0B1E    		;0AE8 3034	<L0B1E>
	JR   C,L0B1C     		;0AEA 3830	<L0B1C>
	JR   NC,L0B1E    		;0AEC 3030	<L0B1E>
	LD   B,L     			;0AEE 45
	LD   B,H     			;0AEF 44
	LD   B,D     			;0AF0 42
	JR   NC,L0B25    		;0AF1 3032	<L0B25>
	LD   SP,M4531    		;0AF3 313145	<M4531>
	JR   C,L0B28     		;0AF6 3830	<L0B28>
	INC  SP      			;0AF8 33
	LD   (HL),45H  			;0AF9 3645	<45H>
	JR   NC,L0B2F    		;0AFB 3032	<L0B2F>
	LD   B,L     			;0AFD 45
	JR   NC,L0B31    		;0AFE 3031	<L0B31>
	LD   B,E     			;0B00 43
	LD   B,D     			;0B01 42
L0B02:	LD   B,C     			;0B02 41
L0B03:	LD   B,L     			;0B03 45
	LD   B,E     			;0B04 43
L0B05:	LD   B,D     			;0B05 42
	LD   B,(HL)  			;0B06 46
	LD   B,L     			;0B07 45
	LD   B,L     			;0B08 45
	LD   B,H     			;0B09 44
	INC  (HL)    			;0B0A 34
	INC  SP      			;0B0B 33
	JR   C,L0B47     		;0B0C 3839	<L0B47>
	JR   C,L0B40     		;0B0E 3830	<L0B40>
	LD   (M3545),A   		;0B10 324535	<M3545>
	JR   C,L0B49     		;0B13 3834	<L0B49>
	LD   B,L     			;0B15 45
L0B16:	SCF          			;0B16 37
	JR   NC,L0B4B    		;0B17 3032	<L0B4B>
	LD   B,L     			;0B19 45
	LD   (HL),41H  			;0B1A 3641	<41H>
L0B1C:	SCF          			;0B1C 37
	JR   NC,L0B62    		;0B1D 3043	<L0B62>
	ADD  HL,SP   			;0B1F 39
	LD   (M3531),A   		;0B20 323135	<M3531>
	LD   B,L     			;0B23 45
	JR   C,L0B56     		;0B24 3830	<L0B56>
	SCF          			;0B26 37
	LD   B,L     			;0B27 45
L0B28:	INC  SP      			;0B28 33
	LD   (HL),30H  			;0B29 3630	<30H>
	JR   NC,L0B5E    		;0B2B 3031	<L0B5E>
	LD   SP,M3736    		;0B2D 313637	<M3736>
	DEC  C       			;0B30 0D
L0B31:	LD   A,(BC)  			;0B31 0A
	LD   A,(M3032)   		;0B32 3A3230	<M3032>
	JR   NC,L0B6B    		;0B35 3034	<L0B6B>
	LD   B,C     			;0B37 41
	JR   NC,L0B6A    		;0B38 3030	<L0B6A>
	JR   NC,L0B71    		;0B3A 3035	<L0B71>
	LD   B,(HL)  			;0B3C 46
	JR   C,L0B6F     		;0B3D 3830	<L0B6F>
	JR   NC,L0B87    		;0B3F 3046	<L0B87>
	INC  SP      			;0B41 33
	JR   NC,L0B75    		;0B42 3031	<L0B75>
	LD   SP,M3132    		;0B44 313231	<M3132>
L0B47:	LD   SP,M3038    		;0B47 313830	<M3038>
	LD   SP,M3232    		;0B4A 313232	<M3232>
	LD   (M3846),A   		;0B4D 324638	<M3846>
	JR   NC,L0B89    		;0B50 3037	<L0B89>
	ADD  HL,SP   			;0B52 39
	INC  SP      			;0B53 33
	LD   (M4135),A   		;0B54 323541	<M4135>
	JR   C,L0B89     		;0B57 3830	<L0B89>
	INC  SP      			;0B59 33
	LD   B,L     			;0B5A 45
	JR   NC,L0B95    		;0B5B 3038	<L0B95>
	LD   B,(HL)  			;0B5D 46
L0B5E:	LD   B,(HL)  			;0B5E 46
	LD   B,L     			;0B5F 45
	LD   B,D     			;0B60 42
	LD   B,E     			;0B61 43
L0B62:	LD   B,D     			;0B62 42
	LD   B,E     			;0B63 43
	LD   (HL),43H  			;0B64 3643	<43H>
	ADD  HL,SP   			;0B66 39
	JR   NC,L0BAF    		;0B67 3046	<L0BAF>
	INC  SP      			;0B69 33
L0B6A:	JR   NC,L0B9D    		;0B6A 3031	<L0B9D>
	DEC  (HL)    			;0B6C 35
	LD   (M3245),A   		;0B6D 324532	<M3245>
	LD   (M4243),A   		;0B70 324342	<M4243>
	LD   B,(HL)  			;0B73 46
	LD   (HL),32H  			;0B74 3632	<32H>
	LD   B,L     			;0B76 45
	LD   (M4334),A   		;0B77 323443	<M4334>
	LD   B,D     			;0B7A 42
	SCF          			;0B7B 37
	LD   SP,M0A0D    		;0B7C 310D0A	<M0A0D>
	LD   A,(M3032)   		;0B7F 3A3230	<M3032>
	JR   NC,L0BB8    		;0B82 3034	<L0BB8>
	LD   B,E     			;0B84 43
	JR   NC,L0BB7    		;0B85 3030	<L0BB7>
L0B87:	JR   NC,L0BCE    		;0B87 3045	<L0BCE>
L0B89:	LD   B,L     			;0B89 45
	LD   (M3031),A   		;0B8A 323130	<M3031>
	LD   B,E     			;0B8D 43
	JR   NC,L0BC8    		;0B8E 3038	<L0BC8>
	LD   (M3832),A   		;0B90 323238	<M3832>
	LD   B,D     			;0B93 42
	JR   C,L0BC6     		;0B94 3830	<L0BC6>
	INC  SP      			;0B96 33
	LD   B,L     			;0B97 45
	JR   NC,L0BD0    		;0B98 3036	<L0BD0>
	LD   B,(HL)  			;0B9A 46
	LD   B,(HL)  			;0B9B 46
	LD   B,L     			;0B9C 45
L0B9D:	LD   B,D     			;0B9D 42
	LD   B,E     			;0B9E 43
	LD   B,D     			;0B9F 42
	LD   B,E     			;0BA0 43
	LD   B,L     			;0BA1 45
	LD   B,E     			;0BA2 43
	ADD  HL,SP   			;0BA3 39
	JR   NC,L0BEC    		;0BA4 3046	<L0BEC>
	LD   B,H     			;0BA6 44
	JR   NC,L0BDB    		;0BA7 3032	<L0BDB>
	LD   B,L     			;0BA9 45
	LD   (M4332),A   		;0BAA 323243	<M4332>
	LD   B,D     			;0BAD 42
	LD   B,(HL)  			;0BAE 46
L0BAF:	LD   B,L     			;0BAF 45
	LD   (M3245),A   		;0BB0 324532	<M3245>
	INC  (HL)    			;0BB3 34
	LD   B,E     			;0BB4 43
	LD   B,D     			;0BB5 42
	LD   B,(HL)  			;0BB6 46
L0BB7:	LD   (HL),32H  			;0BB7 3632	<32H>
	LD   SP,M4531    		;0BB9 313145	<M4531>
	JR   NC,L0BF1    		;0BBC 3033	<L0BF1>
	LD   (M3832),A   		;0BBE 323238	<M3832>
	LD   B,H     			;0BC1 44
	JR   C,L0BF4     		;0BC2 3830	<L0BF4>
	INC  SP      			;0BC4 33
	LD   B,L     			;0BC5 45
L0BC6:	JR   NC,L0BFC    		;0BC6 3034	<L0BFC>
L0BC8:	SCF          			;0BC8 37
	LD   B,L     			;0BC9 45
	DEC  C       			;0BCA 0D
	LD   A,(BC)  			;0BCB 0A
	LD   A,(M3032)   		;0BCC 3A3230	<M3032>
	JR   NC,L0C05    		;0BCF 3034	<L0C05>
	LD   B,L     			;0BD1 45
	JR   NC,L0C04    		;0BD2 3030	<L0C04>
	JR   NC,L0C1C    		;0BD4 3046	<L0C1C>
	LD   B,(HL)  			;0BD6 46
	INC  SP      			;0BD7 33
	LD   B,L     			;0BD8 45
	JR   NC,L0C0F    		;0BD9 3034	<L0C0F>
L0BDB:	LD   SP,M4332    		;0BDB 313243	<M4332>
	ADD  HL,SP   			;0BDE 39
	INC  SP      			;0BDF 33
	LD   B,C     			;0BE0 41
	DEC  (HL)    			;0BE1 35
	LD   B,(HL)  			;0BE2 46
	JR   C,L0C15     		;0BE3 3830	<L0C15>
	LD   B,L     			;0BE5 45
	LD   (HL),30H  			;0BE6 3630	<30H>
	LD   (HL),43H  			;0BE8 3643	<43H>
	ADD  HL,SP   			;0BEA 39
	LD   SP,M3331    		;0BEB 313133	<M3331>
	ADD  HL,SP   			;0BEE 39
	JR   C,L0C21     		;0BEF 3830	<L0C21>
L0BF1:	INC  SP      			;0BF1 33
	LD   B,L     			;0BF2 45
	JR   NC,L0C2C    		;0BF3 3037	<L0C2C>
	LD   SP,M3232    		;0BF5 313232	<M3232>
	LD   SP,M3332    		;0BF8 313233	<M3332>
	JR   C,L0C2D     		;0BFB 3830	<L0C2D>
	INC  (HL)    			;0BFD 34
	LD   B,L     			;0BFE 45
	LD   B,(HL)  			;0BFF 46
	SCF          			;0C00 37
	JR   NC,L0C39    		;0C01 3036	<L0C39>
	JR   NC,L0C3D    		;0C03 3038	<L0C3D>
L0C05:	LD   B,H     			;0C05 44
	SCF          			;0C06 37
	LD   (M3038),A   		;0C07 323830	<M3038>
	LD   B,L     			;0C0A 45
	LD   B,L     			;0C0B 45
	SCF          			;0C0C 37
	LD   (M3045),A   		;0C0D 324530	<M3045>
	LD   SP,M4243    		;0C10 314342	<M4243>
	ADD  HL,SP   			;0C13 39
	LD   B,L     			;0C14 45
L0C15:	INC  (HL)    			;0C15 34
	LD   B,L     			;0C16 45
	DEC  C       			;0C17 0D
	LD   A,(BC)  			;0C18 0A
	LD   A,(M3032)   		;0C19 3A3230	<M3032>
L0C1C:	JR   NC,L0C53    		;0C1C 3035	<L0C53>
	JR   NC,L0C50    		;0C1E 3030	<L0C50>
	JR   NC,L0C52    		;0C20 3030	<L0C52>
	LD   SP,M4141    		;0C22 314141	<M4141>
	SCF          			;0C25 37
	LD   (M4630),A   		;0C26 323046	<M4630>
	LD   SP,M3631    		;0C29 313136	<M3631>
L0C2C:	LD   B,H     			;0C2C 44
L0C2D:	LD   B,E     			;0C2D 43
	LD   B,E     			;0C2E 43
	LD   B,H     			;0C2F 44
	JR   NC,L0C77    		;0C30 3045	<L0C77>
	JR   NC,L0C69    		;0C32 3035	<L0C69>
	LD   B,E     			;0C34 43
	LD   B,D     			;0C35 42
	LD   (HL),31H  			;0C36 3631	<31H>
	LD   B,E     			;0C38 43
L0C39:	JR   C,L0C80     		;0C39 3845	<L0C80>
	LD   B,(HL)  			;0C3B 46
	LD   B,E     			;0C3C 43
L0C3D:	ADD  HL,SP   			;0C3D 39
	LD   (M3031),A   		;0C3E 323130	<M3031>
	LD   B,L     			;0C41 45
	JR   C,L0C74     		;0C42 3830	<L0C74>
	INC  (HL)    			;0C44 34
	LD   (HL),32H  			;0C45 3632	<32H>
	LD   B,L     			;0C47 45
	JR   NC,L0C8E    		;0C48 3044	<L0C8E>
	DEC  (HL)    			;0C4A 35
	LD   B,L     			;0C4B 45
	SCF          			;0C4C 37
	LD   (M4533),A   		;0C4D 323345	<M4533>
L0C50:	LD   SP,M4636    		;0C50 313646	<M4636>
L0C53:	LD   B,(HL)  			;0C53 46
	LD   B,(HL)  			;0C54 46
	SCF          			;0C55 37
	INC  SP      			;0C56 33
	LD   B,C     			;0C57 41
	JR   NC,L0C90    		;0C58 3036	<L0C90>
	JR   C,L0C8C     		;0C5A 3830	<L0C8C>
	LD   B,L     			;0C5C 45
	LD   (HL),30H  			;0C5D 3630	<30H>
	LD   B,C     			;0C5F 41
	LD   (M3638),A   		;0C60 323836	<M3638>
	ADD  HL,SP   			;0C63 39
	DEC  C       			;0C64 0D
	LD   A,(BC)  			;0C65 0A
	LD   A,(M3032)   		;0C66 3A3230	<M3032>
L0C69:	JR   NC,L0CA0    		;0C69 3035	<L0CA0>
	LD   (M3030),A   		;0C6B 323030	<M3030>
	JR   NC,L0CB6    		;0C6E 3046	<L0CB6>
	JR   C,L0CA9     		;0C70 3837	<L0CA9>
	INC  SP      			;0C72 33
	INC  SP      			;0C73 33
L0C74:	LD   B,L     			;0C74 45
	LD   SP,M4637    		;0C75 313746	<M4637>
	LD   B,(HL)  			;0C78 46
	SCF          			;0C79 37
	JR   C,L0CAC     		;0C7A 3830	<L0CAC>
	LD   (HL),30H  			;0C7C 3630	<30H>
	LD   (HL),46H  			;0C7E 3646	<46H>
L0C80:	LD   B,L     			;0C80 45
	JR   NC,L0CB8    		;0C81 3035	<L0CB8>
	LD   (M3038),A   		;0C83 323830	<M3038>
	LD   B,D     			;0C86 42
	JR   NC,L0CBF    		;0C87 3036	<L0CBF>
	JR   NC,L0CBF    		;0C89 3034	<L0CBF>
	LD   B,(HL)  			;0C8B 46
L0C8C:	LD   B,L     			;0C8C 45
	JR   NC,L0CC5    		;0C8D 3036	<L0CC5>
	LD   (M3038),A   		;0C8F 323830	<M3038>
	DEC  (HL)    			;0C92 35
	JR   NC,L0CCB    		;0C93 3036	<L0CCB>
	LD   SP,M4630    		;0C95 313046	<M4630>
	LD   B,L     			;0C98 45
	JR   NC,L0CCE    		;0C99 3033	<L0CCE>
	LD   B,E     			;0C9B 43
	JR   NC,L0CD5    		;0C9C 3037	<L0CD5>
	JR   C,L0CE6     		;0C9E 3846	<L0CE6>
L0CA0:	LD   B,(HL)  			;0CA0 46
	LD   B,E     			;0CA1 43
	ADD  HL,SP   			;0CA2 39
	LD   (M3031),A   		;0CA3 323130	<M3031>
	LD   SP,M3038    		;0CA6 313830	<M3038>
L0CA9:	LD   B,E     			;0CA9 43
	LD   B,D     			;0CAA 42
	LD   (HL),36H  			;0CAB 3636	<36H>
	LD   B,E     			;0CAD 43
	JR   NC,L0CE5    		;0CAE 3035	<L0CE5>
	LD   B,H     			;0CB0 44
	DEC  C       			;0CB1 0D
	LD   A,(BC)  			;0CB2 0A
	LD   A,(M3032)   		;0CB3 3A3230	<M3032>
L0CB6:	JR   NC,L0CED    		;0CB6 3035	<L0CED>
L0CB8:	INC  (HL)    			;0CB8 34
	JR   NC,L0CEB    		;0CB9 3030	<L0CEB>
	JR   NC,L0D00    		;0CBB 3043	<L0D00>
	LD   B,H     			;0CBD 44
	ADD  HL,SP   			;0CBE 39
L0CBF:	LD   B,H     			;0CBF 44
	JR   NC,L0CF7    		;0CC0 3035	<L0CF7>
	LD   B,E     			;0CC2 43
	JR   NC,L0D08    		;0CC3 3043	<L0D08>
L0CC5:	LD   B,H     			;0CC5 44
	LD   B,C     			;0CC6 41
	INC  (HL)    			;0CC7 34
	JR   NC,L0CFF    		;0CC8 3035	<L0CFF>
	LD   B,E     			;0CCA 43
L0CCB:	JR   NC,L0CFD    		;0CCB 3030	<L0CFD>
	LD   (HL),33H  			;0CCD 3633	<33H>
	JR   NC,L0D15    		;0CCF 3044	<L0D15>
	SCF          			;0CD1 37
	LD   B,E     			;0CD2 43
	JR   NC,L0D1A    		;0CD3 3045	<L0D1A>
L0CD5:	LD   B,H     			;0CD5 44
	DEC  (HL)    			;0CD6 35
	LD   B,D     			;0CD7 42
	JR   NC,L0D0C    		;0CD8 3032	<L0D0C>
	JR   C,L0D0C     		;0CDA 3830	<L0D0C>
	SCF          			;0CDC 37
	LD   B,C     			;0CDD 41
	LD   B,C     			;0CDE 41
	LD   B,D     			;0CDF 42
	LD   B,L     			;0CE0 45
	LD   (HL),30H  			;0CE1 3630	<30H>
	SCF          			;0CE3 37
	LD   B,E     			;0CE4 43
L0CE5:	JR   NC,L0D1E    		;0CE5 3037	<L0D1E>
	LD   B,C     			;0CE7 41
	LD   B,L     			;0CE8 45
	LD   (HL),30H  			;0CE9 3630	<30H>
L0CEB:	SCF          			;0CEB 37
	JR   NC,L0D1F    		;0CEC 3031	<L0D1F>
	JR   NC,L0D23    		;0CEE 3033	<L0D23>
	JR   NC,L0D22    		;0CF0 3030	<L0D22>
	JR   NC,L0D28    		;0CF2 3034	<L0D28>
	JR   NC,L0D3C    		;0CF4 3046	<L0D3C>
	INC  SP      			;0CF6 33
L0CF7:	JR   C,L0D29     		;0CF7 3830	<L0D29>
	INC  (HL)    			;0CF9 34
	JR   NC,L0D40    		;0CFA 3044	<L0D40>
	JR   NC,L0D34    		;0CFC 3036	<L0D34>
	DEC  C       			;0CFE 0D
L0CFF:	LD   A,(BC)  			;0CFF 0A
L0D00:	LD   A,(M3032)   		;0D00 3A3230	<M3032>
	JR   NC,L0D3A    		;0D03 3035	<L0D3A>
	LD   (HL),30H  			;0D05 3630	<30H>
	JR   NC,L0D39    		;0D07 3030	<L0D39>
	LD   B,E     			;0D09 43
	JR   C,L0D3D     		;0D0A 3831	<L0D3D>
L0D0C:	JR   C,L0D54     		;0D0C 3846	<L0D54>
	JR   C,L0D53     		;0D0E 3843	<L0D53>
	LD   B,H     			;0D10 44
	LD   B,C     			;0D11 41
	LD   B,D     			;0D12 42
	JR   NC,L0D4A    		;0D13 3035	<L0D4A>
L0D15:	LD   (M3038),A   		;0D15 323830	<M3038>
	LD   (M3630),A   		;0D18 323036	<M3630>
	JR   NC,L0D4E    		;0D1B 3031	<L0D4E>
	LD   SP,M3531    		;0D1D 313135	<M3531>
	JR   C,L0D5A     		;0D20 3838	<L0D5A>
L0D22:	JR   NC,L0D55    		;0D22 3031	<L0D55>
	LD   B,C     			;0D24 41
	LD   B,D     			;0D25 42
	JR   C,L0D6B     		;0D26 3843	<L0D6B>
L0D28:	JR   C,L0D5D     		;0D28 3833	<L0D5D>
	JR   C,L0D5D     		;0D2A 3831	<L0D5D>
	JR   NC,L0D71    		;0D2C 3043	<L0D71>
	LD   B,D     			;0D2E 42
	SCF          			;0D2F 37
M0D30:	LD   B,L     			;0D30 45
	LD   B,E     			;0D31 43
M0D32:	JR   C,L0D77     		;0D32 3843	<L0D77>
L0D34:	LD   B,D     			;0D34 42
	ADD  HL,SP   			;0D35 39
	LD   B,L     			;0D36 45
M0D37:	LD   B,E     			;0D37 43
M0D38:	LD   B,D     			;0D38 42
L0D39:	LD   B,C     			;0D39 41
L0D3A:	LD   B,L     			;0D3A 45
	LD   (M3045),A   		;0D3B 324530	<M3045>
	LD   B,E     			;0D3E 43
	JR   C,L0D77     		;0D3F 3836	<L0D77>
	LD   (M3737),A   		;0D41 323737	<M3737>
M0D44:	SCF          			;0D44 37
	LD   B,C     			;0D45 41
M0D46:	LD   B,(HL)  			;0D46 46
	LD   SP,M3132    		;0D47 313231	<M3132>
L0D4A:	JR   C,L0D59     		;0D4A 380D	<L0D59>
	LD   A,(BC)  			;0D4C 0A
	LD   A,(M3032)   		;0D4D 3A3230	<M3032>
	JR   NC,L0D87    		;0D50 3035	<L0D87>
	JR   C,L0D84     		;0D52 3830	<L0D84>
L0D54:	JR   NC,L0D86    		;0D54 3030	<L0D86>
	LD   SP,M3138    		;0D56 313831	<M3138>
L0D59:	LD   SP,M4133    		;0D59 313341	<M4133>
	JR   NC,L0DA1    		;0D5C 3043	<L0DA1>
	JR   C,L0D90     		;0D5E 3830	<L0D90>
	LD   B,C     			;0D60 41
	SCF          			;0D61 37
	LD   B,E     			;0D62 43
	JR   C,L0DA8     		;0D63 3843	<L0DA8>
	LD   B,D     			;0D65 42
	ADD  HL,SP   			;0D66 39
	LD   B,L     			;0D67 45
	SCF          			;0D68 37
	JR   C,L0DB0     		;0D69 3845	<L0DB0>
L0D6B:	LD   B,D     			;0D6B 42
	ADD  HL,SP   			;0D6C 39
	LD   (HL),34H  			;0D6D 3634	<34H>
	SCF          			;0D6F 37
	LD   (M3045),A   		;0D70 324530	<M3045>
	LD   B,E     			;0D73 43
	LD   B,D     			;0D74 42
	LD   B,L     			;0D75 45
	INC  SP      			;0D76 33
L0D77:	JR   C,L0DA9     		;0D77 3830	<L0DA9>
	LD   SP,M3634    		;0D79 313436	<M3634>
	LD   B,L     			;0D7C 45
	SCF          			;0D7D 37
	LD   B,E     			;0D7E 43
	LD   B,H     			;0D7F 44
	LD   B,D     			;0D80 42
	LD   SP,M3530    		;0D81 313035	<M3530>
L0D84:	LD   B,E     			;0D84 43
	LD   B,H     			;0D85 44
L0D86:	LD   B,C     			;0D86 41
L0D87:	LD   B,D     			;0D87 42
	JR   NC,L0DBF    		;0D88 3035	<L0DBF>
	LD   B,E     			;0D8A 43
	JR   NC,L0DD2    		;0D8B 3045	<L0DD2>
	LD   B,(HL)  			;0D8D 46
	LD   B,E     			;0D8E 43
	ADD  HL,SP   			;0D8F 39
L0D90:	INC  SP      			;0D90 33
	LD   B,C     			;0D91 41
	JR   NC,L0DCB    		;0D92 3037	<L0DCB>
	JR   C,L0DC6     		;0D94 3830	<L0DC6>
	LD   B,D     			;0D96 42
	LD   B,H     			;0D97 44
	DEC  C       			;0D98 0D
	LD   A,(BC)  			;0D99 0A
	LD   A,(M3032)   		;0D9A 3A3230	<M3032>
	JR   NC,L0DD4    		;0D9D 3035	<L0DD4>
	LD   B,C     			;0D9F 41
	JR   NC,L0DD2    		;0DA0 3030	<L0DD2>
	JR   NC,L0DD6    		;0DA2 3032	<L0DD6>
	LD   B,(HL)  			;0DA4 46
	LD   B,L     			;0DA5 45
	LD   (HL),45H  			;0DA6 3645	<45H>
L0DA8:	JR   NC,L0DED    		;0DA8 3043	<L0DED>
	ADD  HL,SP   			;0DAA 39
	INC  SP      			;0DAB 33
	LD   B,C     			;0DAC 41
	JR   NC,L0DE4    		;0DAD 3035	<L0DE4>
	JR   C,L0DE1     		;0DAF 3830	<L0DE1>
	LD   (M4546),A   		;0DB1 324645	<M4546>
	LD   (HL),33H  			;0DB4 3633	<33H>
	JR   NC,L0DFB    		;0DB6 3043	<L0DFB>
	ADD  HL,SP   			;0DB8 39
	INC  SP      			;0DB9 33
	LD   B,C     			;0DBA 41
	DEC  (HL)    			;0DBB 35
	LD   B,(HL)  			;0DBC 46
	JR   C,L0DEF     		;0DBD 3830	<L0DEF>
L0DBF:	LD   B,L     			;0DBF 45
	LD   (HL),30H  			;0DC0 3630	<30H>
	LD   (M3943),A   		;0DC2 324339	<M3943>
	LD   B,(HL)  			;0DC5 46
L0DC6:	SCF          			;0DC6 37
	INC  SP      			;0DC7 33
	LD   B,C     			;0DC8 41
	INC  SP      			;0DC9 33
	DEC  (HL)    			;0DCA 35
L0DCB:	JR   C,L0DFD     		;0DCB 3830	<L0DFD>
	LD   B,C     			;0DCD 41
	SCF          			;0DCE 37
	LD   (M4630),A   		;0DCF 323046	<M4630>
L0DD2:	ADD  HL,SP   			;0DD2 39
	LD   B,E     			;0DD3 43
L0DD4:	LD   B,H     			;0DD4 44
	LD   B,E     			;0DD5 43
L0DD6:	LD   (HL),30H  			;0DD6 3630	<30H>
	DEC  (HL)    			;0DD8 35
	LD   B,E     			;0DD9 43
	LD   B,H     			;0DDA 44
	JR   NC,L0E11    		;0DDB 3034	<L0E11>
	JR   NC,L0E15    		;0DDD 3036	<L0E15>
	INC  SP      			;0DDF 33
	LD   B,L     			;0DE0 45
L0DE1:	INC  SP      			;0DE1 33
	JR   C,L0E19     		;0DE2 3835	<L0E19>
L0DE4:	LD   B,D     			;0DE4 42
	DEC  C       			;0DE5 0D
	LD   A,(BC)  			;0DE6 0A
	LD   A,(M3032)   		;0DE7 3A3230	<M3032>
	JR   NC,L0E21    		;0DEA 3035	<L0E21>
	LD   B,E     			;0DEC 43
L0DED:	JR   NC,L0E1F    		;0DED 3030	<L0E1F>
L0DEF:	JR   NC,L0E24    		;0DEF 3033	<L0E24>
	LD   (M3533),A   		;0DF1 323335	<M3533>
	JR   C,L0E26     		;0DF4 3830	<L0E26>
	LD   SP,M4530    		;0DF6 313045	<M4530>
	LD   B,E     			;0DF9 43
	LD   B,E     			;0DFA 43
L0DFB:	ADD  HL,SP   			;0DFB 39
	LD   B,C     			;0DFC 41
L0DFD:	LD   B,(HL)  			;0DFD 46
	LD   (M3131),A   		;0DFE 323131	<M3131>
	LD   B,(HL)  			;0E01 46
	JR   C,L0E34     		;0E02 3830	<L0E34>
	SCF          			;0E04 37
	SCF          			;0E05 37
	LD   (M3733),A   		;0E06 323337	<M3733>
	SCF          			;0E09 37
	LD   (M3733),A   		;0E0A 323337	<M3733>
	SCF          			;0E0D 37
	INC  SP      			;0E0E 33
	LD   (M4430),A   		;0E0F 323044	<M4430>
	JR   C,L0E44     		;0E12 3830	<L0E44>
	INC  SP      			;0E14 33
L0E15:	LD   B,L     			;0E15 45
	JR   NC,L0E5A    		;0E16 3042	<L0E5A>
	LD   B,(HL)  			;0E18 46
L0E19:	LD   B,(HL)  			;0E19 46
	LD   (M3545),A   		;0E1A 324535	<M3545>
	JR   C,L0E52     		;0E1D 3833	<L0E52>
L0E1F:	INC  (HL)    			;0E1F 34
	SCF          			;0E20 37
L0E21:	LD   B,L     			;0E21 45
	INC  (HL)    			;0E22 34
	LD   B,(HL)  			;0E23 46
L0E24:	LD   (M3631),A   		;0E24 323136	<M3631>
	INC  (HL)    			;0E27 34
	LD   SP,M4330    		;0E28 313043	<M4330>
	LD   B,(HL)  			;0E2B 46
	LD   SP,M3231    		;0E2C 313132	<M3231>
	SCF          			;0E2F 37
	LD   (M0D42),A   		;0E30 32420D	<M0D42>
	LD   A,(BC)  			;0E33 0A
L0E34:	LD   A,(M3032)   		;0E34 3A3230	<M3032>
	JR   NC,L0E6E    		;0E37 3035	<L0E6E>
	LD   B,L     			;0E39 45
	JR   NC,L0E6C    		;0E3A 3030	<L0E6C>
	JR   NC,L0E76    		;0E3C 3038	<L0E76>
	JR   NC,L0E86    		;0E3E 3046	<L0E86>
	INC  SP      			;0E40 33
	LD   SP,M4541    		;0E41 314145	<M4541>
L0E44:	LD   (HL),45H  			;0E44 3645	<45H>
	JR   NC,L0E8A    		;0E46 3042	<L0E8A>
	LD   (HL),31H  			;0E48 3631	<31H>
	LD   (M4246),A   		;0E4A 324642	<M4246>
	LD   (M3531),A   		;0E4D 323135	<M3531>
	LD   B,C     			;0E50 41
	JR   C,L0E83     		;0E51 3830	<L0E83>
	DEC  (HL)    			;0E53 35
	LD   (HL),33H  			;0E54 3633	<33H>
	LD   B,C     			;0E56 41
	DEC  (HL)    			;0E57 35
	LD   B,(HL)  			;0E58 46
	JR   C,L0E8B     		;0E59 3830	<L0E8B>
	LD   B,E     			;0E5B 43
	LD   B,D     			;0E5C 42
	INC  (HL)    			;0E5D 34
	SCF          			;0E5E 37
	LD   (M3030),A   		;0E5F 323030	<M3030>
	ADD  HL,SP   			;0E62 39
	LD   SP,M3036    		;0E63 313630	<M3036>
	INC  SP      			;0E66 33
	LD   B,L     			;0E67 45
	LD   (HL),30H  			;0E68 3630	<30H>
	LD   (M3832),A   		;0E6A 323238	<M3832>
	JR   NC,L0EA2    		;0E6D 3033	<L0EA2>
	LD   B,L     			;0E6F 45
	SCF          			;0E70 37
	LD   SP,M3036    		;0E71 313630	<M3036>
	LD   SP,M3937    		;0E74 313739	<M3937>
	LD   B,D     			;0E77 42
	LD   B,C     			;0E78 41
	LD   B,E     			;0E79 43
	JR   NC,L0EAE    		;0E7A 3032	<L0EAE>
	LD   B,L     			;0E7C 45
	LD   B,(HL)  			;0E7D 46
	DEC  (HL)    			;0E7E 35
	DEC  C       			;0E7F 0D
	LD   A,(BC)  			;0E80 0A
	LD   A,(M3032)   		;0E81 3A3230	<M3032>
	JR   NC,L0EBC    		;0E84 3036	<L0EBC>
L0E86:	JR   NC,L0EB8    		;0E86 3030	<L0EB8>
	JR   NC,L0EBA    		;0E88 3030	<L0EBA>
L0E8A:	JR   NC,L0EBD    		;0E8A 3031	<L0EBD>
	LD   B,E     			;0E8C 43
	LD   B,D     			;0E8D 42
	LD   B,L     			;0E8E 45
	LD   B,L     			;0E8F 45
	LD   B,E     			;0E90 43
	ADD  HL,SP   			;0E91 39
	LD   SP,M3031    		;0E92 313130	<M3031>
	LD   B,E     			;0E95 43
	JR   C,L0EC8     		;0E96 3830	<L0EC8>
	LD   SP,M4441    		;0E98 314144	<M4441>
	LD   (HL),30H  			;0E9B 3630	<30H>
	LD   SP,M3732    		;0E9D 313237	<M3732>
	LD   SP,M4332    		;0EA0 313243	<M4332>
	ADD  HL,SP   			;0EA3 39
	LD   B,E     			;0EA4 43
	LD   B,H     			;0EA5 44
	LD   B,C     			;0EA6 41
	LD   B,D     			;0EA7 42
	JR   NC,L0EDF    		;0EA8 3035	<L0EDF>
	LD   B,E     			;0EAA 43
	JR   NC,L0EF0    		;0EAB 3043	<L0EF0>
	LD   B,H     			;0EAD 44
L0EAE:	ADD  HL,SP   			;0EAE 39
	LD   B,H     			;0EAF 44
	JR   NC,L0EE7    		;0EB0 3035	<L0EE7>
	LD   B,E     			;0EB2 43
	JR   NC,L0EE5    		;0EB3 3030	<L0EE5>
	LD   (HL),32H  			;0EB5 3632	<32H>
	SCF          			;0EB7 37
L0EB8:	LD   B,H     			;0EB8 44
	SCF          			;0EB9 37
L0EBA:	LD   B,E     			;0EBA 43
	JR   NC,L0EEF    		;0EBB 3032	<L0EEF>
L0EBD:	LD   SP,M3330    		;0EBD 313033	<M3330>
	JR   C,L0EF2     		;0EC0 3830	<L0EF2>
	LD   B,E     			;0EC2 43
	LD   B,D     			;0EC3 42
	LD   (HL),36H  			;0EC4 3636	<36H>
	LD   B,E     			;0EC6 43
	JR   C,L0F0C     		;0EC7 3843	<L0F0C>
	LD   B,D     			;0EC9 42
	LD   (M0D46),A   		;0ECA 32460D	<M0D46>
	LD   A,(BC)  			;0ECD 0A
	LD   A,(M3032)   		;0ECE 3A3230	<M3032>
	JR   NC,L0F09    		;0ED1 3036	<L0F09>
	LD   (M3030),A   		;0ED3 323030	<M3030>
	JR   NC,L0F19    		;0ED6 3041	<L0F19>
	LD   (HL),32H  			;0ED8 3632	<32H>
	LD   B,L     			;0EDA 45
	JR   NC,L0F0E    		;0EDB 3031	<L0F0E>
	LD   B,E     			;0EDD 43
	LD   B,D     			;0EDE 42
L0EDF:	ADD  HL,SP   			;0EDF 39
	LD   B,L     			;0EE0 45
	LD   SP,M3031    		;0EE1 313130	<M3031>
	LD   B,E     			;0EE4 43
L0EE5:	JR   C,L0F17     		;0EE5 3830	<L0F17>
L0EE7:	LD   B,E     			;0EE7 43
	LD   B,D     			;0EE8 42
	LD   (HL),36H  			;0EE9 3636	<36H>
	LD   (M3038),A   		;0EEB 323830	<M3038>
	LD   (HL),43H  			;0EEE 3643	<43H>
L0EF0:	LD   B,D     			;0EF0 42
	LD   B,C     			;0EF1 41
L0EF2:	LD   (HL),41H  			;0EF2 3641	<41H>
	LD   B,(HL)  			;0EF4 46
	LD   SP,M4532    		;0EF5 313245	<M4532>
	LD   B,(HL)  			;0EF8 46
	LD   B,E     			;0EF9 43
	ADD  HL,SP   			;0EFA 39
	LD   B,E     			;0EFB 43
	LD   B,D     			;0EFC 42
	LD   B,L     			;0EFD 45
	LD   (HL),43H  			;0EFE 3643	<43H>
	LD   B,D     			;0F00 42
	LD   B,D     			;0F01 42
	LD   B,L     			;0F02 45
	LD   SP,M4141    		;0F03 314141	<M4141>
	SCF          			;0F06 37
	LD   (M3030),A   		;0F07 323030	<M3030>
	SCF          			;0F0A 37
	INC  SP      			;0F0B 33
L0F0C:	LD   B,H     			;0F0C 44
	LD   SP,M4332    		;0F0D 313243	<M4332>
	LD   B,D     			;0F10 42
	LD   (HL),45H  			;0F11 3645	<45H>
	LD   B,E     			;0F13 43
	JR   C,L0F5B     		;0F14 3845	<L0F5B>
	SCF          			;0F16 37
L0F17:	INC  SP      			;0F17 33
	LD   B,H     			;0F18 44
L0F19:	DEC  C       			;0F19 0D
	LD   A,(BC)  			;0F1A 0A
	LD   A,(M3032)   		;0F1B 3A3230	<M3032>
	JR   NC,L0F56    		;0F1E 3036	<L0F56>
	INC  (HL)    			;0F20 34
	JR   NC,L0F53    		;0F21 3030	<L0F53>
	JR   NC,L0F68    		;0F23 3043	<L0F68>
	ADD  HL,SP   			;0F25 39
	LD   B,L     			;0F26 45
	SCF          			;0F27 37
	LD   B,E     			;0F28 43
	LD   B,H     			;0F29 44
	DEC  (HL)    			;0F2A 35
	DEC  (HL)    			;0F2B 35
	JR   NC,L0F64    		;0F2C 3036	<L0F64>
	LD   B,E     			;0F2E 43
	LD   B,H     			;0F2F 44
	JR   NC,L0F66    		;0F30 3034	<L0F66>
	JR   NC,L0F6A    		;0F32 3036	<L0F6A>
	LD   B,C     			;0F34 41
	SCF          			;0F35 37
	LD   (M4630),A   		;0F36 323046	<M4630>
	SCF          			;0F39 37
	INC  SP      			;0F3A 33
	LD   B,H     			;0F3B 44
	LD   SP,M3332    		;0F3C 313233	<M3332>
	LD   B,C     			;0F3F 41
	JR   NC,L0F73    		;0F40 3031	<L0F73>
	JR   C,L0F74     		;0F42 3830	<L0F74>
	LD   B,E     			;0F44 43
	LD   B,D     			;0F45 42
	LD   (HL),46H  			;0F46 3646	<46H>
	LD   B,E     			;0F48 43
	JR   NC,L0F90    		;0F49 3045	<L0F90>
	LD   B,(HL)  			;0F4B 46
	LD   B,E     			;0F4C 43
	ADD  HL,SP   			;0F4D 39
	LD   (M4431),A   		;0F4E 323144	<M4431>
	INC  (HL)    			;0F51 34
	LD   SP,M3234    		;0F52 313432	<M3234>
	LD   (M4432),A   		;0F55 323244	<M4432>
	JR   C,L0F8A     		;0F58 3830	<L0F8A>
	LD   (M3231),A   		;0F5A 323132	<M3231>
	INC  SP      			;0F5D 33
	JR   C,L0F90     		;0F5E 3830	<L0F90>
	LD   B,E     			;0F60 43
	LD   B,D     			;0F61 42
	LD   B,(HL)  			;0F62 46
	LD   B,L     			;0F63 45
L0F64:	JR   NC,L0FA9    		;0F64 3043	<L0FA9>
L0F66:	DEC  C       			;0F66 0D
	LD   A,(BC)  			;0F67 0A
L0F68:	LD   A,(M3032)   		;0F68 3A3230	<M3032>
	JR   NC,L0FA3    		;0F6B 3036	<L0FA3>
	LD   (HL),30H  			;0F6D 3630	<30H>
	JR   NC,L0FA1    		;0F6F 3030	<L0FA1>
	LD   B,(HL)  			;0F71 46
	SCF          			;0F72 37
L0F73:	LD   B,L     			;0F73 45
L0F74:	LD   B,H     			;0F74 44
	INC  (HL)    			;0F75 34
	LD   B,D     			;0F76 42
	LD   (M3844),A   		;0F77 324438	<M3844>
	JR   NC,L0FB3    		;0F7A 3037	<L0FB3>
	JR   C,L0FC0     		;0F7C 3842	<L0FC0>
	LD   SP,M3832    		;0F7E 313238	<M3832>
	LD   (M3035),A   		;0F81 323530	<M3035>
	LD   (HL),30H  			;0F84 3630	<30H>
	JR   C,L0FCC     		;0F86 3844	<L0FCC>
	SCF          			;0F88 37
	LD   (M4638),A   		;0F89 323846	<M4638>
	LD   (M3131),A   		;0F8C 323131	<M3131>
	INC  SP      			;0F8F 33
L0F90:	ADD  HL,SP   			;0F90 39
	JR   C,L0FC3     		;0F91 3830	<L0FC3>
	INC  SP      			;0F93 33
	LD   B,L     			;0F94 45
	LD   (HL),34H  			;0F95 3634	<34H>
	LD   SP,M4632    		;0F97 313246	<M4632>
	SCF          			;0F9A 37
	LD   B,L     			;0F9B 45
	LD   B,H     			;0F9C 44
	INC  (HL)    			;0F9D 34
	LD   B,D     			;0F9E 42
	LD   (M3844),A   		;0F9F 324438	<M3844>
	JR   NC,L0FDB    		;0FA2 3037	<L0FDB>
	JR   C,L0FE8     		;0FA4 3842	<L0FE8>
	LD   SP,M3832    		;0FA6 313238	<M3832>
L0FA9:	LD   SP,M3131    		;0FA9 313131	<M3131>
	LD   B,C     			;0FAC 41
	LD   B,C     			;0FAD 41
	SCF          			;0FAE 37
	LD   (M3838),A   		;0FAF 323838	<M3838>
	INC  (HL)    			;0FB2 34
L0FB3:	DEC  C       			;0FB3 0D
	LD   A,(BC)  			;0FB4 0A
	LD   A,(M3032)   		;0FB5 3A3230	<M3032>
	JR   NC,L0FF0    		;0FB8 3036	<L0FF0>
	JR   C,L0FEC     		;0FBA 3830	<L0FEC>
	JR   NC,L0FEE    		;0FBC 3030	<L0FEE>
	LD   SP,M3031    		;0FBE 313130	<M3031>
	LD   (HL),30H  			;0FC1 3630	<30H>
L0FC3:	JR   C,L1009     		;0FC3 3844	<L1009>
	SCF          			;0FC5 37
	LD   (M4530),A   		;0FC6 323045	<M4530>
	LD   B,L     			;0FC9 45
	LD   SP,M4641    		;0FCA 314146	<M4641>
	LD   B,L     			;0FCD 45
	DEC  (HL)    			;0FCE 35
	LD   B,L     			;0FCF 45
	INC  SP      			;0FD0 33
	JR   NC,L1017    		;0FD1 3044	<L1017>
	DEC  (HL)    			;0FD3 35
	LD   B,E     			;0FD4 43
	LD   B,D     			;0FD5 42
	LD   B,D     			;0FD6 42
	LD   B,L     			;0FD7 45
	LD   B,E     			;0FD8 43
	ADD  HL,SP   			;0FD9 39
	LD   SP,M4436    		;0FDA 313644	<M4436>
	LD   B,C     			;0FDD 41
	LD   SP,M3038    		;0FDE 313830	<M3038>
	LD   (M3631),A   		;0FE1 323136	<M3631>
	LD   B,H     			;0FE4 44
	LD   B,D     			;0FE5 42
	LD   B,E     			;0FE6 43
	LD   B,D     			;0FE7 42
L0FE8:	LD   B,D     			;0FE8 42
	LD   B,L     			;0FE9 45
	LD   B,E     			;0FEA 43
	LD   B,H     			;0FEB 44
L0FEC:	JR   NC,L1033    		;0FEC 3045	<L1033>
L0FEE:	JR   NC,L1025    		;0FEE 3035	<L1025>
L0FF0:	LD   SP,M4238    		;0FF0 313842	<M4238>
	LD   B,C     			;0FF3 41
	LD   (M3231),A   		;0FF4 323132	<M3231>
	INC  SP      			;0FF7 33
	JR   C,L102A     		;0FF8 3830	<L102A>
	LD   B,E     			;0FFA 43
	LD   B,D     			;0FFB 42
	LD   (HL),36H  			;0FFC 3636	<36H>
	DEC  (HL)    			;0FFE 35
	LD   B,L     			;0FFF 45
	DEC  C       			;1000 0D
	LD   A,(BC)  			;1001 0A
	LD   A,(M3032)   		;1002 3A3230	<M3032>
	JR   NC,L103D    		;1005 3036	<L103D>
	LD   B,C     			;1007 41
	JR   NC,L103A    		;1008 3030	<L103A>
	JR   NC,L104F    		;100A 3043	<L104F>
	JR   C,L1051     		;100C 3843	<L1051>
	LD   B,H     			;100E 44
	LD   B,C     			;100F 41
	INC  (HL)    			;1010 34
	JR   NC,L1048    		;1011 3035	<L1048>
	LD   B,E     			;1013 43
	JR   C,L1048     		;1014 3832	<L1048>
	LD   B,L     			;1016 45
L1017:	JR   NC,L104A    		;1017 3031	<L104A>
	LD   B,E     			;1019 43
	LD   B,D     			;101A 42
	ADD  HL,SP   			;101B 39
	LD   B,L     			;101C 45
	LD   B,(HL)  			;101D 46
	LD   B,L     			;101E 45
	LD   SP,M4330    		;101F 313043	<M4330>
	LD   (M4332),A   		;1022 323243	<M4332>
L1025:	JR   NC,L105E    		;1025 3037	<L105E>
	LD   (M3345),A   		;1027 324533	<M3345>
L102A:	LD   B,E     			;102A 43
	INC  SP      			;102B 33
	LD   (HL),35H  			;102C 3635	<35H>
	LD   (M3746),A   		;102E 324637	<M3746>
	LD   B,E     			;1031 43
	LD   B,H     			;1032 44
L1033:	LD   B,C     			;1033 41
	INC  (HL)    			;1034 34
	JR   NC,L106C    		;1035 3035	<L106C>
	LD   B,(HL)  			;1037 46
	LD   B,L     			;1038 45
	INC  SP      			;1039 33
L103A:	JR   NC,L106E    		;103A 3032	<L106E>
	JR   C,L106E     		;103C 3830	<L106E>
	LD   B,H     			;103E 44
	LD   B,(HL)  			;103F 46
	LD   B,L     			;1040 45
	JR   NC,L1073    		;1041 3030	<L1073>
	LD   B,E     			;1043 43
	JR   C,L108C     		;1044 3846	<L108C>
	LD   B,L     			;1046 45
	LD   SP,M3230    		;1047 313032	<M3230>
L104A:	JR   NC,L1091    		;104A 3045	<L1091>
	INC  SP      			;104C 33
	DEC  C       			;104D 0D
	LD   A,(BC)  			;104E 0A
L104F:	LD   A,(M3032)   		;104F 3A3230	<M3032>
	JR   NC,L108A    		;1052 3036	<L108A>
	LD   B,E     			;1054 43
	JR   NC,L1087    		;1055 3030	<L1087>
	JR   NC,L108F    		;1057 3036	<L108F>
	LD   B,D     			;1059 42
	SCF          			;105A 37
	LD   B,L     			;105B 45
	LD   B,C     			;105C 41
	SCF          			;105D 37
L105E:	LD   (M3538),A   		;105E 323835	<M3538>
	JR   C,L1094     		;1061 3831	<L1094>
	JR   C,L10AA     		;1063 3845	<L10AA>
	LD   B,D     			;1065 42
	LD   (M3345),A   		;1066 324533	<M3345>
	LD   B,H     			;1069 44
	INC  SP      			;106A 33
	LD   (HL),35H  			;106B 3635	<35H>
	LD   (M3746),A   		;106D 324637	<M3746>
	LD   B,E     			;1070 43
	LD   B,H     			;1071 44
	LD   B,C     			;1072 41
L1073:	INC  (HL)    			;1073 34
	JR   NC,L10AB    		;1074 3035	<L10AB>
	LD   B,(HL)  			;1076 46
	LD   B,L     			;1077 45
	LD   (M3230),A   		;1078 323032	<M3230>
	JR   C,L10AE     		;107B 3831	<L10AE>
	LD   SP,M4546    		;107D 314645	<M4546>
	INC  SP      			;1080 33
	JR   NC,L10B5    		;1081 3032	<L10B5>
	JR   NC,L10BA    		;1083 3035	<L10BA>
	DEC  (HL)    			;1085 35
	SCF          			;1086 37
L1087:	LD   B,L     			;1087 45
	LD   B,(HL)  			;1088 46
	LD   B,L     			;1089 45
L108A:	LD   SP,M3342    		;108A 314233	<M3342>
	JR   C,L10C3     		;108D 3834	<L10C3>
L108F:	LD   SP,M4133    		;108F 313341	<M4133>
	INC  SP      			;1092 33
	LD   B,E     			;1093 43
L1094:	JR   C,L10C6     		;1094 3830	<L10C6>
	LD   B,C     			;1096 41
	SCF          			;1097 37
	JR   NC,L10CA    		;1098 3030	<L10CA>
	DEC  C       			;109A 0D
	LD   A,(BC)  			;109B 0A
	LD   A,(M3032)   		;109C 3A3230	<M3032>
	JR   NC,L10D7    		;109F 3036	<L10D7>
	LD   B,L     			;10A1 45
	JR   NC,L10D4    		;10A2 3030	<L10D4>
	JR   NC,L10D8    		;10A4 3032	<L10D8>
	JR   C,L10DB     		;10A6 3833	<L10DB>
	LD   B,D     			;10A8 42
	LD   SP,M4538    		;10A9 313845	<M4538>
	SCF          			;10AC 37
	LD   B,(HL)  			;10AD 46
L10AE:	SCF          			;10AE 37
	LD   B,E     			;10AF 43
	LD   B,H     			;10B0 44
	LD   B,C     			;10B1 41
	INC  (HL)    			;10B2 34
	JR   NC,L10EA    		;10B3 3035	<L10EA>
L10B5:	LD   (M3038),A   		;10B5 323830	<M3038>
	LD   B,C     			;10B8 41
	LD   B,(HL)  			;10B9 46
L10BA:	LD   B,L     			;10BA 45
	LD   (M3230),A   		;10BB 323032	<M3230>
	JR   NC,L10F3    		;10BE 3033	<L10F3>
	LD   B,L     			;10C0 45
	SCF          			;10C1 37
	LD   B,L     			;10C2 45
L10C3:	LD   B,C     			;10C3 41
	SCF          			;10C4 37
	LD   (M3238),A   		;10C5 323832	<M3238>
	LD   B,D     			;10C8 42
	LD   SP,M4638    		;10C9 313846	<M4638>
	JR   NC,L1100    		;10CC 3032	<L1100>
	LD   B,L     			;10CE 45
	JR   NC,L1102    		;10CF 3031	<L1102>
	LD   B,E     			;10D1 43
	LD   B,D     			;10D2 42
	LD   B,D     			;10D3 42
L10D4:	LD   B,L     			;10D4 45
	LD   B,E     			;10D5 43
	LD   B,D     			;10D6 42
L10D7:	LD   (HL),45H  			;10D7 3645	<45H>
	LD   (M3030),A   		;10D9 323030	<M3030>
	LD   B,H     			;10DC 44
	LD   B,E     			;10DD 43
	LD   B,H     			;10DE 44
	LD   B,E     			;10DF 43
	LD   (HL),30H  			;10E0 3630	<30H>
	DEC  (HL)    			;10E2 35
	LD   B,E     			;10E3 43
	JR   NC,L111E    		;10E4 3038	<L111E>
	SCF          			;10E6 37
	DEC  C       			;10E7 0D
	LD   A,(BC)  			;10E8 0A
	LD   A,(M3032)   		;10E9 3A3230	<M3032>
	JR   NC,L1125    		;10EC 3037	<L1125>
	JR   NC,L1120    		;10EE 3030	<L1120>
	JR   NC,L1122    		;10F0 3030	<L1122>
	LD   (M3031),A   		;10F2 323130	<M3031>
	LD   SP,M3038    		;10F5 313830	<M3038>
	LD   B,E     			;10F8 43
	LD   B,D     			;10F9 42
	LD   (HL),36H  			;10FA 3636	<36H>
	LD   (M3038),A   		;10FC 323830	<M3038>
	LD   B,E     			;10FF 43
L1100:	LD   B,L     			;1100 45
	SCF          			;1101 37
L1102:	LD   B,E     			;1102 43
	ADD  HL,SP   			;1103 39
	INC  SP      			;1104 33
	LD   B,L     			;1105 45
	JR   NC,L114A    		;1106 3042	<L114A>
	LD   B,(HL)  			;1108 46
	LD   B,(HL)  			;1109 46
	LD   (M3045),A   		;110A 324530	<M3045>
	LD   B,E     			;110D 43
	SCF          			;110E 37
	LD   B,L     			;110F 45
	LD   B,E     			;1110 43
	LD   (HL),30H  			;1111 3630	<30H>
	LD   SP,M3732    		;1113 313237	<M3732>
	SCF          			;1116 37
	SCF          			;1117 37
	LD   (M3045),A   		;1118 324530	<M3045>
	LD   B,E     			;111B 43
	SCF          			;111C 37
	LD   B,L     			;111D 45
L111E:	LD   B,(HL)  			;111E 46
	LD   B,L     			;111F 45
L1120:	DEC  (HL)    			;1120 35
	JR   NC,L1167    		;1121 3044	<L1167>
	JR   C,L1158     		;1123 3833	<L1158>
L1125:	LD   (HL),35H  			;1125 3635	<35H>
	JR   NC,L116E    		;1127 3045	<L116E>
	SCF          			;1129 37
	LD   B,E     			;112A 43
	ADD  HL,SP   			;112B 39
	LD   B,L     			;112C 45
	SCF          			;112D 37
	LD   (M3045),A   		;112E 324530	<M3045>
	LD   B,H     			;1131 44
	JR   C,L116B     		;1132 3837	<L116B>
	DEC  C       			;1134 0D
	LD   A,(BC)  			;1135 0A
	LD   A,(M3032)   		;1136 3A3230	<M3032>
	JR   NC,L1172    		;1139 3037	<L1172>
	LD   (M3030),A   		;113B 323030	<M3030>
	JR   NC,L1174    		;113E 3034	<L1174>
	LD   B,L     			;1140 45
	INC  SP      			;1141 33
	LD   (HL),43H  			;1142 3643	<43H>
	LD   B,C     			;1144 41
	LD   B,(HL)  			;1145 46
	SCF          			;1146 37
	LD   B,E     			;1147 43
	LD   B,H     			;1148 44
	LD   B,C     			;1149 41
L114A:	INC  (HL)    			;114A 34
	JR   NC,L1182    		;114B 3035	<L1182>
	LD   (M4630),A   		;114D 323046	<M4630>
	LD   B,C     			;1150 41
	SCF          			;1151 37
	LD   SP,M4645    		;1152 314546	<M4645>
	LD   B,E     			;1155 43
	ADD  HL,SP   			;1156 39
	LD   B,L     			;1157 45
L1158:	SCF          			;1158 37
	LD   (M3045),A   		;1159 324530	<M3045>
	LD   B,H     			;115C 44
	INC  (HL)    			;115D 34
	LD   B,L     			;115E 45
	INC  SP      			;115F 33
	LD   (HL),43H  			;1160 3643	<43H>
	LD   B,D     			;1162 42
	LD   B,(HL)  			;1163 46
	SCF          			;1164 37
	INC  SP      			;1165 33
	LD   B,C     			;1166 41
L1167:	JR   NC,L119F    		;1167 3036	<L119F>
	JR   C,L119B     		;1169 3830	<L119B>
L116B:	LD   B,L     			;116B 45
	LD   (HL),30H  			;116C 3630	<30H>
L116E:	LD   B,C     			;116E 41
	LD   (M4638),A   		;116F 323846	<M4638>
L1172:	JR   C,L11AB     		;1172 3837	<L11AB>
L1174:	LD   SP,M4645    		;1174 314546	<M4645>
	LD   B,E     			;1177 43
	ADD  HL,SP   			;1178 39
	LD   B,E     			;1179 43
	LD   B,H     			;117A 44
	ADD  HL,SP   			;117B 39
	LD   B,H     			;117C 44
	JR   NC,L11B4    		;117D 3035	<L11B4>
	LD   B,L     			;117F 45
	LD   B,D     			;1180 42
	DEC  C       			;1181 0D
L1182:	LD   A,(BC)  			;1182 0A
	LD   A,(M3032)   		;1183 3A3230	<M3032>
	JR   NC,L11BF    		;1186 3037	<L11BF>
	INC  (HL)    			;1188 34
	JR   NC,L11BB    		;1189 3030	<L11BB>
	JR   NC,L11BF    		;118B 3032	<L11BF>
	JR   NC,L11C2    		;118D 3033	<L11C2>
	LD   B,E     			;118F 43
	JR   NC,L11C8    		;1190 3036	<L11C8>
	LD   SP,M4437    		;1192 313744	<M4437>
	SCF          			;1195 37
	LD   (M3330),A   		;1196 323033	<M3330>
	SCF          			;1199 37
	LD   (M3041),A   		;119A 324130	<M3041>
	LD   (M3038),A   		;119D 323830	<M3038>
	SCF          			;11A0 37
	LD   B,E     			;11A1 43
	LD   B,C     			;11A2 41
	LD   B,H     			;11A3 44
	LD   B,E     			;11A4 43
	LD   B,D     			;11A5 42
	LD   (HL),46H  			;11A6 3646	<46H>
	LD   (M3230),A   		;11A8 323032	<M3230>
L11AB:	LD   B,L     			;11AB 45
	LD   (M3031),A   		;11AC 323130	<M3031>
	LD   SP,M3038    		;11AF 313830	<M3038>
	LD   B,E     			;11B2 43
	LD   B,D     			;11B3 42
L11B4:	LD   B,H     			;11B4 44
	LD   B,L     			;11B5 45
	LD   (M3045),A   		;11B6 324530	<M3045>
	INC  SP      			;11B9 33
	LD   B,E     			;11BA 43
L11BB:	LD   B,D     			;11BB 42
	LD   (HL),45H  			;11BC 3645	<45H>
	LD   B,E     			;11BE 43
L11BF:	JR   C,L11F3     		;11BF 3832	<L11F3>
	LD   B,L     			;11C1 45
L11C2:	DEC  (HL)    			;11C2 35
	JR   C,L11FA     		;11C3 3835	<L11FA>
	LD   B,L     			;11C5 45
	LD   B,E     			;11C6 43
	LD   B,H     			;11C7 44
L11C8:	JR   C,L11FE     		;11C8 3834	<L11FE>
	JR   NC,L1203    		;11CA 3037	<L1203>
	LD   B,H     			;11CC 44
	LD   B,E     			;11CD 43
	DEC  C       			;11CE 0D
	LD   A,(BC)  			;11CF 0A
	LD   A,(M3032)   		;11D0 3A3230	<M3032>
	JR   NC,L120C    		;11D3 3037	<L120C>
	LD   (HL),30H  			;11D5 3630	<30H>
	JR   NC,L1209    		;11D7 3030	<L1209>
	LD   SP,M3244    		;11D9 314432	<M3244>
	JR   NC,L1224    		;11DC 3046	<L1224>
	LD   B,C     			;11DE 41
	JR   NC,L1212    		;11DF 3031	<L1212>
	JR   C,L1216     		;11E1 3833	<L1216>
	LD   B,E     			;11E3 43
	JR   NC,L122C    		;11E4 3046	<L122C>
	INC  SP      			;11E6 33
	LD   B,L     			;11E7 45
	LD   B,H     			;11E8 44
	LD   (HL),38H  			;11E9 3638	<38H>
	JR   NC,L1230    		;11EB 3043	<L1230>
	LD   B,L     			;11ED 45
	LD   B,H     			;11EE 44
	SCF          			;11EF 37
	JR   C,L1234     		;11F0 3842	<L1234>
	JR   NC,L122A    		;11F2 3036	<L122A>
	SCF          			;11F4 37
	LD   (M3632),A   		;11F5 323236	<M3632>
	LD   (M3038),A   		;11F8 323830	<M3038>
	JR   NC,L1240    		;11FB 3043	<L1240>
	LD   B,L     			;11FD 45
L11FE:	LD   B,H     			;11FE 44
	LD   (HL),38H  			;11FF 3638	<38H>
	JR   NC,L1246    		;1201 3043	<L1246>
L1203:	LD   B,L     			;1203 45
	LD   B,H     			;1204 44
	SCF          			;1205 37
	JR   C,L124A     		;1206 3842	<L124A>
	JR   NC,L1240    		;1208 3036	<L1240>
	SCF          			;120A 37
	LD   (M3632),A   		;120B 323236	<M3632>
	INC  (HL)    			;120E 34
	JR   C,L1241     		;120F 3830	<L1241>
	LD   B,(HL)  			;1211 46
L1212:	LD   B,D     			;1212 42
	INC  SP      			;1213 33
	SCF          			;1214 37
	LD   (M3031),A   		;1215 323130	<M3031>
	LD   SP,M3745    		;1218 314537	<M3745>
	DEC  C       			;121B 0D
	LD   A,(BC)  			;121C 0A
	LD   A,(M3032)   		;121D 3A3230	<M3032>
	JR   NC,L1259    		;1220 3037	<L1259>
	JR   C,L1254     		;1222 3830	<L1254>
L1224:	JR   NC,L1256    		;1224 3030	<L1256>
	JR   C,L1258     		;1226 3830	<L1258>
	LD   B,E     			;1228 43
	LD   B,D     			;1229 42
L122A:	ADD  HL,SP   			;122A 39
	LD   B,L     			;122B 45
L122C:	LD   B,E     			;122C 43
	ADD  HL,SP   			;122D 39
	INC  SP      			;122E 33
	LD   B,C     			;122F 41
L1230:	DEC  (HL)    			;1230 35
	LD   B,(HL)  			;1231 46
	JR   C,L1264     		;1232 3830	<L1264>
L1234:	LD   B,L     			;1234 45
	LD   (HL),30H  			;1235 3630	<30H>
	SCF          			;1237 37
	LD   B,E     			;1238 43
	JR   NC,L126D    		;1239 3032	<L126D>
	LD   SP,M3637    		;123B 313736	<M3637>
	LD   SP,M3333    		;123E 313333	<M3333>
L1241:	LD   B,C     			;1241 41
	JR   NC,L1274    		;1242 3030	<L1274>
	JR   C,L1276     		;1244 3830	<L1276>
L1246:	LD   B,E     			;1246 43
	LD   B,(HL)  			;1247 46
	INC  (HL)    			;1248 34
	LD   B,L     			;1249 45
L124A:	JR   NC,L1282    		;124A 3036	<L1282>
	JR   NC,L127E    		;124C 3030	<L127E>
	LD   (M3641),A   		;124E 324136	<M3641>
	JR   NC,L128B    		;1251 3038	<L128B>
	JR   NC,L128C    		;1253 3037	<L128C>
	LD   B,E     			;1255 43
L1256:	LD   (M4146),A   		;1256 324641	<M4146>
L1259:	SCF          			;1259 37
	LD   B,L     			;125A 45
	LD   B,H     			;125B 44
	INC  (HL)    			;125C 34
	LD   (M3442),A   		;125D 324234	<M3442>
	JR   NC,L1299    		;1260 3037	<L1299>
	INC  SP      			;1262 33
	JR   C,L1295     		;1263 3830	<L1295>
	INC  SP      			;1265 33
	LD   B,H     			;1266 44
	ADD  HL,SP   			;1267 39
	DEC  C       			;1268 0D
	LD   A,(BC)  			;1269 0A
	LD   A,(M3032)   		;126A 3A3230	<M3032>
L126D:	JR   NC,L12A6    		;126D 3037	<L12A6>
	LD   B,C     			;126F 41
	JR   NC,L12A2    		;1270 3030	<L12A2>
	JR   NC,L12A6    		;1272 3032	<L12A6>
L1274:	LD   SP,M3030    		;1274 313030	<M3030>
	JR   C,L12A9     		;1277 3830	<L12A9>
	LD   (M3632),A   		;1279 323236	<M3632>
	JR   NC,L12B6    		;127C 3038	<L12B6>
L127E:	JR   NC,L12C3    		;127E 3043	<L12C3>
	ADD  HL,SP   			;1280 39
	LD   B,(HL)  			;1281 46
L1282:	SCF          			;1282 37
	LD   (M3241),A   		;1283 324132	<M3241>
	LD   B,(HL)  			;1286 46
	JR   C,L12B9     		;1287 3830	<L12B9>
	SCF          			;1289 37
	LD   B,E     			;128A 43
L128B:	LD   B,D     			;128B 42
L128C:	DEC  (HL)    			;128C 35
	LD   (M4630),A   		;128D 323046	<M4630>
	JR   C,L12C4     		;1290 3832	<L12C4>
	LD   SP,M3432    		;1292 313234	<M3432>
L1295:	JR   C,L12C7     		;1295 3830	<L12C7>
	LD   B,E     			;1297 43
	LD   B,D     			;1298 42
L1299:	LD   B,L     			;1299 45
	LD   (HL),43H  			;129A 3643	<43H>
	LD   B,H     			;129C 44
	LD   B,E     			;129D 43
	LD   (HL),30H  			;129E 3630	<30H>
	DEC  (HL)    			;12A0 35
	LD   B,E     			;12A1 43
L12A2:	JR   C,L12D6     		;12A2 3832	<L12D6>
	LD   SP,M3833    		;12A4 313338	<M3833>
	JR   NC,L12D9    		;12A7 3030	<L12D9>
L12A9:	LD   (M3232),A   		;12A9 323232	<M3232>
	LD   B,(HL)  			;12AC 46
	JR   C,L12DF     		;12AD 3830	<L12DF>
	LD   SP,M4538    		;12AF 313845	<M4538>
	SCF          			;12B2 37
	LD   B,D     			;12B3 42
	DEC  (HL)    			;12B4 35
	DEC  C       			;12B5 0D
L12B6:	LD   A,(BC)  			;12B6 0A
	LD   A,(M3032)   		;12B7 3A3230	<M3032>
	JR   NC,L12F3    		;12BA 3037	<L12F3>
	LD   B,E     			;12BC 43
	JR   NC,L12EF    		;12BD 3030	<L12EF>
	JR   NC,L12F1    		;12BF 3030	<L12F1>
	LD   (HL),30H  			;12C1 3630	<30H>
L12C3:	LD   SP,M4443    		;12C3 314344	<M4443>
	LD   B,C     			;12C6 41
L12C7:	LD   B,D     			;12C7 42
	JR   NC,L12FF    		;12C8 3035	<L12FF>
	LD   (M3030),A   		;12CA 323030	<M3030>
	LD   (M3630),A   		;12CD 323036	<M3630>
	JR   NC,L1305    		;12D0 3033	<L1305>
	INC  SP      			;12D2 33
	LD   B,C     			;12D3 41
	DEC  (HL)    			;12D4 35
	JR   C,L130F     		;12D5 3838	<L130F>
	JR   NC,L130C    		;12D7 3033	<L130C>
L12D9:	LD   B,H     			;12D9 44
	LD   B,D     			;12DA 42
	JR   C,L1310     		;12DB 3833	<L1310>
	JR   C,L130F     		;12DD 3830	<L130F>
L12DF:	DEC  (HL)    			;12DF 35
	LD   SP,M3645    		;12E0 314536	<M3645>
	LD   (HL),43H  			;12E3 3643	<43H>
	INC  SP      			;12E5 33
	LD   B,(HL)  			;12E6 46
	LD   SP,M3030    		;12E7 313030	<M3030>
	LD   (M3531),A   		;12EA 323135	<M3531>
	LD   (HL),38H  			;12ED 3638	<38H>
L12EF:	JR   NC,L1324    		;12EF 3033	<L1324>
L12F1:	LD   B,E     			;12F1 43
	JR   C,L132B     		;12F2 3837	<L132B>
	LD   B,(HL)  			;12F4 46
	INC  SP      			;12F5 33
	JR   C,L132E     		;12F6 3836	<L132E>
	SCF          			;12F8 37
	SCF          			;12F9 37
	LD   B,(HL)  			;12FA 46
	LD   B,D     			;12FB 42
	LD   B,E     			;12FC 43
	ADD  HL,SP   			;12FD 39
	LD   (M3541),A   		;12FE 324135	<M3541>
	LD   (HL),0DH  			;1301 360D	<0DH>
	LD   A,(BC)  			;1303 0A
	LD   A,(M3032)   		;1304 3A3230	<M3032>
	JR   NC,L1340    		;1307 3037	<L1340>
	LD   B,L     			;1309 45
	JR   NC,L133C    		;130A 3030	<L133C>
L130C:	JR   NC,L1341    		;130C 3033	<L1341>
	LD   SP,M3038    		;130E 313830	<M3038>
	SCF          			;1311 37
	LD   B,E     			;1312 43
	LD   B,D     			;1313 42
	DEC  (HL)    			;1314 35
	LD   (M3231),A   		;1315 323132	<M3231>
	INC  SP      			;1318 33
	JR   C,L134B     		;1319 3830	<L134B>
	LD   (M3030),A   		;131B 323030	<M3030>
	LD   B,C     			;131E 41
	LD   B,E     			;131F 43
	LD   B,D     			;1320 42
	LD   B,C     			;1321 41
	LD   B,L     			;1322 45
	LD   (M3831),A   		;1323 323138	<M3831>
	LD   B,D     			;1326 42
	JR   NC,L1361    		;1327 3038	<L1361>
	LD   (M3332),A   		;1329 323233	<M3332>
	LD   SP,M3038    		;132C 313830	<M3038>
	INC  SP      			;132F 33
	SCF          			;1330 37
	LD   B,E     			;1331 43
	ADD  HL,SP   			;1332 39
	SCF          			;1333 37
	LD   B,L     			;1334 45
	LD   B,L     			;1335 45
	LD   (HL),32H  			;1336 3632	<32H>
	JR   NC,L137D    		;1338 3043	<L137D>
	JR   NC,L137F    		;133A 3043	<L137F>
L133C:	LD   B,D     			;133C 42
	LD   B,L     			;133D 45
	LD   B,L     			;133E 45
	INC  SP      			;133F 33
L1340:	LD   B,L     			;1340 45
L1341:	JR   NC,L1386    		;1341 3043	<L1386>
	LD   B,(HL)  			;1343 46
	LD   B,(HL)  			;1344 46
	LD   B,C     			;1345 41
	SCF          			;1346 37
	LD   B,E     			;1347 43
	ADD  HL,SP   			;1348 39
	INC  SP      			;1349 33
	LD   B,L     			;134A 45
L134B:	JR   NC,L1391    		;134B 3044	<L1391>
	LD   (M0D38),A   		;134D 32380D	<M0D38>
	LD   A,(BC)  			;1350 0A
	LD   A,(M3032)   		;1351 3A3230	<M3032>
	JR   NC,L138E    		;1354 3038	<L138E>
	JR   NC,L1388    		;1356 3030	<L1388>
	JR   NC,L138A    		;1358 3030	<L138A>
	LD   B,(HL)  			;135A 46
	LD   B,(HL)  			;135B 46
	JR   NC,L1394    		;135C 3036	<L1394>
	JR   NC,L1393    		;135E 3033	<L1393>
	LD   (M3431),A   		;1360 323134	<M3431>
	DEC  (HL)    			;1363 35
	JR   C,L1396     		;1364 3830	<L1396>
	INC  SP      			;1366 33
	INC  (HL)    			;1367 34
	INC  SP      			;1368 33
	INC  (HL)    			;1369 34
	INC  SP      			;136A 33
	INC  (HL)    			;136B 34
	INC  SP      			;136C 33
	INC  (HL)    			;136D 34
	LD   B,E     			;136E 43
	LD   B,D     			;136F 42
	JR   C,L13A8     		;1370 3836	<L13A8>
	INC  SP      			;1372 33
	LD   B,L     			;1373 45
	JR   NC,L13AE    		;1374 3038	<L13AE>
	LD   B,E     			;1376 43
	LD   B,(HL)  			;1377 46
	LD   SP,M4630    		;1378 313046	<M4630>
	DEC  (HL)    			;137B 35
	LD   (M4631),A   		;137C 323146	<M4631>
L137F:	LD   (HL),37H  			;137F 3637	<37H>
	LD   B,E     			;1381 43
	LD   (M3232),A   		;1382 323232	<M3232>
	LD   B,D     			;1385 42
L1386:	JR   C,L13B8     		;1386 3830	<L13B8>
L1388:	LD   B,E     			;1388 43
	ADD  HL,SP   			;1389 39
L138A:	LD   (M3431),A   		;138A 323134	<M3431>
	LD   B,L     			;138D 45
L138E:	JR   C,L13C0     		;138E 3830	<L13C0>
	LD   SP,M3031    		;1390 313130	<M3031>
L1393:	JR   C,L13C5     		;1393 3830	<L13C5>
	JR   NC,L13C7    		;1395 3030	<L13C7>
	LD   SP,M3130    		;1397 313031	<M3130>
	SCF          			;139A 37
	LD   B,E     			;139B 43
	DEC  C       			;139C 0D
	LD   A,(BC)  			;139D 0A
	LD   A,(M3032)   		;139E 3A3230	<M3032>
	JR   NC,L13DB    		;13A1 3038	<L13DB>
	LD   (M3030),A   		;13A3 323030	<M3030>
	JR   NC,L13D8    		;13A6 3030	<L13D8>
L13A8:	INC  SP      			;13A8 33
	LD   B,(HL)  			;13A9 46
	INC  SP      			;13AA 33
	JR   NC,L13E4    		;13AB 3037	<L13E4>
	INC  SP      			;13AD 33
L13AE:	JR   NC,L13E0    		;13AE 3030	<L13E0>
	LD   B,(HL)  			;13B0 46
	LD   B,L     			;13B1 45
	DEC  (HL)    			;13B2 35
	SCF          			;13B3 37
	LD   SP,M3332    		;13B4 313233	<M3332>
	SCF          			;13B7 37
L13B8:	LD   SP,M3332    		;13B8 313233	<M3332>
	INC  SP      			;13BB 33
	LD   (HL),31H  			;13BC 3631	<31H>
	INC  SP      			;13BE 33
	LD   (M3733),A   		;13BF 323337	<M3733>
	LD   (M3332),A   		;13C2 323233	<M3332>
L13C5:	INC  SP      			;13C5 33
	LD   (HL),31H  			;13C6 3631	<31H>
	INC  (HL)    			;13C8 34
	LD   (M3733),A   		;13C9 323337	<M3733>
	LD   (M3145),A   		;13CC 324531	<M3145>
	LD   B,C     			;13CF 41
	SCF          			;13D0 37
	LD   B,L     			;13D1 45
	LD   B,H     			;13D2 44
	DEC  (HL)    			;13D3 35
	LD   (M3031),A   		;13D4 323130	<M3031>
	LD   B,L     			;13D7 45
L13D8:	ADD  HL,SP   			;13D8 39
	LD   B,(HL)  			;13D9 46
	LD   B,D     			;13DA 42
L13DB:	LD   B,E     			;13DB 43
	ADD  HL,SP   			;13DC 39
	LD   (M3331),A   		;13DD 323133	<M3331>
L13E0:	LD   B,L     			;13E0 45
	JR   C,L1413     		;13E1 3830	<L1413>
	LD   SP,M3031    		;13E3 313130	<M3031>
	JR   C,L1419     		;13E6 3831	<L1419>
	INC  SP      			;13E8 33
	DEC  C       			;13E9 0D
	LD   A,(BC)  			;13EA 0A
	LD   A,(M3032)   		;13EB 3A3230	<M3032>
	JR   NC,L1428    		;13EE 3038	<L1428>
	INC  (HL)    			;13F0 34
	JR   NC,L1423    		;13F1 3030	<L1423>
	JR   NC,L1425    		;13F3 3030	<L1425>
	JR   NC,L1427    		;13F5 3030	<L1427>
	LD   SP,M3032    		;13F7 313230	<M3032>
	JR   NC,L142F    		;13FA 3033	<L142F>
	SCF          			;13FC 37
	LD   B,L     			;13FD 45
	LD   B,(HL)  			;13FE 46
	LD   B,L     			;13FF 45
	JR   NC,L1434    		;1400 3032	<L1434>
	LD   (M3030),A   		;1402 323030	<M3030>
	LD   B,H     			;1405 44
	LD   B,L     			;1406 45
	DEC  (HL)    			;1407 35
	INC  SP      			;1408 33
	LD   B,L     			;1409 45
	JR   NC,L1441    		;140A 3035	<L1441>
	LD   B,E     			;140C 43
	LD   B,(HL)  			;140D 46
	SCF          			;140E 37
	LD   B,L     			;140F 45
	LD   B,L     			;1410 45
	LD   SP,M4546    		;1411 314645	<M4546>
	LD   SP,M3337    		;1414 313733	<M3337>
	JR   C,L1449     		;1417 3830	<L1449>
L1419:	INC  SP      			;1419 33
	SCF          			;141A 37
	ADD  HL,SP   			;141B 39
	INC  SP      			;141C 33
	SCF          			;141D 37
	LD   B,E     			;141E 43
	ADD  HL,SP   			;141F 39
	LD   B,E     			;1420 43
	LD   B,D     			;1421 42
	LD   (M3131),A   		;1422 323131	<M3131>
L1425:	ADD  HL,SP   			;1425 39
	LD   SP,M4530    		;1426 313045	<M4530>
	ADD  HL,SP   			;1429 39
	LD   B,E     			;142A 43
	ADD  HL,SP   			;142B 39
	LD   (M3431),A   		;142C 323134	<M3431>
L142F:	LD   SP,M3038    		;142F 313830	<M3038>
	LD   SP,M4631    		;1432 313146	<M4631>
	JR   NC,L1444    		;1435 300D	<L1444>
	LD   A,(BC)  			;1437 0A
	LD   A,(M3032)   		;1438 3A3230	<M3032>
	JR   NC,L1475    		;143B 3038	<L1475>
	LD   (HL),30H  			;143D 3630	<30H>
	JR   NC,L1471    		;143F 3030	<L1471>
L1441:	JR   NC,L147B    		;1441 3038	<L147B>
	JR   NC,L1475    		;1443 3030	<L1475>
	SCF          			;1445 37
	LD   B,L     			;1446 45
	LD   SP,M4139    		;1447 313941	<M4139>
	LD   (HL),31H  			;144A 3631	<31H>
	ADD  HL,SP   			;144C 39
	LD   B,C     			;144D 41
	LD   (HL),43H  			;144E 3643	<43H>
	JR   C,L1485     		;1450 3833	<L1485>
	SCF          			;1452 37
	LD   B,E     			;1453 43
	ADD  HL,SP   			;1454 39
	INC  SP      			;1455 33
	LD   B,C     			;1456 41
	INC  SP      			;1457 33
	SCF          			;1458 37
	JR   C,L148B     		;1459 3830	<L148B>
	LD   B,C     			;145B 41
	SCF          			;145C 37
	LD   B,E     			;145D 43
	JR   NC,L1492    		;145E 3032	<L1492>
	LD   B,C     			;1460 41
	LD   (M3842),A   		;1461 324238	<M3842>
	JR   NC,L149D    		;1464 3037	<L149D>
	LD   B,E     			;1466 43
	LD   B,D     			;1467 42
	DEC  (HL)    			;1468 35
	LD   (M3131),A   		;1469 323131	<M3131>
	LD   B,L     			;146C 45
	JR   C,L149F     		;146D 3830	<L149F>
	LD   (M3030),A   		;146F 323030	<M3030>
	LD   B,H     			;1472 44
	JR   NC,L14A6    		;1473 3031	<L14A6>
L1475:	LD   (M3030),A   		;1475 323030	<M3030>
	INC  SP      			;1478 33
	SCF          			;1479 37
	ADD  HL,SP   			;147A 39
L147B:	LD   B,C     			;147B 41
	LD   (HL),32H  			;147C 3632	<32H>
	JR   NC,L14B4    		;147E 3034	<L14B4>
	JR   C,L14C4     		;1480 3842	<L14C4>
	SCF          			;1482 37
	DEC  C       			;1483 0D
	LD   A,(BC)  			;1484 0A
L1485:	LD   A,(M3032)   		;1485 3A3230	<M3032>
	JR   NC,L14C2    		;1488 3038	<L14C2>
	JR   C,L14BC     		;148A 3830	<L14BC>
	JR   NC,L14BE    		;148C 3030	<L14BE>
	LD   B,E     			;148E 43
	LD   B,D     			;148F 42
	LD   (M3131),A   		;1490 323131	<M3131>
	JR   NC,L14DB    		;1493 3046	<L14DB>
	JR   C,L14D8     		;1495 3841	<L14D8>
	SCF          			;1497 37
	LD   B,E     			;1498 43
	ADD  HL,SP   			;1499 39
	JR   NC,L14D2    		;149A 3036	<L14D2>
	INC  SP      			;149C 33
L149D:	SCF          			;149D 37
	LD   B,H     			;149E 44
L149F:	SCF          			;149F 37
	LD   (M3330),A   		;14A0 323033	<M3330>
	LD   (HL),37H  			;14A3 3637	<37H>
	LD   B,L     			;14A5 45
L14A6:	LD   (M3446),A   		;14A6 324634	<M3446>
	SCF          			;14A9 37
	LD   B,E     			;14AA 43
	LD   B,H     			;14AB 44
	ADD  HL,SP   			;14AC 39
	LD   B,H     			;14AD 44
	JR   NC,L14E5    		;14AE 3035	<L14E5>
	LD   B,C     			;14B0 41
	JR   NC,L14E5    		;14B1 3032	<L14E5>
	JR   NC,L14E7    		;14B3 3032	<L14E7>
	LD   B,H     			;14B5 44
	LD   B,L     			;14B6 45
	LD   B,H     			;14B7 44
	DEC  (HL)    			;14B8 35
	LD   B,D     			;14B9 42
	JR   NC,L14F3    		;14BA 3037	<L14F3>
L14BC:	JR   C,L14EE     		;14BC 3830	<L14EE>
L14BE:	SCF          			;14BE 37
	LD   B,C     			;14BF 41
	LD   B,C     			;14C0 41
	LD   B,D     			;14C1 42
L14C2:	LD   (M4546),A   		;14C2 324645	<M4546>
	LD   (HL),45H  			;14C5 3645	<45H>
	JR   NC,L14FB    		;14C7 3032	<L14FB>
	JR   NC,L14FD    		;14C9 3032	<L14FD>
	LD   (M4137),A   		;14CB 323741	<M4137>
	ADD  HL,SP   			;14CE 39
	DEC  (HL)    			;14CF 35
	DEC  C       			;14D0 0D
	LD   A,(BC)  			;14D1 0A
L14D2:	LD   A,(M3032)   		;14D2 3A3230	<M3032>
	JR   NC,L150F    		;14D5 3038	<L150F>
	LD   B,C     			;14D7 41
L14D8:	JR   NC,L150A    		;14D8 3030	<L150A>
	JR   NC,L151D    		;14DA 3041	<L151D>
	LD   (HL),35H  			;14DC 3635	<35H>
	SCF          			;14DE 37
	JR   NC,L1512    		;14DF 3031	<L1512>
	LD   (M3030),A   		;14E1 323030	<M3030>
	INC  SP      			;14E4 33
L14E5:	SCF          			;14E5 37
	ADD  HL,SP   			;14E6 39
L14E7:	LD   B,C     			;14E7 41
	LD   (M3032),A   		;14E8 323230	<M3032>
	LD   SP,M4346    		;14EB 314643	<M4346>
L14EE:	LD   B,D     			;14EE 42
	LD   (M3131),A   		;14EF 323131	<M3131>
	JR   NC,L153A    		;14F2 3046	<L153A>
	JR   C,L152D     		;14F4 3837	<L152D>
	LD   B,L     			;14F6 45
	JR   NC,L153F    		;14F7 3046	<L153F>
	JR   NC,L1541    		;14F9 3046	<L1541>
L14FB:	LD   (M4546),A   		;14FB 324645	<M4546>
	LD   (HL),33H  			;14FE 3633	<33H>
	JR   C,L1536     		;1500 3834	<L1536>
	SCF          			;1502 37
	SCF          			;1503 37
	LD   B,L     			;1504 45
	JR   NC,L153E    		;1505 3037	<L153E>
	JR   NC,L1540    		;1507 3037	<L1540>
	JR   NC,L1542    		;1509 3037	<L1542>
	LD   B,L     			;150B 45
	LD   (HL),30H  			;150C 3630	<30H>
	SCF          			;150E 37
L150F:	LD   B,D     			;150F 42
	JR   NC,L1546    		;1510 3034	<L1546>
L1512:	SCF          			;1512 37
	LD   B,E     			;1513 43
	LD   B,H     			;1514 44
	JR   NC,L1558    		;1515 3041	<L1558>
	JR   NC,L155F    		;1517 3046	<L155F>
	LD   B,C     			;1519 41
	SCF          			;151A 37
	ADD  HL,SP   			;151B 39
	DEC  (HL)    			;151C 35
L151D:	DEC  C       			;151D 0D
	LD   A,(BC)  			;151E 0A
	LD   A,(M3032)   		;151F 3A3230	<M3032>
	JR   NC,L155C    		;1522 3038	<L155C>
	LD   B,E     			;1524 43
	JR   NC,L1557    		;1525 3030	<L1557>
	JR   NC,L156C    		;1527 3043	<L156C>
	ADD  HL,SP   			;1529 39
	JR   NC,L1562    		;152A 3036	<L1562>
	INC  SP      			;152C 33
L152D:	JR   C,L1572     		;152D 3843	<L1572>
	LD   B,H     			;152F 44
	JR   NC,L1573    		;1530 3041	<L1573>
	JR   NC,L157A    		;1532 3046	<L157A>
	LD   B,C     			;1534 41
	SCF          			;1535 37
L1536:	LD   B,E     			;1536 43
	ADD  HL,SP   			;1537 39
	SCF          			;1538 37
	ADD  HL,SP   			;1539 39
L153A:	LD   B,C     			;153A 41
	LD   B,L     			;153B 45
	SCF          			;153C 37
	SCF          			;153D 37
L153E:	LD   (M3645),A   		;153E 324536	<M3645>
L1541:	LD   B,C     			;1541 41
L1542:	INC  SP      			;1542 33
	INC  (HL)    			;1543 34
	LD   (M3333),A   		;1544 323333	<M3333>
	LD   B,L     			;1547 45
	JR   NC,L157E    		;1548 3034	<L157E>
	ADD  HL,SP   			;154A 39
	JR   NC,L1584    		;154B 3037	<L1584>
	SCF          			;154D 37
	JR   NC,L1586    		;154E 3036	<L1586>
	INC  SP      			;1550 33
	JR   C,L1596     		;1551 3843	<L1596>
	LD   B,H     			;1553 44
	JR   NC,L1597    		;1554 3041	<L1597>
	JR   NC,L159E    		;1556 3046	<L159E>
L1558:	INC  SP      			;1558 33
	LD   B,L     			;1559 45
	LD   (HL),43H  			;155A 3643	<43H>
L155C:	INC  SP      			;155C 33
	LD   (M3733),A   		;155D 323337	<M3733>
	JR   C,L1592     		;1560 3830	<L1592>
L1562:	INC  SP      			;1562 33
	LD   B,L     			;1563 45
	JR   NC,L15AB    		;1564 3045	<L15AB>
	LD   B,(HL)  			;1566 46
	LD   B,(HL)  			;1567 46
	LD   B,L     			;1568 45
	INC  SP      			;1569 33
	DEC  C       			;156A 0D
	LD   A,(BC)  			;156B 0A
L156C:	LD   A,(M3032)   		;156C 3A3230	<M3032>
	JR   NC,L15A9    		;156F 3038	<L15A9>
	LD   B,L     			;1571 45
L1572:	JR   NC,L15A4    		;1572 3030	<L15A4>
	JR   NC,L15A9    		;1574 3033	<L15A9>
	SCF          			;1576 37
	LD   B,E     			;1577 43
	ADD  HL,SP   			;1578 39
	LD   (M3331),A   		;1579 323133	<M3331>
	LD   B,L     			;157C 45
	JR   C,L15AF     		;157D 3830	<L15AF>
	LD   SP,M3031    		;157F 313130	<M3031>
	JR   C,L15B4     		;1582 3830	<L15B4>
L1584:	JR   NC,L15BD    		;1584 3037	<L15BD>
L1586:	LD   B,L     			;1586 45
	LD   SP,M4239    		;1587 313942	<M4239>
	LD   (HL),31H  			;158A 3631	<31H>
	ADD  HL,SP   			;158C 39
	LD   B,D     			;158D 42
	LD   (HL),43H  			;158E 3643	<43H>
	ADD  HL,SP   			;1590 39
	LD   (M3031),A   		;1591 323130	<M3031>
	JR   NC,L15C7    		;1594 3031	<L15C7>
L1596:	ADD  HL,SP   			;1596 39
L1597:	LD   B,E     			;1597 43
	LD   B,H     			;1598 44
	LD   B,L     			;1599 45
	DEC  (HL)    			;159A 35
	JR   NC,L15D1    		;159B 3034	<L15D1>
	LD   (M3038),A   		;159D 323830	<M3038>
	LD   B,C     			;15A0 41
	LD   (M3331),A   		;15A1 323133	<M3331>
L15A4:	LD   (M3931),A   		;15A4 323139	<M3931>
	LD   B,(HL)  			;15A7 46
	LD   B,L     			;15A8 45
L15A9:	JR   NC,L15DF    		;15A9 3034	<L15DF>
L15AB:	LD   (M3038),A   		;15AB 323830	<M3038>
	INC  SP      			;15AE 33
L15AF:	LD   (M3431),A   		;15AF 323134	<M3431>
	LD   B,(HL)  			;15B2 46
	LD   SP,M4439    		;15B3 313944	<M4439>
	SCF          			;15B6 37
	DEC  C       			;15B7 0D
	LD   A,(BC)  			;15B8 0A
	LD   A,(M3032)   		;15B9 3A3230	<M3032>
	JR   NC,L15F7    		;15BC 3039	<L15F7>
	JR   NC,L15F0    		;15BE 3030	<L15F0>
	JR   NC,L15F2    		;15C0 3030	<L15F2>
	INC  SP      			;15C2 33
	LD   B,C     			;15C3 41
	DEC  (HL)    			;15C4 35
	JR   C,L15FF     		;15C5 3838	<L15FF>
L15C7:	JR   NC,L1601    		;15C7 3038	<L1601>
	SCF          			;15C9 37
	INC  SP      			;15CA 33
	LD   B,H     			;15CB 44
	INC  (HL)    			;15CC 34
	SCF          			;15CD 37
	LD   B,L     			;15CE 45
	DEC  (HL)    			;15CF 35
	LD   B,E     			;15D0 43
L15D1:	LD   B,H     			;15D1 44
	LD   (M3033),A   		;15D2 323330	<M3033>
	ADD  HL,SP   			;15D5 39
	LD   B,L     			;15D6 45
	LD   SP,M3031    		;15D7 313130	<M3031>
	LD   B,(HL)  			;15DA 46
	ADD  HL,SP   			;15DB 39
	INC  SP      			;15DC 33
	LD   B,C     			;15DD 41
	DEC  (HL)    			;15DE 35
L15DF:	LD   B,L     			;15DF 45
	JR   C,L1612     		;15E0 3830	<L1612>
	LD   B,E     			;15E2 43
	LD   B,D     			;15E3 42
	DEC  (HL)    			;15E4 35
	SCF          			;15E5 37
	LD   (M3038),A   		;15E6 323830	<M3038>
	LD   (HL),46H  			;15E9 3646	<46H>
	INC  SP      			;15EB 33
	LD   (M3431),A   		;15EC 323134	<M3431>
	INC  SP      			;15EF 33
L15F0:	LD   SP,M4430    		;15F0 313044	<M4430>
	LD   B,(HL)  			;15F3 46
	LD   B,(HL)  			;15F4 46
	LD   B,D     			;15F5 42
	LD   B,(HL)  			;15F6 46
L15F7:	SCF          			;15F7 37
	INC  SP      			;15F8 33
	LD   B,C     			;15F9 41
	JR   NC,L1641    		;15FA 3045	<L1641>
	JR   C,L162E     		;15FC 3830	<L162E>
	LD   B,(HL)  			;15FE 46
L15FF:	LD   B,L     			;15FF 45
	JR   NC,L163A    		;1600 3038	<L163A>
	JR   C,L1638     		;1602 3834	<L1638>
	DEC  C       			;1604 0D
	LD   A,(BC)  			;1605 0A
	LD   A,(M3032)   		;1606 3A3230	<M3032>
	JR   NC,L1644    		;1609 3039	<L1644>
	LD   (M3030),A   		;160B 323030	<M3030>
	JR   NC,L1643    		;160E 3033	<L1643>
	JR   NC,L1658    		;1610 3046	<L1658>
L1612:	JR   C,L1657     		;1612 3843	<L1657>
	ADD  HL,SP   			;1614 39
	INC  (HL)    			;1615 34
	LD   B,L     			;1616 45
	LD   (M3733),A   		;1617 323337	<M3733>
	JR   C,L1654     		;161A 3838	<L1654>
	LD   (HL),31H  			;161C 3631	<31H>
	LD   (HL),38H  			;161E 3638	<38H>
	JR   NC,L1657    		;1620 3035	<L1657>
	LD   B,(HL)  			;1622 46
	LD   (M3133),A   		;1623 323331	<M3133>
	LD   B,C     			;1626 41
	LD   B,C     			;1627 41
	LD   (HL),32H  			;1628 3632	<32H>
	JR   C,L1660     		;162A 3834	<L1660>
	LD   SP,M4634    		;162C 313446	<M4634>
	LD   (M3533),A   		;162F 323335	<M3533>
	LD   B,L     			;1632 45
	LD   SP,M4141    		;1633 314141	<M4141>
	LD   SP,M4531    		;1636 313145	<M4531>
	LD   (HL),44H  			;1639 3644	<44H>
	LD   B,E     			;163B 43
	LD   (M3146),A   		;163C 324631	<M3146>
	JR   NC,L1671    		;163F 3030	<L1671>
L1641:	LD   (M3133),A   		;1641 323331	<M3133>
L1644:	LD   B,L     			;1644 45
	DEC  (HL)    			;1645 35
	LD   B,L     			;1646 45
	LD   SP,M4241    		;1647 314142	<M4241>
	LD   (HL),31H  			;164A 3631	<31H>
	LD   (M3332),A   		;164C 323233	<M3332>
	LD   B,C     			;164F 41
	ADD  HL,SP   			;1650 39
	DEC  C       			;1651 0D
	LD   A,(BC)  			;1652 0A
	LD   A,(M3032)   		;1653 3A3230	<M3032>
	JR   NC,L1691    		;1656 3039	<L1691>
L1658:	INC  (HL)    			;1658 34
	JR   NC,L168B    		;1659 3030	<L168B>
	JR   NC,L1694    		;165B 3037	<L1694>
	LD   B,L     			;165D 45
	LD   B,(HL)  			;165E 46
	LD   B,(HL)  			;165F 46
L1660:	LD   (M3733),A   		;1660 323337	<M3733>
	LD   B,L     			;1663 45
	LD   (M3433),A   		;1664 323334	<M3433>
	LD   B,L     			;1667 45
	LD   (M3531),A   		;1668 323135	<M3531>
	ADD  HL,SP   			;166B 39
	JR   C,L169E     		;166C 3830	<L169E>
	JR   C,L16A6     		;166E 3836	<L16A6>
	LD   B,(HL)  			;1670 46
L1671:	LD   B,L     			;1671 45
	JR   NC,L16BA    		;1672 3046	<L16BA>
	INC  SP      			;1674 33
	JR   C,L16A7     		;1675 3830	<L16A7>
	LD   (M4533),A   		;1677 323345	<M4533>
	JR   NC,L16C2    		;167A 3046	<L16C2>
	SCF          			;167C 37
	SCF          			;167D 37
	SCF          			;167E 37
	JR   C,L16B3     		;167F 3832	<L16B3>
	LD   SP,M3635    		;1681 313536	<M3635>
	LD   SP,M4339    		;1684 313943	<M4339>
	LD   B,(HL)  			;1687 46
	SCF          			;1688 37
	LD   B,L     			;1689 45
	LD   (M3131),A   		;168A 323131	<M3131>
	LD   B,(HL)  			;168D 46
	JR   C,L16C0     		;168E 3830	<L16C0>
	LD   B,D     			;1690 42
L1691:	LD   (HL),37H  			;1691 3637	<37H>
	SCF          			;1693 37
L1694:	LD   (M3531),A   		;1694 323135	<M3531>
	LD   B,C     			;1697 41
	LD   SP,M3739    		;1698 313937	<M3739>
	JR   C,L16CF     		;169B 3832	<L16CF>
	LD   B,(HL)  			;169D 46
L169E:	DEC  C       			;169E 0D
	LD   A,(BC)  			;169F 0A
	LD   A,(M3032)   		;16A0 3A3230	<M3032>
	JR   NC,L16DE    		;16A3 3039	<L16DE>
	LD   (HL),30H  			;16A5 3630	<30H>
L16A7:	JR   NC,L16D9    		;16A7 3030	<L16D9>
	JR   C,L16E2     		;16A9 3837	<L16E2>
	JR   C,L16DE     		;16AB 3831	<L16DE>
	LD   B,E     			;16AD 43
	LD   B,(HL)  			;16AE 46
	SCF          			;16AF 37
	LD   B,L     			;16B0 45
	LD   (M3433),A   		;16B1 323334	<M3433>
	LD   B,L     			;16B4 45
	LD   (M3231),A   		;16B5 323132	<M3231>
	JR   NC,L16F2    		;16B8 3038	<L16F2>
L16BA:	JR   NC,L16FE    		;16BA 3042	<L16FE>
	LD   (HL),37H  			;16BC 3637	<37H>
	SCF          			;16BE 37
	SCF          			;16BF 37
L16C0:	ADD  HL,SP   			;16C0 39
	LD   (M4233),A   		;16C1 323342	<M4233>
	LD   (HL),37H  			;16C4 3637	<37H>
	SCF          			;16C6 37
	LD   B,E     			;16C7 43
	ADD  HL,SP   			;16C8 39
	INC  SP      			;16C9 33
	LD   B,L     			;16CA 45
	JR   NC,L1703    		;16CB 3036	<L1703>
	LD   B,E     			;16CD 43
	LD   B,(HL)  			;16CE 46
L16CF:	JR   NC,L1715    		;16CF 3044	<L1715>
	LD   (M4130),A   		;16D1 323041	<M4130>
	LD   B,(HL)  			;16D4 46
	LD   B,E     			;16D5 43
	ADD  HL,SP   			;16D6 39
	LD   (M3531),A   		;16D7 323135	<M3531>
	JR   C,L1714     		;16DA 3838	<L1714>
	JR   NC,L170E    		;16DC 3030	<L170E>
L16DE:	LD   SP,M4535    		;16DE 313545	<M4535>
	JR   C,L1713     		;16E1 3830	<L1713>
	JR   NC,L1726    		;16E3 3041	<L1726>
	JR   NC,L172D    		;16E5 3046	<L172D>
	INC  SP      			;16E7 33
	JR   C,L171F     		;16E8 3835	<L171F>
	JR   NC,L16F9    		;16EA 300D	<L16F9>
	LD   A,(BC)  			;16EC 0A
	LD   A,(M3032)   		;16ED 3A3230	<M3032>
	JR   NC,L172B    		;16F0 3039	<L172B>
L16F2:	JR   C,L1724     		;16F2 3830	<L1724>
	JR   NC,L1726    		;16F4 3030	<L1726>
	JR   NC,L173B    		;16F6 3043	<L173B>
	LD   (M3733),A   		;16F8 323337	<M3733>
	LD   B,L     			;16FB 45
	LD   B,C     			;16FC 41
	SCF          			;16FD 37
L16FE:	LD   B,E     			;16FE 43
	JR   C,L1744     		;16FF 3843	<L1744>
	LD   B,H     			;1701 44
	LD   B,L     			;1702 45
L1703:	DEC  (HL)    			;1703 35
	JR   NC,L173A    		;1704 3034	<L173A>
	LD   (M3030),A   		;1706 323030	<M3030>
	INC  SP      			;1709 33
	INC  SP      			;170A 33
	LD   B,L     			;170B 45
	LD   SP,M4630    		;170C 313046	<M4630>
	LD   B,(HL)  			;170F 46
	LD   SP,M3531    		;1710 313135	<M3531>
L1713:	SCF          			;1713 37
L1714:	JR   C,L1746     		;1714 3830	<L1746>
	LD   B,(HL)  			;1716 46
	INC  SP      			;1717 33
	LD   SP,M3841    		;1718 314138	<M3841>
	LD   (HL),38H  			;171B 3638	<38H>
	LD   (HL),31H  			;171D 3631	<31H>
L171F:	LD   (M4246),A   		;171F 324642	<M4246>
	JR   NC,L1765    		;1722 3041	<L1765>
L1724:	JR   NC,L176C    		;1724 3046	<L176C>
L1726:	LD   B,H     			;1726 44
	JR   C,L175B     		;1727 3832	<L175B>
	LD   B,L     			;1729 45
	JR   NC,L175D    		;172A 3031	<L175D>
	LD   B,E     			;172C 43
L172D:	LD   B,D     			;172D 42
	LD   (HL),36H  			;172E 3636	<36H>
	LD   (M3230),A   		;1730 323032	<M3230>
	LD   B,D     			;1733 42
	INC  SP      			;1734 33
	LD   B,C     			;1735 41
	INC  SP      			;1736 33
	LD   SP,M0A0D    		;1737 310D0A	<M0A0D>
L173A:	LD   A,(M3032)   		;173A 3A3230	<M3032>
	JR   NC,L1778    		;173D 3039	<L1778>
	LD   B,C     			;173F 41
	JR   NC,L1772    		;1740 3030	<L1772>
	JR   NC,L1774    		;1742 3030	<L1774>
L1744:	LD   B,E     			;1744 43
	JR   C,L1777     		;1745 3830	<L1777>
	LD   B,(HL)  			;1747 46
	LD   B,L     			;1748 45
	DEC  (HL)    			;1749 35
	JR   NC,L177F    		;174A 3033	<L177F>
	JR   NC,L1780    		;174C 3032	<L1780>
	INC  (HL)    			;174E 34
	LD   B,E     			;174F 43
	LD   B,H     			;1750 44
	LD   B,L     			;1751 45
	JR   C,L1784     		;1752 3830	<L1784>
	ADD  HL,SP   			;1754 39
	LD   (M3331),A   		;1755 323133	<M3331>
	JR   C,L1792     		;1758 3838	<L1792>
	JR   NC,L178F    		;175A 3033	<L178F>
	LD   (HL),32H  			;175C 3632	<32H>
	LD   (HL),46H  			;175E 3646	<46H>
	SCF          			;1760 37
	SCF          			;1761 37
	LD   B,L     			;1762 45
	LD   B,C     			;1763 41
	SCF          			;1764 37
L1765:	LD   (M4630),A   		;1765 323046	<M4630>
	LD   B,D     			;1768 42
	LD   (M3045),A   		;1769 324530	<M3045>
L176C:	LD   B,E     			;176C 43
	SCF          			;176D 37
	LD   B,L     			;176E 45
	LD   B,E     			;176F 43
	LD   (HL),30H  			;1770 3630	<30H>
L1772:	LD   SP,M3732    		;1772 313237	<M3732>
	SCF          			;1775 37
	SCF          			;1776 37
L1777:	INC  SP      			;1777 33
L1778:	LD   B,L     			;1778 45
	LD   SP,M4632    		;1779 313246	<M4632>
	LD   B,(HL)  			;177C 46
	LD   (M3733),A   		;177D 323337	<M3733>
L1780:	LD   B,L     			;1780 45
	LD   B,E     			;1781 43
	LD   (HL),30H  			;1782 3630	<30H>
L1784:	LD   B,E     			;1784 43
	DEC  C       			;1785 0D
	LD   A,(BC)  			;1786 0A
	LD   A,(M3032)   		;1787 3A3230	<M3032>
	JR   NC,L17C5    		;178A 3039	<L17C5>
	LD   B,E     			;178C 43
	JR   NC,L17BF    		;178D 3030	<L17BF>
L178F:	JR   NC,L17C1    		;178F 3030	<L17C1>
	LD   SP,M3732    		;1791 313237	<M3732>
	SCF          			;1794 37
	SCF          			;1795 37
	LD   (M3545),A   		;1796 324535	<M3545>
	ADD  HL,SP   			;1799 39
	INC  SP      			;179A 33
	DEC  (HL)    			;179B 35
	LD   (M4430),A   		;179C 323044	<M4430>
	SCF          			;179F 37
	LD   SP,M3138    		;17A0 313831	<M3138>
	LD   (HL),43H  			;17A3 3643	<43H>
	LD   B,H     			;17A5 44
	LD   B,L     			;17A6 45
	JR   C,L17D9     		;17A7 3830	<L17D9>
	ADD  HL,SP   			;17A9 39
	LD   B,E     			;17AA 43
	LD   B,H     			;17AB 44
	DEC  (HL)    			;17AC 35
	DEC  (HL)    			;17AD 35
	JR   NC,L17E6    		;17AE 3036	<L17E6>
	INC  SP      			;17B0 33
	LD   B,L     			;17B1 45
	LD   SP,M4632    		;17B2 313246	<M4632>
	LD   B,(HL)  			;17B5 46
	LD   (M3031),A   		;17B6 323130	<M3031>
	LD   B,H     			;17B9 44
	JR   C,L17EC     		;17BA 3830	<L17EC>
	SCF          			;17BC 37
	LD   B,L     			;17BD 45
	LD   B,E     			;17BE 43
L17BF:	LD   (HL),30H  			;17BF 3630	<30H>
L17C1:	LD   SP,M3732    		;17C1 313237	<M3732>
	SCF          			;17C4 37
L17C5:	SCF          			;17C5 37
	LD   (M3545),A   		;17C6 324535	<M3545>
	ADD  HL,SP   			;17C9 39
	INC  SP      			;17CA 33
	DEC  (HL)    			;17CB 35
	LD   (M4530),A   		;17CC 323045	<M4530>
	LD   B,C     			;17CF 41
	JR   NC,L1814    		;17D0 3042	<L1814>
	DEC  C       			;17D2 0D
	LD   A,(BC)  			;17D3 0A
	LD   A,(M3032)   		;17D4 3A3230	<M3032>
	JR   NC,L1812    		;17D7 3039	<L1812>
L17D9:	LD   B,L     			;17D9 45
	JR   NC,L180C    		;17DA 3030	<L180C>
	JR   NC,L1821    		;17DC 3043	<L1821>
	LD   B,H     			;17DE 44
	LD   B,L     			;17DF 45
	DEC  (HL)    			;17E0 35
	JR   NC,L1817    		;17E1 3034	<L1817>
	LD   B,E     			;17E3 43
	JR   NC,L1819    		;17E4 3033	<L1819>
L17E6:	LD   B,L     			;17E6 45
	LD   SP,M4631    		;17E7 313146	<M4631>
	LD   B,(HL)  			;17EA 46
	LD   B,E     			;17EB 43
L17EC:	ADD  HL,SP   			;17EC 39
	LD   B,E     			;17ED 43
	LD   B,H     			;17EE 44
	LD   B,L     			;17EF 45
	DEC  (HL)    			;17F0 35
	JR   NC,L1827    		;17F1 3034	<L1827>
	LD   B,E     			;17F3 43
	JR   NC,L1828    		;17F4 3032	<L1828>
	LD   SP,M3136    		;17F6 313631	<M3136>
	JR   C,L182B     		;17F9 3830	<L182B>
	SCF          			;17FB 37
	LD   B,L     			;17FC 45
	LD   (M3346),A   		;17FD 324633	<M3346>
	INC  (HL)    			;1800 34
	LD   B,C     			;1801 41
	LD   (HL),30H  			;1802 3630	<30H>
	SCF          			;1804 37
	LD   B,H     			;1805 44
	JR   NC,L183B    		;1806 3033	<L183B>
	LD   (HL),37H  			;1808 3637	<37H>
	LD   B,(HL)  			;180A 46
	LD   (M3342),A   		;180B 324233	<M3342>
	LD   (HL),46H  			;180E 3646	<46H>
	LD   B,(HL)  			;1810 46
	LD   B,E     			;1811 43
L1812:	ADD  HL,SP   			;1812 39
	LD   (M3531),A   		;1813 323135	<M3531>
	LD   B,(HL)  			;1816 46
L1817:	JR   C,L1849     		;1817 3830	<L1849>
L1819:	SCF          			;1819 37
	LD   B,L     			;181A 45
	JR   NC,L1863    		;181B 3046	<L1863>
	LD   (M0D39),A   		;181D 32390D	<M0D39>
	LD   A,(BC)  			;1820 0A
L1821:	LD   A,(M3032)   		;1821 3A3230	<M3032>
	JR   NC,L1867    		;1824 3041	<L1867>
	JR   NC,L1858    		;1826 3030	<L1858>
L1828:	JR   NC,L185A    		;1828 3030	<L185A>
	INC  SP      			;182A 33
L182B:	JR   NC,L185D    		;182B 3030	<L185D>
	SCF          			;182D 37
	INC  SP      			;182E 33
	LD   (HL),30H  			;182F 3630	<30H>
	JR   NC,L1865    		;1831 3032	<L1865>
	LD   B,L     			;1833 45
	LD   (M4334),A   		;1834 323443	<M4334>
	LD   B,D     			;1837 42
	LD   B,C     			;1838 41
	LD   (HL),43H  			;1839 3643	<43H>
L183B:	ADD  HL,SP   			;183B 39
	JR   NC,L1884    		;183C 3046	<L1884>
	INC  SP      			;183E 33
	JR   NC,L1874    		;183F 3033	<L1874>
	SCF          			;1841 37
	LD   (M3845),A   		;1842 324538	<M3845>
	LD   B,E     			;1845 43
	INC  SP      			;1846 33
	LD   B,C     			;1847 41
	LD   SP,M3846    		;1848 314638	<M3846>
	JR   NC,L1892    		;184B 3045	<L1892>
	LD   (HL),30H  			;184D 3630	<30H>
	INC  (HL)    			;184F 34
	LD   (M3038),A   		;1850 323830	<M3038>
	INC  SP      			;1853 33
	INC  SP      			;1854 33
	DEC  (HL)    			;1855 35
	LD   (M3038),A   		;1856 323830	<M3038>
	INC  SP      			;1859 33
L185A:	LD   (M3342),A   		;185A 324233	<M3342>
L185D:	DEC  (HL)    			;185D 35
	LD   B,E     			;185E 43
	JR   NC,L1893    		;185F 3032	<L1893>
	LD   B,L     			;1861 45
	LD   (M4332),A   		;1862 323243	<M4332>
L1865:	LD   B,D     			;1865 42
	LD   B,D     			;1866 42
L1867:	LD   (HL),32H  			;1867 3632	<32H>
	LD   B,L     			;1869 45
	INC  (HL)    			;186A 34
	JR   NC,L187A    		;186B 300D	<L187A>
	LD   A,(BC)  			;186D 0A
	LD   A,(M3032)   		;186E 3A3230	<M3032>
	JR   NC,L18B4    		;1871 3041	<L18B4>
	LD   (M3030),A   		;1873 323030	<M3030>
	JR   NC,L18AA    		;1876 3032	<L18AA>
	INC  (HL)    			;1878 34
	LD   B,E     			;1879 43
L187A:	LD   B,D     			;187A 42
	LD   B,C     			;187B 41
	LD   B,L     			;187C 45
	LD   (M3545),A   		;187D 324535	<M3545>
	LD   B,(HL)  			;1880 46
	LD   B,E     			;1881 43
	LD   B,D     			;1882 42
	JR   C,L18CA     		;1883 3845	<L18CA>
	LD   B,E     			;1885 43
	LD   B,D     			;1886 42
	DEC  (HL)    			;1887 35
	LD   (HL),32H  			;1888 3632	<32H>
	JR   NC,L18BC    		;188A 3030	<L18BC>
	LD   B,C     			;188C 41
	LD   (M4631),A   		;188D 323146	<M4631>
	LD   B,(HL)  			;1890 46
	JR   NC,L18D9    		;1891 3046	<L18D9>
L1893:	LD   (M3032),A   		;1893 323230	<M3032>
	LD   B,C     			;1896 41
	JR   C,L18C9     		;1897 3830	<L18C9>
	INC  SP      			;1899 33
	LD   B,L     			;189A 45
	JR   NC,L18D4    		;189B 3037	<L18D4>
	LD   B,(HL)  			;189D 46
	LD   B,(HL)  			;189E 46
	LD   B,E     			;189F 43
	ADD  HL,SP   			;18A0 39
	LD   (M3845),A   		;18A1 324538	<M3845>
	LD   B,L     			;18A4 45
	INC  SP      			;18A5 33
	DEC  (HL)    			;18A6 35
	LD   (M3138),A   		;18A7 323831	<M3138>
L18AA:	INC  (HL)    			;18AA 34
	LD   (M3742),A   		;18AB 324237	<M3742>
	LD   B,L     			;18AE 45
	LD   B,C     			;18AF 41
	SCF          			;18B0 37
	LD   (M3038),A   		;18B1 323830	<M3038>
L18B4:	LD   B,(HL)  			;18B4 46
	INC  SP      			;18B5 33
	LD   B,L     			;18B6 45
	JR   NC,L18FE    		;18B7 3045	<L18FE>
	DEC  C       			;18B9 0D
	LD   A,(BC)  			;18BA 0A
	LD   A,(M3032)   		;18BB 3A3230	<M3032>
	JR   NC,L1901    		;18BE 3041	<L1901>
	INC  (HL)    			;18C0 34
	JR   NC,L18F3    		;18C1 3030	<L18F3>
	JR   NC,L18F5    		;18C3 3030	<L18F5>
	INC  (HL)    			;18C5 34
	LD   B,(HL)  			;18C6 46
	LD   B,(HL)  			;18C7 46
	LD   B,E     			;18C8 43
L18C9:	ADD  HL,SP   			;18C9 39
L18CA:	JR   NC,L1912    		;18CA 3046	<L1912>
	LD   B,H     			;18CC 44
	JR   NC,L1901    		;18CD 3032	<L1901>
	LD   B,L     			;18CF 45
	JR   C,L1916     		;18D0 3844	<L1916>
	INC  SP      			;18D2 33
	DEC  (HL)    			;18D3 35
L18D4:	LD   B,E     			;18D4 43
	JR   NC,L1909    		;18D5 3032	<L1909>
	LD   B,L     			;18D7 45
	DEC  (HL)    			;18D8 35
L18D9:	LD   B,L     			;18D9 45
	LD   B,E     			;18DA 43
	LD   B,D     			;18DB 42
	INC  (HL)    			;18DC 34
	LD   B,L     			;18DD 45
	LD   B,E     			;18DE 43
	JR   NC,L1922    		;18DF 3041	<L1922>
	LD   B,(HL)  			;18E1 46
	INC  SP      			;18E2 33
	LD   (M4635),A   		;18E3 323546	<M4635>
	JR   C,L1918     		;18E6 3830	<L1918>
	INC  SP      			;18E8 33
	LD   (M4430),A   		;18E9 323044	<M4430>
	JR   C,L191E     		;18EC 3830	<L191E>
	LD   (M4631),A   		;18EE 323146	<M4631>
	LD   B,(HL)  			;18F1 46
	JR   NC,L193A    		;18F2 3046	<L193A>
	LD   (M3032),A   		;18F4 323230	<M3032>
	LD   B,C     			;18F7 41
	JR   C,L192A     		;18F8 3830	<L192A>
	INC  SP      			;18FA 33
	LD   (M4631),A   		;18FB 323146	<M4631>
L18FE:	JR   C,L1930     		;18FE 3830	<L1930>
	LD   (M3231),A   		;1900 323132	<M3231>
	SCF          			;1903 37
	LD   (HL),33H  			;1904 3633	<33H>
	DEC  C       			;1906 0D
	LD   A,(BC)  			;1907 0A
	LD   A,(M3032)   		;1908 3A3230	<M3032>
	JR   NC,L194E    		;190B 3041	<L194E>
	LD   (HL),30H  			;190D 3630	<30H>
	JR   NC,L1941    		;190F 3030	<L1941>
	JR   C,L1943     		;1911 3830	<L1943>
	LD   B,(HL)  			;1913 46
	INC  SP      			;1914 33
	SCF          			;1915 37
L1916:	LD   B,L     			;1916 45
	LD   B,L     			;1917 45
L1918:	LD   (HL),45H  			;1918 3645	<45H>
	JR   NC,L1953    		;191A 3037	<L1953>
	SCF          			;191C 37
	LD   B,(HL)  			;191D 46
L191E:	LD   B,D     			;191E 42
	LD   (M3245),A   		;191F 324532	<M3245>
L1922:	INC  (HL)    			;1922 34
	LD   B,E     			;1923 43
	LD   B,D     			;1924 42
	LD   B,D     			;1925 42
	LD   (HL),33H  			;1926 3633	<33H>
	LD   B,L     			;1928 45
	JR   NC,L1960    		;1929 3035	<L1960>
	LD   B,(HL)  			;192B 46
	LD   B,(HL)  			;192C 46
	LD   B,(HL)  			;192D 46
	SCF          			;192E 37
	INC  SP      			;192F 33
L1930:	LD   B,C     			;1930 41
	JR   NC,L1978    		;1931 3045	<L1978>
	JR   C,L1965     		;1933 3830	<L1965>
	LD   B,(HL)  			;1935 46
	LD   B,L     			;1936 45
	JR   NC,L1970    		;1937 3037	<L1970>
	LD   (M4638),A   		;1939 323846	<M4638>
	JR   C,L1970     		;193C 3832	<L1970>
	LD   B,L     			;193E 45
	LD   (M4332),A   		;193F 323243	<M4332>
	LD   B,D     			;1942 42
L1943:	LD   B,D     			;1943 42
	LD   B,L     			;1944 45
	LD   (M3045),A   		;1945 324530	<M3045>
	LD   SP,M4243    		;1948 314342	<M4243>
	INC  (HL)    			;194B 34
	LD   (HL),32H  			;194C 3632	<32H>
L194E:	JR   C,L1981     		;194E 3831	<L1981>
	LD   (M3130),A   		;1950 323031	<M3130>
L1953:	DEC  C       			;1953 0D
	LD   A,(BC)  			;1954 0A
	LD   A,(M3032)   		;1955 3A3230	<M3032>
	JR   NC,L199B    		;1958 3041	<L199B>
	JR   C,L198C     		;195A 3830	<L198C>
	JR   NC,L198E    		;195C 3030	<L198E>
	LD   B,E     			;195E 43
	LD   B,D     			;195F 42
L1960:	LD   (HL),36H  			;1960 3636	<36H>
	LD   (M3030),A   		;1962 323030	<M3030>
L1965:	LD   B,L     			;1965 45
	INC  SP      			;1966 33
	LD   B,C     			;1967 41
	JR   NC,L19AD    		;1968 3043	<L19AD>
	JR   C,L199C     		;196A 3830	<L199C>
	LD   B,C     			;196C 41
	SCF          			;196D 37
	LD   (M3038),A   		;196E 323830	<M3038>
	JR   C,L19B6     		;1971 3843	<L19B6>
	LD   B,H     			;1973 44
	DEC  (HL)    			;1974 35
	DEC  (HL)    			;1975 35
	JR   NC,L19AE    		;1976 3036	<L19AE>
L1978:	LD   B,E     			;1978 43
	LD   B,H     			;1979 44
	JR   NC,L19B0    		;197A 3034	<L19B0>
	JR   NC,L19B4    		;197C 3036	<L19B4>
	LD   SP,M4638    		;197E 313846	<M4638>
L1981:	LD   (M3132),A   		;1981 323231	<M3132>
	JR   NC,L19B7    		;1984 3031	<L19B7>
	JR   C,L19B8     		;1986 3830	<L19B8>
	LD   B,E     			;1988 43
	LD   B,D     			;1989 42
	DEC  (HL)    			;198A 35
	LD   (HL),32H  			;198B 3632	<32H>
	JR   C,L19C1     		;198D 3832	<L19C1>
	INC  (HL)    			;198F 34
	LD   (M3045),A   		;1990 324530	<M3045>
	LD   B,C     			;1993 41
	INC  SP      			;1994 33
	LD   (HL),45H  			;1995 3645	<45H>
	LD   B,L     			;1997 45
	LD   (M3345),A   		;1998 324533	<M3345>
L199B:	LD   B,D     			;199B 42
L199C:	INC  SP      			;199C 33
	LD   (HL),34H  			;199D 3634	<34H>
	SCF          			;199F 37
	DEC  C       			;19A0 0D
	LD   A,(BC)  			;19A1 0A
	LD   A,(M3032)   		;19A2 3A3230	<M3032>
	JR   NC,L19E8    		;19A5 3041	<L19E8>
	LD   B,C     			;19A7 41
	JR   NC,L19DA    		;19A8 3030	<L19DA>
	JR   NC,L19DD    		;19AA 3031	<L19DD>
	SCF          			;19AC 37
L19AD:	LD   B,(HL)  			;19AD 46
L19AE:	SCF          			;19AE 37
	INC  SP      			;19AF 33
L19B0:	LD   B,C     			;19B0 41
	JR   NC,L19E6    		;19B1 3033	<L19E6>
	JR   C,L19E5     		;19B3 3830	<L19E5>
	JR   NC,L19EE    		;19B5 3037	<L19EE>
L19B7:	INC  SP      			;19B7 33
L19B8:	JR   C,L19EB     		;19B8 3831	<L19EB>
	LD   SP,M4133    		;19BA 313341	<M4133>
	JR   NC,L19F5    		;19BD 3036	<L19F5>
	JR   C,L19F1     		;19BF 3830	<L19F1>
L19C1:	LD   B,L     			;19C1 45
	LD   (HL),30H  			;19C2 3630	<30H>
	LD   B,C     			;19C4 41
	LD   (M3030),A   		;19C5 323030	<M3030>
	LD   B,C     			;19C8 41
	INC  SP      			;19C9 33
	LD   B,C     			;19CA 41
	JR   NC,L1A02    		;19CB 3035	<L1A02>
	JR   C,L19FF     		;19CD 3830	<L19FF>
	JR   NC,L1A08    		;19CF 3037	<L1A08>
	INC  SP      			;19D1 33
	JR   C,L1A19     		;19D2 3845	<L1A19>
	LD   B,C     			;19D4 41
	SCF          			;19D5 37
	LD   B,L     			;19D6 45
	LD   B,C     			;19D7 41
	SCF          			;19D8 37
	LD   (M4530),A   		;19D9 323045	<M4530>
	JR   C,L1A10     		;19DC 3832	<L1A10>
	LD   B,L     			;19DE 45
	JR   NC,L1A22    		;19DF 3041	<L1A22>
	INC  SP      			;19E1 33
	LD   (HL),46H  			;19E2 3646	<46H>
	LD   B,(HL)  			;19E4 46
L19E5:	INC  SP      			;19E5 33
L19E6:	LD   SP,M3030    		;19E6 313030	<M3030>
	JR   C,L1A1D     		;19E9 3832	<L1A1D>
L19EB:	JR   NC,L1A30    		;19EB 3043	<L1A30>
	DEC  C       			;19ED 0D
L19EE:	LD   A,(BC)  			;19EE 0A
	LD   A,(M3032)   		;19EF 3A3230	<M3032>
	JR   NC,L1A35    		;19F2 3041	<L1A35>
	LD   B,E     			;19F4 43
L19F5:	JR   NC,L1A27    		;19F5 3030	<L1A27>
	JR   NC,L1A2B    		;19F7 3032	<L1A2B>
	LD   SP,M4633    		;19F9 313346	<M4633>
	LD   SP,M4430    		;19FC 313044	<M4430>
L19FF:	LD   B,(HL)  			;19FF 46
	LD   B,(HL)  			;1A00 46
	INC  SP      			;1A01 33
L1A02:	LD   (M3031),A   		;1A02 323130	<M3031>
	LD   SP,M3038    		;1A05 313830	<M3038>
L1A08:	SCF          			;1A08 37
	LD   B,L     			;1A09 45
	LD   B,L     			;1A0A 45
	LD   (HL),31H  			;1A0B 3631	<31H>
	DEC  (HL)    			;1A0D 35
	SCF          			;1A0E 37
	SCF          			;1A0F 37
L1A10:	LD   (M3431),A   		;1A10 323134	<M3431>
	SCF          			;1A13 37
	LD   SP,M4430    		;1A14 313044	<M4430>
	LD   B,(HL)  			;1A17 46
	LD   (M4531),A   		;1A18 323145	<M4531>
	LD   B,C     			;1A1B 41
	JR   C,L1A4F     		;1A1C 3831	<L1A4F>
	JR   NC,L1A51    		;1A1E 3031	<L1A51>
	JR   NC,L1A52    		;1A20 3030	<L1A52>
L1A22:	LD   SP,M3736    		;1A22 313637	<M3736>
	LD   SP,M3332    		;1A25 313233	<M3332>
	LD   SP,M4630    		;1A28 313046	<M4630>
L1A2B:	LD   B,E     			;1A2B 43
	LD   B,(HL)  			;1A2C 46
	LD   B,D     			;1A2D 42
	LD   B,E     			;1A2E 43
	INC  SP      			;1A2F 33
L1A30:	INC  (HL)    			;1A30 34
	JR   C,L1A63     		;1A31 3830	<L1A63>
	INC  SP      			;1A33 33
	LD   B,E     			;1A34 43
L1A35:	LD   B,H     			;1A35 44
	LD   B,C     			;1A36 41
	LD   B,D     			;1A37 42
	LD   (M0D37),A   		;1A38 32370D	<M0D37>
	LD   A,(BC)  			;1A3B 0A
	LD   A,(M3032)   		;1A3C 3A3230	<M3032>
	JR   NC,L1A82    		;1A3F 3041	<L1A82>
	LD   B,L     			;1A41 45
	JR   NC,L1A74    		;1A42 3030	<L1A74>
	JR   NC,L1A76    		;1A44 3030	<L1A76>
	DEC  (HL)    			;1A46 35
	LD   (M3038),A   		;1A47 323830	<M3038>
	INC  (HL)    			;1A4A 34
	LD   B,E     			;1A4B 43
	LD   B,H     			;1A4C 44
	LD   SP,M3042    		;1A4D 314230	<M3042>
	LD   B,D     			;1A50 42
L1A51:	LD   B,E     			;1A51 43
L1A52:	ADD  HL,SP   			;1A52 39
	LD   (M3531),A   		;1A53 323135	<M3531>
	SCF          			;1A56 37
	LD   SP,M3130    		;1A57 313031	<M3130>
	LD   SP,M3043    		;1A5A 314330	<M3043>
	JR   NC,L1A8F    		;1A5D 3030	<L1A8F>
	INC  SP      			;1A5F 33
	LD   B,C     			;1A60 41
	DEC  (HL)    			;1A61 35
	JR   C,L1A9C     		;1A62 3838	<L1A9C>
	JR   NC,L1A9A    		;1A64 3034	<L1A9A>
	SCF          			;1A66 37
	LD   SP,M3139    		;1A67 313931	<M3139>
	JR   NC,L1AB2    		;1A6A 3046	<L1AB2>
	LD   B,H     			;1A6C 44
	LD   SP,M3245    		;1A6D 314532	<M3245>
	JR   NC,L1AA5    		;1A70 3033	<L1AA5>
	LD   B,C     			;1A72 41
	JR   NC,L1AA5    		;1A73 3030	<L1AA5>
	JR   C,L1AA7     		;1A75 3830	<L1AA7>
	INC  (HL)    			;1A77 34
	SCF          			;1A78 37
	LD   SP,M3139    		;1A79 313931	<M3139>
	JR   NC,L1AC4    		;1A7C 3046	<L1AC4>
	LD   B,H     			;1A7E 44
	LD   B,L     			;1A7F 45
	LD   B,D     			;1A80 42
	LD   (M3641),A   		;1A81 324136	<M3641>
	LD   (M3535),A   		;1A84 323535	<M3535>
	DEC  C       			;1A87 0D
	LD   A,(BC)  			;1A88 0A
	LD   A,(M3032)   		;1A89 3A3230	<M3032>
	JR   NC,L1AD0    		;1A8C 3042	<L1AD0>
	JR   NC,L1AC0    		;1A8E 3030	<L1AC0>
	JR   NC,L1AC2    		;1A90 3030	<L1AC2>
	JR   C,L1AC4     		;1A92 3830	<L1AC4>
	INC  SP      			;1A94 33
	LD   B,C     			;1A95 41
	DEC  (HL)    			;1A96 35
	LD   B,(HL)  			;1A97 46
	JR   C,L1ACA     		;1A98 3830	<L1ACA>
L1A9A:	LD   B,(HL)  			;1A9A 46
	LD   B,L     			;1A9B 45
L1A9C:	JR   NC,L1AD2    		;1A9C 3034	<L1AD2>
	LD   (M3030),A   		;1A9E 323030	<M3030>
	INC  (HL)    			;1AA1 34
	LD   B,E     			;1AA2 43
	LD   B,H     			;1AA3 44
	INC  SP      			;1AA4 33
L1AA5:	LD   B,L     			;1AA5 45
	JR   NC,L1AEA    		;1AA6 3042	<L1AEA>
	LD   B,E     			;1AA8 43
	ADD  HL,SP   			;1AA9 39
	INC  SP      			;1AAA 33
	LD   B,C     			;1AAB 41
	LD   (HL),38H  			;1AAC 3638	<38H>
	JR   C,L1AE0     		;1AAE 3830	<L1AE0>
	LD   B,L     			;1AB0 45
	LD   (HL),30H  			;1AB1 3630	<30H>
	LD   B,(HL)  			;1AB3 46
	LD   (M3038),A   		;1AB4 323830	<M3038>
	INC  (HL)    			;1AB7 34
	LD   B,E     			;1AB8 43
	LD   B,H     			;1AB9 44
	DEC  (HL)    			;1ABA 35
	LD   B,L     			;1ABB 45
	JR   NC,L1B00    		;1ABC 3042	<L1B00>
	LD   B,E     			;1ABE 43
	ADD  HL,SP   			;1ABF 39
L1AC0:	LD   B,E     			;1AC0 43
	LD   B,H     			;1AC1 44
L1AC2:	SCF          			;1AC2 37
	LD   B,C     			;1AC3 41
L1AC4:	JR   NC,L1B08    		;1AC4 3042	<L1B08>
	LD   B,E     			;1AC6 43
	ADD  HL,SP   			;1AC7 39
	JR   NC,L1B0F    		;1AC8 3045	<L1B0F>
L1ACA:	JR   NC,L1B04    		;1ACA 3038	<L1B04>
	LD   (M3641),A   		;1ACC 324136	<M3641>
	INC  (HL)    			;1ACF 34
L1AD0:	JR   C,L1B02     		;1AD0 3830	<L1B02>
L1AD2:	LD   B,D     			;1AD2 42
	LD   (HL),0DH  			;1AD3 360D	<0DH>
	LD   A,(BC)  			;1AD5 0A
	LD   A,(M3032)   		;1AD6 3A3230	<M3032>
	JR   NC,L1B1D    		;1AD9 3042	<L1B1D>
	LD   (M3030),A   		;1ADB 323030	<M3030>
	JR   NC,L1B25    		;1ADE 3045	<L1B25>
L1AE0:	LD   B,H     			;1AE0 44
	DEC  (HL)    			;1AE1 35
	LD   B,D     			;1AE2 42
	INC  SP      			;1AE3 33
	DEC  (HL)    			;1AE4 35
	LD   SP,M3131    		;1AE5 313131	<M3131>
	ADD  HL,SP   			;1AE8 39
	INC  SP      			;1AE9 33
L1AEA:	JR   C,L1B1C     		;1AEA 3830	<L1B1C>
	LD   SP,M4330    		;1AEC 313043	<M4330>
	JR   NC,L1B27    		;1AEF 3036	<L1B27>
	JR   NC,L1B27    		;1AF1 3034	<L1B27>
	LD   B,E     			;1AF3 43
	LD   B,H     			;1AF4 44
	LD   (M3045),A   		;1AF5 324530	<M3045>
	LD   B,D     			;1AF8 42
	LD   B,E     			;1AF9 43
	ADD  HL,SP   			;1AFA 39
	SCF          			;1AFB 37
	ADD  HL,SP   			;1AFC 39
	JR   C,L1B36     		;1AFD 3837	<L1B36>
	JR   C,L1B38     		;1AFF 3837	<L1B38>
	LD   (M3731),A   		;1B01 323137	<M3731>
L1B04:	ADD  HL,SP   			;1B04 39
	LD   SP,M4333    		;1B05 313343	<M4333>
L1B08:	LD   B,(HL)  			;1B08 46
	LD   SP,M3631    		;1B09 313136	<M3631>
	LD   (HL),38H  			;1B0C 3638	<38H>
	JR   NC,L1B44    		;1B0E 3034	<L1B44>
	JR   C,L1B42     		;1B10 3830	<L1B42>
	LD   (HL),30H  			;1B12 3630	<30H>
	JR   NC,L1B5B    		;1B14 3045	<L1B5B>
	LD   B,H     			;1B16 44
	LD   B,D     			;1B17 42
	JR   NC,L1B5D    		;1B18 3043	<L1B5D>
	ADD  HL,SP   			;1B1A 39
	LD   B,L     			;1B1B 45
L1B1C:	LD   B,D     			;1B1C 42
L1B1D:	JR   NC,L1B50    		;1B1D 3031	<L1B50>
	DEC  (HL)    			;1B1F 35
	LD   (HL),0DH  			;1B20 360D	<0DH>
	LD   A,(BC)  			;1B22 0A
	LD   A,(M3032)   		;1B23 3A3230	<M3032>
	JR   NC,L1B6A    		;1B26 3042	<L1B6A>
	INC  (HL)    			;1B28 34
	JR   NC,L1B5B    		;1B29 3030	<L1B5B>
	JR   NC,L1B5E    		;1B2B 3031	<L1B5E>
	JR   C,L1B5F     		;1B2D 3830	<L1B5F>
	JR   NC,L1B61    		;1B2F 3030	<L1B61>
	ADD  HL,SP   			;1B31 39
	LD   B,L     			;1B32 45
	LD   B,D     			;1B33 42
	JR   NC,L1B67    		;1B34 3031	<L1B67>
L1B36:	JR   NC,L1B6B    		;1B36 3033	<L1B6B>
L1B38:	JR   NC,L1B6E    		;1B38 3034	<L1B6E>
	LD   B,E     			;1B3A 43
	LD   B,H     			;1B3B 44
	DEC  (HL)    			;1B3C 35
	JR   NC,L1B6F    		;1B3D 3030	<L1B6F>
	LD   B,D     			;1B3F 42
	JR   NC,L1B78    		;1B40 3036	<L1B78>
L1B42:	JR   NC,L1B78    		;1B42 3034	<L1B78>
L1B44:	LD   B,E     			;1B44 43
	LD   B,H     			;1B45 44
	LD   (M3045),A   		;1B46 324530	<M3045>
	LD   B,D     			;1B49 42
	LD   B,E     			;1B4A 43
	ADD  HL,SP   			;1B4B 39
	LD   B,E     			;1B4C 43
	DEC  (HL)    			;1B4D 35
	LD   SP,M3441    		;1B4E 314134	<M3441>
	LD   B,(HL)  			;1B51 46
	LD   SP,M3133    		;1B52 313331	<M3133>
	LD   B,C     			;1B55 41
	INC  (HL)    			;1B56 34
	SCF          			;1B57 37
	LD   SP,M3033    		;1B58 313330	<M3033>
L1B5B:	ADD  HL,SP   			;1B5B 39
	LD   B,E     			;1B5C 43
L1B5D:	LD   SP,M3844    		;1B5D 314438	<M3844>
	JR   NC,L1BA5    		;1B60 3043	<L1BA5>
	LD   SP,M4630    		;1B62 313046	<M4630>
	INC  SP      			;1B65 33
	LD   B,E     			;1B66 43
L1B67:	ADD  HL,SP   			;1B67 39
	LD   B,E     			;1B68 43
	LD   B,H     			;1B69 44
L1B6A:	LD   (HL),37H  			;1B6A 3637	<37H>
	LD   SP,M0D44    		;1B6C 31440D	<M0D44>
L1B6F:	LD   A,(BC)  			;1B6F 0A
	LD   A,(M3032)   		;1B70 3A3230	<M3032>
	JR   NC,L1BB7    		;1B73 3042	<L1BB7>
	LD   (HL),30H  			;1B75 3630	<30H>
	JR   NC,L1BA9    		;1B77 3030	<L1BA9>
	JR   NC,L1BBD    		;1B79 3042	<L1BBD>
	JR   NC,L1BB3    		;1B7B 3036	<L1BB3>
	JR   NC,L1BB1    		;1B7D 3032	<L1BB1>
	LD   B,E     			;1B7F 43
	LD   B,H     			;1B80 44
	LD   (M3045),A   		;1B81 324530	<M3045>
	LD   B,D     			;1B84 42
	LD   B,E     			;1B85 43
	ADD  HL,SP   			;1B86 39
	INC  SP      			;1B87 33
	LD   B,C     			;1B88 41
	LD   (HL),31H  			;1B89 3631	<31H>
	JR   C,L1BBD     		;1B8B 3830	<L1BBD>
	JR   NC,L1BC6    		;1B8D 3037	<L1BC6>
	INC  SP      			;1B8F 33
	JR   NC,L1BC2    		;1B90 3030	<L1BC2>
	LD   (HL),30H  			;1B92 3630	<30H>
	LD   SP,M4330    		;1B94 313043	<M4330>
	JR   NC,L1BC9    		;1B97 3030	<L1BC9>
	LD   B,L     			;1B99 45
	LD   B,D     			;1B9A 42
	JR   NC,L1BD6    		;1B9B 3039	<L1BD6>
	LD   B,L     			;1B9D 45
	LD   B,D     			;1B9E 42
	JR   NC,L1BD2    		;1B9F 3031	<L1BD2>
	JR   NC,L1BD6    		;1BA1 3033	<L1BD6>
	JR   NC,L1BD9    		;1BA3 3034	<L1BD9>
L1BA5:	LD   B,E     			;1BA5 43
	LD   B,H     			;1BA6 44
	DEC  (HL)    			;1BA7 35
	JR   NC,L1BDA    		;1BA8 3030	<L1BDA>
	LD   B,D     			;1BAA 42
	LD   B,E     			;1BAB 43
	ADD  HL,SP   			;1BAC 39
	LD   B,E     			;1BAD 43
	LD   B,H     			;1BAE 44
	LD   (HL),37H  			;1BAF 3637	<37H>
L1BB1:	JR   NC,L1BF5    		;1BB1 3042	<L1BF5>
L1BB3:	INC  SP      			;1BB3 33
	JR   C,L1BE6     		;1BB4 3830	<L1BE6>
	LD   B,C     			;1BB6 41
L1BB7:	JR   NC,L1BEA    		;1BB7 3031	<L1BEA>
	LD   B,H     			;1BB9 44
	INC  (HL)    			;1BBA 34
	DEC  C       			;1BBB 0D
	LD   A,(BC)  			;1BBC 0A
L1BBD:	LD   A,(M3032)   		;1BBD 3A3230	<M3032>
	JR   NC,L1C04    		;1BC0 3042	<L1C04>
L1BC2:	JR   C,L1BF4     		;1BC2 3830	<L1BF4>
	JR   NC,L1BF6    		;1BC4 3030	<L1BF6>
L1BC6:	JR   NC,L1BF9    		;1BC6 3031	<L1BF9>
	JR   NC,L1BFC    		;1BC8 3032	<L1BFC>
	LD   B,E     			;1BCA 43
	LD   B,H     			;1BCB 44
	DEC  (HL)    			;1BCC 35
	JR   NC,L1BFF    		;1BCD 3030	<L1BFF>
	LD   B,D     			;1BCF 42
	INC  SP      			;1BD0 33
	JR   C,L1C03     		;1BD1 3830	<L1C03>
	LD   (M4530),A   		;1BD3 323045	<M4530>
L1BD6:	JR   NC,L1C0F    		;1BD6 3037	<L1C0F>
	JR   NC,L1C10    		;1BD8 3036	<L1C10>
L1BDA:	JR   NC,L1C10    		;1BDA 3034	<L1C10>
	LD   B,E     			;1BDC 43
	LD   B,H     			;1BDD 44
	LD   (M3045),A   		;1BDE 324530	<M3045>
	LD   B,D     			;1BE1 42
	LD   B,E     			;1BE2 43
	ADD  HL,SP   			;1BE3 39
	INC  SP      			;1BE4 33
	LD   B,L     			;1BE5 45
L1BE6:	JR   NC,L1C1D    		;1BE6 3035	<L1C1D>
	LD   B,E     			;1BE8 43
	LD   B,H     			;1BE9 44
L1BEA:	LD   B,H     			;1BEA 44
	LD   B,E     			;1BEB 43
	JR   NC,L1C30    		;1BEC 3042	<L1C30>
	SCF          			;1BEE 37
	LD   B,L     			;1BEF 45
	LD   B,(HL)  			;1BF0 46
	LD   B,L     			;1BF1 45
	LD   SP,M3335    		;1BF2 313533	<M3335>
L1BF5:	JR   C,L1C27     		;1BF5 3830	<L1C27>
	LD   (M3644),A   		;1BF7 324436	<M3644>
	LD   SP,M3235    		;1BFA 313532	<M3235>
	LD   B,L     			;1BFD 45
	LD   (HL),42H  			;1BFE 3642	<42H>
	INC  (HL)    			;1C00 34
	LD   (HL),32H  			;1C01 3632	<32H>
L1C03:	INC  SP      			;1C03 33
L1C04:	SCF          			;1C04 37
	SCF          			;1C05 37
	LD   B,H     			;1C06 44
	LD   B,E     			;1C07 43
	DEC  C       			;1C08 0D
	LD   A,(BC)  			;1C09 0A
	LD   A,(M3032)   		;1C0A 3A3230	<M3032>
	JR   NC,L1C51    		;1C0D 3042	<L1C51>
L1C0F:	LD   B,C     			;1C0F 41
L1C10:	JR   NC,L1C42    		;1C10 3030	<L1C42>
	JR   NC,L1C46    		;1C12 3032	<L1C46>
	INC  SP      			;1C14 33
	INC  SP      			;1C15 33
	LD   (HL),30H  			;1C16 3630	<30H>
	JR   NC,L1C4C    		;1C18 3032	<L1C4C>
	INC  SP      			;1C1A 33
	INC  SP      			;1C1B 33
	LD   (HL),46H  			;1C1C 3646	<46H>
	JR   C,L1C52     		;1C1E 3832	<L1C52>
	LD   SP,M4435    		;1C20 313544	<M4435>
	LD   SP,M4330    		;1C23 313043	<M4330>
	LD   B,(HL)  			;1C26 46
L1C27:	LD   B,C     			;1C27 41
	LD   B,(HL)  			;1C28 46
	LD   SP,M3131    		;1C29 313131	<M3131>
	LD   B,D     			;1C2C 42
	JR   NC,L1C5F    		;1C2D 3030	<L1C5F>
	LD   B,E     			;1C2F 43
L1C30:	LD   (HL),30H  			;1C30 3630	<30H>
	DEC  (HL)    			;1C32 35
	LD   SP,M3139    		;1C33 313931	<M3139>
	JR   NC,L1C7E    		;1C36 3046	<L1C7E>
	LD   B,D     			;1C38 42
	LD   B,H     			;1C39 44
	ADD  HL,SP   			;1C3A 39
	LD   (M3131),A   		;1C3B 323131	<M3131>
	DEC  (HL)    			;1C3E 35
	LD   SP,M4331    		;1C3F 313143	<M4331>
L1C42:	LD   B,(HL)  			;1C42 46
	LD   B,L     			;1C43 45
	LD   B,D     			;1C44 42
	LD   B,H     			;1C45 44
L1C46:	ADD  HL,SP   			;1C46 39
	INC  SP      			;1C47 33
	LD   B,L     			;1C48 45
	JR   NC,L1C7D    		;1C49 3032	<L1C7D>
	LD   SP,M3631    		;1C4B 313136	<M3631>
	LD   B,(HL)  			;1C4E 46
	JR   C,L1C81     		;1C4F 3830	<L1C81>
L1C51:	JR   NC,L1C98    		;1C51 3045	<L1C98>
	LD   (HL),33H  			;1C53 3633	<33H>
	DEC  C       			;1C55 0D
	LD   A,(BC)  			;1C56 0A
	LD   A,(M3032)   		;1C57 3A3230	<M3032>
	JR   NC,L1C9E    		;1C5A 3042	<L1C9E>
	LD   B,E     			;1C5C 43
	JR   NC,L1C8F    		;1C5D 3030	<L1C8F>
L1C5F:	JR   NC,L1C91    		;1C5F 3030	<L1C91>
	SCF          			;1C61 37
	LD   B,L     			;1C62 45
	LD   B,H     			;1C63 44
	LD   B,D     			;1C64 42
	JR   NC,L1C97    		;1C65 3030	<L1C97>
	LD   B,L     			;1C67 45
	INC  (HL)    			;1C68 34
	LD   B,C     			;1C69 41
	JR   NC,L1CA5    		;1C6A 3039	<L1CA5>
	INC  SP      			;1C6C 33
	LD   B,H     			;1C6D 44
	LD   (M4630),A   		;1C6E 323046	<M4630>
	LD   (HL),43H  			;1C71 3643	<43H>
	LD   B,H     			;1C73 44
	LD   B,L     			;1C74 45
	JR   C,L1CA7     		;1C75 3830	<L1CA7>
	LD   B,D     			;1C77 42
	LD   B,E     			;1C78 43
	LD   B,H     			;1C79 44
	JR   C,L1CB1     		;1C7A 3835	<L1CB1>
	JR   NC,L1CC1    		;1C7C 3043	<L1CC1>
L1C7E:	LD   B,E     			;1C7E 43
	LD   B,H     			;1C7F 44
	ADD  HL,SP   			;1C80 39
L1C81:	INC  (HL)    			;1C81 34
	JR   NC,L1CC7    		;1C82 3043	<L1CC7>
	LD   B,E     			;1C84 43
	LD   B,H     			;1C85 44
	ADD  HL,SP   			;1C86 39
	LD   B,H     			;1C87 44
	JR   NC,L1CCD    		;1C88 3043	<L1CCD>
	LD   B,E     			;1C8A 43
	LD   B,H     			;1C8B 44
	LD   B,C     			;1C8C 41
	LD   B,L     			;1C8D 45
	JR   NC,L1CD3    		;1C8E 3043	<L1CD3>
	LD   B,E     			;1C90 43
L1C91:	LD   B,H     			;1C91 44
	ADD  HL,SP   			;1C92 39
	LD   (HL),30H  			;1C93 3630	<30H>
	LD   B,H     			;1C95 44
	LD   B,E     			;1C96 43
L1C97:	ADD  HL,SP   			;1C97 39
L1C98:	LD   (M3331),A   		;1C98 323133	<M3331>
	LD   (HL),38H  			;1C9B 3638	<38H>
	JR   NC,L1CE2    		;1C9D 3043	<L1CE2>
	LD   B,(HL)  			;1C9F 46
	DEC  (HL)    			;1CA0 35
	LD   (HL),0DH  			;1CA1 360D	<0DH>
	LD   A,(BC)  			;1CA3 0A
	LD   A,(M3032)   		;1CA4 3A3230	<M3032>
L1CA7:	JR   NC,L1CEB    		;1CA7 3042	<L1CEB>
	LD   B,L     			;1CA9 45
	JR   NC,L1CDC    		;1CAA 3030	<L1CDC>
	JR   NC,L1CE1    		;1CAC 3033	<L1CE1>
	LD   B,C     			;1CAE 41
	LD   (HL),42H  			;1CAF 3642	<42H>
L1CB1:	JR   C,L1CE3     		;1CB1 3830	<L1CE3>
	JR   C,L1CEC     		;1CB3 3837	<L1CEC>
	JR   C,L1CEE     		;1CB5 3837	<L1CEE>
	JR   C,L1CF0     		;1CB7 3837	<L1CF0>
	LD   B,E     			;1CB9 43
	LD   B,(HL)  			;1CBA 46
	LD   B,E     			;1CBB 43
	ADD  HL,SP   			;1CBC 39
	INC  SP      			;1CBD 33
	LD   B,C     			;1CBE 41
	LD   (HL),42H  			;1CBF 3642	<42H>
L1CC1:	JR   C,L1CF3     		;1CC1 3830	<L1CF3>
	INC  SP      			;1CC3 33
	LD   B,H     			;1CC4 44
	LD   B,E     			;1CC5 43
	JR   NC,L1CFA    		;1CC6 3032	<L1CFA>
	LD   SP,M3141    		;1CC8 314131	<M3141>
	LD   SP,M3033    		;1CCB 313330	<M3033>
	LD   (HL),30H  			;1CCE 3630	<30H>
	LD   SP,M4443    		;1CD0 314344	<M4443>
L1CD3:	LD   B,(HL)  			;1CD3 46
	LD   (HL),30H  			;1CD4 3630	<30H>
	LD   B,D     			;1CD6 42
	LD   B,E     			;1CD7 43
	ADD  HL,SP   			;1CD8 39
	LD   B,L     			;1CD9 45
	DEC  (HL)    			;1CDA 35
	LD   B,E     			;1CDB 43
L1CDC:	DEC  (HL)    			;1CDC 35
	LD   SP,M3836    		;1CDD 313638	<M3836>
	JR   NC,L1D17    		;1CE0 3035	<L1D17>
L1CE2:	LD   B,L     			;1CE2 45
L1CE3:	LD   (M3133),A   		;1CE3 323331	<M3133>
	LD   B,C     			;1CE6 41
	INC  (HL)    			;1CE7 34
	LD   B,(HL)  			;1CE8 46
	LD   B,E     			;1CE9 43
	LD   B,H     			;1CEA 44
L1CEB:	JR   NC,L1D26    		;1CEB 3039	<L1D26>
	JR   NC,L1D34    		;1CED 3045	<L1D34>
	DEC  C       			;1CEF 0D
L1CF0:	LD   A,(BC)  			;1CF0 0A
	LD   A,(M3032)   		;1CF1 3A3230	<M3032>
	JR   NC,L1D39    		;1CF4 3043	<L1D39>
	JR   NC,L1D28    		;1CF6 3030	<L1D28>
	JR   NC,L1D2A    		;1CF8 3030	<L1D2A>
L1CFA:	JR   NC,L1D3F    		;1CFA 3043	<L1D3F>
	LD   B,E     			;1CFC 43
	LD   SP,M3145    		;1CFD 314531	<M3145>
	INC  SP      			;1D00 33
	LD   B,L     			;1D01 45
	JR   NC,L1D46    		;1D02 3042	<L1D46>
	LD   B,E     			;1D04 43
	LD   B,(HL)  			;1D05 46
	LD   SP,M4530    		;1D06 313045	<M4530>
	LD   B,L     			;1D09 45
	LD   B,E     			;1D0A 43
	ADD  HL,SP   			;1D0B 39
	LD   SP,M3836    		;1D0C 313638	<M3836>
	JR   NC,L1D46    		;1D0F 3035	<L1D46>
	LD   B,L     			;1D11 45
	LD   SP,M4141    		;1D12 314141	<M4141>
	LD   SP,M3332    		;1D15 313233	<M3332>
	LD   B,C     			;1D18 41
	LD   (HL),43H  			;1D19 3643	<43H>
	JR   C,L1D50     		;1D1B 3833	<L1D50>
	LD   B,C     			;1D1D 41
	LD   (HL),44H  			;1D1E 3644	<44H>
	JR   C,L1D52     		;1D20 3830	<L1D52>
	LD   B,(HL)  			;1D22 46
	LD   B,L     			;1D23 45
	JR   NC,L1D5A    		;1D24 3034	<L1D5A>
L1D26:	LD   B,H     			;1D26 44
	JR   NC,L1D5E    		;1D27 3035	<L1D5E>
	LD   B,(HL)  			;1D29 46
L1D2A:	LD   (M3733),A   		;1D2A 323337	<M3733>
	LD   B,L     			;1D2D 45
	LD   (M4433),A   		;1D2E 323344	<M4433>
	ADD  HL,SP   			;1D31 39
	JR   NC,L1D6A    		;1D32 3036	<L1D6A>
L1D34:	JR   C,L1D66     		;1D34 3830	<L1D66>
	INC  (HL)    			;1D36 34
	LD   B,(HL)  			;1D37 46
	LD   B,H     			;1D38 44
L1D39:	ADD  HL,SP   			;1D39 39
	LD   (HL),34H  			;1D3A 3634	<34H>
	DEC  C       			;1D3C 0D
	LD   A,(BC)  			;1D3D 0A
	LD   A,(M3032)   		;1D3E 3A3230	<M3032>
	JR   NC,L1D86    		;1D41 3043	<L1D86>
	LD   (M3030),A   		;1D43 323030	<M3030>
L1D46:	JR   NC,L1D7F    		;1D46 3037	<L1D7F>
	LD   B,L     			;1D48 45
	LD   (M4433),A   		;1D49 323344	<M4433>
	ADD  HL,SP   			;1D4C 39
	LD   (M3836),A   		;1D4D 323638	<M3836>
L1D50:	JR   NC,L1D88    		;1D50 3036	<L1D88>
L1D52:	LD   B,(HL)  			;1D52 46
	LD   B,H     			;1D53 44
	ADD  HL,SP   			;1D54 39
	SCF          			;1D55 37
	LD   B,L     			;1D56 45
	LD   (M4633),A   		;1D57 323346	<M4633>
L1D5A:	LD   B,L     			;1D5A 45
	LD   B,(HL)  			;1D5B 46
	JR   C,L1D90     		;1D5C 3832	<L1D90>
L1D5E:	JR   C,L1D90     		;1D5E 3830	<L1D90>
	LD   (M4531),A   		;1D60 323145	<M4531>
	LD   B,(HL)  			;1D63 46
	LD   B,(HL)  			;1D64 46
	INC  SP      			;1D65 33
L1D66:	LD   B,C     			;1D66 41
	LD   (HL),45H  			;1D67 3645	<45H>
	JR   C,L1D9B     		;1D69 3830	<L1D9B>
	JR   NC,L1DB3    		;1D6B 3046	<L1DB3>
	JR   NC,L1DB5    		;1D6D 3046	<L1DB5>
	JR   NC,L1DB7    		;1D6F 3046	<L1DB7>
	INC  (HL)    			;1D71 34
	SCF          			;1D72 37
	INC  SP      			;1D73 33
	LD   B,L     			;1D74 45
	JR   NC,L1DAC    		;1D75 3035	<L1DAC>
	LD   B,(HL)  			;1D77 46
	DEC  (HL)    			;1D78 35
	LD   B,H     			;1D79 44
	ADD  HL,SP   			;1D7A 39
	LD   B,L     			;1D7B 45
	DEC  (HL)    			;1D7C 35
	LD   B,H     			;1D7D 44
	DEC  (HL)    			;1D7E 35
L1D7F:	LD   B,E     			;1D7F 43
	DEC  (HL)    			;1D80 35
	LD   B,H     			;1D81 44
	ADD  HL,SP   			;1D82 39
	LD   B,E     			;1D83 43
	LD   B,D     			;1D84 42
	INC  SP      			;1D85 33
L1D86:	JR   C,L1DBE     		;1D86 3836	<L1DBE>
L1D88:	LD   (HL),0DH  			;1D88 360D	<0DH>
	LD   A,(BC)  			;1D8A 0A
	LD   A,(M3032)   		;1D8B 3A3230	<M3032>
	JR   NC,L1DD3    		;1D8E 3043	<L1DD3>
L1D90:	INC  (HL)    			;1D90 34
	JR   NC,L1DC3    		;1D91 3030	<L1DC3>
	JR   NC,L1DC8    		;1D93 3033	<L1DC8>
	JR   NC,L1DC9    		;1D95 3032	<L1DC9>
	JR   NC,L1DDE    		;1D97 3045	<L1DDE>
	DEC  (HL)    			;1D99 35
	LD   B,E     			;1D9A 43
L1D9B:	DEC  (HL)    			;1D9B 35
	INC  SP      			;1D9C 33
	LD   B,C     			;1D9D 41
	DEC  (HL)    			;1D9E 35
	JR   C,L1DD9     		;1D9F 3838	<L1DD9>
	JR   NC,L1DDB    		;1DA1 3038	<L1DDB>
	SCF          			;1DA3 37
	INC  SP      			;1DA4 33
	LD   B,H     			;1DA5 44
	INC  (HL)    			;1DA6 34
	SCF          			;1DA7 37
	LD   B,H     			;1DA8 44
	ADD  HL,SP   			;1DA9 39
	LD   SP,M3141    		;1DAA 314131	<M3141>
	INC  SP      			;1DAD 33
	JR   C,L1DE1     		;1DAE 3831	<L1DE1>
	INC  (HL)    			;1DB0 34
	LD   B,(HL)  			;1DB1 46
	JR   NC,L1DF5    		;1DB2 3041	<L1DF5>
	LD   B,C     			;1DB4 41
L1DB5:	LD   (HL),32H  			;1DB5 3632	<32H>
L1DB7:	LD   B,E     			;1DB7 43
	LD   B,H     			;1DB8 44
	ADD  HL,SP   			;1DB9 39
	LD   B,C     			;1DBA 41
	LD   (HL),41H  			;1DBB 3641	<41H>
	LD   SP,M3832    		;1DBD 313238	<M3832>
	JR   NC,L1DF8    		;1DC0 3036	<L1DF8>
	LD   SP,M3743    		;1DC2 314337	<M3743>
	LD   B,D     			;1DC5 42
	LD   B,(HL)  			;1DC6 46
	LD   B,L     			;1DC7 45
L1DC8:	JR   NC,L1DFF    		;1DC8 3035	<L1DFF>
	LD   SP,M3038    		;1DCA 313830	<M3038>
	INC  SP      			;1DCD 33
	LD   (M3133),A   		;1DCE 323331	<M3133>
	JR   NC,L1E18    		;1DD1 3045	<L1E18>
L1DD3:	LD   B,C     			;1DD3 41
	LD   B,C     			;1DD4 41
	LD   B,D     			;1DD5 42
	DEC  C       			;1DD6 0D
	LD   A,(BC)  			;1DD7 0A
	LD   A,(M3032)   		;1DD8 3A3230	<M3032>
L1DDB:	JR   NC,L1E20    		;1DDB 3043	<L1E20>
	LD   (HL),30H  			;1DDD 3630	<30H>
	JR   NC,L1E11    		;1DDF 3030	<L1E11>
L1DE1:	LD   B,E     			;1DE1 43
	LD   SP,M3145    		;1DE2 314531	<M3145>
	LD   B,E     			;1DE5 43
	LD   B,D     			;1DE6 42
	LD   SP,M4441    		;1DE7 314144	<M4441>
	ADD  HL,SP   			;1DEA 39
	LD   B,E     			;1DEB 43
	LD   SP,M4330    		;1DEC 313043	<M4330>
	LD   B,H     			;1DEF 44
	LD   SP,M3145    		;1DF0 314531	<M3145>
	LD   B,H     			;1DF3 44
	ADD  HL,SP   			;1DF4 39
L1DF5:	LD   B,(HL)  			;1DF5 46
	LD   SP,M4433    		;1DF6 313344	<M4433>
	LD   (M4330),A   		;1DF9 323043	<M4330>
	LD   B,C     			;1DFC 41
	SCF          			;1DFD 37
	LD   B,C     			;1DFE 41
L1DFF:	LD   B,L     			;1DFF 45
	LD   (HL),46H  			;1E00 3646	<46H>
	JR   C,L1E47     		;1E02 3843	<L1E47>
	JR   C,L1E38     		;1E04 3832	<L1E38>
	LD   B,D     			;1E06 42
	LD   B,C     			;1E07 41
	LD   B,L     			;1E08 45
	LD   (M3631),A   		;1E09 323136	<M3631>
	LD   B,L     			;1E0C 45
	JR   C,L1E3F     		;1E0D 3830	<L1E3F>
	LD   B,C     			;1E0F 41
	LD   (HL),37H  			;1E10 3637	<37H>
	SCF          			;1E12 37
	JR   NC,L1E46    		;1E13 3031	<L1E46>
	JR   NC,L1E47    		;1E15 3030	<L1E47>
	JR   NC,L1E4E    		;1E17 3035	<L1E4E>
	JR   NC,L1E52    		;1E19 3037	<L1E52>
	INC  SP      			;1E1B 33
	JR   C,L1E4E     		;1E1C 3830	<L1E4E>
	LD   SP,M4330    		;1E1E 313043	<M4330>
	LD   (M0D44),A   		;1E21 32440D	<M0D44>
	LD   A,(BC)  			;1E24 0A
	LD   A,(M3032)   		;1E25 3A3230	<M3032>
	JR   NC,L1E6D    		;1E28 3043	<L1E6D>
	JR   C,L1E5C     		;1E2A 3830	<L1E5C>
	JR   NC,L1E5E    		;1E2C 3030	<L1E5E>
	LD   SP,M4630    		;1E2E 313046	<M4630>
	LD   B,C     			;1E31 41
	LD   (M3742),A   		;1E32 324237	<M3742>
	LD   SP,M3943    		;1E35 314339	<M3943>
L1E38:	INC  SP      			;1E38 33
	LD   B,C     			;1E39 41
	LD   (HL),41H  			;1E3A 3641	<41H>
	JR   C,L1E6E     		;1E3C 3830	<L1E6E>
	LD   B,(HL)  			;1E3E 46
L1E3F:	LD   B,L     			;1E3F 45
	JR   NC,L1E75    		;1E40 3033	<L1E75>
	LD   B,E     			;1E42 43
	JR   NC,L1E77    		;1E43 3032	<L1E77>
	LD   SP,M4341    		;1E45 314143	<M4341>
	LD   SP,M3033    		;1E48 313330	<M3033>
	LD   (HL),30H  			;1E4B 3630	<30H>
	LD   (M4443),A   		;1E4D 324344	<M4443>
	LD   B,(HL)  			;1E50 46
	LD   (HL),30H  			;1E51 3630	<30H>
	LD   B,D     			;1E53 42
	LD   B,E     			;1E54 43
	ADD  HL,SP   			;1E55 39
	LD   (M4331),A   		;1E56 323143	<M4331>
	LD   B,H     			;1E59 44
	LD   SP,M3033    		;1E5A 313330	<M3033>
	LD   (HL),30H  			;1E5D 3630	<30H>
	LD   (M4443),A   		;1E5F 324344	<M4443>
	LD   B,(HL)  			;1E62 46
	LD   (HL),30H  			;1E63 3630	<30H>
	LD   B,D     			;1E65 42
	LD   B,E     			;1E66 43
	ADD  HL,SP   			;1E67 39
	INC  SP      			;1E68 33
	LD   B,C     			;1E69 41
	LD   SP,M3845    		;1E6A 314538	<M3845>
L1E6D:	JR   NC,L1E9F    		;1E6D 3030	<L1E9F>
	ADD  HL,SP   			;1E6F 39
	DEC  C       			;1E70 0D
	LD   A,(BC)  			;1E71 0A
	LD   A,(M3032)   		;1E72 3A3230	<M3032>
L1E75:	JR   NC,L1EBA    		;1E75 3043	<L1EBA>
L1E77:	LD   B,C     			;1E77 41
	JR   NC,L1EAA    		;1E78 3030	<L1EAA>
	JR   NC,L1EC1    		;1E7A 3045	<L1EC1>
	LD   (HL),45H  			;1E7C 3645	<45H>
	JR   NC,L1EC6    		;1E7E 3046	<L1EC6>
	LD   B,L     			;1E80 45
	LD   (M4330),A   		;1E81 323043	<M4330>
	JR   NC,L1EB8    		;1E84 3032	<L1EB8>
	LD   SP,M3243    		;1E86 314332	<M3243>
	LD   SP,M3033    		;1E89 313330	<M3033>
	LD   (HL),30H  			;1E8C 3630	<30H>
	LD   SP,M4443    		;1E8E 314344	<M4443>
	LD   B,(HL)  			;1E91 46
	LD   (HL),30H  			;1E92 3630	<30H>
	LD   B,D     			;1E94 42
	LD   B,E     			;1E95 43
	ADD  HL,SP   			;1E96 39
	LD   (M3841),A   		;1E97 324138	<M3841>
	ADD  HL,SP   			;1E9A 39
	JR   C,L1ECD     		;1E9B 3830	<L1ECD>
	SCF          			;1E9D 37
	LD   B,E     			;1E9E 43
L1E9F:	LD   B,D     			;1E9F 42
	DEC  (HL)    			;1EA0 35
	LD   (M3530),A   		;1EA1 323035	<M3530>
	SCF          			;1EA4 37
	INC  SP      			;1EA5 33
	LD   B,C     			;1EA6 41
	LD   SP,M3845    		;1EA7 314538	<M3845>
L1EAA:	JR   NC,L1EF1    		;1EAA 3045	<L1EF1>
	LD   (HL),45H  			;1EAC 3645	<45H>
	JR   NC,L1EF6    		;1EAE 3046	<L1EF6>
	LD   B,L     			;1EB0 45
	LD   B,E     			;1EB1 43
	JR   NC,L1EF7    		;1EB2 3043	<L1EF7>
	LD   (M4135),A   		;1EB4 323541	<M4135>
	JR   NC,L1EFD    		;1EB7 3044	<L1EFD>
	LD   (M3731),A   		;1EB9 323137	<M3731>
	LD   B,D     			;1EBC 42
	DEC  C       			;1EBD 0D
	LD   A,(BC)  			;1EBE 0A
	LD   A,(M3032)   		;1EBF 3A3230	<M3032>
	JR   NC,L1F07    		;1EC2 3043	<L1F07>
	LD   B,E     			;1EC4 43
	JR   NC,L1EF7    		;1EC5 3030	<L1EF7>
	JR   NC,L1F0E    		;1EC7 3045	<L1F0E>
	INC  SP      			;1EC9 33
	LD   SP,M3433    		;1ECA 313334	<M3433>
L1ECD:	LD   (HL),32H  			;1ECD 3632	<32H>
	INC  SP      			;1ECF 33
	INC  (HL)    			;1ED0 34
	LD   B,L     			;1ED1 45
	LD   (M3533),A   		;1ED2 323335	<M3533>
	LD   B,L     			;1ED5 45
	LD   (M3533),A   		;1ED6 323335	<M3533>
	LD   (HL),32H  			;1ED9 3632	<32H>
	INC  SP      			;1EDB 33
	INC  SP      			;1EDC 33
	LD   B,C     			;1EDD 41
	LD   (HL),36H  			;1EDE 3636	<36H>
	JR   C,L1F12     		;1EE0 3830	<L1F12>
	LD   B,D     			;1EE2 42
	JR   C,L1F17     		;1EE3 3832	<L1F17>
	JR   NC,L1F2D    		;1EE5 3046	<L1F2D>
	LD   (M4133),A   		;1EE7 323341	<M4133>
	LD   (HL),38H  			;1EEA 3638	<38H>
	JR   C,L1F1E     		;1EEC 3830	<L1F1E>
	ADD  HL,SP   			;1EEE 39
	LD   SP,M3032    		;1EEF 313230	<M3032>
	LD   B,L     			;1EF2 45
	LD   B,E     			;1EF3 43
	LD   B,L     			;1EF4 45
	LD   B,D     			;1EF5 42
L1EF6:	DEC  (HL)    			;1EF6 35
L1EF7:	LD   B,L     			;1EF7 45
	LD   (M3533),A   		;1EF8 323335	<M3533>
	LD   (HL),34H  			;1EFB 3634	<34H>
L1EFD:	SCF          			;1EFD 37
	LD   B,L     			;1EFE 45
	LD   B,H     			;1EFF 44
	DEC  (HL)    			;1F00 35
	LD   B,(HL)  			;1F01 46
	LD   B,(HL)  			;1F02 46
	LD   (HL),38H  			;1F03 3638	<38H>
	JR   NC,L1F39    		;1F05 3032	<L1F39>
L1F07:	INC  SP      			;1F07 33
	LD   B,D     			;1F08 42
	INC  SP      			;1F09 33
	DEC  C       			;1F0A 0D
	LD   A,(BC)  			;1F0B 0A
	LD   A,(M3032)   		;1F0C 3A3230	<M3032>
	JR   NC,L1F54    		;1F0F 3043	<L1F54>
	LD   B,L     			;1F11 45
L1F12:	JR   NC,L1F44    		;1F12 3030	<L1F44>
	JR   NC,L1F46    		;1F14 3030	<L1F46>
	INC  (HL)    			;1F16 34
L1F17:	JR   C,L1F4F     		;1F17 3836	<L1F4F>
	INC  SP      			;1F19 33
	JR   NC,L1F62    		;1F1A 3046	<L1F62>
	LD   B,D     			;1F1C 42
	LD   (HL),32H  			;1F1D 3632	<32H>
	LD   (HL),42H  			;1F1F 3642	<42H>
	INC  SP      			;1F21 33
	LD   B,L     			;1F22 45
	LD   SP,M4336    		;1F23 313643	<M4336>
	LD   B,(HL)  			;1F26 46
	LD   SP,M4630    		;1F27 313046	<M4630>
	LD   B,D     			;1F2A 42
	INC  (HL)    			;1F2B 34
	LD   (HL),32H  			;1F2C 3632	<32H>
	INC  SP      			;1F2E 33
	LD   B,L     			;1F2F 45
	DEC  (HL)    			;1F30 35
	INC  SP      			;1F31 33
	LD   B,C     			;1F32 41
	LD   (HL),43H  			;1F33 3643	<43H>
	JR   C,L1F67     		;1F35 3830	<L1F67>
	LD   B,E     			;1F37 43
	LD   B,(HL)  			;1F38 46
L1F39:	SCF          			;1F39 37
	LD   B,L     			;1F3A 45
	LD   B,L     			;1F3B 45
	LD   SP,M4546    		;1F3C 314645	<M4546>
	LD   B,E     			;1F3F 43
	JR   C,L1F75     		;1F40 3833	<L1F75>
	JR   NC,L1F89    		;1F42 3045	<L1F89>
L1F44:	LD   B,E     			;1F44 43
	LD   (M3832),A   		;1F45 323238	<M3832>
	ADD  HL,SP   			;1F48 39
	JR   C,L1F7B     		;1F49 3830	<L1F7B>
	JR   NC,L1F7E    		;1F4B 3031	<L1F7E>
	JR   NC,L1F7F    		;1F4D 3030	<L1F7F>
L1F4F:	JR   NC,L1F86    		;1F4F 3035	<L1F86>
	LD   B,H     			;1F51 44
	LD   (HL),32H  			;1F52 3632	<32H>
L1F54:	JR   C,L1F8F     		;1F54 3839	<L1F8F>
	LD   SP,M0A0D    		;1F56 310D0A	<M0A0D>
	LD   A,(M3032)   		;1F59 3A3230	<M3032>
	JR   NC,L1FA2    		;1F5C 3044	<L1FA2>
	JR   NC,L1F90    		;1F5E 3030	<L1F90>
	JR   NC,L1F92    		;1F60 3030	<L1F92>
L1F62:	LD   B,E     			;1F62 43
	LD   B,D     			;1F63 42
	LD   SP,M3139    		;1F64 313931	<M3139>
L1F67:	JR   NC,L1FAF    		;1F67 3046	<L1FAF>
	LD   B,C     			;1F69 41
	INC  SP      			;1F6A 33
	LD   B,C     			;1F6B 41
	LD   (HL),45H  			;1F6C 3645	<45H>
	JR   C,L1FA0     		;1F6E 3830	<L1FA0>
	LD   B,C     			;1F70 41
	LD   SP,M3032    		;1F71 313230	<M3032>
	LD   (HL),31H  			;1F74 3631	<31H>
	LD   SP,M3538    		;1F76 313835	<M3538>
	LD   B,E     			;1F79 43
	INC  SP      			;1F7A 33
L1F7B:	LD   B,C     			;1F7B 41
	LD   (HL),42H  			;1F7C 3642	<42H>
L1F7E:	JR   C,L1FB0     		;1F7E 3830	<L1FB0>
	LD   B,(HL)  			;1F80 46
	LD   B,L     			;1F81 45
	JR   NC,L1FB6    		;1F82 3032	<L1FB6>
	LD   (M3130),A   		;1F84 323031	<M3130>
	LD   B,E     			;1F87 43
	INC  SP      			;1F88 33
L1F89:	LD   B,C     			;1F89 41
	LD   (HL),43H  			;1F8A 3643	<43H>
	JR   C,L1FBE     		;1F8C 3830	<L1FBE>
	LD   B,E     			;1F8E 43
L1F8F:	LD   B,(HL)  			;1F8F 46
L1F90:	SCF          			;1F90 37
	LD   B,L     			;1F91 45
L1F92:	LD   B,H     			;1F92 44
	LD   (HL),32H  			;1F93 3632	<32H>
	JR   C,L1FCA     		;1F95 3833	<L1FCA>
	JR   NC,L1FDF    		;1F97 3046	<L1FDF>
	LD   B,E     			;1F99 43
	LD   B,E     			;1F9A 43
	LD   (HL),32H  			;1F9B 3632	<32H>
	JR   C,L1FCF     		;1F9D 3830	<L1FCF>
	LD   SP,M3030    		;1F9F 313030	<M3030>
L1FA2:	INC  SP      			;1FA2 33
	LD   B,C     			;1FA3 41
	DEC  C       			;1FA4 0D
	LD   A,(BC)  			;1FA5 0A
	LD   A,(M3032)   		;1FA6 3A3230	<M3032>
	JR   NC,L1FEF    		;1FA9 3044	<L1FEF>
	LD   (M3030),A   		;1FAB 323030	<M3030>
	JR   NC,L1FE0    		;1FAE 3030	<L1FE0>
L1FB0:	DEC  (HL)    			;1FB0 35
	LD   B,H     			;1FB1 44
	LD   (HL),30H  			;1FB2 3630	<30H>
	JR   C,L1FF9     		;1FB4 3843	<L1FF9>
L1FB6:	LD   B,D     			;1FB6 42
	LD   SP,M3139    		;1FB7 313931	<M3139>
	JR   NC,L2002    		;1FBA 3046	<L2002>
	LD   B,C     			;1FBC 41
	INC  SP      			;1FBD 33
L1FBE:	LD   B,C     			;1FBE 41
	LD   (HL),45H  			;1FBF 3645	<45H>
	JR   C,L1FF3     		;1FC1 3830	<L1FF3>
	LD   B,C     			;1FC3 41
	LD   SP,M3032    		;1FC4 313230	<M3032>
	INC  SP      			;1FC7 33
	LD   B,L     			;1FC8 45
	LD   SP,M3338    		;1FC9 313833	<M3338>
	ADD  HL,SP   			;1FCC 39
	LD   SP,M3045    		;1FCD 314530	<M3045>
	INC  (HL)    			;1FD0 34
	JR   NC,L2004    		;1FD1 3031	<L2004>
	JR   NC,L2009    		;1FD3 3034	<L2009>
	JR   NC,L2007    		;1FD5 3030	<L2007>
	SCF          			;1FD7 37
	JR   C,L2020     		;1FD8 3846	<L2020>
	LD   B,L     			;1FDA 45
	JR   NC,L2012    		;1FDB 3035	<L2012>
	LD   (M3138),A   		;1FDD 323831	<M3138>
L1FE0:	LD   B,D     			;1FE0 42
	INC  SP      			;1FE1 33
	LD   B,C     			;1FE2 41
	LD   (HL),43H  			;1FE3 3643	<43H>
	JR   C,L2017     		;1FE5 3830	<L2017>
	JR   C,L2019     		;1FE7 3830	<L2019>
	LD   B,(HL)  			;1FE9 46
	LD   B,L     			;1FEA 45
	LD   SP,M3335    		;1FEB 313533	<M3335>
	JR   C,L2029     		;1FEE 3839	<L2029>
	INC  (HL)    			;1FF0 34
	DEC  C       			;1FF1 0D
	LD   A,(BC)  			;1FF2 0A
L1FF3:	LD   A,(M3032)   		;1FF3 3A3230	<M3032>
	JR   NC,L203C    		;1FF6 3044	<L203C>
	INC  (HL)    			;1FF8 34
L1FF9:	JR   NC,L202B    		;1FF9 3030	<L202B>
	JR   NC,L202D    		;1FFB 3030	<L202D>
	LD   (M3644),A   		;1FFD 324436	<M3644>
	LD   SP,M3035    		;2000 313530	<M3035>
	INC  (HL)    			;2003 34
L2004:	LD   B,E     			;2004 43
	LD   B,D     			;2005 42
	LD   (M3231),A   		;2006 323132	<M3231>
L2009:	LD   B,C     			;2009 41
	JR   C,L2045     		;200A 3839	<L2045>
	JR   C,L203E     		;200C 3830	<L203E>
	LD   B,E     			;200E 43
	LD   B,(HL)  			;200F 46
	SCF          			;2010 37
	LD   B,L     			;2011 45
L2012:	LD   B,C     			;2012 41
	INC  SP      			;2013 33
	LD   (M4538),A   		;2014 323845	<M4538>
L2017:	LD   (HL),33H  			;2017 3633	<33H>
L2019:	LD   B,C     			;2019 41
	LD   (HL),45H  			;201A 3645	<45H>
	JR   C,L204E     		;201C 3830	<L204E>
	LD   B,C     			;201E 41
	LD   SP,M3032    		;201F 313230	<M3032>
	LD   (M4342),A   		;2022 324243	<M4342>
	LD   B,D     			;2025 42
	INC  SP      			;2026 33
	LD   B,D     			;2027 42
	INC  SP      			;2028 33
L2029:	JR   NC,L206F    		;2029 3044	<L206F>
L202B:	ADD  HL,SP   			;202B 39
	LD   SP,M3138    		;202C 313831	<M3138>
	LD   B,E     			;202F 43
	INC  SP      			;2030 33
	LD   B,C     			;2031 41
	LD   (HL),36H  			;2032 3636	<36H>
	JR   C,L2066     		;2034 3830	<L2066>
	LD   B,L     			;2036 45
	LD   (HL),31H  			;2037 3631	<31H>
	LD   B,(HL)  			;2039 46
	LD   (M4530),A   		;203A 323045	<M4530>
	ADD  HL,SP   			;203D 39
L203E:	DEC  C       			;203E 0D
	LD   A,(BC)  			;203F 0A
	LD   A,(M3032)   		;2040 3A3230	<M3032>
	JR   NC,L2089    		;2043 3044	<L2089>
L2045:	LD   (HL),30H  			;2045 3630	<30H>
	JR   NC,L2079    		;2047 3030	<L2079>
	LD   SP,M3335    		;2049 313533	<M3335>
	LD   B,C     			;204C 41
	LD   (HL),38H  			;204D 3638	<38H>
	JR   C,L2081     		;204F 3830	<L2081>
	LD   B,L     			;2051 45
	LD   (HL),30H  			;2052 3630	<30H>
	LD   B,(HL)  			;2054 46
	LD   (M3030),A   		;2055 323030	<M3030>
	LD   B,L     			;2058 45
	INC  SP      			;2059 33
	LD   B,C     			;205A 41
	LD   (HL),45H  			;205B 3645	<45H>
	JR   C,L208F     		;205D 3830	<L208F>
	JR   NC,L20A7    		;205F 3046	<L20A7>
	JR   NC,L20A9    		;2061 3046	<L20A9>
	JR   NC,L20AB    		;2063 3046	<L20AB>
	JR   NC,L209D    		;2065 3036	<L209D>
	JR   NC,L2099    		;2067 3030	<L2099>
	JR   NC,L209F    		;2069 3034	<L209F>
	JR   NC,L20B3    		;206B 3046	<L20B3>
	INC  SP      			;206D 33
	JR   NC,L20B6    		;206E 3046	<L20B6>
	LD   B,E     			;2070 43
	LD   SP,M3038    		;2071 313830	<M3038>
	ADD  HL,SP   			;2074 39
	INC  SP      			;2075 33
	LD   B,C     			;2076 41
	LD   (HL),45H  			;2077 3645	<45H>
L2079:	JR   C,L20AB     		;2079 3830	<L20AB>
	JR   NC,L20B3    		;207B 3036	<L20B3>
	JR   NC,L20B5    		;207D 3036	<L20B5>
	JR   NC,L20B6    		;207F 3035	<L20B6>
L2081:	JR   NC,L20BA    		;2081 3037	<L20BA>
	INC  SP      			;2083 33
	JR   NC,L20CC    		;2084 3046	<L20CC>
	LD   B,E     			;2086 43
	LD   B,C     			;2087 41
	LD   B,(HL)  			;2088 46
L2089:	INC  (HL)    			;2089 34
	INC  SP      			;208A 33
	DEC  C       			;208B 0D
	LD   A,(BC)  			;208C 0A
	LD   A,(M3032)   		;208D 3A3230	<M3032>
	JR   NC,L20D6    		;2090 3044	<L20D6>
	JR   C,L20C4     		;2092 3830	<L20C4>
	JR   NC,L20C6    		;2094 3030	<L20C6>
	LD   B,E     			;2096 43
	LD   B,H     			;2097 44
	LD   B,H     			;2098 44
L2099:	LD   B,E     			;2099 43
	JR   NC,L20DE    		;209A 3042	<L20DE>
	LD   B,L     			;209C 45
L209D:	DEC  (HL)    			;209D 35
	INC  SP      			;209E 33
L209F:	LD   B,L     			;209F 45
	JR   NC,L20D8    		;20A0 3036	<L20D8>
	LD   B,E     			;20A2 43
	LD   B,(HL)  			;20A3 46
	INC  SP      			;20A4 33
	LD   B,C     			;20A5 41
	LD   (HL),43H  			;20A6 3643	<43H>
	JR   C,L20DA     		;20A8 3830	<L20DA>
	JR   C,L20DC     		;20AA 3830	<L20DC>
	LD   B,(HL)  			;20AC 46
	LD   B,L     			;20AD 45
	LD   SP,M3335    		;20AE 313533	<M3335>
	JR   C,L20E3     		;20B1 3830	<L20E3>
L20B3:	LD   (M3644),A   		;20B3 324436	<M3644>
L20B6:	LD   SP,M3735    		;20B6 313537	<M3735>
	SCF          			;20B9 37
L20BA:	LD   B,L     			;20BA 45
	LD   SP,M3633    		;20BB 313336	<M3633>
	JR   NC,L20F3    		;20BE 3033	<L20F3>
	LD   B,E     			;20C0 43
	ADD  HL,SP   			;20C1 39
	SCF          			;20C2 37
	JR   C,L20F7     		;20C3 3832	<L20F7>
	LD   SP,M4536    		;20C5 313645	<M4536>
	JR   C,L20FA     		;20C8 3830	<L20FA>
	LD   B,E     			;20CA 43
	LD   B,(HL)  			;20CB 46
L20CC:	LD   B,L     			;20CC 45
	LD   B,D     			;20CD 42
	LD   (M3731),A   		;20CE 323137	<M3731>
	LD   B,(HL)  			;20D1 46
	JR   C,L2104     		;20D2 3830	<L2104>
	JR   NC,L2107    		;20D4 3031	<L2107>
L20D6:	JR   NC,L211C    		;20D6 3044	<L211C>
L20D8:	DEC  C       			;20D8 0D
	LD   A,(BC)  			;20D9 0A
L20DA:	LD   A,(M3032)   		;20DA 3A3230	<M3032>
	JR   NC,L2123    		;20DD 3044	<L2123>
	LD   B,C     			;20DF 41
	JR   NC,L2112    		;20E0 3030	<L2112>
	JR   NC,L2114    		;20E2 3030	<L2114>
	JR   NC,L2116    		;20E4 3030	<L2116>
	JR   NC,L211B    		;20E6 3033	<L211B>
	LD   B,C     			;20E8 41
	DEC  (HL)    			;20E9 35
	JR   C,L2124     		;20EA 3838	<L2124>
	JR   NC,L2126    		;20EC 3038	<L2126>
	SCF          			;20EE 37
	INC  SP      			;20EF 33
	LD   B,H     			;20F0 44
	LD   B,(HL)  			;20F1 46
	DEC  (HL)    			;20F2 35
L20F3:	LD   B,L     			;20F3 45
	DEC  (HL)    			;20F4 35
	LD   B,H     			;20F5 44
	ADD  HL,SP   			;20F6 39
L20F7:	LD   SP,M3141    		;20F7 314131	<M3141>
L20FA:	INC  SP      			;20FA 33
	LD   B,H     			;20FB 44
	ADD  HL,SP   			;20FC 39
	JR   C,L2132     		;20FD 3833	<L2132>
	DEC  (HL)    			;20FF 35
	LD   B,(HL)  			;2100 46
	LD   SP,M4141    		;2101 314141	<M4141>
L2104:	LD   (HL),37H  			;2104 3637	<37H>
	SCF          			;2106 37
L2107:	LD   B,D     			;2107 42
	JR   NC,L213E    		;2108 3034	<L213E>
	SCF          			;210A 37
	LD   B,H     			;210B 44
	DEC  (HL)    			;210C 35
	INC  SP      			;210D 33
	LD   B,L     			;210E 45
	JR   NC,L2148    		;210F 3037	<L2148>
	JR   C,L2146     		;2111 3833	<L2146>
	DEC  (HL)    			;2113 35
L2114:	LD   B,(HL)  			;2114 46
	INC  SP      			;2115 33
L2116:	LD   B,L     			;2116 45
	JR   NC,L214E    		;2117 3035	<L214E>
	LD   B,E     			;2119 43
	LD   B,(HL)  			;211A 46
L211B:	LD   SP,M4141    		;211B 314141	<M4141>
	LD   (HL),37H  			;211E 3637	<37H>
	SCF          			;2120 37
	LD   B,D     			;2121 42
	LD   SP,M4539    		;2122 313945	<M4539>
	DEC  C       			;2125 0D
L2126:	LD   A,(BC)  			;2126 0A
	LD   A,(M3032)   		;2127 3A3230	<M3032>
	JR   NC,L2170    		;212A 3044	<L2170>
	LD   B,E     			;212C 43
	JR   NC,L215F    		;212D 3030	<L215F>
	JR   NC,L2165    		;212F 3034	<L2165>
	LD   B,(HL)  			;2131 46
L2132:	LD   B,H     			;2132 44
	LD   SP,M3145    		;2133 314531	<M3145>
	LD   (M4633),A   		;2136 323346	<M4633>
	LD   SP,M4433    		;2139 313344	<M4433>
	LD   (M4430),A   		;213C 323044	<M4430>
	LD   B,(HL)  			;213F 46
	LD   (M3745),A   		;2140 324537	<M3745>
	LD   B,H     			;2143 44
	SCF          			;2144 37
	JR   NC,L2179    		;2145 3032	<L2179>
	INC  SP      			;2147 33
L2148:	SCF          			;2148 37
	LD   SP,M3943    		;2149 314339	<M3943>
	LD   B,C     			;214C 41
	LD   B,(HL)  			;214D 46
L214E:	LD   B,H     			;214E 44
	INC  SP      			;214F 33
	JR   C,L2185     		;2150 3833	<L2185>
	LD   B,H     			;2152 44
	INC  SP      			;2153 33
	JR   C,L218A     		;2154 3834	<L218A>
	LD   (M3031),A   		;2156 323130	<M3031>
	ADD  HL,SP   			;2159 39
	JR   C,L218C     		;215A 3830	<L218C>
	SCF          			;215C 37
	LD   B,L     			;215D 45
	LD   B,(HL)  			;215E 46
L215F:	LD   B,L     			;215F 45
	JR   NC,L2194    		;2160 3032	<L2194>
	LD   SP,M3746    		;2162 314637	<M3746>
L2165:	SCF          			;2165 37
	LD   B,L     			;2166 45
	LD   (HL),37H  			;2167 3637	<37H>
	LD   B,(HL)  			;2169 46
	LD   (M3245),A   		;216A 324532	<M3245>
	LD   (HL),37H  			;216D 3637	<37H>
	SCF          			;216F 37
L2170:	JR   NC,L21A2    		;2170 3030	<L21A2>
	DEC  C       			;2172 0D
	LD   A,(BC)  			;2173 0A
	LD   A,(M3032)   		;2174 3A3230	<M3032>
	JR   NC,L21BD    		;2177 3044	<L21BD>
L2179:	LD   B,L     			;2179 45
	JR   NC,L21AC    		;217A 3030	<L21AC>
	JR   NC,L21AF    		;217C 3031	<L21AF>
	LD   SP,M4430    		;217E 313044	<M4430>
	JR   C,L21B3     		;2181 3830	<L21B3>
	JR   NC,L21CB    		;2183 3046	<L21CB>
L2185:	INC  SP      			;2185 33
	JR   NC,L21B9    		;2186 3031	<L21B9>
	LD   (M4131),A   		;2188 323141	<M4131>
	LD   B,E     			;218B 43
L218C:	LD   B,H     			;218C 44
	DEC  (HL)    			;218D 35
	INC  (HL)    			;218E 34
	JR   NC,L21D6    		;218F 3045	<L21D6>
	LD   B,E     			;2191 43
	LD   B,H     			;2192 44
	DEC  (HL)    			;2193 35
L2194:	LD   B,(HL)  			;2194 46
	JR   NC,L21DC    		;2195 3045	<L21DC>
	LD   (M3031),A   		;2197 323130	<M3031>
	LD   SP,M3038    		;219A 313830	<M3038>
	LD   B,E     			;219D 43
	LD   B,D     			;219E 42
	DEC  (HL)    			;219F 35
	LD   B,L     			;21A0 45
	LD   B,E     			;21A1 43
L21A2:	JR   C,L21D6     		;21A2 3832	<L21D6>
	LD   B,L     			;21A4 45
	LD   (M4335),A   		;21A5 323543	<M4335>
	LD   B,D     			;21A8 42
	LD   B,(HL)  			;21A9 46
	LD   B,L     			;21AA 45
	LD   B,E     			;21AB 43
L21AC:	ADD  HL,SP   			;21AC 39
	JR   NC,L21F5    		;21AD 3046	<L21F5>
L21AF:	INC  SP      			;21AF 33
	JR   NC,L21E2    		;21B0 3030	<L21E2>
	ADD  HL,SP   			;21B2 39
L21B3:	LD   SP,M3041    		;21B3 314130	<M3041>
	LD   B,(HL)  			;21B6 46
	JR   NC,L21FF    		;21B7 3046	<L21FF>
L21B9:	JR   NC,L2201    		;21B9 3046	<L2201>
	JR   NC,L2203    		;21BB 3046	<L2203>
L21BD:	LD   (HL),42H  			;21BD 3642	<42H>
	DEC  C       			;21BF 0D
	LD   A,(BC)  			;21C0 0A
	LD   A,(M3032)   		;21C1 3A3230	<M3032>
	JR   NC,L220B    		;21C4 3045	<L220B>
	JR   NC,L21F8    		;21C6 3030	<L21F8>
	JR   NC,L21FA    		;21C8 3030	<L21FA>
	LD   B,E     			;21CA 43
L21CB:	LD   B,H     			;21CB 44
	DEC  (HL)    			;21CC 35
	INC  (HL)    			;21CD 34
	JR   NC,L2215    		;21CE 3045	<L2215>
	LD   B,E     			;21D0 43
	ADD  HL,SP   			;21D1 39
	LD   SP,M3042    		;21D2 314230	<M3042>
	LD   B,(HL)  			;21D5 46
L21D6:	INC  SP      			;21D6 33
	JR   NC,L2209    		;21D7 3030	<L2209>
	DEC  (HL)    			;21D9 35
	LD   SP,M4341    		;21DA 314143	<M4341>
	LD   B,H     			;21DD 44
	DEC  (HL)    			;21DE 35
	INC  (HL)    			;21DF 34
	JR   NC,L2227    		;21E0 3045	<L2227>
L21E2:	LD   B,E     			;21E2 43
	ADD  HL,SP   			;21E3 39
	JR   NC,L222C    		;21E4 3046	<L222C>
	INC  SP      			;21E6 33
	JR   NC,L2219    		;21E7 3030	<L2219>
	ADD  HL,SP   			;21E9 39
	LD   SP,M3041    		;21EA 314130	<M3041>
	LD   B,(HL)  			;21ED 46
	JR   NC,L2236    		;21EE 3046	<L2236>
	JR   NC,L2238    		;21F0 3046	<L2238>
	JR   NC,L223A    		;21F2 3046	<L223A>
	LD   B,E     			;21F4 43
L21F5:	LD   B,H     			;21F5 44
	DEC  (HL)    			;21F6 35
	INC  (HL)    			;21F7 34
L21F8:	JR   NC,L223F    		;21F8 3045	<L223F>
L21FA:	LD   B,E     			;21FA 43
	ADD  HL,SP   			;21FB 39
	LD   SP,M3045    		;21FC 314530	<M3045>
L21FF:	LD   B,C     			;21FF 41
	JR   NC,L2248    		;2200 3046	<L2248>
	INC  SP      			;2202 33
L2203:	JR   NC,L2235    		;2203 3030	<L2235>
	LD   B,H     			;2205 44
	LD   SP,M4341    		;2206 314143	<M4341>
L2209:	LD   B,H     			;2209 44
	SCF          			;220A 37
L220B:	JR   C,L221A     		;220B 380D	<L221A>
	LD   A,(BC)  			;220D 0A
	LD   A,(M3032)   		;220E 3A3230	<M3032>
	JR   NC,L2258    		;2211 3045	<L2258>
	LD   (M3030),A   		;2213 323030	<M3030>
	JR   NC,L224D    		;2216 3035	<L224D>
	INC  (HL)    			;2218 34
L2219:	JR   NC,L2260    		;2219 3045	<L2260>
	LD   (M3045),A   		;221B 324530	<M3045>
	LD   B,L     			;221E 45
	JR   NC,L2252    		;221F 3031	<L2252>
	LD   (M3038),A   		;2221 323830	<M3038>
	JR   NC,L2269    		;2224 3043	<L2269>
	LD   B,H     			;2226 44
L2227:	JR   C,L225C     		;2227 3833	<L225C>
	JR   NC,L2270    		;2229 3045	<L2270>
	LD   B,E     			;222B 43
L222C:	ADD  HL,SP   			;222C 39
	JR   NC,L2275    		;222D 3046	<L2275>
	INC  SP      			;222F 33
	JR   NC,L2263    		;2230 3031	<L2263>
	LD   SP,M4131    		;2232 313141	<M4131>
L2235:	JR   NC,L227D    		;2235 3046	<L227D>
	JR   NC,L227F    		;2237 3046	<L227F>
	JR   NC,L2281    		;2239 3046	<L2281>
	JR   NC,L2283    		;223B 3046	<L2283>
	LD   B,E     			;223D 43
	LD   B,H     			;223E 44
L223F:	DEC  (HL)    			;223F 35
	INC  (HL)    			;2240 34
	JR   NC,L2288    		;2241 3045	<L2288>
	LD   (M3145),A   		;2243 324531	<M3145>
	INC  SP      			;2246 33
	JR   NC,L227A    		;2247 3031	<L227A>
	LD   (M3137),A   		;2249 323731	<M3137>
	LD   B,(HL)  			;224C 46
L224D:	LD   B,E     			;224D 43
	LD   B,H     			;224E 44
	JR   C,L2284     		;224F 3833	<L2284>
	JR   NC,L2298    		;2251 3045	<L2298>
	LD   B,E     			;2253 43
	ADD  HL,SP   			;2254 39
	LD   SP,M3233    		;2255 313332	<M3233>
L2258:	LD   B,H     			;2258 44
	DEC  C       			;2259 0D
	LD   A,(BC)  			;225A 0A
	LD   A,(M3032)   		;225B 3A3230	<M3032>
	JR   NC,L22A5    		;225E 3045	<L22A5>
L2260:	INC  (HL)    			;2260 34
	JR   NC,L2293    		;2261 3030	<L2293>
L2263:	JR   NC,L2295    		;2263 3030	<L2295>
	LD   B,(HL)  			;2265 46
	INC  SP      			;2266 33
	JR   NC,L2299    		;2267 3030	<L2299>
L2269:	LD   B,H     			;2269 44
	LD   SP,M4341    		;226A 314143	<M4341>
	LD   B,H     			;226D 44
	DEC  (HL)    			;226E 35
	INC  (HL)    			;226F 34
L2270:	JR   NC,L22B7    		;2270 3045	<L22B7>
	LD   (M3145),A   		;2272 324531	<M3145>
L2275:	JR   C,L22A7     		;2275 3830	<L22A7>
	LD   SP,M4132    		;2277 313241	<M4132>
L227A:	JR   NC,L22AC    		;227A 3030	<L22AC>
	LD   B,E     			;227C 43
L227D:	LD   B,H     			;227D 44
	JR   C,L22B3     		;227E 3833	<L22B3>
	JR   NC,L22C7    		;2280 3045	<L22C7>
	LD   B,E     			;2282 43
L2283:	ADD  HL,SP   			;2283 39
L2284:	LD   B,E     			;2284 43
	LD   B,H     			;2285 44
	LD   B,L     			;2286 45
	ADD  HL,SP   			;2287 39
L2288:	JR   NC,L22CF    		;2288 3045	<L22CF>
	LD   B,E     			;228A 43
	ADD  HL,SP   			;228B 39
	LD   B,L     			;228C 45
	LD   (HL),30H  			;228D 3630	<30H>
	LD   B,(HL)  			;228F 46
	LD   (M3631),A   		;2290 323136	<M3631>
L2293:	JR   C,L22C6     		;2293 3831	<L22C6>
L2295:	JR   NC,L22DA    		;2295 3043	<L22DA>
	LD   B,(HL)  			;2297 46
L2298:	SCF          			;2298 37
L2299:	LD   B,L     			;2299 45
	INC  SP      			;229A 33
	LD   (M3532),A   		;229B 323235	<M3532>
	JR   C,L22D0     		;229E 3830	<L22D0>
	LD   B,E     			;22A0 43
	ADD  HL,SP   			;22A1 39
	LD   (M3331),A   		;22A2 323133	<M3331>
L22A5:	LD   B,E     			;22A5 43
	DEC  C       			;22A6 0D
L22A7:	LD   A,(BC)  			;22A7 0A
	LD   A,(M3032)   		;22A8 3A3230	<M3032>
	JR   NC,L22F2    		;22AB 3045	<L22F2>
	LD   (HL),30H  			;22AD 3630	<30H>
	JR   NC,L22E1    		;22AF 3030	<L22E1>
	INC  SP      			;22B1 33
	LD   B,C     			;22B2 41
L22B3:	JR   C,L22E5     		;22B3 3830	<L22E5>
	SCF          			;22B5 37
	LD   B,L     			;22B6 45
L22B7:	LD   B,C     			;22B7 41
	SCF          			;22B8 37
	LD   B,E     			;22B9 43
	JR   NC,L22EF    		;22BA 3033	<L22EF>
	LD   B,C     			;22BC 41
	LD   SP,M3846    		;22BD 314638	<M3846>
	JR   NC,L2303    		;22C0 3041	<L2303>
	SCF          			;22C2 37
	LD   B,E     			;22C3 43
	JR   C,L22F9     		;22C4 3833	<L22F9>
L22C6:	LD   (HL),33H  			;22C6 3633	<33H>
	JR   C,L22FC     		;22C8 3832	<L22FC>
	LD   B,L     			;22CA 45
	LD   (M4137),A   		;22CB 323741	<M4137>
	LD   B,L     			;22CE 45
L22CF:	SCF          			;22CF 37
L22D0:	SCF          			;22D0 37
	INC  SP      			;22D1 33
	LD   B,C     			;22D2 41
	LD   SP,M3838    		;22D3 313838	<M3838>
	JR   NC,L2319    		;22D6 3041	<L2319>
	SCF          			;22D8 37
	LD   B,E     			;22D9 43
L22DA:	JR   NC,L2321    		;22DA 3045	<L2321>
	LD   B,H     			;22DC 44
	INC  (HL)    			;22DD 34
	LD   B,D     			;22DE 42
	LD   (M3830),A   		;22DF 323038	<M3830>
	JR   NC,L231B    		;22E2 3037	<L231B>
	ADD  HL,SP   			;22E4 39
L22E5:	LD   (M3245),A   		;22E5 324532	<M3245>
	ADD  HL,SP   			;22E8 39
	LD   B,C     			;22E9 41
	LD   B,L     			;22EA 45
	SCF          			;22EB 37
	SCF          			;22EC 37
	SCF          			;22ED 37
	JR   C,L2322     		;22EE 3832	<L2322>
	INC  SP      			;22F0 33
	JR   NC,L2325    		;22F1 3032	<L2325>
	DEC  C       			;22F3 0D
	LD   A,(BC)  			;22F4 0A
	LD   A,(M3032)   		;22F5 3A3230	<M3032>
	JR   NC,L233F    		;22F8 3045	<L233F>
	JR   C,L232C     		;22FA 3830	<L232C>
L22FC:	JR   NC,L232E    		;22FC 3030	<L232E>
	LD   B,C     			;22FE 41
	LD   B,L     			;22FF 45
	SCF          			;2300 37
	SCF          			;2301 37
	LD   B,E     			;2302 43
L2303:	ADD  HL,SP   			;2303 39
	LD   (M3836),A   		;2304 323638	<M3836>
	JR   NC,L2340    		;2307 3037	<L2340>
	LD   B,L     			;2309 45
	LD   B,C     			;230A 41
	SCF          			;230B 37
	LD   B,E     			;230C 43
	JR   C,L2341     		;230D 3832	<L2341>
	INC  SP      			;230F 33
	INC  SP      			;2310 33
	DEC  (HL)    			;2311 35
	LD   B,E     			;2312 43
	JR   NC,L2347    		;2313 3032	<L2347>
	INC  SP      			;2315 33
	DEC  (HL)    			;2316 35
	LD   B,L     			;2317 45
	LD   (M3533),A   		;2318 323335	<M3533>
L231B:	LD   (HL),31H  			;231B 3631	<31H>
	LD   B,C     			;231D 41
	LD   B,C     			;231E 41
	SCF          			;231F 37
	LD   (M3030),A   		;2320 323030	<M3030>
	LD   (HL),32H  			;2323 3632	<32H>
L2325:	LD   B,D     			;2325 42
	LD   (M3242),A   		;2326 324232	<M3242>
	LD   B,D     			;2329 42
	SCF          			;232A 37
	SCF          			;232B 37
L232C:	LD   SP,M3438    		;232C 313834	<M3438>
	ADD  HL,SP   			;232F 39
	INC  SP      			;2330 33
	LD   B,E     			;2331 43
	LD   (M3030),A   		;2332 323030	<M3030>
	LD   B,C     			;2335 41
	INC  SP      			;2336 33
	LD   (M3831),A   		;2337 323138	<M3831>
	JR   C,L236C     		;233A 3830	<L236C>
	LD   (M3245),A   		;233C 324532	<M3245>
L233F:	LD   SP,M0A0D    		;233F 310D0A	<M0A0D>
	LD   A,(M3032)   		;2342 3A3230	<M3032>
	JR   NC,L238C    		;2345 3045	<L238C>
L2347:	LD   B,C     			;2347 41
	JR   NC,L237A    		;2348 3030	<L237A>
	JR   NC,L237E    		;234A 3032	<L237E>
	ADD  HL,SP   			;234C 39
	LD   B,E     			;234D 43
	LD   B,D     			;234E 42
	LD   B,(HL)  			;234F 46
	LD   B,L     			;2350 45
	LD   (M3146),A   		;2351 324631	<M3146>
	JR   C,L2389     		;2354 3833	<L2389>
	LD   B,E     			;2356 43
	INC  SP      			;2357 33
	LD   B,E     			;2358 43
	LD   (M3030),A   		;2359 323030	<M3030>
	ADD  HL,SP   			;235C 39
	LD   B,L     			;235D 45
	LD   B,D     			;235E 42
	LD   (M3733),A   		;235F 323337	<M3733>
	LD   B,L     			;2362 45
	LD   (M3633),A   		;2363 323336	<M3633>
	LD   (HL),36H  			;2366 3636	<36H>
	LD   B,(HL)  			;2368 46
	LD   B,L     			;2369 45
	LD   B,D     			;236A 42
	LD   SP,M4438    		;236B 313844	<M4438>
	LD   B,H     			;236E 44
	INC  SP      			;236F 33
	LD   B,E     			;2370 43
	LD   (M3030),A   		;2371 323030	<M3030>
	LD   B,C     			;2374 41
	LD   (M3333),A   		;2375 323333	<M3333>
	DEC  (HL)    			;2378 35
	LD   (M3242),A   		;2379 324232	<M3242>
	JR   NC,L23C3    		;237C 3045	<L23C3>
L237E:	LD   B,(HL)  			;237E 46
	LD   SP,M3133    		;237F 313331	<M3133>
	INC  SP      			;2382 33
	LD   SP,M3133    		;2383 313331	<M3133>
	JR   C,L23CC     		;2386 3844	<L23CC>
	JR   NC,L23BD    		;2388 3033	<L23BD>
	LD   B,E     			;238A 43
	ADD  HL,SP   			;238B 39
L238C:	LD   B,(HL)  			;238C 46
	DEC  C       			;238D 0D
	LD   A,(BC)  			;238E 0A
	LD   A,(M3032)   		;238F 3A3230	<M3032>
	JR   NC,L23D9    		;2392 3045	<L23D9>
	LD   B,E     			;2394 43
	JR   NC,L23C7    		;2395 3030	<L23C7>
	JR   NC,L23CB    		;2397 3032	<L23CB>
	JR   NC,L23CB    		;2399 3030	<L23CB>
	LD   (HL),32H  			;239B 3632	<32H>
	INC  SP      			;239D 33
	LD   SP,M3133    		;239E 313331	<M3133>
	LD   B,C     			;23A1 41
	SCF          			;23A2 37
	SCF          			;23A3 37
	LD   SP,M3233    		;23A4 313332	<M3233>
	LD   B,D     			;23A7 42
	LD   SP,M4641    		;23A8 314146	<M4641>
	DEC  (HL)    			;23AB 35
	LD   B,L     			;23AC 45
	LD   (HL),33H  			;23AD 3633	<33H>
	LD   B,(HL)  			;23AF 46
	LD   SP,M3133    		;23B0 313331	<M3133>
	INC  SP      			;23B3 33
	SCF          			;23B4 37
	LD   (M4232),A   		;23B5 323242	<M4232>
	SCF          			;23B8 37
	INC  SP      			;23B9 33
	LD   (M3742),A   		;23BA 324237	<M3742>
L23BD:	SCF          			;23BD 37
	LD   B,(HL)  			;23BE 46
	LD   SP,M3645    		;23BF 314536	<M3645>
	LD   B,E     			;23C2 43
L23C3:	JR   NC,L23F7    		;23C3 3032	<L23F7>
	JR   C,L23F7     		;23C5 3830	<L23F7>
L23C7:	JR   C,L240E     		;23C7 3845	<L240E>
	LD   (HL),38H  			;23C9 3638	<38H>
L23CB:	JR   NC,L23FF    		;23CB 3032	<L23FF>
	LD   B,L     			;23CD 45
	LD   (M4339),A   		;23CE 323943	<M4339>
	LD   B,D     			;23D1 42
	LD   B,D     			;23D2 42
	LD   B,L     			;23D3 45
	LD   B,D     			;23D4 42
	LD   (HL),37H  			;23D5 3637	<37H>
	SCF          			;23D7 37
	LD   B,C     			;23D8 41
L23D9:	LD   SP,M0A0D    		;23D9 310D0A	<M0A0D>
	LD   A,(M3032)   		;23DC 3A3230	<M3032>
	JR   NC,L2426    		;23DF 3045	<L2426>
	LD   B,L     			;23E1 45
	JR   NC,L2414    		;23E2 3030	<L2414>
	JR   NC,L2417    		;23E4 3031	<L2417>
	LD   B,D     			;23E6 42
	LD   SP,M3541    		;23E7 314135	<M3541>
	LD   B,(HL)  			;23EA 46
	LD   (HL),39H  			;23EB 3639	<39H>
	SCF          			;23ED 37
	LD   B,L     			;23EE 45
	LD   B,C     			;23EF 41
	JR   NC,L2434    		;23F0 3042	<L2434>
	INC  SP      			;23F2 33
	SCF          			;23F3 37
	SCF          			;23F4 37
	LD   B,E     			;23F5 43
	ADD  HL,SP   			;23F6 39
L23F7:	LD   (M3031),A   		;23F7 323130	<M3031>
	LD   SP,M3038    		;23FA 313830	<M3038>
	LD   B,E     			;23FD 43
	LD   B,D     			;23FE 42
L23FF:	INC  (HL)    			;23FF 34
	LD   B,L     			;2400 45
	LD   B,E     			;2401 43
	JR   C,L2447     		;2402 3843	<L2447>
	LD   B,D     			;2404 42
	JR   C,L244C     		;2405 3845	<L244C>
	JR   NC,L243F    		;2407 3036	<L243F>
	LD   SP,M3336    		;2409 313633	<M3336>
	LD   B,C     			;240C 41
	JR   NC,L2454    		;240D 3045	<L2454>
	JR   C,L2441     		;240F 3830	<L2441>
	LD   B,(HL)  			;2411 46
	LD   B,L     			;2412 45
	JR   NC,L2447    		;2413 3032	<L2447>
	LD   (M3038),A   		;2415 323830	<M3038>
	LD   B,D     			;2418 42
	JR   NC,L2451    		;2419 3036	<L2451>
	JR   NC,L2451    		;241B 3034	<L2451>
	LD   B,(HL)  			;241D 46
	LD   B,L     			;241E 45
	JR   NC,L2457    		;241F 3036	<L2457>
	LD   (M3038),A   		;2421 323830	<M3038>
	DEC  (HL)    			;2424 35
	LD   B,D     			;2425 42
L2426:	LD   (HL),0DH  			;2426 360D	<0DH>
	LD   A,(BC)  			;2428 0A
	LD   A,(M3032)   		;2429 3A3230	<M3032>
	JR   NC,L2474    		;242C 3046	<L2474>
	JR   NC,L2460    		;242E 3030	<L2460>
	JR   NC,L2462    		;2430 3030	<L2462>
	JR   NC,L246A    		;2432 3036	<L246A>
L2434:	JR   NC,L246C    		;2434 3036	<L246C>
	LD   B,(HL)  			;2436 46
	LD   B,L     			;2437 45
	JR   NC,L246F    		;2438 3035	<L246F>
	LD   B,E     			;243A 43
	JR   NC,L2474    		;243B 3037	<L2474>
	JR   C,L2482     		;243D 3843	<L2482>
L243F:	LD   B,H     			;243F 44
	LD   (M3034),A   		;2440 323430	<M3034>
	LD   SP,M3943    		;2443 314339	<M3943>
	LD   SP,M3231    		;2446 313132	<M3231>
	ADD  HL,SP   			;2449 39
	JR   C,L247C     		;244A 3830	<L247C>
L244C:	LD   SP,M4541    		;244C 314145	<M4541>
	LD   (HL),33H  			;244F 3633	<33H>
L2451:	LD   B,(HL)  			;2451 46
	LD   B,D     			;2452 42
	JR   C,L2498     		;2453 3843	<L2498>
	JR   C,L249D     		;2455 3846	<L249D>
L2457:	INC  SP      			;2457 33
	LD   SP,M4541    		;2458 314145	<M4541>
	LD   (HL),43H  			;245B 3643	<43H>
	JR   NC,L24A1    		;245D 3042	<L24A1>
	JR   NC,L2492    		;245F 3031	<L2492>
	LD   (M4246),A   		;2461 324642	<M4246>
	LD   B,E     			;2464 43
	ADD  HL,SP   			;2465 39
	LD   B,L     			;2466 45
	LD   B,H     			;2467 44
	INC  (HL)    			;2468 34
	LD   B,D     			;2469 42
L246A:	JR   C,L24B0     		;246A 3844	<L24B0>
L246C:	JR   C,L249E     		;246C 3830	<L249E>
	INC  SP      			;246E 33
L246F:	LD   B,C     			;246F 41
	DEC  (HL)    			;2470 35
	LD   B,(HL)  			;2471 46
	INC  SP      			;2472 33
	LD   B,(HL)  			;2473 46
L2474:	DEC  C       			;2474 0D
	LD   A,(BC)  			;2475 0A
	LD   A,(M3032)   		;2476 3A3230	<M3032>
	JR   NC,L24C1    		;2479 3046	<L24C1>
	LD   (M3030),A   		;247B 323030	<M3030>
	JR   NC,L24B8    		;247E 3038	<L24B8>
	JR   NC,L24C8    		;2480 3046	<L24C8>
L2482:	LD   B,L     			;2482 45
	JR   NC,L24B9    		;2483 3034	<L24B9>
	LD   (M3038),A   		;2485 323830	<M3038>
	LD   B,H     			;2488 44
	LD   (M3831),A   		;2489 323138	<M3831>
	LD   B,E     			;248C 43
	JR   C,L24BF     		;248D 3830	<L24BF>
	INC  (HL)    			;248F 34
	LD   B,L     			;2490 45
	LD   B,(HL)  			;2491 46
L2492:	LD   B,L     			;2492 45
	JR   NC,L24CB    		;2493 3036	<L24CB>
	LD   (M3038),A   		;2495 323830	<M3038>
L2498:	DEC  (HL)    			;2498 35
	LD   B,L     			;2499 45
	LD   (HL),30H  			;249A 3630	<30H>
	LD   (M3843),A   		;249C 324338	<M3843>
	JR   NC,L24D7    		;249F 3036	<L24D7>
L24A1:	JR   NC,L24E8    		;24A1 3045	<L24E8>
	SCF          			;24A3 37
	ADD  HL,SP   			;24A4 39
	LD   (M3631),A   		;24A5 323136	<M3631>
	LD   B,(HL)  			;24A8 46
	LD   SP,M4339    		;24A9 313943	<M4339>
	LD   B,(HL)  			;24AC 46
	INC  (HL)    			;24AD 34
	LD   B,L     			;24AE 45
	LD   B,L     			;24AF 45
L24B0:	LD   B,H     			;24B0 44
	INC  (HL)    			;24B1 34
	INC  SP      			;24B2 33
	JR   NC,L24F6    		;24B3 3041	<L24F6>
	JR   C,L24E7     		;24B5 3830	<L24E7>
	LD   B,E     			;24B7 43
L24B8:	ADD  HL,SP   			;24B8 39
L24B9:	LD   B,E     			;24B9 43
	LD   B,H     			;24BA 44
	LD   B,L     			;24BB 45
	DEC  (HL)    			;24BC 35
	JR   NC,L24F3    		;24BD 3034	<L24F3>
L24BF:	LD   SP,M0D32    		;24BF 31320D	<M0D32>
	LD   A,(BC)  			;24C2 0A
	LD   A,(M3032)   		;24C3 3A3230	<M3032>
	JR   NC,L250E    		;24C6 3046	<L250E>
L24C8:	INC  (HL)    			;24C8 34
	JR   NC,L24FB    		;24C9 3030	<L24FB>
L24CB:	JR   NC,L2510    		;24CB 3043	<L2510>
	JR   NC,L2501    		;24CD 3032	<L2501>
	LD   SP,M3330    		;24CF 313033	<M3330>
	JR   C,L2504     		;24D2 3830	<L2504>
	LD   B,E     			;24D4 43
	LD   B,D     			;24D5 42
	SCF          			;24D6 37
L24D7:	LD   (HL),43H  			;24D7 3643	<43H>
	JR   C,L2520     		;24D9 3845	<L2520>
	SCF          			;24DB 37
	LD   (M3045),A   		;24DC 324530	<M3045>
	LD   B,H     			;24DF 44
	INC  (HL)    			;24E0 34
	LD   (HL),33H  			;24E1 3633	<33H>
	LD   B,C     			;24E3 41
	JR   NC,L2516    		;24E4 3030	<L2516>
	JR   C,L2518     		;24E6 3830	<L2518>
L24E8:	LD   B,(HL)  			;24E8 46
	LD   (HL),46H  			;24E9 3646	<46H>
	JR   NC,L2524    		;24EB 3037	<L2524>
	SCF          			;24ED 37
	LD   B,(HL)  			;24EE 46
	SCF          			;24EF 37
	INC  SP      			;24F0 33
	LD   B,C     			;24F1 41
	JR   NC,L2528    		;24F2 3034	<L2528>
	JR   C,L2526     		;24F4 3830	<L2526>
L24F6:	LD   B,E     			;24F6 43
	LD   B,D     			;24F7 42
	SCF          			;24F8 37
	SCF          			;24F9 37
	LD   (M4638),A   		;24FA 323846	<M4638>
	JR   C,L2536     		;24FD 3837	<L2536>
	JR   NC,L2546    		;24FF 3045	<L2546>
L2501:	LD   B,(HL)  			;2501 46
	LD   B,E     			;2502 43
	ADD  HL,SP   			;2503 39
L2504:	LD   B,E     			;2504 43
	LD   B,H     			;2505 44
	LD   B,L     			;2506 45
	DEC  (HL)    			;2507 35
	JR   NC,L253E    		;2508 3034	<L253E>
	LD   B,E     			;250A 43
	JR   NC,L2553    		;250B 3046	<L2553>
	JR   NC,L251C    		;250D 300D	<L251C>
	LD   A,(BC)  			;250F 0A
L2510:	LD   A,(M3032)   		;2510 3A3230	<M3032>
	JR   NC,L255B    		;2513 3046	<L255B>
	LD   (HL),30H  			;2515 3630	<30H>
	JR   NC,L2549    		;2517 3030	<L2549>
	INC  SP      			;2519 33
	LD   B,C     			;251A 41
	LD   (HL),41H  			;251B 3641	<41H>
	JR   C,L254F     		;251D 3830	<L254F>
	LD   B,(HL)  			;251F 46
L2520:	LD   B,L     			;2520 45
	JR   NC,L2555    		;2521 3032	<L2555>
	LD   B,H     			;2523 44
L2524:	JR   C,L2558     		;2524 3832	<L2558>
L2526:	LD   SP,M4431    		;2526 313144	<M4431>
	JR   C,L255B     		;2529 3830	<L255B>
	LD   (M3038),A   		;252B 323830	<M3038>
	LD   B,(HL)  			;252E 46
	SCF          			;252F 37
	LD   B,L     			;2530 45
	LD   B,C     			;2531 41
	SCF          			;2532 37
	LD   B,E     			;2533 43
	JR   C,L2569     		;2534 3833	<L2569>
L2536:	LD   (HL),30H  			;2536 3630	<30H>
	JR   NC,L256D    		;2538 3033	<L256D>
	LD   B,C     			;253A 41
	LD   SP,M3833    		;253B 313338	<M3833>
L253E:	JR   NC,L2586    		;253E 3046	<L2586>
	LD   B,L     			;2540 45
	JR   NC,L2576    		;2541 3033	<L2576>
	LD   B,E     			;2543 43
	JR   NC,L2579    		;2544 3033	<L2579>
L2546:	LD   B,L     			;2546 45
	JR   NC,L258A    		;2547 3041	<L258A>
L2549:	LD   B,(HL)  			;2549 46
	LD   B,(HL)  			;254A 46
	LD   B,E     			;254B 43
	ADD  HL,SP   			;254C 39
	INC  SP      			;254D 33
	LD   B,C     			;254E 41
L254F:	INC  SP      			;254F 33
	SCF          			;2550 37
	JR   C,L2583     		;2551 3830	<L2583>
L2553:	LD   B,C     			;2553 41
	SCF          			;2554 37
L2555:	LD   B,E     			;2555 43
	JR   NC,L258F    		;2556 3037	<L258F>
L2558:	LD   B,L     			;2558 45
	LD   B,L     			;2559 45
	ADD  HL,SP   			;255A 39
L255B:	DEC  C       			;255B 0D
	LD   A,(BC)  			;255C 0A
	LD   A,(M3032)   		;255D 3A3230	<M3032>
	JR   NC,L25A8    		;2560 3046	<L25A8>
	JR   C,L2594     		;2562 3830	<L2594>
	JR   NC,L2596    		;2564 3030	<L2596>
	LD   B,C     			;2566 41
	SCF          			;2567 37
	LD   B,E     			;2568 43
L2569:	JR   NC,L259E    		;2569 3033	<L259E>
	LD   B,C     			;256B 41
	SCF          			;256C 37
L256D:	LD   B,L     			;256D 45
	JR   C,L25A0     		;256E 3830	<L25A0>
	LD   B,L     			;2570 45
	LD   (HL),30H  			;2571 3630	<30H>
	LD   B,(HL)  			;2573 46
	LD   B,E     			;2574 43
	JR   C,L25AA     		;2575 3833	<L25AA>
	LD   (HL),46H  			;2577 3646	<46H>
L2579:	LD   B,(HL)  			;2579 46
	INC  SP      			;257A 33
	LD   B,L     			;257B 45
	JR   NC,L25B7    		;257C 3039	<L25B7>
	LD   B,(HL)  			;257E 46
	LD   B,(HL)  			;257F 46
	LD   B,E     			;2580 43
	ADD  HL,SP   			;2581 39
	JR   NC,L25BA    		;2582 3036	<L25BA>
	JR   NC,L25BE    		;2584 3038	<L25BE>
L2586:	LD   (M3331),A   		;2586 323133	<M3331>
	LD   (HL),38H  			;2589 3638	<38H>
	JR   NC,L25D0    		;258B 3043	<L25D0>
	LD   B,D     			;258D 42
	INC  SP      			;258E 33
L258F:	JR   C,L25D5     		;258F 3844	<L25D5>
	JR   C,L25C6     		;2591 3833	<L25C6>
	LD   B,L     			;2593 45
L2594:	JR   NC,L25CE    		;2594 3038	<L25CE>
L2596:	LD   B,E     			;2596 43
	LD   B,(HL)  			;2597 46
	SCF          			;2598 37
	LD   B,L     			;2599 45
	LD   B,(HL)  			;259A 46
	LD   B,L     			;259B 45
	JR   NC,L25D2    		;259C 3034	<L25D2>
L259E:	LD   (M4630),A   		;259E 323046	<M4630>
	DEC  (HL)    			;25A1 35
	LD   SP,M3131    		;25A2 313131	<M3131>
	LD   B,L     			;25A5 45
	LD   SP,M0D38    		;25A6 31380D	<M0D38>
	LD   A,(BC)  			;25A9 0A
L25AA:	LD   A,(M3032)   		;25AA 3A3230	<M3032>
	JR   NC,L25F5    		;25AD 3046	<L25F5>
	LD   B,C     			;25AF 41
	JR   NC,L25E2    		;25B0 3030	<L25E2>
	JR   NC,L25EC    		;25B2 3038	<L25EC>
	JR   NC,L25E7    		;25B4 3031	<L25E7>
	LD   B,C     			;25B6 41
L25B7:	LD   B,C     			;25B7 41
	JR   NC,L25EC    		;25B8 3032	<L25EC>
L25BA:	JR   NC,L2601    		;25BA 3045	<L2601>
	LD   B,L     			;25BC 45
	LD   SP,M4241    		;25BD 314142	<M4241>
	JR   NC,L25F3    		;25C0 3031	<L25F3>
	LD   (M4533),A   		;25C2 323345	<M4533>
	JR   NC,L260D    		;25C5 3046	<L260D>
	LD   B,(HL)  			;25C7 46
	LD   B,(HL)  			;25C8 46
	INC  SP      			;25C9 33
	LD   B,C     			;25CA 41
	LD   (HL),41H  			;25CB 3641	<41H>
	JR   C,L25FF     		;25CD 3830	<L25FF>
	LD   B,(HL)  			;25CF 46
L25D0:	LD   B,L     			;25D0 45
	JR   NC,L2606    		;25D1 3033	<L2606>
	LD   B,H     			;25D3 44
	JR   C,L2608     		;25D4 3832	<L2608>
	LD   B,L     			;25D6 45
	SCF          			;25D7 37
	LD   B,L     			;25D8 45
	SCF          			;25D9 37
	LD   B,L     			;25DA 45
	LD   B,L     			;25DB 45
	LD   (HL),30H  			;25DC 3630	<30H>
	LD   B,(HL)  			;25DE 46
	LD   (M3038),A   		;25DF 323830	<M3038>
L25E2:	DEC  (HL)    			;25E2 35
	LD   (M3245),A   		;25E3 324532	<M3245>
	INC  (HL)    			;25E6 34
L25E7:	LD   B,E     			;25E7 43
	LD   B,D     			;25E8 42
	LD   B,D     			;25E9 42
	LD   B,L     			;25EA 45
	LD   B,E     			;25EB 43
L25EC:	ADD  HL,SP   			;25EC 39
	LD   (M3742),A   		;25ED 324237	<M3742>
	LD   B,L     			;25F0 45
	LD   (M4645),A   		;25F1 324546	<M4645>
	LD   B,H     			;25F4 44
L25F5:	DEC  C       			;25F5 0D
	LD   A,(BC)  			;25F6 0A
	LD   A,(M3032)   		;25F7 3A3230	<M3032>
	JR   NC,L2642    		;25FA 3046	<L2642>
	LD   B,E     			;25FC 43
	JR   NC,L262F    		;25FD 3030	<L262F>
L25FF:	JR   NC,L2637    		;25FF 3036	<L2637>
L2601:	LD   (HL),41H  			;2601 3641	<41H>
	LD   (HL),43H  			;2603 3643	<43H>
	JR   NC,L263A    		;2605 3033	<L263A>
	LD   B,C     			;2607 41
L2608:	LD   (HL),38H  			;2608 3638	<38H>
	JR   C,L263C     		;260A 3830	<L263C>
	LD   B,L     			;260C 45
L260D:	LD   (HL),30H  			;260D 3630	<30H>
	LD   B,(HL)  			;260F 46
	LD   (M3038),A   		;2610 323830	<M3038>
	INC  (HL)    			;2613 34
	LD   (M3245),A   		;2614 324532	<M3245>
	INC  (HL)    			;2617 34
	LD   B,E     			;2618 43
	LD   B,D     			;2619 42
	LD   B,(HL)  			;261A 46
	LD   B,L     			;261B 45
	LD   (M3841),A   		;261C 324138	<M3841>
	ADD  HL,SP   			;261F 39
	JR   C,L2652     		;2620 3830	<L2652>
	SCF          			;2622 37
	LD   B,E     			;2623 43
	LD   B,D     			;2624 42
	DEC  (HL)    			;2625 35
	LD   B,E     			;2626 43
	JR   C,L265B     		;2627 3832	<L265B>
	LD   SP,M4438    		;2629 313844	<M4438>
	LD   SP,M3339    		;262C 313933	<M3339>
L262F:	LD   B,C     			;262F 41
	INC  SP      			;2630 33
	SCF          			;2631 37
	JR   C,L2664     		;2632 3830	<L2664>
	LD   B,(HL)  			;2634 46
	LD   B,L     			;2635 45
	LD   (M4445),A   		;2636 324544	<M4445>
	JR   NC,L2681    		;2639 3046	<L2681>
	LD   B,L     			;263B 45
L263C:	LD   SP,M3342    		;263C 314233	<M3342>
	JR   NC,L2683    		;263F 3042	<L2683>
	LD   B,L     			;2641 45
L2642:	DEC  C       			;2642 0D
	LD   A,(BC)  			;2643 0A
	LD   A,(M3032)   		;2644 3A3230	<M3032>
	JR   NC,L268F    		;2647 3046	<L268F>
	LD   B,L     			;2649 45
	JR   NC,L267C    		;264A 3030	<L267C>
	JR   NC,L267E    		;264C 3030	<L267E>
	INC  SP      			;264E 33
	INC  SP      			;264F 33
	LD   B,L     			;2650 45
	JR   NC,L2687    		;2651 3034	<L2687>
	LD   B,E     			;2653 43
	LD   B,(HL)  			;2654 46
	LD   B,L     			;2655 45
	LD   B,H     			;2656 44
	DEC  (HL)    			;2657 35
	LD   B,(HL)  			;2658 46
	LD   B,(HL)  			;2659 46
	LD   (HL),38H  			;265A 3638	<38H>
	JR   NC,L268E    		;265C 3030	<L268E>
	LD   (HL),30H  			;265E 3630	<30H>
	LD   (M3332),A   		;2660 323233	<M3332>
	JR   C,L269B     		;2663 3836	<L269B>
	LD   (M3333),A   		;2665 323333	<M3333>
	JR   C,L269A     		;2668 3830	<L269A>
	INC  SP      			;266A 33
	LD   SP,M4630    		;266B 313046	<M4630>
	ADD  HL,SP   			;266E 39
	LD   B,E     			;266F 43
	ADD  HL,SP   			;2670 39
	SCF          			;2671 37
	LD   B,L     			;2672 45
	LD   B,(HL)  			;2673 46
	LD   B,(HL)  			;2674 46
	LD   B,E     			;2675 43
	ADD  HL,SP   			;2676 39
	JR   NC,L26A9    		;2677 3030	<L26A9>
	JR   NC,L26AB    		;2679 3030	<L26AB>
	JR   NC,L26AD    		;267B 3030	<L26AD>
	JR   NC,L26AF    		;267D 3030	<L26AF>
	JR   NC,L26B1    		;267F 3030	<L26B1>
L2681:	JR   NC,L26B3    		;2681 3030	<L26B3>
L2683:	JR   NC,L26B5    		;2683 3030	<L26B5>
	JR   NC,L26B7    		;2685 3030	<L26B7>
L2687:	JR   NC,L26B9    		;2687 3030	<L26B9>
	JR   NC,L26BB    		;2689 3030	<L26BB>
	JR   NC,L26BD    		;268B 3030	<L26BD>
	LD   B,(HL)  			;268D 46
L268E:	INC  (HL)    			;268E 34
L268F:	DEC  C       			;268F 0D
	LD   A,(BC)  			;2690 0A
	LD   A,(M3032)   		;2691 3A3230	<M3032>
	LD   SP,M3030    		;2694 313030	<M3030>
	JR   NC,L26C9    		;2697 3030	<L26C9>
	JR   NC,L26CC    		;2699 3031	<L26CC>
L269B:	INC  (HL)    			;269B 34
	JR   NC,L26CE    		;269C 3030	<L26CE>
	JR   NC,L26D0    		;269E 3030	<L26D0>
	JR   NC,L26D2    		;26A0 3030	<L26D2>
	JR   NC,L26D6    		;26A2 3032	<L26D6>
	JR   NC,L26D6    		;26A4 3030	<L26D6>
	JR   NC,L26DC    		;26A6 3034	<L26DC>
	JR   NC,L26DF    		;26A8 3035	<L26DF>
	JR   NC,L26E2    		;26AA 3036	<L26E2>
	JR   NC,L26DE    		;26AC 3030	<L26DE>
	JR   NC,L26E8    		;26AE 3038	<L26E8>
	JR   NC,L26E2    		;26B0 3030	<L26E2>
	LD   SP,M3036    		;26B2 313630	<M3036>
L26B5:	JR   NC,L26E8    		;26B5 3031	<L26E8>
L26B7:	JR   C,L26E9     		;26B7 3830	<L26E9>
L26B9:	JR   NC,L26EC    		;26B9 3031	<L26EC>
L26BB:	ADD  HL,SP   			;26BB 39
	JR   NC,L26EE    		;26BC 3030	<L26EE>
	LD   SP,M4641    		;26BE 314146	<M4641>
	LD   B,(HL)  			;26C1 46
	LD   SP,M3042    		;26C2 314230	<M3042>
	JR   NC,L26F9    		;26C5 3032	<L26F9>
	LD   (M3030),A   		;26C7 323030	<M3030>
	LD   (M3133),A   		;26CA 323331	<M3133>
	LD   SP,M3432    		;26CD 313234	<M3432>
L26D0:	JR   NC,L2709    		;26D0 3037	<L2709>
L26D2:	LD   (M3135),A   		;26D2 323531	<M3135>
	LD   B,L     			;26D5 45
L26D6:	LD   (M3037),A   		;26D6 323730	<M3037>
	JR   NC,L270E    		;26D9 3033	<L270E>
	LD   B,H     			;26DB 44
L26DC:	DEC  C       			;26DC 0D
	LD   A,(BC)  			;26DD 0A
L26DE:	LD   A,(M3032)   		;26DE 3A3230	<M3032>
	LD   SP,M3230    		;26E1 313032	<M3230>
	JR   NC,L2716    		;26E4 3030	<L2716>
	JR   NC,L2719    		;26E6 3031	<L2719>
L26E8:	LD   B,E     			;26E8 43
L26E9:	LD   B,L     			;26E9 45
	JR   C,L271D     		;26EA 3831	<L271D>
L26EC:	LD   B,H     			;26EC 44
	JR   NC,L2722    		;26ED 3033	<L2722>
	LD   (M3036),A   		;26EF 323630	<M3036>
	LD   SP,M3033    		;26F2 313330	<M3033>
	JR   NC,L2727    		;26F5 3030	<L2727>
	INC  SP      			;26F7 33
	LD   SP,M3931    		;26F8 313139	<M3931>
	INC  SP      			;26FB 33
	LD   (M3030),A   		;26FC 323030	<M3030>
	INC  SP      			;26FF 33
	INC  SP      			;2700 33
	LD   SP,M3345    		;2701 314533	<M3345>
	DEC  (HL)    			;2704 35
	JR   NC,L273C    		;2705 3035	<L273C>
	LD   (M3541),A   		;2707 324135	<M3541>
	LD   SP,M4232    		;270A 313242	<M4232>
	LD   SP,M3332    		;270D 313233	<M3332>
	INC  (HL)    			;2710 34
	JR   NC,L2744    		;2711 3031	<L2744>
	INC  SP      			;2713 33
	LD   B,C     			;2714 41
	JR   NC,L2747    		;2715 3030	<L2747>
	INC  SP      			;2717 33
	LD   B,E     			;2718 43
L2719:	JR   NC,L274B    		;2719 3030	<L274B>
	JR   NC,L2751    		;271B 3034	<L2751>
L271D:	JR   C,L2765     		;271D 3846	<L2765>
	JR   C,L2751     		;271F 3830	<L2751>
	INC  SP      			;2721 33
L2722:	LD   SP,M3130    		;2722 313031	<M3130>
	JR   C,L276D     		;2725 3846	<L276D>
L2727:	LD   B,(HL)  			;2727 46
	SCF          			;2728 37
	DEC  C       			;2729 0D
	LD   A,(BC)  			;272A 0A
	LD   A,(M3032)   		;272B 3A3230	<M3032>
	LD   SP,M3430    		;272E 313034	<M3430>
	JR   NC,L2763    		;2731 3030	<L2763>
	JR   NC,L276D    		;2733 3038	<L276D>
	JR   NC,L276C    		;2735 3035	<L276C>
	LD   B,D     			;2737 42
	JR   NC,L276B    		;2738 3031	<L276B>
	LD   (HL),32H  			;273A 3632	<32H>
L273C:	JR   C,L276E     		;273C 3830	<L276E>
	LD   (M3044),A   		;273E 324430	<M3044>
	JR   NC,L2773    		;2741 3030	<L2773>
	LD   B,H     			;2743 44
L2744:	JR   C,L2776     		;2744 3830	<L2776>
	JR   C,L277A     		;2746 3832	<L277A>
	JR   NC,L277A    		;2748 3030	<L277A>
	JR   NC,L277F    		;274A 3033	<L277F>
	JR   NC,L2780    		;274C 3032	<L2780>
	JR   NC,L2786    		;274E 3036	<L2786>
	JR   NC,L2786    		;2750 3034	<L2786>
	JR   NC,L2797    		;2752 3043	<L2797>
	JR   NC,L278E    		;2754 3038	<L278E>
	JR   NC,L2791    		;2756 3039	<L2791>
	JR   NC,L278B    		;2758 3031	<L278B>
	JR   NC,L278D    		;275A 3031	<L278D>
	JR   NC,L2790    		;275C 3032	<L2790>
	JR   NC,L2792    		;275E 3032	<L2792>
	JR   NC,L2794    		;2760 3032	<L2794>
	JR   NC,L2796    		;2762 3032	<L2796>
	JR   NC,L2799    		;2764 3033	<L2799>
	JR   NC,L279B    		;2766 3033	<L279B>
	JR   NC,L279D    		;2768 3033	<L279D>
	JR   NC,L279F    		;276A 3033	<L279F>
L276C:	JR   NC,L27A2    		;276C 3034	<L27A2>
L276E:	JR   NC,L27A5    		;276E 3035	<L27A5>
	JR   NC,L27A8    		;2770 3036	<L27A8>
	JR   NC,L27AB    		;2772 3037	<L27AB>
	INC  SP      			;2774 33
	LD   B,L     			;2775 45
L2776:	DEC  C       			;2776 0D
	LD   A,(BC)  			;2777 0A
	LD   A,(M3032)   		;2778 3A3230	<M3032>
	LD   SP,M3630    		;277B 313036	<M3630>
	JR   NC,L27B0    		;277E 3030	<L27B0>
L2780:	JR   NC,L27B2    		;2780 3030	<L27B2>
	JR   C,L27B4     		;2782 3830	<L27B4>
	ADD  HL,SP   			;2784 39
	JR   NC,L27C8    		;2785 3041	<L27C8>
	JR   NC,L27CB    		;2787 3042	<L27CB>
	LD   (HL),34H  			;2789 3634	<34H>
L278B:	JR   NC,L27C1    		;278B 3034	<L27C1>
L278D:	JR   NC,L27D4    		;278D 3045	<L27D4>
	LD   SP,M3346    		;278F 314633	<M3346>
L2792:	LD   B,(HL)  			;2792 46
	JR   NC,L27CB    		;2793 3036	<L27CB>
	DEC  (HL)    			;2795 35
L2796:	LD   B,D     			;2796 42
L2797:	INC  (HL)    			;2797 34
	LD   B,(HL)  			;2798 46
L2799:	LD   (HL),36H  			;2799 3636	<36H>
L279B:	LD   (HL),44H  			;279B 3644	<44H>
L279D:	SCF          			;279D 37
	LD   B,H     			;279E 44
L279F:	JR   NC,L27D8    		;279F 3037	<L27D8>
	SCF          			;27A1 37
L27A2:	LD   B,(HL)  			;27A2 46
	LD   (HL),46H  			;27A3 3646	<46H>
L27A5:	SCF          			;27A5 37
	ADD  HL,SP   			;27A6 39
	SCF          			;27A7 37
L27A8:	INC  SP      			;27A8 33
	INC  SP      			;27A9 33
	ADD  HL,SP   			;27AA 39
L27AB:	SCF          			;27AB 37
	LD   (HL),46H  			;27AC 3646	<46H>
	LD   B,E     			;27AE 43
	JR   NC,L27E1    		;27AF 3030	<L27E1>
	JR   NC,L27E4    		;27B1 3031	<L27E4>
	JR   NC,L27E7    		;27B3 3032	<L27E7>
	JR   NC,L27E7    		;27B5 3030	<L27E7>
	JR   NC,L27F1    		;27B7 3038	<L27F1>
	JR   NC,L27EF    		;27B9 3034	<L27EF>
	JR   NC,L27EF    		;27BB 3032	<L27EF>
	JR   NC,L27F3    		;27BD 3034	<L27F3>
	JR   NC,L27F9    		;27BF 3038	<L27F9>
L27C1:	LD   B,E     			;27C1 43
	LD   B,H     			;27C2 44
	DEC  C       			;27C3 0D
	LD   A,(BC)  			;27C4 0A
	LD   A,(M3032)   		;27C5 3A3230	<M3032>
L27C8:	LD   SP,M3830    		;27C8 313038	<M3830>
L27CB:	JR   NC,L27FD    		;27CB 3030	<L27FD>
	JR   NC,L27FF    		;27CD 3030	<L27FF>
	JR   NC,L2801    		;27CF 3030	<L2801>
	LD   (M3130),A   		;27D1 323031	<M3130>
L27D4:	JR   NC,L2806    		;27D4 3030	<L2806>
	JR   NC,L2810    		;27D6 3038	<L2810>
L27D8:	JR   NC,L280E    		;27D8 3034	<L280E>
	JR   NC,L280E    		;27DA 3032	<L280E>
	JR   NC,L2812    		;27DC 3034	<L2812>
	JR   NC,L2812    		;27DE 3032	<L2812>
	LD   SP,M3030    		;27E0 313030	<M3030>
	INC  (HL)    			;27E3 34
L27E4:	JR   NC,L281E    		;27E4 3038	<L281E>
	JR   NC,L2818    		;27E6 3030	<L2818>
	JR   NC,L281B    		;27E8 3031	<L281B>
	JR   NC,L281E    		;27EA 3032	<L281E>
	JR   NC,L281E    		;27EC 3030	<L281E>
	JR   NC,L2828    		;27EE 3038	<L2828>
	JR   NC,L2826    		;27F0 3034	<L2826>
	JR   NC,L2826    		;27F2 3032	<L2826>
	LD   SP,M3039    		;27F4 313930	<M3039>
	DEC  (HL)    			;27F7 35
	JR   NC,L282B    		;27F8 3031	<L282B>
	JR   NC,L282D    		;27FA 3031	<L282D>
	JR   NC,L282F    		;27FC 3031	<L282F>
	LD   SP,M3039    		;27FE 313930	<M3039>
L2801:	DEC  (HL)    			;2801 35
	JR   NC,L2835    		;2802 3031	<L2835>
	JR   NC,L2839    		;2804 3033	<L2839>
L2806:	LD   SP,M3039    		;2806 313930	<M3039>
	LD   SP,M3530    		;2809 313035	<M3530>
	JR   NC,L283F    		;280C 3031	<L283F>
L280E:	LD   B,C     			;280E 41
	ADD  HL,SP   			;280F 39
L2810:	DEC  C       			;2810 0D
	LD   A,(BC)  			;2811 0A
L2812:	LD   A,(M3032)   		;2812 3A3230	<M3032>
	LD   SP,M4130    		;2815 313041	<M4130>
L2818:	JR   NC,L284A    		;2818 3030	<L284A>
	JR   NC,L284C    		;281A 3030	<L284C>
	INC  SP      			;281C 33
	LD   SP,M3039    		;281D 313930	<M3039>
	LD   SP,M3530    		;2820 313035	<M3530>
	JR   NC,L2856    		;2823 3031	<L2856>
	LD   SP,M3039    		;2825 313930	<M3039>
L2828:	LD   SP,M3130    		;2828 313031	<M3130>
L282B:	LD   SP,M3039    		;282B 313930	<M3039>
	DEC  (HL)    			;282E 35
L282F:	JR   NC,L2862    		;282F 3031	<L2862>
	JR   NC,L2864    		;2831 3031	<L2864>
	JR   NC,L2866    		;2833 3031	<L2866>
L2835:	LD   SP,M3039    		;2835 313930	<M3039>
	DEC  (HL)    			;2838 35
L2839:	JR   NC,L286E    		;2839 3033	<L286E>
	LD   SP,M3039    		;283B 313930	<M3039>
	LD   SP,M3530    		;283E 313035	<M3530>
	LD   SP,M3039    		;2841 313930	<M3039>
	LD   SP,M3130    		;2844 313031	<M3130>
	JR   NC,L287A    		;2847 3031	<L287A>
	JR   NC,L2880    		;2849 3035	<L2880>
	LD   SP,M3039    		;284B 313930	<M3039>
	INC  SP      			;284E 33
	JR   NC,L2882    		;284F 3031	<L2882>
	JR   NC,L2884    		;2851 3031	<L2884>
	JR   NC,L288A    		;2853 3035	<L288A>
	LD   SP,M3039    		;2855 313930	<M3039>
	INC  SP      			;2858 33
	JR   NC,L2890    		;2859 3035	<L2890>
	LD   (M0D43),A   		;285B 32430D	<M0D43>
	LD   A,(BC)  			;285E 0A
	LD   A,(M3032)   		;285F 3A3230	<M3032>
L2862:	LD   SP,M4330    		;2862 313043	<M4330>
	JR   NC,L2897    		;2865 3030	<L2897>
	JR   NC,L2899    		;2867 3030	<L2899>
	LD   SP,M3931    		;2869 313139	<M3931>
	JR   NC,L289F    		;286C 3031	<L289F>
L286E:	JR   NC,L28A5    		;286E 3035	<L28A5>
	JR   NC,L28A5    		;2870 3033	<L28A5>
	LD   SP,M3039    		;2872 313930	<M3039>
	LD   SP,M3530    		;2875 313035	<M3530>
	LD   SP,M3039    		;2878 313930	<M3039>
	JR   NC,L28AD    		;287B 3030	<L28AD>
	JR   NC,L28AF    		;287D 3030	<L28AF>
	LD   B,E     			;287F 43
L2880:	JR   NC,L28B2    		;2880 3030	<L28B2>
L2882:	JR   NC,L28B4    		;2882 3030	<L28B4>
L2884:	JR   NC,L28B6    		;2884 3030	<L28B6>
	JR   NC,L28B8    		;2886 3030	<L28B8>
	JR   NC,L28BA    		;2888 3030	<L28BA>
L288A:	JR   NC,L28BD    		;288A 3031	<L28BD>
	JR   NC,L28BE    		;288C 3030	<L28BE>
	JR   NC,L28C0    		;288E 3030	<L28C0>
L2890:	JR   NC,L28D5    		;2890 3043	<L28D5>
	JR   NC,L28C4    		;2892 3030	<L28C4>
	JR   NC,L28C6    		;2894 3030	<L28C6>
	JR   NC,L28C8    		;2896 3030	<L28C8>
	JR   NC,L28CA    		;2898 3030	<L28CA>
	JR   NC,L28CC    		;289A 3030	<L28CC>
	JR   NC,L28D0    		;289C 3032	<L28D0>
	JR   NC,L28D0    		;289E 3030	<L28D0>
	JR   NC,L28D2    		;28A0 3030	<L28D2>
	JR   NC,L28D5    		;28A2 3031	<L28D5>
	JR   NC,L28D6    		;28A4 3030	<L28D6>
	JR   NC,L28D8    		;28A6 3030	<L28D8>
	ADD  HL,SP   			;28A8 39
	ADD  HL,SP   			;28A9 39
	DEC  C       			;28AA 0D
	LD   A,(BC)  			;28AB 0A
	LD   A,(M3032)   		;28AC 3A3230	<M3032>
L28AF:	LD   SP,M4530    		;28AF 313045	<M4530>
L28B2:	JR   NC,L28E4    		;28B2 3030	<L28E4>
L28B4:	JR   NC,L28E6    		;28B4 3030	<L28E6>
L28B6:	LD   B,E     			;28B6 43
	JR   NC,L28E9    		;28B7 3030	<L28E9>
	JR   NC,L28EB    		;28B9 3030	<L28EB>
	JR   NC,L28ED    		;28BB 3030	<L28ED>
L28BD:	JR   NC,L28EF    		;28BD 3030	<L28EF>
	JR   NC,L28F1    		;28BF 3030	<L28F1>
	JR   NC,L28F3    		;28C1 3030	<L28F3>
	JR   NC,L28F7    		;28C3 3032	<L28F7>
	JR   NC,L28F7    		;28C5 3030	<L28F7>
	JR   NC,L28F9    		;28C7 3030	<L28F9>
	JR   NC,L28FB    		;28C9 3030	<L28FB>
	JR   NC,L28FD    		;28CB 3030	<L28FD>
	JR   NC,L28FF    		;28CD 3030	<L28FF>
	JR   NC,L2901    		;28CF 3030	<L2901>
	JR   NC,L2903    		;28D1 3030	<L2903>
	JR   NC,L2905    		;28D3 3030	<L2905>
L28D5:	JR   NC,L291A    		;28D5 3043	<L291A>
	JR   NC,L2909    		;28D7 3030	<L2909>
	JR   NC,L290B    		;28D9 3030	<L290B>
	JR   NC,L290D    		;28DB 3030	<L290D>
	JR   NC,L290F    		;28DD 3030	<L290F>
	JR   NC,L2913    		;28DF 3032	<L2913>
	JR   NC,L2913    		;28E1 3030	<L2913>
	JR   NC,L2915    		;28E3 3030	<L2915>
	JR   NC,L2918    		;28E5 3031	<L2918>
	JR   NC,L2919    		;28E7 3030	<L2919>
L28E9:	JR   NC,L291B    		;28E9 3030	<L291B>
L28EB:	JR   NC,L291D    		;28EB 3030	<L291D>
L28ED:	JR   NC,L2921    		;28ED 3032	<L2921>
L28EF:	JR   NC,L2921    		;28EF 3030	<L2921>
L28F1:	JR   NC,L2923    		;28F1 3030	<L2923>
L28F3:	JR   NC,L2925    		;28F3 3030	<L2925>
	LD   B,H     			;28F5 44
	LD   SP,M0A0D    		;28F6 310D0A	<M0A0D>
L28F9:	LD   A,(M3032)   		;28F9 3A3230	<M3032>
	LD   SP,M3031    		;28FC 313130	<M3031>
L28FF:	JR   NC,L2931    		;28FF 3030	<L2931>
L2901:	JR   NC,L2933    		;2901 3030	<L2933>
L2903:	JR   NC,L2935    		;2903 3030	<L2935>
L2905:	JR   NC,L2937    		;2905 3030	<L2937>
	JR   NC,L2939    		;2907 3030	<L2939>
L2909:	JR   NC,L293B    		;2909 3030	<L293B>
L290B:	JR   NC,L293D    		;290B 3030	<L293D>
L290D:	JR   NC,L293F    		;290D 3030	<L293F>
L290F:	LD   B,C     			;290F 41
	JR   NC,L2942    		;2910 3030	<L2942>
	JR   NC,L2944    		;2912 3030	<L2944>
	JR   NC,L2946    		;2914 3030	<L2946>
	JR   NC,L2948    		;2916 3030	<L2948>
L2918:	JR   NC,L294E    		;2918 3034	<L294E>
L291A:	JR   NC,L294C    		;291A 3030	<L294C>
	JR   NC,L294E    		;291C 3030	<L294E>
	JR   NC,L2950    		;291E 3030	<L2950>
	JR   NC,L2952    		;2920 3030	<L2952>
	JR   NC,L2954    		;2922 3030	<L2954>
	JR   NC,L2967    		;2924 3041	<L2967>
	JR   NC,L2958    		;2926 3030	<L2958>
	JR   NC,L295B    		;2928 3031	<L295B>
	JR   NC,L295C    		;292A 3030	<L295C>
	JR   NC,L295E    		;292C 3030	<L295E>
	JR   NC,L2960    		;292E 3030	<L2960>
	JR   NC,L2962    		;2930 3030	<L2962>
	JR   NC,L2964    		;2932 3030	<L2964>
	JR   NC,L2966    		;2934 3030	<L2966>
	JR   NC,L2969    		;2936 3031	<L2969>
	JR   NC,L296B    		;2938 3031	<L296B>
	LD   B,(HL)  			;293A 46
L293B:	LD   B,L     			;293B 45
	JR   NC,L2970    		;293C 3032	<L2970>
	LD   B,(HL)  			;293E 46
L293F:	LD   B,L     			;293F 45
	JR   NC,L2973    		;2940 3031	<L2973>
L2942:	LD   B,D     			;2942 42
	DEC  (HL)    			;2943 35
L2944:	DEC  C       			;2944 0D
	LD   A,(BC)  			;2945 0A
L2946:	LD   A,(M3032)   		;2946 3A3230	<M3032>
	LD   SP,M3231    		;2949 313132	<M3231>
L294C:	JR   NC,L297E    		;294C 3030	<L297E>
L294E:	JR   NC,L2980    		;294E 3030	<L2980>
L2950:	LD   SP,M4546    		;2950 314645	<M4546>
	JR   NC,L2986    		;2953 3031	<L2986>
	JR   NC,L2987    		;2955 3030	<L2987>
	JR   NC,L298A    		;2957 3031	<L298A>
	JR   NC,L298C    		;2959 3031	<L298C>
L295B:	LD   B,(HL)  			;295B 46
L295C:	LD   B,L     			;295C 45
	JR   NC,L298F    		;295D 3030	<L298F>
	JR   NC,L2993    		;295F 3032	<L2993>
	LD   SP,M3046    		;2961 314630	<M3046>
L2964:	LD   B,(HL)  			;2964 46
	LD   SP,M3146    		;2965 314631	<M3146>
	LD   B,(HL)  			;2968 46
L2969:	LD   SP,M3146    		;2969 314631	<M3146>
	LD   B,(HL)  			;296C 46
	LD   SP,M3046    		;296D 314630	<M3046>
L2970:	LD   B,(HL)  			;2970 46
	JR   NC,L29B9    		;2971 3046	<L29B9>
L2973:	JR   NC,L29BB    		;2973 3046	<L29BB>
	JR   NC,L29BD    		;2975 3046	<L29BD>
	JR   NC,L29BF    		;2977 3046	<L29BF>
	ADD  HL,SP   			;2979 39
	ADD  HL,SP   			;297A 39
	INC  SP      			;297B 33
	ADD  HL,SP   			;297C 39
	ADD  HL,SP   			;297D 39
L297E:	LD   B,(HL)  			;297E 46
	JR   NC,L29B2    		;297F 3031	<L29B2>
	LD   SP,M3043    		;2981 314330	<M3043>
	JR   NC,L29C9    		;2984 3043	<L29C9>
L2986:	INC  SP      			;2986 33
L2987:	JR   NC,L29B9    		;2987 3030	<L29B9>
	LD   B,E     			;2989 43
L298A:	DEC  (HL)    			;298A 35
	JR   NC,L29C5    		;298B 3038	<L29C5>
	JR   NC,L29D1    		;298D 3042	<L29D1>
L298F:	SCF          			;298F 37
	JR   NC,L299F    		;2990 300D	<L299F>
	LD   A,(BC)  			;2992 0A
L2993:	LD   A,(M3032)   		;2993 3A3230	<M3032>
	LD   SP,M3431    		;2996 313134	<M3431>
	JR   NC,L29CB    		;2999 3030	<L29CB>
	JR   NC,L29CD    		;299B 3030	<L29CD>
	JR   NC,L29CF    		;299D 3030	<L29CF>
L299F:	ADD  HL,SP   			;299F 39
	JR   NC,L29D2    		;29A0 3030	<L29D2>
	LD   B,L     			;29A2 45
	LD   B,(HL)  			;29A3 46
	JR   NC,L29D7    		;29A4 3031	<L29D7>
	LD   (HL),33H  			;29A6 3633	<33H>
	JR   NC,L29DA    		;29A8 3030	<L29DA>
	LD   B,L     			;29AA 45
	LD   B,L     			;29AB 45
	JR   NC,L29E0    		;29AC 3032	<L29E0>
	LD   B,E     			;29AE 43
	DEC  (HL)    			;29AF 35
	JR   NC,L29EA    		;29B0 3038	<L29EA>
L29B2:	JR   NC,L29F6    		;29B2 3042	<L29F6>
	JR   NC,L29E6    		;29B4 3030	<L29E6>
	JR   NC,L29F1    		;29B6 3039	<L29F1>
	JR   NC,L29EA    		;29B8 3030	<L29EA>
	JR   NC,L29F1    		;29BA 3035	<L29F1>
	JR   NC,L29EE    		;29BC 3030	<L29EE>
	JR   NC,L29F1    		;29BE 3031	<L29F1>
	JR   NC,L29F2    		;29C0 3030	<L29F2>
	JR   NC,L29FC    		;29C2 3038	<L29FC>
	JR   NC,L29F6    		;29C4 3030	<L29F6>
	INC  (HL)    			;29C6 34
	ADD  HL,SP   			;29C7 39
	LD   SP,M3932    		;29C8 313239	<M3932>
L29CB:	LD   B,(HL)  			;29CB 46
	JR   NC,L29FF    		;29CC 3031	<L29FF>
	LD   SP,M3043    		;29CE 314330	<M3043>
L29D1:	JR   NC,L2A16    		;29D1 3043	<L2A16>
	INC  SP      			;29D3 33
	JR   NC,L2A06    		;29D4 3030	<L2A06>
	LD   B,E     			;29D6 43
L29D7:	DEC  (HL)    			;29D7 35
	JR   NC,L2A12    		;29D8 3038	<L2A12>
L29DA:	JR   NC,L2A1E    		;29DA 3042	<L2A1E>
	LD   B,C     			;29DC 41
	LD   (M0A0D),A   		;29DD 320D0A	<M0A0D>
L29E0:	LD   A,(M3032)   		;29E0 3A3230	<M3032>
	LD   SP,M3631    		;29E3 313136	<M3631>
L29E6:	JR   NC,L2A18    		;29E6 3030	<L2A18>
	JR   NC,L2A1A    		;29E8 3030	<L2A1A>
L29EA:	JR   NC,L2A1C    		;29EA 3030	<L2A1C>
	LD   B,C     			;29EC 41
	JR   NC,L2A1F    		;29ED 3030	<L2A1F>
	LD   B,L     			;29EF 45
	LD   B,(HL)  			;29F0 46
L29F1:	JR   NC,L2A24    		;29F1 3031	<L2A24>
	LD   (HL),33H  			;29F3 3633	<33H>
	JR   NC,L2A27    		;29F5 3030	<L2A27>
	LD   B,L     			;29F7 45
	LD   B,L     			;29F8 45
	JR   NC,L2A2D    		;29F9 3032	<L2A2D>
	LD   B,E     			;29FB 43
L29FC:	DEC  (HL)    			;29FC 35
	JR   NC,L2A37    		;29FD 3038	<L2A37>
L29FF:	JR   NC,L2A43    		;29FF 3042	<L2A43>
	JR   NC,L2A33    		;2A01 3030	<L2A33>
	JR   NC,L2A46    		;2A03 3041	<L2A46>
	JR   NC,L2A37    		;2A05 3030	<L2A37>
	JR   NC,L2A3F    		;2A07 3036	<L2A3F>
	JR   NC,L2A3B    		;2A09 3030	<L2A3B>
	JR   NC,L2A3E    		;2A0B 3031	<L2A3E>
	JR   NC,L2A3F    		;2A0D 3030	<L2A3F>
	JR   NC,L2A49    		;2A0F 3038	<L2A49>
	JR   NC,L2A43    		;2A11 3030	<L2A43>
	INC  (HL)    			;2A13 34
	ADD  HL,SP   			;2A14 39
	LD   SP,M3932    		;2A15 313239	<M3932>
L2A18:	LD   B,(HL)  			;2A18 46
	JR   NC,L2A4C    		;2A19 3031	<L2A4C>
	LD   SP,M3043    		;2A1B 314330	<M3043>
L2A1E:	JR   NC,L2A63    		;2A1E 3043	<L2A63>
	INC  SP      			;2A20 33
	JR   NC,L2A53    		;2A21 3030	<L2A53>
	LD   B,E     			;2A23 43
L2A24:	DEC  (HL)    			;2A24 35
	JR   NC,L2A5F    		;2A25 3038	<L2A5F>
L2A27:	JR   NC,L2A6B    		;2A27 3042	<L2A6B>
	SCF          			;2A29 37
	LD   B,(HL)  			;2A2A 46
	DEC  C       			;2A2B 0D
	LD   A,(BC)  			;2A2C 0A
L2A2D:	LD   A,(M3032)   		;2A2D 3A3230	<M3032>
	LD   SP,M3831    		;2A30 313138	<M3831>
L2A33:	JR   NC,L2A65    		;2A33 3030	<L2A65>
	JR   NC,L2A67    		;2A35 3030	<L2A67>
L2A37:	JR   NC,L2A69    		;2A37 3030	<L2A69>
	LD   B,D     			;2A39 42
	JR   NC,L2A6C    		;2A3A 3030	<L2A6C>
	LD   B,L     			;2A3C 45
	LD   B,(HL)  			;2A3D 46
L2A3E:	JR   NC,L2A71    		;2A3E 3031	<L2A71>
	LD   (HL),33H  			;2A40 3633	<33H>
	JR   NC,L2A74    		;2A42 3030	<L2A74>
	LD   B,L     			;2A44 45
	LD   B,L     			;2A45 45
L2A46:	JR   NC,L2A7A    		;2A46 3032	<L2A7A>
	LD   B,E     			;2A48 43
L2A49:	DEC  (HL)    			;2A49 35
	JR   NC,L2A84    		;2A4A 3038	<L2A84>
L2A4C:	JR   NC,L2A90    		;2A4C 3042	<L2A90>
	JR   NC,L2A80    		;2A4E 3030	<L2A80>
	JR   NC,L2A94    		;2A50 3042	<L2A94>
	JR   NC,L2A84    		;2A52 3030	<L2A84>
	JR   NC,L2A8D    		;2A54 3037	<L2A8D>
	JR   NC,L2A88    		;2A56 3030	<L2A88>
	JR   NC,L2A8B    		;2A58 3031	<L2A8B>
	JR   NC,L2A8C    		;2A5A 3030	<L2A8C>
	JR   NC,L2A96    		;2A5C 3038	<L2A96>
	JR   NC,L2A90    		;2A5E 3030	<L2A90>
	INC  (HL)    			;2A60 34
	ADD  HL,SP   			;2A61 39
	LD   SP,M3932    		;2A62 313239	<M3932>
L2A65:	LD   B,(HL)  			;2A65 46
	JR   NC,L2A99    		;2A66 3031	<L2A99>
	LD   SP,M3043    		;2A68 314330	<M3043>
L2A6B:	JR   NC,L2AB0    		;2A6B 3043	<L2AB0>
	INC  SP      			;2A6D 33
	JR   NC,L2AA0    		;2A6E 3030	<L2AA0>
	LD   B,E     			;2A70 43
L2A71:	DEC  (HL)    			;2A71 35
	JR   NC,L2AAC    		;2A72 3038	<L2AAC>
L2A74:	JR   NC,L2AB8    		;2A74 3042	<L2AB8>
	DEC  (HL)    			;2A76 35
	LD   B,E     			;2A77 43
	DEC  C       			;2A78 0D
	LD   A,(BC)  			;2A79 0A
L2A7A:	LD   A,(M3032)   		;2A7A 3A3230	<M3032>
	LD   SP,M4131    		;2A7D 313141	<M4131>
L2A80:	JR   NC,L2AB2    		;2A80 3030	<L2AB2>
	JR   NC,L2AB4    		;2A82 3030	<L2AB4>
L2A84:	JR   NC,L2AB6    		;2A84 3030	<L2AB6>
	LD   B,E     			;2A86 43
	JR   NC,L2AB9    		;2A87 3030	<L2AB9>
	LD   B,L     			;2A89 45
	LD   B,(HL)  			;2A8A 46
L2A8B:	JR   NC,L2ABE    		;2A8B 3031	<L2ABE>
L2A8D:	LD   (HL),33H  			;2A8D 3633	<33H>
	JR   NC,L2AC1    		;2A8F 3030	<L2AC1>
	LD   B,L     			;2A91 45
	LD   B,L     			;2A92 45
	JR   NC,L2AC7    		;2A93 3032	<L2AC7>
	LD   B,E     			;2A95 43
L2A96:	DEC  (HL)    			;2A96 35
	JR   NC,L2AD1    		;2A97 3038	<L2AD1>
L2A99:	JR   NC,L2ADD    		;2A99 3042	<L2ADD>
	JR   NC,L2ACD    		;2A9B 3030	<L2ACD>
	JR   NC,L2AE2    		;2A9D 3043	<L2AE2>
	JR   NC,L2AD1    		;2A9F 3030	<L2AD1>
	JR   NC,L2ADB    		;2AA1 3038	<L2ADB>
	JR   NC,L2AD5    		;2AA3 3030	<L2AD5>
	JR   NC,L2AD8    		;2AA5 3031	<L2AD8>
	JR   NC,L2AD9    		;2AA7 3030	<L2AD9>
	JR   NC,L2AE3    		;2AA9 3038	<L2AE3>
	JR   NC,L2ADD    		;2AAB 3030	<L2ADD>
	INC  (HL)    			;2AAD 34
	ADD  HL,SP   			;2AAE 39
	LD   SP,M3932    		;2AAF 313239	<M3932>
L2AB2:	LD   B,(HL)  			;2AB2 46
	JR   NC,L2AE6    		;2AB3 3031	<L2AE6>
	LD   SP,M3043    		;2AB5 314330	<M3043>
L2AB8:	JR   NC,L2AFD    		;2AB8 3043	<L2AFD>
	INC  SP      			;2ABA 33
	JR   NC,L2AED    		;2ABB 3030	<L2AED>
	LD   B,E     			;2ABD 43
L2ABE:	DEC  (HL)    			;2ABE 35
	JR   NC,L2AF9    		;2ABF 3038	<L2AF9>
L2AC1:	JR   NC,L2B06    		;2AC1 3043	<L2B06>
	INC  SP      			;2AC3 33
	JR   C,L2AD3     		;2AC4 380D	<L2AD3>
	LD   A,(BC)  			;2AC6 0A
L2AC7:	LD   A,(M3032)   		;2AC7 3A3230	<M3032>
	LD   SP,M4331    		;2ACA 313143	<M4331>
L2ACD:	JR   NC,L2AFF    		;2ACD 3030	<L2AFF>
	JR   NC,L2B01    		;2ACF 3030	<L2B01>
L2AD1:	JR   NC,L2B03    		;2AD1 3030	<L2B03>
L2AD3:	LD   B,H     			;2AD3 44
	JR   NC,L2B06    		;2AD4 3030	<L2B06>
	LD   B,L     			;2AD6 45
	LD   B,(HL)  			;2AD7 46
L2AD8:	JR   NC,L2B0B    		;2AD8 3031	<L2B0B>
	LD   (HL),33H  			;2ADA 3633	<33H>
	JR   NC,L2B0E    		;2ADC 3030	<L2B0E>
	LD   B,L     			;2ADE 45
	LD   B,L     			;2ADF 45
	JR   NC,L2B14    		;2AE0 3032	<L2B14>
L2AE2:	LD   B,E     			;2AE2 43
L2AE3:	DEC  (HL)    			;2AE3 35
	JR   NC,L2B1E    		;2AE4 3038	<L2B1E>
L2AE6:	JR   NC,L2B2B    		;2AE6 3043	<L2B2B>
	JR   NC,L2B1A    		;2AE8 3030	<L2B1A>
	JR   NC,L2B30    		;2AEA 3044	<L2B30>
	JR   NC,L2B1E    		;2AEC 3030	<L2B1E>
	JR   NC,L2B29    		;2AEE 3039	<L2B29>
	JR   NC,L2B22    		;2AF0 3030	<L2B22>
	JR   NC,L2B25    		;2AF2 3031	<L2B25>
	JR   NC,L2B26    		;2AF4 3030	<L2B26>
	JR   NC,L2B30    		;2AF6 3038	<L2B30>
	JR   NC,L2B2A    		;2AF8 3030	<L2B2A>
	INC  (HL)    			;2AFA 34
	ADD  HL,SP   			;2AFB 39
	LD   SP,M3932    		;2AFC 313239	<M3932>
L2AFF:	LD   B,(HL)  			;2AFF 46
	JR   NC,L2B33    		;2B00 3031	<L2B33>
	LD   SP,M3043    		;2B02 314330	<M3043>
	JR   NC,L2B4A    		;2B05 3043	<L2B4A>
	INC  SP      			;2B07 33
	JR   NC,L2B3A    		;2B08 3030	<L2B3A>
	LD   B,E     			;2B0A 43
L2B0B:	DEC  (HL)    			;2B0B 35
	JR   NC,L2B46    		;2B0C 3038	<L2B46>
L2B0E:	JR   NC,L2B54    		;2B0E 3044	<L2B54>
	LD   SP,M0D33    		;2B10 31330D	<M0D33>
	LD   A,(BC)  			;2B13 0A
L2B14:	LD   A,(M3032)   		;2B14 3A3230	<M3032>
	LD   SP,M4531    		;2B17 313145	<M4531>
L2B1A:	JR   NC,L2B4C    		;2B1A 3030	<L2B4C>
	JR   NC,L2B4E    		;2B1C 3030	<L2B4E>
L2B1E:	JR   NC,L2B50    		;2B1E 3030	<L2B50>
	LD   B,H     			;2B20 44
	JR   NC,L2B53    		;2B21 3030	<L2B53>
	LD   B,L     			;2B23 45
	LD   B,(HL)  			;2B24 46
L2B25:	JR   NC,L2B58    		;2B25 3031	<L2B58>
	LD   (HL),33H  			;2B27 3633	<33H>
L2B29:	JR   NC,L2B5B    		;2B29 3030	<L2B5B>
L2B2B:	LD   B,L     			;2B2B 45
	LD   B,L     			;2B2C 45
	JR   NC,L2B61    		;2B2D 3032	<L2B61>
	LD   B,E     			;2B2F 43
L2B30:	DEC  (HL)    			;2B30 35
	JR   NC,L2B6B    		;2B31 3038	<L2B6B>
L2B33:	JR   NC,L2B79    		;2B33 3044	<L2B79>
	JR   NC,L2B67    		;2B35 3030	<L2B67>
	JR   NC,L2B7D    		;2B37 3044	<L2B7D>
	JR   NC,L2B6B    		;2B39 3030	<L2B6B>
	JR   NC,L2B7E    		;2B3B 3041	<L2B7E>
	JR   NC,L2B6F    		;2B3D 3030	<L2B6F>
	JR   NC,L2B72    		;2B3F 3031	<L2B72>
	JR   NC,L2B73    		;2B41 3030	<L2B73>
	JR   NC,L2B7D    		;2B43 3038	<L2B7D>
	JR   NC,L2B77    		;2B45 3030	<L2B77>
	INC  (HL)    			;2B47 34
	ADD  HL,SP   			;2B48 39
	LD   SP,M3332    		;2B49 313233	<M3332>
L2B4C:	JR   NC,L2B7E    		;2B4C 3030	<L2B7E>
L2B4E:	LD   (M4431),A   		;2B4E 323144	<M4431>
	JR   NC,L2B83    		;2B51 3030	<L2B83>
L2B53:	LD   B,L     			;2B53 45
L2B54:	LD   B,(HL)  			;2B54 46
	JR   NC,L2B88    		;2B55 3031	<L2B88>
	LD   B,E     			;2B57 43
L2B58:	DEC  (HL)    			;2B58 35
	JR   NC,L2B93    		;2B59 3038	<L2B93>
L2B5B:	LD   SP,M3241    		;2B5B 314132	<M3241>
	INC  (HL)    			;2B5E 34
	DEC  C       			;2B5F 0D
	LD   A,(BC)  			;2B60 0A
L2B61:	LD   A,(M3032)   		;2B61 3A3230	<M3032>
	LD   SP,M3032    		;2B64 313230	<M3032>
L2B67:	JR   NC,L2B99    		;2B67 3030	<L2B99>
	JR   NC,L2B9B    		;2B69 3030	<L2B9B>
L2B6B:	JR   NC,L2B9E    		;2B6B 3031	<L2B9E>
	JR   C,L2B9F     		;2B6D 3830	<L2B9F>
L2B6F:	JR   NC,L2BA6    		;2B6F 3035	<L2BA6>
	JR   C,L2BA3     		;2B71 3830	<L2BA3>
L2B73:	LD   (M3843),A   		;2B73 324338	<M3843>
	JR   NC,L2BA8    		;2B76 3030	<L2BA8>
	SCF          			;2B78 37
L2B79:	LD   (M3630),A   		;2B79 323036	<M3630>
	LD   B,E     			;2B7C 43
L2B7D:	DEC  (HL)    			;2B7D 35
L2B7E:	JR   NC,L2BB8    		;2B7E 3038	<L2BB8>
	LD   SP,M3041    		;2B80 314130	<M3041>
L2B83:	JR   NC,L2BB6    		;2B83 3031	<L2BB6>
	JR   C,L2BB7     		;2B85 3830	<L2BB7>
	JR   NC,L2BBA    		;2B87 3031	<L2BBA>
	LD   B,L     			;2B89 45
	JR   NC,L2BBC    		;2B8A 3030	<L2BBC>
	DEC  (HL)    			;2B8C 35
	LD   B,C     			;2B8D 41
	JR   NC,L2BC0    		;2B8E 3030	<L2BC0>
	LD   B,H     			;2B90 44
	JR   NC,L2BC3    		;2B91 3030	<L2BC3>
L2B93:	SCF          			;2B93 37
	INC  (HL)    			;2B94 34
	ADD  HL,SP   			;2B95 39
	LD   SP,M3332    		;2B96 313233	<M3332>
L2B99:	JR   NC,L2BCB    		;2B99 3030	<L2BCB>
L2B9B:	LD   (M4431),A   		;2B9B 323144	<M4431>
L2B9E:	JR   NC,L2BD0    		;2B9E 3030	<L2BD0>
	LD   B,L     			;2BA0 45
	LD   B,(HL)  			;2BA1 46
	JR   NC,L2BD5    		;2BA2 3031	<L2BD5>
	LD   B,E     			;2BA4 43
	DEC  (HL)    			;2BA5 35
L2BA6:	JR   NC,L2BE0    		;2BA6 3038	<L2BE0>
L2BA8:	LD   SP,M3441    		;2BA8 314134	<M3441>
	LD   B,H     			;2BAB 44
	DEC  C       			;2BAC 0D
	LD   A,(BC)  			;2BAD 0A
	LD   A,(M3032)   		;2BAE 3A3230	<M3032>
	LD   SP,M3232    		;2BB1 313232	<M3232>
	JR   NC,L2BE6    		;2BB4 3030	<L2BE6>
L2BB6:	JR   NC,L2BE8    		;2BB6 3030	<L2BE8>
L2BB8:	JR   NC,L2BEB    		;2BB8 3031	<L2BEB>
L2BBA:	ADD  HL,SP   			;2BBA 39
	JR   NC,L2BED    		;2BBB 3030	<L2BED>
	DEC  (HL)    			;2BBD 35
	JR   C,L2BF0     		;2BBE 3830	<L2BF0>
L2BC0:	LD   (M3843),A   		;2BC0 324338	<M3843>
L2BC3:	JR   NC,L2BF5    		;2BC3 3030	<L2BF5>
	SCF          			;2BC5 37
	LD   (M3630),A   		;2BC6 323036	<M3630>
	LD   B,E     			;2BC9 43
	DEC  (HL)    			;2BCA 35
L2BCB:	JR   NC,L2C05    		;2BCB 3038	<L2C05>
	LD   SP,M3041    		;2BCD 314130	<M3041>
L2BD0:	JR   NC,L2C03    		;2BD0 3031	<L2C03>
	ADD  HL,SP   			;2BD2 39
	JR   NC,L2C05    		;2BD3 3030	<L2C05>
L2BD5:	LD   SP,M3045    		;2BD5 314530	<M3045>
	JR   NC,L2C0F    		;2BD8 3035	<L2C0F>
	LD   B,C     			;2BDA 41
	JR   NC,L2C0D    		;2BDB 3030	<L2C0D>
	LD   B,H     			;2BDD 44
	LD   SP,M3730    		;2BDE 313037	<M3730>
	INC  (HL)    			;2BE1 34
	ADD  HL,SP   			;2BE2 39
	LD   SP,M3332    		;2BE3 313233	<M3332>
L2BE6:	JR   NC,L2C18    		;2BE6 3030	<L2C18>
L2BE8:	LD   (M4431),A   		;2BE8 323144	<M4431>
L2BEB:	JR   NC,L2C1D    		;2BEB 3030	<L2C1D>
L2BED:	LD   B,L     			;2BED 45
	LD   B,(HL)  			;2BEE 46
	JR   NC,L2C22    		;2BEF 3031	<L2C22>
	LD   B,E     			;2BF1 43
	DEC  (HL)    			;2BF2 35
	JR   NC,L2C2D    		;2BF3 3038	<L2C2D>
L2BF5:	LD   SP,M3241    		;2BF5 314132	<M3241>
	LD   B,C     			;2BF8 41
	DEC  C       			;2BF9 0D
	LD   A,(BC)  			;2BFA 0A
	LD   A,(M3032)   		;2BFB 3A3230	<M3032>
	LD   SP,M3432    		;2BFE 313234	<M3432>
	JR   NC,L2C33    		;2C01 3030	<L2C33>
L2C03:	JR   NC,L2C35    		;2C03 3030	<L2C35>
L2C05:	JR   NC,L2C38    		;2C05 3031	<L2C38>
	LD   B,C     			;2C07 41
	JR   NC,L2C3A    		;2C08 3030	<L2C3A>
	DEC  (HL)    			;2C0A 35
	JR   C,L2C3D     		;2C0B 3830	<L2C3D>
L2C0D:	LD   (M3843),A   		;2C0D 324338	<M3843>
	JR   NC,L2C42    		;2C10 3030	<L2C42>
	SCF          			;2C12 37
	LD   (M3630),A   		;2C13 323036	<M3630>
	LD   B,E     			;2C16 43
	DEC  (HL)    			;2C17 35
L2C18:	JR   NC,L2C52    		;2C18 3038	<L2C52>
	LD   SP,M3041    		;2C1A 314130	<M3041>
L2C1D:	JR   NC,L2C50    		;2C1D 3031	<L2C50>
	LD   B,C     			;2C1F 41
	JR   NC,L2C52    		;2C20 3030	<L2C52>
L2C22:	LD   SP,M3045    		;2C22 314530	<M3045>
	JR   NC,L2C5C    		;2C25 3035	<L2C5C>
	LD   B,C     			;2C27 41
	JR   NC,L2C5A    		;2C28 3030	<L2C5A>
	LD   B,H     			;2C2A 44
	LD   (M3730),A   		;2C2B 323037	<M3730>
	INC  (HL)    			;2C2E 34
	ADD  HL,SP   			;2C2F 39
	LD   SP,M3332    		;2C30 313233	<M3332>
L2C33:	JR   NC,L2C65    		;2C33 3030	<L2C65>
L2C35:	LD   (M4431),A   		;2C35 323144	<M4431>
L2C38:	JR   NC,L2C6A    		;2C38 3030	<L2C6A>
L2C3A:	LD   B,L     			;2C3A 45
	LD   B,(HL)  			;2C3B 46
	JR   NC,L2C6F    		;2C3C 3031	<L2C6F>
	LD   B,E     			;2C3E 43
	DEC  (HL)    			;2C3F 35
	JR   NC,L2C7A    		;2C40 3038	<L2C7A>
L2C42:	LD   SP,M3043    		;2C42 314330	<M3043>
	DEC  (HL)    			;2C45 35
	DEC  C       			;2C46 0D
	LD   A,(BC)  			;2C47 0A
	LD   A,(M3032)   		;2C48 3A3230	<M3032>
	LD   SP,M3632    		;2C4B 313236	<M3632>
	JR   NC,L2C80    		;2C4E 3030	<L2C80>
L2C50:	JR   NC,L2C82    		;2C50 3030	<L2C82>
L2C52:	JR   NC,L2C85    		;2C52 3031	<L2C85>
	LD   B,C     			;2C54 41
	JR   NC,L2C87    		;2C55 3030	<L2C87>
	DEC  (HL)    			;2C57 35
	JR   C,L2C8A     		;2C58 3830	<L2C8A>
L2C5A:	LD   (M3843),A   		;2C5A 324338	<M3843>
	JR   NC,L2C8F    		;2C5D 3030	<L2C8F>
	SCF          			;2C5F 37
	LD   (M3630),A   		;2C60 323036	<M3630>
	LD   B,E     			;2C63 43
	DEC  (HL)    			;2C64 35
L2C65:	JR   NC,L2C9F    		;2C65 3038	<L2C9F>
	LD   SP,M3043    		;2C67 314330	<M3043>
L2C6A:	JR   NC,L2C9D    		;2C6A 3031	<L2C9D>
	LD   B,C     			;2C6C 41
	JR   NC,L2C9F    		;2C6D 3030	<L2C9F>
L2C6F:	LD   SP,M3045    		;2C6F 314530	<M3045>
	JR   NC,L2CA9    		;2C72 3035	<L2CA9>
	LD   B,C     			;2C74 41
	JR   NC,L2CA7    		;2C75 3030	<L2CA7>
	LD   B,H     			;2C77 44
	INC  SP      			;2C78 33
	JR   NC,L2CB2    		;2C79 3037	<L2CB2>
	INC  (HL)    			;2C7B 34
	ADD  HL,SP   			;2C7C 39
	LD   SP,M3332    		;2C7D 313233	<M3332>
L2C80:	JR   NC,L2CB2    		;2C80 3030	<L2CB2>
L2C82:	LD   (M4431),A   		;2C82 323144	<M4431>
L2C85:	JR   NC,L2CB7    		;2C85 3030	<L2CB7>
L2C87:	LD   B,L     			;2C87 45
	LD   B,(HL)  			;2C88 46
	JR   NC,L2CBC    		;2C89 3031	<L2CBC>
	LD   B,E     			;2C8B 43
	DEC  (HL)    			;2C8C 35
	JR   NC,L2CC7    		;2C8D 3038	<L2CC7>
L2C8F:	LD   SP,M4545    		;2C8F 314545	<M4545>
	JR   NC,L2CA1    		;2C92 300D	<L2CA1>
	LD   A,(BC)  			;2C94 0A
	LD   A,(M3032)   		;2C95 3A3230	<M3032>
	LD   SP,M3832    		;2C98 313238	<M3832>
	JR   NC,L2CCD    		;2C9B 3030	<L2CCD>
L2C9D:	JR   NC,L2CCF    		;2C9D 3030	<L2CCF>
L2C9F:	JR   NC,L2CD2    		;2C9F 3031	<L2CD2>
L2CA1:	LD   B,C     			;2CA1 41
	JR   NC,L2CD4    		;2CA2 3030	<L2CD4>
	DEC  (HL)    			;2CA4 35
	JR   C,L2CD7     		;2CA5 3830	<L2CD7>
L2CA7:	LD   (M3843),A   		;2CA7 324338	<M3843>
	JR   NC,L2CDC    		;2CAA 3030	<L2CDC>
	SCF          			;2CAC 37
	LD   (M3630),A   		;2CAD 323036	<M3630>
	LD   B,E     			;2CB0 43
	DEC  (HL)    			;2CB1 35
L2CB2:	JR   NC,L2CEC    		;2CB2 3038	<L2CEC>
	LD   SP,M3045    		;2CB4 314530	<M3045>
L2CB7:	JR   NC,L2CEA    		;2CB7 3031	<L2CEA>
	LD   B,C     			;2CB9 41
	JR   NC,L2CEC    		;2CBA 3030	<L2CEC>
L2CBC:	LD   SP,M3045    		;2CBC 314530	<M3045>
	JR   NC,L2CF6    		;2CBF 3035	<L2CF6>
	LD   B,C     			;2CC1 41
	JR   NC,L2CF4    		;2CC2 3030	<L2CF4>
	LD   B,H     			;2CC4 44
	INC  (HL)    			;2CC5 34
	JR   NC,L2CFF    		;2CC6 3037	<L2CFF>
	INC  (HL)    			;2CC8 34
	ADD  HL,SP   			;2CC9 39
	LD   SP,M3332    		;2CCA 313233	<M3332>
L2CCD:	JR   NC,L2CFF    		;2CCD 3030	<L2CFF>
L2CCF:	LD   (M4431),A   		;2CCF 323144	<M4431>
L2CD2:	JR   NC,L2D04    		;2CD2 3030	<L2D04>
L2CD4:	LD   B,L     			;2CD4 45
	LD   B,(HL)  			;2CD5 46
	JR   NC,L2D09    		;2CD6 3031	<L2D09>
	LD   B,E     			;2CD8 43
	DEC  (HL)    			;2CD9 35
	JR   NC,L2D14    		;2CDA 3038	<L2D14>
L2CDC:	LD   (M4230),A   		;2CDC 323042	<M4230>
	LD   B,D     			;2CDF 42
	DEC  C       			;2CE0 0D
	LD   A,(BC)  			;2CE1 0A
	LD   A,(M3032)   		;2CE2 3A3230	<M3032>
	LD   SP,M4132    		;2CE5 313241	<M4132>
	JR   NC,L2D1A    		;2CE8 3030	<L2D1A>
L2CEA:	JR   NC,L2D1C    		;2CEA 3030	<L2D1C>
L2CEC:	JR   NC,L2D1F    		;2CEC 3031	<L2D1F>
	LD   B,C     			;2CEE 41
	JR   NC,L2D21    		;2CEF 3030	<L2D21>
	DEC  (HL)    			;2CF1 35
	JR   C,L2D24     		;2CF2 3830	<L2D24>
L2CF4:	LD   (M3843),A   		;2CF4 324338	<M3843>
	JR   NC,L2D29    		;2CF7 3030	<L2D29>
	SCF          			;2CF9 37
	LD   (M3630),A   		;2CFA 323036	<M3630>
	LD   B,E     			;2CFD 43
	DEC  (HL)    			;2CFE 35
L2CFF:	JR   NC,L2D39    		;2CFF 3038	<L2D39>
	LD   (M3030),A   		;2D01 323030	<M3030>
L2D04:	JR   NC,L2D37    		;2D04 3031	<L2D37>
	LD   B,C     			;2D06 41
	JR   NC,L2D39    		;2D07 3030	<L2D39>
L2D09:	LD   SP,M3045    		;2D09 314530	<M3045>
	JR   NC,L2D43    		;2D0C 3035	<L2D43>
	LD   B,C     			;2D0E 41
	JR   NC,L2D41    		;2D0F 3030	<L2D41>
	LD   B,H     			;2D11 44
	DEC  (HL)    			;2D12 35
	JR   NC,L2D4C    		;2D13 3037	<L2D4C>
	INC  (HL)    			;2D15 34
	ADD  HL,SP   			;2D16 39
	LD   SP,M3132    		;2D17 313231	<M3132>
L2D1A:	JR   NC,L2D4C    		;2D1A 3030	<L2D4C>
L2D1C:	INC  (HL)    			;2D1C 34
	LD   SP,M3045    		;2D1D 314530	<M3045>
	JR   NC,L2D52    		;2D20 3030	<L2D52>
	INC  SP      			;2D22 33
	JR   NC,L2D57    		;2D23 3032	<L2D57>
	LD   B,E     			;2D25 43
	DEC  (HL)    			;2D26 35
	JR   NC,L2D61    		;2D27 3038	<L2D61>
L2D29:	INC  SP      			;2D29 33
	SCF          			;2D2A 37
	JR   C,L2D66     		;2D2B 3839	<L2D66>
	DEC  C       			;2D2D 0D
	LD   A,(BC)  			;2D2E 0A
	LD   A,(M3032)   		;2D2F 3A3230	<M3032>
	LD   SP,M4332    		;2D32 313243	<M4332>
	JR   NC,L2D67    		;2D35 3030	<L2D67>
L2D37:	JR   NC,L2D69    		;2D37 3030	<L2D69>
L2D39:	JR   NC,L2D6D    		;2D39 3032	<L2D6D>
	LD   B,D     			;2D3B 42
	JR   NC,L2D6E    		;2D3C 3030	<L2D6E>
	LD   B,L     			;2D3E 45
	LD   B,C     			;2D3F 41
	JR   NC,L2D84    		;2D40 3042	<L2D84>
	LD   B,H     			;2D42 44
L2D43:	LD   (M3030),A   		;2D43 323030	<M3030>
	LD   B,H     			;2D46 44
	JR   NC,L2D79    		;2D47 3030	<L2D79>
	SCF          			;2D49 37
	LD   B,E     			;2D4A 43
	DEC  (HL)    			;2D4B 35
L2D4C:	JR   NC,L2D86    		;2D4C 3038	<L2D86>
	INC  SP      			;2D4E 33
	SCF          			;2D4F 37
	JR   NC,L2D82    		;2D50 3030	<L2D82>
L2D52:	LD   (M3042),A   		;2D52 324230	<M3042>
	JR   NC,L2D8A    		;2D55 3033	<L2D8A>
L2D57:	LD   (M3030),A   		;2D57 323030	<M3030>
	LD   (HL),34H  			;2D5A 3634	<34H>
	JR   NC,L2D8E    		;2D5C 3030	<L2D8E>
	JR   C,L2D98     		;2D5E 3838	<L2D98>
	LD   SP,M3433    		;2D60 313334	<M3433>
	ADD  HL,SP   			;2D63 39
	LD   SP,M3132    		;2D64 313231	<M3132>
L2D67:	JR   NC,L2D99    		;2D67 3030	<L2D99>
L2D69:	INC  (HL)    			;2D69 34
	LD   SP,M3045    		;2D6A 314530	<M3045>
L2D6D:	JR   NC,L2D9F    		;2D6D 3030	<L2D9F>
	INC  SP      			;2D6F 33
	JR   NC,L2DA4    		;2D70 3032	<L2DA4>
	LD   B,E     			;2D72 43
	DEC  (HL)    			;2D73 35
	JR   NC,L2DAE    		;2D74 3038	<L2DAE>
	INC  SP      			;2D76 33
	LD   B,C     			;2D77 41
	INC  (HL)    			;2D78 34
L2D79:	LD   B,E     			;2D79 43
	DEC  C       			;2D7A 0D
	LD   A,(BC)  			;2D7B 0A
	LD   A,(M3032)   		;2D7C 3A3230	<M3032>
	LD   SP,M4532    		;2D7F 313245	<M4532>
L2D82:	JR   NC,L2DB4    		;2D82 3030	<L2DB4>
L2D84:	JR   NC,L2DB6    		;2D84 3030	<L2DB6>
L2D86:	JR   NC,L2DBA    		;2D86 3032	<L2DBA>
	LD   B,L     			;2D88 45
	JR   NC,L2DBB    		;2D89 3030	<L2DBB>
	LD   B,L     			;2D8B 45
	LD   B,C     			;2D8C 41
	JR   NC,L2DD1    		;2D8D 3042	<L2DD1>
	LD   B,H     			;2D8F 44
	LD   (M3030),A   		;2D90 323030	<M3030>
	LD   B,H     			;2D93 44
	JR   NC,L2DC6    		;2D94 3030	<L2DC6>
	SCF          			;2D96 37
	LD   B,E     			;2D97 43
L2D98:	DEC  (HL)    			;2D98 35
L2D99:	JR   NC,L2DD3    		;2D99 3038	<L2DD3>
	INC  SP      			;2D9B 33
	LD   B,C     			;2D9C 41
	JR   NC,L2DCF    		;2D9D 3030	<L2DCF>
L2D9F:	LD   (M3045),A   		;2D9F 324530	<M3045>
	JR   NC,L2DD7    		;2DA2 3033	<L2DD7>
L2DA4:	LD   (M3030),A   		;2DA4 323030	<M3030>
	LD   (HL),34H  			;2DA7 3634	<34H>
	JR   NC,L2DDB    		;2DA9 3030	<L2DDB>
	LD   B,L     			;2DAB 45
	LD   B,E     			;2DAC 43
	LD   SP,M3433    		;2DAD 313334	<M3433>
	ADD  HL,SP   			;2DB0 39
	LD   SP,M3132    		;2DB1 313231	<M3132>
L2DB4:	JR   NC,L2DE6    		;2DB4 3030	<L2DE6>
L2DB6:	INC  (HL)    			;2DB6 34
	LD   SP,M3045    		;2DB7 314530	<M3045>
L2DBA:	JR   NC,L2DEC    		;2DBA 3030	<L2DEC>
	INC  SP      			;2DBC 33
	JR   NC,L2DF1    		;2DBD 3032	<L2DF1>
	LD   B,E     			;2DBF 43
	DEC  (HL)    			;2DC0 35
	JR   NC,L2DFB    		;2DC1 3038	<L2DFB>
	INC  SP      			;2DC3 33
	LD   B,E     			;2DC4 43
	LD   B,D     			;2DC5 42
L2DC6:	LD   B,H     			;2DC6 44
	DEC  C       			;2DC7 0D
	LD   A,(BC)  			;2DC8 0A
	LD   A,(M3032)   		;2DC9 3A3230	<M3032>
	LD   SP,M3033    		;2DCC 313330	<M3033>
L2DCF:	JR   NC,L2E01    		;2DCF 3030	<L2E01>
L2DD1:	JR   NC,L2E03    		;2DD1 3030	<L2E03>
L2DD3:	JR   NC,L2E07    		;2DD3 3032	<L2E07>
	LD   B,(HL)  			;2DD5 46
	JR   NC,L2E08    		;2DD6 3030	<L2E08>
	LD   B,L     			;2DD8 45
	LD   B,C     			;2DD9 41
	JR   NC,L2E1E    		;2DDA 3042	<L2E1E>
	LD   B,H     			;2DDC 44
	LD   (M3030),A   		;2DDD 323030	<M3030>
	LD   B,H     			;2DE0 44
	JR   NC,L2E13    		;2DE1 3030	<L2E13>
	SCF          			;2DE3 37
	LD   B,E     			;2DE4 43
	DEC  (HL)    			;2DE5 35
L2DE6:	JR   NC,L2E20    		;2DE6 3038	<L2E20>
	INC  SP      			;2DE8 33
	LD   B,E     			;2DE9 43
	JR   NC,L2E1C    		;2DEA 3030	<L2E1C>
L2DEC:	LD   (M3046),A   		;2DEC 324630	<M3046>
	JR   NC,L2E24    		;2DEF 3033	<L2E24>
L2DF1:	LD   (M3030),A   		;2DF1 323030	<M3030>
	LD   (HL),34H  			;2DF4 3634	<34H>
	JR   NC,L2E28    		;2DF6 3030	<L2E28>
	LD   (HL),41H  			;2DF8 3641	<41H>
	LD   SP,M3438    		;2DFA 313834	<M3438>
	ADD  HL,SP   			;2DFD 39
	LD   SP,M3132    		;2DFE 313231	<M3132>
L2E01:	JR   NC,L2E33    		;2E01 3030	<L2E33>
L2E03:	INC  (HL)    			;2E03 34
	LD   SP,M3045    		;2E04 314530	<M3045>
L2E07:	JR   NC,L2E39    		;2E07 3030	<L2E39>
	INC  SP      			;2E09 33
	JR   NC,L2E3E    		;2E0A 3032	<L2E3E>
	LD   B,E     			;2E0C 43
	DEC  (HL)    			;2E0D 35
	JR   NC,L2E48    		;2E0E 3038	<L2E48>
	INC  SP      			;2E10 33
	LD   B,H     			;2E11 44
	LD   SP,M0D34    		;2E12 31340D	<M0D34>
	LD   A,(BC)  			;2E15 0A
	LD   A,(M3032)   		;2E16 3A3230	<M3032>
	LD   SP,M3233    		;2E19 313332	<M3233>
L2E1C:	JR   NC,L2E4E    		;2E1C 3030	<L2E4E>
L2E1E:	JR   NC,L2E50    		;2E1E 3030	<L2E50>
L2E20:	JR   NC,L2E55    		;2E20 3033	<L2E55>
	LD   SP,M3030    		;2E22 313030	<M3030>
	LD   B,L     			;2E25 45
	LD   B,C     			;2E26 41
	JR   NC,L2E6B    		;2E27 3042	<L2E6B>
	LD   B,H     			;2E29 44
	LD   (M3030),A   		;2E2A 323030	<M3030>
	LD   B,H     			;2E2D 44
	JR   NC,L2E60    		;2E2E 3030	<L2E60>
	SCF          			;2E30 37
	LD   B,E     			;2E31 43
	DEC  (HL)    			;2E32 35
L2E33:	JR   NC,L2E6D    		;2E33 3038	<L2E6D>
	INC  SP      			;2E35 33
	LD   B,H     			;2E36 44
	JR   NC,L2E69    		;2E37 3030	<L2E69>
L2E39:	INC  SP      			;2E39 33
	LD   SP,M3030    		;2E3A 313030	<M3030>
	INC  SP      			;2E3D 33
L2E3E:	LD   (M3030),A   		;2E3E 323030	<M3030>
	LD   (HL),34H  			;2E41 3634	<34H>
	JR   NC,L2E75    		;2E43 3030	<L2E75>
	LD   SP,M3136    		;2E45 313631	<M3136>
L2E48:	LD   B,E     			;2E48 43
	INC  (HL)    			;2E49 34
	ADD  HL,SP   			;2E4A 39
	LD   SP,M3132    		;2E4B 313231	<M3132>
L2E4E:	JR   NC,L2E80    		;2E4E 3030	<L2E80>
L2E50:	INC  (HL)    			;2E50 34
	LD   SP,M3045    		;2E51 314530	<M3045>
	JR   NC,L2E86    		;2E54 3030	<L2E86>
	INC  SP      			;2E56 33
	JR   NC,L2E8B    		;2E57 3032	<L2E8B>
	LD   B,E     			;2E59 43
	DEC  (HL)    			;2E5A 35
	JR   NC,L2E95    		;2E5B 3038	<L2E95>
	INC  (HL)    			;2E5D 34
	JR   NC,L2E93    		;2E5E 3033	<L2E93>
L2E60:	LD   B,E     			;2E60 43
	DEC  C       			;2E61 0D
	LD   A,(BC)  			;2E62 0A
	LD   A,(M3032)   		;2E63 3A3230	<M3032>
	LD   SP,M3433    		;2E66 313334	<M3433>
L2E69:	JR   NC,L2E9B    		;2E69 3030	<L2E9B>
L2E6B:	JR   NC,L2E9D    		;2E6B 3030	<L2E9D>
L2E6D:	JR   NC,L2EA2    		;2E6D 3033	<L2EA2>
	INC  SP      			;2E6F 33
	JR   NC,L2EA2    		;2E70 3030	<L2EA2>
	LD   B,L     			;2E72 45
	LD   B,C     			;2E73 41
	JR   NC,L2EB8    		;2E74 3042	<L2EB8>
	LD   B,H     			;2E76 44
	LD   (M3030),A   		;2E77 323030	<M3030>
	LD   B,H     			;2E7A 44
	JR   NC,L2EAD    		;2E7B 3030	<L2EAD>
	SCF          			;2E7D 37
	LD   B,E     			;2E7E 43
	DEC  (HL)    			;2E7F 35
L2E80:	JR   NC,L2EBA    		;2E80 3038	<L2EBA>
	INC  (HL)    			;2E82 34
	JR   NC,L2EB5    		;2E83 3030	<L2EB5>
	JR   NC,L2EBA    		;2E85 3033	<L2EBA>
	INC  SP      			;2E87 33
	JR   NC,L2EBA    		;2E88 3030	<L2EBA>
	INC  SP      			;2E8A 33
L2E8B:	LD   (M3030),A   		;2E8B 323030	<M3030>
	LD   (HL),34H  			;2E8E 3634	<34H>
	JR   NC,L2EC2    		;2E90 3030	<L2EC2>
	DEC  (HL)    			;2E92 35
L2E93:	INC  SP      			;2E93 33
	LD   SP,M3443    		;2E94 314334	<M3443>
	ADD  HL,SP   			;2E97 39
	LD   SP,M3132    		;2E98 313231	<M3132>
L2E9B:	JR   NC,L2ECD    		;2E9B 3030	<L2ECD>
L2E9D:	INC  (HL)    			;2E9D 34
	LD   SP,M3045    		;2E9E 314530	<M3045>
	JR   NC,L2ED3    		;2EA1 3030	<L2ED3>
	INC  SP      			;2EA3 33
	JR   NC,L2ED8    		;2EA4 3032	<L2ED8>
	LD   B,E     			;2EA6 43
	DEC  (HL)    			;2EA7 35
	JR   NC,L2EE2    		;2EA8 3038	<L2EE2>
	INC  (HL)    			;2EAA 34
	INC  (HL)    			;2EAB 34
	LD   B,H     			;2EAC 44
L2EAD:	INC  (HL)    			;2EAD 34
	DEC  C       			;2EAE 0D
	LD   A,(BC)  			;2EAF 0A
	LD   A,(M3032)   		;2EB0 3A3230	<M3032>
	LD   SP,M3633    		;2EB3 313336	<M3633>
	JR   NC,L2EE8    		;2EB6 3030	<L2EE8>
L2EB8:	JR   NC,L2EEA    		;2EB8 3030	<L2EEA>
L2EBA:	JR   NC,L2EEF    		;2EBA 3033	<L2EEF>
	INC  SP      			;2EBC 33
	JR   NC,L2EEF    		;2EBD 3030	<L2EEF>
	LD   B,L     			;2EBF 45
	LD   B,C     			;2EC0 41
	JR   NC,L2F05    		;2EC1 3042	<L2F05>
	LD   B,H     			;2EC3 44
	LD   (M3030),A   		;2EC4 323030	<M3030>
	LD   B,H     			;2EC7 44
	JR   NC,L2EFA    		;2EC8 3030	<L2EFA>
	SCF          			;2ECA 37
	LD   B,E     			;2ECB 43
	DEC  (HL)    			;2ECC 35
L2ECD:	JR   NC,L2F07    		;2ECD 3038	<L2F07>
	INC  (HL)    			;2ECF 34
	INC  (HL)    			;2ED0 34
	JR   NC,L2F03    		;2ED1 3030	<L2F03>
L2ED3:	INC  SP      			;2ED3 33
	INC  SP      			;2ED4 33
	JR   NC,L2F07    		;2ED5 3030	<L2F07>
	INC  SP      			;2ED7 33
L2ED8:	LD   (M3030),A   		;2ED8 323030	<M3030>
	LD   (HL),34H  			;2EDB 3634	<34H>
	JR   NC,L2F0F    		;2EDD 3030	<L2F0F>
	JR   C,L2F15     		;2EDF 3834	<L2F15>
	LD   SP,M3443    		;2EE1 314334	<M3443>
	ADD  HL,SP   			;2EE4 39
	LD   SP,M3632    		;2EE5 313236	<M3632>
L2EE8:	JR   NC,L2F20    		;2EE8 3036	<L2F20>
L2EEA:	JR   NC,L2F22    		;2EEA 3036	<L2F22>
	JR   NC,L2F24    		;2EEC 3036	<L2F24>
	JR   NC,L2F26    		;2EEE 3036	<L2F26>
	INC  (HL)    			;2EF0 34
	LD   (HL),38H  			;2EF1 3638	<38H>
	JR   NC,L2F25    		;2EF3 3030	<L2F25>
	JR   NC,L2F3D    		;2EF5 3046	<L2F3D>
	JR   NC,L2F2C    		;2EF7 3033	<L2F2C>
	LD   (HL),39H  			;2EF9 3639	<39H>
	DEC  C       			;2EFB 0D
	LD   A,(BC)  			;2EFC 0A
	LD   A,(M3032)   		;2EFD 3A3230	<M3032>
	LD   SP,M3833    		;2F00 313338	<M3833>
L2F03:	JR   NC,L2F35    		;2F03 3030	<L2F35>
L2F05:	JR   NC,L2F37    		;2F05 3030	<L2F37>
L2F07:	LD   B,E     			;2F07 43
	JR   NC,L2F3A    		;2F08 3030	<L2F3A>
	JR   NC,L2F52    		;2F0A 3046	<L2F52>
	JR   NC,L2F51    		;2F0C 3043	<L2F51>
	JR   NC,L2F43    		;2F0E 3033	<L2F43>
	JR   NC,L2F43    		;2F10 3031	<L2F43>
	JR   NC,L2F59    		;2F12 3045	<L2F59>
	JR   NC,L2F46    		;2F14 3030	<L2F46>
	JR   NC,L2F5E    		;2F16 3046	<L2F5E>
	JR   NC,L2F4C    		;2F18 3032	<L2F4C>
	JR   NC,L2F60    		;2F1A 3044	<L2F60>
	JR   NC,L2F4E    		;2F1C 3030	<L2F4E>
	JR   NC,L2F66    		;2F1E 3046	<L2F66>
L2F20:	JR   NC,L2F56    		;2F20 3034	<L2F56>
L2F22:	JR   NC,L2F66    		;2F22 3042	<L2F66>
L2F24:	JR   NC,L2F56    		;2F24 3030	<L2F56>
L2F26:	JR   NC,L2F6E    		;2F26 3046	<L2F6E>
	JR   NC,L2F62    		;2F28 3038	<L2F62>
	JR   NC,L2F63    		;2F2A 3037	<L2F63>
L2F2C:	JR   NC,L2F5E    		;2F2C 3030	<L2F5E>
	JR   NC,L2F76    		;2F2E 3046	<L2F76>
	JR   NC,L2F62    		;2F30 3030	<L2F62>
	JR   NC,L2F7A    		;2F32 3046	<L2F7A>
	JR   NC,L2F66    		;2F34 3030	<L2F66>
	JR   NC,L2F7E    		;2F36 3046	<L2F7E>
	LD   SP,M3038    		;2F38 313830	<M3038>
	SCF          			;2F3B 37
	JR   NC,L2F6E    		;2F3C 3030	<L2F6E>
	JR   NC,L2F86    		;2F3E 3046	<L2F86>
	JR   NC,L2F72    		;2F40 3030	<L2F72>
	LD   SP,M3046    		;2F42 314630	<M3046>
	JR   NC,L2F7B    		;2F45 3034	<L2F7B>
	JR   NC,L2F56    		;2F47 300D	<L2F56>
	LD   A,(BC)  			;2F49 0A
	LD   A,(M3032)   		;2F4A 3A3230	<M3032>
	LD   SP,M4133    		;2F4D 313341	<M4133>
	JR   NC,L2F82    		;2F50 3030	<L2F82>
L2F52:	JR   NC,L2F84    		;2F52 3030	<L2F84>
	LD   B,(HL)  			;2F54 46
	LD   (HL),37H  			;2F55 3637	<37H>
	SCF          			;2F57 37
	LD   B,H     			;2F58 44
L2F59:	JR   NC,L2F8C    		;2F59 3031	<L2F8C>
	LD   (HL),46H  			;2F5B 3646	<46H>
	SCF          			;2F5D 37
L2F5E:	LD   B,(HL)  			;2F5E 46
	LD   B,(HL)  			;2F5F 46
L2F60:	JR   C,L2F92     		;2F60 3830	<L2F92>
L2F62:	LD   SP,M3130    		;2F62 313031	<M3130>
	JR   NC,L2F98    		;2F65 3031	<L2F98>
	JR   NC,L2F9A    		;2F67 3031	<L2F9A>
	JR   NC,L2F9C    		;2F69 3031	<L2F9C>
	LD   (HL),37H  			;2F6B 3637	<37H>
	SCF          			;2F6D 37
L2F6E:	LD   B,H     			;2F6E 44
	LD   SP,M3645    		;2F6F 314536	<M3645>
L2F72:	LD   B,(HL)  			;2F72 46
	SCF          			;2F73 37
	LD   B,(HL)  			;2F74 46
	LD   B,(HL)  			;2F75 46
L2F76:	JR   C,L2FA9     		;2F76 3831	<L2FA9>
	LD   B,L     			;2F78 45
	LD   SP,M3145    		;2F79 314531	<M3145>
	LD   B,L     			;2F7C 45
	LD   SP,M3145    		;2F7D 314531	<M3145>
	LD   B,L     			;2F80 45
	LD   (HL),39H  			;2F81 3639	<39H>
	SCF          			;2F83 37
L2F84:	LD   B,L     			;2F84 45
	JR   NC,L2FCD    		;2F85 3046	<L2FCD>
	SCF          			;2F87 37
	LD   (HL),38H  			;2F88 3638	<38H>
	INC  (HL)    			;2F8A 34
	LD   B,(HL)  			;2F8B 46
L2F8C:	JR   C,L2FBE     		;2F8C 3830	<L2FBE>
	LD   B,(HL)  			;2F8E 46
	JR   NC,L2FD7    		;2F8F 3046	<L2FD7>
	JR   NC,L2FD9    		;2F91 3046	<L2FD9>
	LD   B,D     			;2F93 42
	LD   B,D     			;2F94 42
	DEC  C       			;2F95 0D
	LD   A,(BC)  			;2F96 0A
	LD   A,(M3032)   		;2F97 3A3230	<M3032>
L2F9A:	LD   SP,M4333    		;2F9A 313343	<M4333>
	JR   NC,L2FCF    		;2F9D 3030	<L2FCF>
	JR   NC,L2FD1    		;2F9F 3030	<L2FD1>
	LD   B,(HL)  			;2FA1 46
	JR   NC,L2FEA    		;2FA2 3046	<L2FEA>
	LD   (HL),37H  			;2FA4 3637	<37H>
	SCF          			;2FA6 37
	LD   B,H     			;2FA7 44
	JR   NC,L2FED    		;2FA8 3043	<L2FED>
	LD   (HL),46H  			;2FAA 3646	<46H>
	SCF          			;2FAC 37
	LD   B,(HL)  			;2FAD 46
	LD   B,(HL)  			;2FAE 46
	JR   C,L2FE1     		;2FAF 3830	<L2FE1>
	JR   C,L2FE3     		;2FB1 3830	<L2FE3>
	INC  (HL)    			;2FB3 34
	JR   NC,L2FEA    		;2FB4 3034	<L2FEA>
	JR   NC,L2FE8    		;2FB6 3030	<L2FE8>
	JR   NC,L2FEE    		;2FB8 3034	<L2FEE>
	LD   (HL),36H  			;2FBA 3636	<36H>
	SCF          			;2FBC 37
	LD   B,H     			;2FBD 44
L2FBE:	LD   SP,M3646    		;2FBE 314636	<M3646>
	LD   B,(HL)  			;2FC1 46
	SCF          			;2FC2 37
	LD   B,(HL)  			;2FC3 46
	JR   NC,L2FF6    		;2FC4 3030	<L2FF6>
	LD   SP,M3146    		;2FC6 314631	<M3146>
	LD   B,(HL)  			;2FC9 46
	LD   SP,M3146    		;2FCA 314631	<M3146>
L2FCD:	LD   B,(HL)  			;2FCD 46
	LD   SP,M3646    		;2FCE 314636	<M3646>
L2FD1:	JR   C,L300A     		;2FD1 3837	<L300A>
	LD   B,L     			;2FD3 45
	JR   NC,L301C    		;2FD4 3046	<L301C>
	SCF          			;2FD6 37
L2FD7:	LD   (HL),38H  			;2FD7 3638	<38H>
L2FD9:	INC  (HL)    			;2FD9 34
	JR   NC,L300C    		;2FDA 3030	<L300C>
	JR   NC,L3024    		;2FDC 3046	<L3024>
	JR   NC,L3026    		;2FDE 3046	<L3026>
	LD   (HL),44H  			;2FE0 3644	<44H>
	DEC  C       			;2FE2 0D
L2FE3:	LD   A,(BC)  			;2FE3 0A
	LD   A,(M3032)   		;2FE4 3A3230	<M3032>
	LD   SP,M4533    		;2FE7 313345	<M4533>
L2FEA:	JR   NC,L301C    		;2FEA 3030	<L301C>
	JR   NC,L301E    		;2FEC 3030	<L301E>
L2FEE:	LD   B,(HL)  			;2FEE 46
	JR   NC,L3037    		;2FEF 3046	<L3037>
	JR   NC,L3039    		;2FF1 3046	<L3039>
	JR   NC,L3025    		;2FF3 3030	<L3025>
	JR   NC,L302A    		;2FF5 3033	<L302A>
	LD   (M3133),A   		;2FF7 323331	<M3133>
	INC  (HL)    			;2FFA 34
	JR   NC,L3035    		;2FFB 3038	<L3035>
	JR   NC,L3032    		;2FFD 3033	<L3032>
	INC  (HL)    			;2FFF 34
	LD   B,H     			;3000 44
	LD   SP,M3034    		;3001 313430	<M3034>
	LD   (M3330),A   		;3004 323033	<M3330>
	INC  SP      			;3007 33
	SCF          			;3008 37
	LD   SP,M3034    		;3009 313430	<M3034>
L300C:	INC  (HL)    			;300C 34
	JR   NC,L3042    		;300D 3033	<L3042>
	INC  SP      			;300F 33
	LD   B,(HL)  			;3010 46
	LD   SP,M3034    		;3011 313430	<M3034>
	LD   SP,M3330    		;3014 313033	<M3330>
	INC  (HL)    			;3017 34
	INC  SP      			;3018 33
	LD   SP,M3034    		;3019 313430	<M3034>
L301C:	JR   NC,L304E    		;301C 3030	<L304E>
L301E:	LD   B,E     			;301E 43
	LD   (M3146),A   		;301F 324631	<M3146>
	INC  (HL)    			;3022 34
	JR   NC,L305D    		;3023 3038	<L305D>
L3025:	JR   NC,L306A    		;3025 3043	<L306A>
	LD   (HL),45H  			;3027 3645	<45H>
	LD   SP,M3034    		;3029 313430	<M3034>
	LD   (M4532),A   		;302C 323245	<M4532>
	DEC  C       			;302F 0D
M3030:	LD   A,(BC)  			;3030 0A
M3031:	LD   A,(M3032)   		;3031 3A3230	<M3032>
M3034:	LD   SP,M3034    		;3034 313430	<M3034>
L3037:	JR   NC,L3069    		;3037 3030	<L3069>
L3039:	JR   NC,L306B    		;3039 3030	<L306B>
	LD   B,E     			;303B 43
	INC  SP      			;303C 33
	LD   B,D     			;303D 42
	LD   SP,M3034    		;303E 313430	<M3034>
M3041:	INC  (HL)    			;3041 34
L3042:	JR   NC,L3087    		;3042 3043	<L3087>
M3044:	LD   (HL),35H  			;3044 3635	<35H>
M3046:	LD   SP,M3034    		;3046 313430	<M3034>
	LD   SP,M4330    		;3049 313043	<M4330>
	INC  (HL)    			;304C 34
	JR   C,L3080     		;304D 3831	<L3080>
	INC  (HL)    			;304F 34
	JR   NC,L308A    		;3050 3038	<L308A>
	JR   NC,L3084    		;3052 3030	<L3084>
	LD   (HL),45H  			;3054 3645	<45H>
	LD   SP,M3034    		;3056 313430	<M3034>
	LD   (M3030),A   		;3059 323030	<M3030>
	LD   (HL),31H  			;305C 3631	<31H>
	LD   SP,M3034    		;305E 313430	<M3034>
	INC  (HL)    			;3061 34
	JR   NC,L3094    		;3062 3030	<L3094>
	LD   (HL),35H  			;3064 3635	<35H>
	LD   SP,M3034    		;3066 313430	<M3034>
L3069:	LD   SP,M3030    		;3069 313030	<M3030>
	LD   (HL),39H  			;306C 3639	<39H>
	LD   SP,M3034    		;306E 313430	<M3034>
	JR   NC,L30A3    		;3071 3030	<L30A3>
	JR   NC,L30AA    		;3073 3035	<L30AA>
	LD   SP,M3431    		;3075 313134	<M3431>
	LD   SP,M3038    		;3078 313830	<M3038>
	LD   (HL),0DH  			;307B 360D	<0DH>
	LD   A,(BC)  			;307D 0A
	LD   A,(M3032)   		;307E 3A3230	<M3032>
	LD   SP,M3234    		;3081 313432	<M3234>
L3084:	JR   NC,L30B6    		;3084 3030	<L30B6>
	JR   NC,L30B8    		;3086 3030	<L30B8>
	JR   NC,L30C0    		;3088 3036	<L30C0>
L308A:	LD   B,L     			;308A 45
	LD   SP,M3534    		;308B 313435	<M3534>
	LD   B,E     			;308E 43
	LD   SP,M3234    		;308F 313432	<M3234>
	DEC  (HL)    			;3092 35
	JR   NC,L30C6    		;3093 3031	<L30C6>
	JR   NC,L30CB    		;3095 3034	<L30CB>
	LD   SP,M3037    		;3097 313730	<M3037>
	SCF          			;309A 37
	JR   NC,L30E2    		;309B 3045	<L30E2>
	JR   NC,L30D0    		;309D 3031	<L30D0>
	JR   NC,L30D3    		;309F 3032	<L30D3>
	JR   NC,L30D4    		;30A1 3031	<L30D4>
L30A3:	LD   (M3336),A   		;30A3 323633	<M3336>
	JR   C,L30D9     		;30A6 3831	<L30D9>
	DEC  (HL)    			;30A8 35
	DEC  (HL)    			;30A9 35
L30AA:	LD   SP,M3631    		;30AA 313136	<M3631>
	JR   NC,L30E1    		;30AD 3032	<L30E1>
	JR   NC,L30E6    		;30AF 3035	<L30E6>
	LD   SP,M3031    		;30B1 313130	<M3031>
	LD   SP,M4342    		;30B4 314243	<M4342>
	LD   SP,M3635    		;30B7 313536	<M3635>
	LD   B,L     			;30BA 45
	LD   SP,M4532    		;30BB 313245	<M4532>
	JR   C,L30F1     		;30BE 3831	<L30F1>
L30C0:	DEC  (HL)    			;30C0 35
	LD   (M3538),A   		;30C1 323835	<M3538>
	JR   C,L30F7     		;30C4 3831	<L30F7>
L30C6:	INC  (HL)    			;30C6 34
	JR   C,L310B     		;30C7 3842	<L310B>
	DEC  C       			;30C9 0D
	LD   A,(BC)  			;30CA 0A
L30CB:	LD   A,(M3032)   		;30CB 3A3230	<M3032>
	LD   SP,M3434    		;30CE 313434	<M3434>
	JR   NC,L3103    		;30D1 3030	<L3103>
L30D3:	JR   NC,L3106    		;30D3 3031	<L3106>
	LD   (HL),36H  			;30D5 3636	<36H>
	INC  (HL)    			;30D7 34
	LD   SP,M3443    		;30D8 314334	<M3443>
	JR   NC,L310E    		;30DB 3031	<L310E>
	LD   (HL),35H  			;30DD 3635	<35H>
	SCF          			;30DF 37
	LD   (M3038),A   		;30E0 323830	<M3038>
	LD   SP,M3238    		;30E3 313832	<M3238>
L30E6:	LD   SP,M3036    		;30E6 313630	<M3036>
	LD   SP,M3334    		;30E9 313433	<M3334>
	INC  SP      			;30EC 33
	LD   B,E     			;30ED 43
	LD   B,E     			;30EE 43
	INC  (HL)    			;30EF 34
	LD   SP,M3736    		;30F0 313637	<M3736>
	LD   B,(HL)  			;30F3 46
	JR   NC,L3127    		;30F4 3031	<L3127>
	LD   B,(HL)  			;30F6 46
L30F7:	JR   NC,L312A    		;30F7 3031	<L312A>
	LD   (HL),30H  			;30F9 3630	<30H>
	LD   SP,M3130    		;30FB 313031	<M3130>
	JR   NC,L3141    		;30FE 3041	<L3141>
	JR   NC,L3145    		;3100 3043	<L3145>
	LD   (M3033),A   		;3102 323330	<M3033>
	LD   SP,M3730    		;3105 313037	<M3730>
	JR   NC,L313B    		;3108 3031	<L313B>
	JR   NC,L3152    		;310A 3046	<L3152>
	JR   NC,L3143    		;310C 3035	<L3143>
L310E:	JR   NC,L3144    		;310E 3034	<L3144>
	LD   SP,M3032    		;3110 313230	<M3032>
	DEC  (HL)    			;3113 35
	INC  SP      			;3114 33
	DEC  (HL)    			;3115 35
	DEC  C       			;3116 0D
	LD   A,(BC)  			;3117 0A
	LD   A,(M3032)   		;3118 3A3230	<M3032>
	LD   SP,M3634    		;311B 313436	<M3634>
	JR   NC,L3150    		;311E 3030	<L3150>
	JR   NC,L3152    		;3120 3030	<L3152>
	LD   B,H     			;3122 44
	LD   (M3134),A   		;3123 323431	<M3134>
	JR   C,L3158     		;3126 3830	<L3158>
	LD   SP,M4637    		;3128 313746	<M4637>
	DEC  (HL)    			;312B 35
	JR   NC,L315F    		;312C 3031	<L315F>
	JR   C,L3163     		;312E 3833	<L3163>
M3130:	LD   B,E     			;3130 43
M3131:	INC  (HL)    			;3131 34
M3132:	INC  (HL)    			;3132 34
M3133:	SCF          			;3133 37
M3134:	LD   B,E     			;3134 43
M3135:	LD   SP,M3238    		;3135 313832	<M3238>
M3138:	JR   C,L316A     		;3138 3830	<L316A>
	LD   SP,M3735    		;313A 313537	<M3735>
	LD   B,D     			;313D 42
	LD   B,L     			;313E 45
	LD   SP,M3038    		;313F 313830	<M3038>
	LD   SP,M4637    		;3142 313746	<M4637>
L3145:	JR   NC,L3179    		;3145 3032	<L3179>
	INC  (HL)    			;3147 34
	JR   C,L317C     		;3148 3832	<L317C>
	JR   NC,L318F    		;314A 3043	<L318F>
	JR   NC,L3187    		;314C 3039	<L3187>
	JR   C,L3189     		;314E 3839	<L3189>
L3150:	JR   C,L3186     		;3150 3834	<L3186>
L3152:	JR   C,L3186     		;3152 3832	<L3186>
	JR   NC,L3188    		;3154 3032	<L3188>
	JR   NC,L3191    		;3156 3039	<L3191>
L3158:	JR   C,L3193     		;3158 3839	<L3193>
	JR   C,L3193     		;315A 3837	<L3193>
	JR   NC,L31A3    		;315C 3045	<L31A3>
	JR   C,L31A3     		;315E 3843	<L31A3>
	JR   NC,L3194    		;3160 3032	<L3194>
	SCF          			;3162 37
L3163:	DEC  C       			;3163 0D
	LD   A,(BC)  			;3164 0A
	LD   A,(M3032)   		;3165 3A3230	<M3032>
	LD   SP,M3834    		;3168 313438	<M3834>
	JR   NC,L319D    		;316B 3030	<L319D>
	JR   NC,L31B2    		;316D 3043	<L31B2>
	JR   NC,L31A5    		;316F 3034	<L31A5>
	JR   C,L31A5     		;3171 3832	<L31A5>
	JR   NC,L31A7    		;3173 3032	<L31A7>
	JR   NC,L31A9    		;3175 3032	<L31A9>
	JR   NC,L31AB    		;3177 3032	<L31AB>
L3179:	JR   NC,L31BE    		;3179 3043	<L31BE>
	JR   NC,L31B4    		;317B 3037	<L31B4>
	JR   NC,L31AF    		;317D 3030	<L31AF>
	INC  SP      			;317F 33
	LD   (HL),30H  			;3180 3630	<30H>
	INC  (HL)    			;3182 34
	JR   NC,L31C9    		;3183 3044	<L31C9>
	LD   B,C     			;3185 41
L3186:	LD   B,H     			;3186 44
L3187:	JR   NC,L31CC    		;3187 3043	<L31CC>
L3189:	JR   C,L31CF     		;3189 3844	<L31CF>
	INC  (HL)    			;318B 34
	LD   B,E     			;318C 43
	JR   C,L31D3     		;318D 3844	<L31D3>
L318F:	LD   B,E     			;318F 43
	JR   C,L31C4     		;3190 3832	<L31C4>
	DEC  (HL)    			;3192 35
L3193:	JR   NC,L31C9    		;3193 3034	<L31C9>
	LD   B,E     			;3195 43
	LD   B,E     			;3196 43
	JR   NC,L31D2    		;3197 3039	<L31D2>
	INC  (HL)    			;3199 34
	LD   B,D     			;319A 42
	LD   B,C     			;319B 41
	INC  SP      			;319C 33
L319D:	JR   C,L31CF     		;319D 3830	<L31CF>
	JR   C,L31D4     		;319F 3833	<L31D4>
	LD   B,E     			;31A1 43
	LD   SP,M4438    		;31A2 313844	<M4438>
L31A5:	LD   B,L     			;31A5 45
	LD   B,C     			;31A6 41
L31A7:	JR   C,L31E0     		;31A7 3837	<L31E0>
L31A9:	ADD  HL,SP   			;31A9 39
	JR   NC,L31E0    		;31AA 3034	<L31E0>
	INC  (HL)    			;31AC 34
	JR   NC,L31DF    		;31AD 3030	<L31DF>
L31AF:	INC  (HL)    			;31AF 34
	DEC  C       			;31B0 0D
	LD   A,(BC)  			;31B1 0A
L31B2:	LD   A,(M3032)   		;31B2 3A3230	<M3032>
	LD   SP,M4134    		;31B5 313441	<M4134>
	JR   NC,L31EA    		;31B8 3030	<L31EA>
	JR   NC,L31EC    		;31BA 3030	<L31EC>
	JR   C,L3202     		;31BC 3844	<L3202>
L31BE:	LD   (M3842),A   		;31BE 324238	<M3842>
	JR   C,L31FB     		;31C1 3838	<L31FB>
	DEC  (HL)    			;31C3 35
L31C4:	JR   C,L31F8     		;31C4 3832	<L31F8>
	LD   B,E     			;31C6 43
	LD   SP,M4430    		;31C7 313044	<M4430>
	JR   NC,L320F    		;31CA 3043	<L320F>
L31CC:	JR   C,L3213     		;31CC 3845	<L3213>
	JR   C,L3215     		;31CE 3845	<L3215>
	INC  (HL)    			;31D0 34
	LD   B,D     			;31D1 42
L31D2:	JR   C,L320C     		;31D2 3838	<L320C>
L31D4:	JR   C,L320B     		;31D4 3835	<L320B>
	JR   C,L320B     		;31D6 3833	<L320B>
	JR   NC,L320A    		;31D8 3030	<L320A>
	JR   C,L3220     		;31DA 3844	<L3220>
	LD   B,C     			;31DC 41
	LD   B,H     			;31DD 44
	INC  (HL)    			;31DE 34
L31DF:	SCF          			;31DF 37
L31E0:	LD   B,E     			;31E0 43
	LD   (HL),30H  			;31E1 3630	<30H>
	JR   NC,L321A    		;31E3 3035	<L321A>
	LD   B,D     			;31E5 42
	JR   NC,L3221    		;31E6 3039	<L3221>
	JR   C,L322F     		;31E8 3845	<L322F>
L31EA:	JR   NC,L3230    		;31EA 3044	<L3230>
L31EC:	JR   C,L3232     		;31EC 3844	<L3232>
	JR   NC,L3233    		;31EE 3043	<L3233>
	LD   B,E     			;31F0 43
	LD   B,L     			;31F1 45
	JR   C,L3239     		;31F2 3845	<L3239>
	INC  (HL)    			;31F4 34
	LD   B,H     			;31F5 44
	JR   C,L3239     		;31F6 3841	<L3239>
L31F8:	JR   C,L3231     		;31F8 3837	<L3231>
	LD   B,E     			;31FA 43
L31FB:	DEC  (HL)    			;31FB 35
	SCF          			;31FC 37
	DEC  C       			;31FD 0D
	LD   A,(BC)  			;31FE 0A
	LD   A,(M3032)   		;31FF 3A3230	<M3032>
L3202:	LD   SP,M4334    		;3202 313443	<M4334>
	JR   NC,L3237    		;3205 3030	<L3237>
	JR   NC,L324C    		;3207 3043	<L324C>
	JR   NC,L3244    		;3209 3039	<L3244>
L320B:	LD   B,E     			;320B 43
L320C:	LD   (HL),38H  			;320C 3638	<38H>
	INC  SP      			;320E 33
L320F:	JR   C,L3241     		;320F 3830	<L3241>
	JR   C,L3256     		;3211 3843	<L3256>
L3213:	JR   C,L325A     		;3213 3845	<L325A>
L3215:	JR   C,L325C     		;3215 3845	<L325C>
	INC  (HL)    			;3217 34
	LD   B,L     			;3218 45
	JR   C,L3260     		;3219 3845	<L3260>
	INC  (HL)    			;321B 34
	JR   NC,L3254    		;321C 3036	<L3254>
	JR   C,L3250     		;321E 3830	<L3250>
L3220:	DEC  (HL)    			;3220 35
L3221:	INC  (HL)    			;3221 34
	LD   B,L     			;3222 45
	JR   NC,L3267    		;3223 3042	<L3267>
	JR   NC,L325F    		;3225 3038	<L325F>
	JR   NC,L325E    		;3227 3035	<L325E>
	JR   NC,L325F    		;3229 3034	<L325F>
	LD   B,E     			;322B 43
	LD   SP,M4238    		;322C 313842	<M4238>
L322F:	JR   C,L3269     		;322F 3838	<L3269>
L3231:	JR   C,L3274     		;3231 3841	<L3274>
L3233:	JR   C,L327A     		;3233 3845	<L327A>
M3235:	LD   B,E     			;3235 43
M3236:	LD   B,L     			;3236 45
L3237:	JR   NC,L327D    		;3237 3044	<L327D>
L3239:	JR   C,L327F     		;3239 3844	<L327F>
	JR   NC,L3280    		;323B 3043	<L3280>
	JR   C,L3282     		;323D 3843	<L3282>
	JR   C,L3285     		;323F 3844	<L3285>
L3241:	LD   B,E     			;3241 43
M3242:	LD   B,L     			;3242 45
M3243:	JR   C,L328A     		;3243 3845	<L328A>
M3245:	INC  (HL)    			;3245 34
M3246:	LD   B,D     			;3246 42
	JR   NC,L328C    		;3247 3043	<L328C>
	LD   (HL),0DH  			;3249 360D	<0DH>
	LD   A,(BC)  			;324B 0A
L324C:	LD   A,(M3032)   		;324C 3A3230	<M3032>
	LD   SP,M4534    		;324F 313445	<M4534>
	JR   NC,L3284    		;3252 3030	<L3284>
L3254:	JR   NC,L3286    		;3254 3030	<L3286>
L3256:	SCF          			;3256 37
	INC  (HL)    			;3257 34
	JR   NC,L328B    		;3258 3031	<L328B>
L325A:	JR   NC,L32A0    		;325A 3044	<L32A0>
L325C:	INC  (HL)    			;325C 34
	LD   B,E     			;325D 43
L325E:	JR   C,L32A4     		;325E 3844	<L32A4>
L3260:	JR   C,L32A6     		;3260 3844	<L32A6>
	JR   NC,L32A7    		;3262 3043	<L32A7>
	LD   B,E     			;3264 43
	LD   B,H     			;3265 44
	JR   C,L32AD     		;3266 3845	<L32AD>
	JR   C,L32AE     		;3268 3844	<L32AE>
	JR   C,L32AE     		;326A 3842	<L32AE>
	JR   NC,L32B1    		;326C 3043	<L32B1>
	LD   B,E     			;326E 43
	LD   B,E     			;326F 43
	JR   NC,L32AB    		;3270 3039	<L32AB>
	JR   C,L32AA     		;3272 3836	<L32AA>
L3274:	JR   C,L32A9     		;3274 3833	<L32A9>
	JR   C,L32A8     		;3276 3830	<L32A8>
	JR   C,L32BD     		;3278 3843	<L32BD>
L327A:	LD   B,E     			;327A 43
	LD   B,H     			;327B 44
	INC  (HL)    			;327C 34
L327D:	SCF          			;327D 37
	LD   B,E     			;327E 43
L327F:	SCF          			;327F 37
L3280:	JR   NC,L32B2    		;3280 3030	<L32B2>
L3282:	JR   C,L32C9     		;3282 3845	<L32C9>
L3284:	JR   NC,L32CA    		;3284 3044	<L32CA>
L3286:	LD   B,E     			;3286 43
	LD   B,C     			;3287 41
	JR   C,L32C1     		;3288 3837	<L32C1>
L328A:	LD   B,C     			;328A 41
L328B:	LD   (HL),30H  			;328B 3630	<30H>
	INC  SP      			;328D 33
	INC  (HL)    			;328E 34
	LD   SP,M4530    		;328F 313045	<M4530>
	LD   (M3845),A   		;3292 324538	<M3845>
	ADD  HL,SP   			;3295 39
	LD   SP,M0A0D    		;3296 310D0A	<M0A0D>
	LD   A,(M3032)   		;3299 3A3230	<M3032>
	LD   SP,M3035    		;329C 313530	<M3035>
	JR   NC,L32D1    		;329F 3030	<L32D1>
	JR   NC,L32E8    		;32A1 3045	<L32E8>
	JR   NC,L32E9    		;32A3 3044	<L32E9>
	LD   B,E     			;32A5 43
L32A6:	LD   B,C     			;32A6 41
L32A7:	JR   C,L32E0     		;32A7 3837	<L32E0>
L32A9:	LD   B,C     			;32A9 41
L32AA:	SCF          			;32AA 37
L32AB:	JR   NC,L32E1    		;32AB 3034	<L32E1>
L32AD:	JR   NC,L32E7    		;32AD 3038	<L32E7>
	JR   C,L32E6     		;32AF 3835	<L32E6>
L32B1:	LD   B,E     			;32B1 43
L32B2:	INC  (HL)    			;32B2 34
	JR   NC,L32E6    		;32B3 3031	<L32E6>
	DEC  (HL)    			;32B5 35
	LD   B,H     			;32B6 44
	JR   NC,L32FC    		;32B7 3043	<L32FC>
	LD   B,C     			;32B9 41
	JR   NC,L32F5    		;32BA 3039	<L32F5>
	DEC  (HL)    			;32BC 35
L32BD:	JR   C,L32F1     		;32BD 3832	<L32F1>
	LD   B,C     			;32BF 41
	LD   B,L     			;32C0 45
L32C1:	JR   C,L3308     		;32C1 3845	<L3308>
	JR   NC,L3309    		;32C3 3044	<L3309>
	JR   C,L330B     		;32C5 3844	<L330B>
	LD   SP,M3845    		;32C7 314538	<M3845>
L32CA:	LD   B,L     			;32CA 45
	INC  (HL)    			;32CB 34
	JR   C,L3306     		;32CC 3838	<L3306>
	DEC  (HL)    			;32CE 35
	JR   C,L3303     		;32CF 3832	<L3303>
L32D1:	JR   C,L3318     		;32D1 3845	<L3318>
	JR   C,L331A     		;32D3 3845	<L331A>
	INC  (HL)    			;32D5 34
	LD   B,D     			;32D6 42
	JR   NC,L3311    		;32D7 3038	<L3311>
	LD   (M3836),A   		;32D9 323638	<M3836>
	INC  SP      			;32DC 33
	JR   C,L330F     		;32DD 3830	<L330F>
	JR   C,L3324     		;32DF 3843	<L3324>
L32E1:	LD   B,E     			;32E1 43
	LD   (M0D38),A   		;32E2 32380D	<M0D38>
	LD   A,(BC)  			;32E5 0A
L32E6:	LD   A,(M3032)   		;32E6 3A3230	<M3032>
L32E9:	LD   SP,M3235    		;32E9 313532	<M3235>
	JR   NC,L331E    		;32EC 3030	<L331E>
	JR   NC,L3332    		;32EE 3042	<L3332>
	JR   C,L332A     		;32F0 3838	<L332A>
	LD   B,E     			;32F2 43
	JR   NC,L3326    		;32F3 3031	<L3326>
L32F5:	SCF          			;32F5 37
	JR   C,L332F     		;32F6 3837	<L332F>
	JR   NC,L333F    		;32F8 3045	<L333F>
	INC  (HL)    			;32FA 34
	LD   B,H     			;32FB 44
L32FC:	JR   C,L3342     		;32FC 3844	<L3342>
	JR   NC,L3343    		;32FE 3043	<L3343>
	LD   B,E     			;3300 43
	LD   B,L     			;3301 45
	JR   C,L3349     		;3302 3845	<L3349>
	INC  (HL)    			;3304 34
	LD   B,D     			;3305 42
L3306:	JR   NC,L3340    		;3306 3038	<L3340>
L3308:	JR   NC,L333F    		;3308 3035	<L333F>
	JR   NC,L3351    		;330A 3045	<L3351>
	JR   C,L3353     		;330C 3845	<L3353>
	INC  (HL)    			;330E 34
L330F:	LD   B,D     			;330F 42
	JR   NC,L334A    		;3310 3038	<L334A>
	JR   NC,L3349    		;3312 3035	<L3349>
	JR   NC,L334A    		;3314 3034	<L334A>
	JR   C,L334A     		;3316 3832	<L334A>
L3318:	JR   NC,L335F    		;3318 3045	<L335F>
L331A:	INC  (HL)    			;331A 34
	LD   B,H     			;331B 44
	JR   C,L335F     		;331C 3841	<L335F>
L331E:	JR   C,L3350     		;331E 3830	<L3350>
	LD   SP,M3839    		;3320 313938	<M3839>
	SCF          			;3323 37
L3324:	JR   NC,L336B    		;3324 3045	<L336B>
L3326:	JR   C,L336D     		;3326 3845	<L336D>
	JR   C,L336F     		;3328 3845	<L336F>
L332A:	JR   C,L3371     		;332A 3845	<L3371>
	JR   C,L3373     		;332C 3845	<L3373>
	JR   C,L3363     		;332E 3833	<L3363>
M3330:	LD   SP,M0A0D    		;3330 310D0A	<M0A0D>
M3333:	LD   A,(M3032)   		;3333 3A3230	<M3032>
M3336:	LD   SP,M3435    		;3336 313534	<M3435>
M3339:	JR   NC,L336B    		;3339 3030	<L336B>
	JR   NC,L3382    		;333B 3045	<L3382>
	JR   C,L3384     		;333D 3845	<L3384>
L333F:	JR   C,L3386     		;333F 3845	<L3386>
M3341:	JR   C,L3386     		;3341 3843	<L3386>
L3343:	JR   NC,L338A    		;3343 3045	<L338A>
M3345:	JR   C,L338C     		;3345 3845	<L338C>
	JR   C,L338E     		;3347 3845	<L338E>
L3349:	JR   C,L3390     		;3349 3845	<L3390>
	JR   C,L3392     		;334B 3845	<L3392>
	JR   C,L3394     		;334D 3845	<L3394>
	JR   C,L3396     		;334F 3845	<L3396>
L3351:	JR   C,L3398     		;3351 3845	<L3398>
L3353:	JR   C,L339A     		;3353 3845	<L339A>
	JR   C,L339A     		;3355 3843	<L339A>
	JR   NC,L3389    		;3357 3030	<L3389>
	DEC  (HL)    			;3359 35
	LD   B,L     			;335A 45
	JR   C,L3391     		;335B 3834	<L3391>
	JR   C,L3391     		;335D 3832	<L3391>
L335F:	JR   NC,L339A    		;335F 3039	<L339A>
	JR   C,L339C     		;3361 3839	<L339C>
L3363:	JR   C,L339C     		;3363 3837	<L339C>
	JR   NC,L3399    		;3365 3032	<L3399>
	JR   NC,L33AC    		;3367 3043	<L33AC>
	JR   NC,L33A4    		;3369 3039	<L33A4>
L336B:	JR   C,L33B2     		;336B 3845	<L33B2>
L336D:	JR   C,L33B4     		;336D 3845	<L33B4>
L336F:	JR   C,L33A2     		;336F 3831	<L33A2>
L3371:	JR   C,L33AB     		;3371 3838	<L33AB>
L3373:	JR   C,L33AC     		;3373 3837	<L33AC>
	JR   NC,L33BA    		;3375 3043	<L33BA>
	JR   NC,L33B2    		;3377 3039	<L33B2>
	JR   C,L33B2     		;3379 3837	<L33B2>
	JR   NC,L33AE    		;337B 3031	<L33AE>
	LD   (HL),0DH  			;337D 360D	<0DH>
	LD   A,(BC)  			;337F 0A
	LD   A,(M3032)   		;3380 3A3230	<M3032>
	LD   SP,M3635    		;3383 313536	<M3635>
L3386:	JR   NC,L33B8    		;3386 3030	<L33B8>
	JR   NC,L33CF    		;3388 3045	<L33CF>
L338A:	JR   C,L33D1     		;338A 3845	<L33D1>
L338C:	JR   NC,L33D0    		;338C 3042	<L33D0>
L338E:	JR   NC,L33C9    		;338E 3039	<L33C9>
L3390:	JR   C,L33C2     		;3390 3830	<L33C2>
L3392:	INC  SP      			;3392 33
	DEC  (HL)    			;3393 35
L3394:	JR   C,L33C8     		;3394 3832	<L33C8>
L3396:	JR   C,L33C8     		;3396 3830	<L33C8>
L3398:	JR   NC,L33DD    		;3398 3043	<L33DD>
L339A:	JR   C,L33E0     		;339A 3844	<L33E0>
L339C:	JR   C,L33E2     		;339C 3844	<L33E2>
	LD   SP,M3845    		;339E 314538	<M3845>
	LD   B,L     			;33A1 45
L33A2:	LD   B,L     			;33A2 45
	ADD  HL,SP   			;33A3 39
L33A4:	JR   NC,L33DC    		;33A4 3036	<L33DC>
	JR   C,L33DB     		;33A6 3833	<L33DB>
	ADD  HL,SP   			;33A8 39
	JR   NC,L33E3    		;33A9 3038	<L33E3>
L33AB:	LD   B,E     			;33AB 43
L33AC:	LD   B,L     			;33AC 45
	LD   B,L     			;33AD 45
L33AE:	JR   NC,L33E8    		;33AE 3038	<L33E8>
	JR   C,L33E8     		;33B0 3836	<L33E8>
L33B2:	JR   NC,L33E7    		;33B2 3033	<L33E7>
L33B4:	DEC  (HL)    			;33B4 35
	JR   NC,L33EF    		;33B5 3038	<L33EF>
	LD   B,E     			;33B7 43
L33B8:	LD   B,L     			;33B8 45
	LD   B,L     			;33B9 45
L33BA:	JR   NC,L33F4    		;33BA 3038	<L33F4>
	LD   B,H     			;33BC 44
	JR   NC,L33F0    		;33BD 3031	<L33F0>
	INC  SP      			;33BF 33
	JR   C,L33F2     		;33C0 3830	<L33F2>
L33C2:	JR   C,L3407     		;33C2 3843	<L3407>
	LD   B,C     			;33C4 41
	LD   B,L     			;33C5 45
	JR   NC,L3400    		;33C6 3038	<L3400>
L33C8:	JR   C,L340E     		;33C8 3844	<L340E>
	SCF          			;33CA 37
	DEC  C       			;33CB 0D
	LD   A,(BC)  			;33CC 0A
	LD   A,(M3032)   		;33CD 3A3230	<M3032>
L33D0:	LD   SP,M3835    		;33D0 313538	<M3835>
	JR   NC,L3405    		;33D3 3030	<L3405>
	JR   NC,L340C    		;33D5 3035	<L340C>
	JR   C,L340B     		;33D7 3832	<L340B>
	LD   B,E     			;33D9 43
	LD   B,H     			;33DA 44
L33DB:	JR   NC,L3420    		;33DB 3043	<L3420>
L33DD:	JR   C,L3423     		;33DD 3844	<L3423>
	JR   C,L3425     		;33DF 3844	<L3425>
	JR   NC,L3426    		;33E1 3043	<L3426>
L33E3:	LD   B,E     			;33E3 43
	LD   B,E     			;33E4 43
	JR   C,L341E     		;33E5 3837	<L341E>
L33E7:	JR   C,L341F     		;33E7 3836	<L341F>
	JR   NC,L341E    		;33E9 3033	<L341E>
	JR   NC,L341D    		;33EB 3030	<L341D>
	JR   NC,L3433    		;33ED 3044	<L3433>
L33EF:	LD   B,E     			;33EF 43
L33F0:	LD   B,C     			;33F0 41
	LD   B,C     			;33F1 41
L33F2:	SCF          			;33F2 37
	LD   B,H     			;33F3 44
L33F4:	DEC  (HL)    			;33F4 35
	JR   NC,L3427    		;33F5 3030	<L3427>
	LD   (HL),45H  			;33F7 3645	<45H>
	JR   NC,L343E    		;33F9 3043	<L343E>
	JR   C,L3441     		;33FB 3844	<L3441>
	JR   NC,L3436    		;33FD 3037	<L3436>
	JR   C,L3437     		;33FF 3836	<L3437>
	JR   NC,L3436    		;3401 3033	<L3436>
	INC  (HL)    			;3403 34
	JR   NC,L3436    		;3404 3030	<L3436>
	LD   B,L     			;3406 45
L3407:	LD   (M3045),A   		;3407 324530	<M3045>
	LD   B,L     			;340A 45
L340B:	JR   NC,L3450    		;340B 3043	<L3450>
	LD   B,E     			;340D 43
L340E:	LD   B,E     			;340E 43
	JR   C,L3448     		;340F 3837	<L3448>
	LD   B,C     			;3411 41
	LD   (HL),30H  			;3412 3630	<30H>
	INC  (HL)    			;3414 34
	JR   NC,L3459    		;3415 3042	<L3459>
	LD   B,L     			;3417 45
	DEC  C       			;3418 0D
	LD   A,(BC)  			;3419 0A
	LD   A,(M3032)   		;341A 3A3230	<M3032>
L341D:	LD   SP,M4135    		;341D 313541	<M4135>
L3420:	JR   NC,L3452    		;3420 3030	<L3452>
	JR   NC,L3454    		;3422 3030	<L3454>
	JR   NC,L345C    		;3424 3036	<L345C>
L3426:	INC  (HL)    			;3426 34
L3427:	INC  SP      			;3427 33
	JR   NC,L346D    		;3428 3043	<L346D>
	LD   B,E     			;342A 43
	LD   B,H     			;342B 44
	JR   NC,L3471    		;342C 3043	<L3471>
	LD   B,H     			;342E 44
	JR   NC,L3465    		;342F 3034	<L3465>
M3431:	LD   B,E     			;3431 43
M3432:	JR   C,L3479     		;3432 3845	<L3479>
M3434:	LD   B,E     			;3434 43
M3435:	LD   B,L     			;3435 45
L3436:	JR   NC,L346B    		;3436 3033	<L346B>
M3438:	LD   B,E     			;3438 43
M3439:	JR   NC,L3473    		;3439 3038	<L3473>
	LD   B,E     			;343B 43
	LD   B,E     			;343C 43
	LD   B,L     			;343D 45
L343E:	JR   C,L3485     		;343E 3845	<L3485>
	JR   NC,L3486    		;3440 3044	<L3486>
M3442:	LD   B,E     			;3442 43
M3443:	LD   B,H     			;3443 44
M3444:	JR   NC,L3489    		;3444 3043	<L3489>
M3446:	LD   B,E     			;3446 43
	LD   B,L     			;3447 45
L3448:	JR   C,L347E     		;3448 3834	<L347E>
	JR   NC,L347D    		;344A 3031	<L347D>
	INC  (HL)    			;344C 34
	LD   B,H     			;344D 44
	JR   NC,L3493    		;344E 3043	<L3493>
L3450:	JR   C,L3495     		;3450 3843	<L3495>
L3452:	LD   B,E     			;3452 43
	LD   B,L     			;3453 45
L3454:	JR   C,L349B     		;3454 3845	<L349B>
	INC  (HL)    			;3456 34
	LD   B,H     			;3457 44
	JR   C,L349E     		;3458 3844	<L349E>
	INC  (HL)    			;345A 34
	JR   NC,L348F    		;345B 3032	<L348F>
	SCF          			;345D 37
	JR   NC,L3494    		;345E 3034	<L3494>
	JR   NC,L3493    		;3460 3031	<L3493>
	JR   NC,L349A    		;3462 3036	<L349A>
	LD   B,E     			;3464 43
L3465:	DEC  C       			;3465 0D
	LD   A,(BC)  			;3466 0A
	LD   A,(M3032)   		;3467 3A3230	<M3032>
	LD   SP,M4335    		;346A 313543	<M4335>
L346D:	JR   NC,L349F    		;346D 3030	<L349F>
	JR   NC,L34B5    		;346F 3044	<L34B5>
L3471:	JR   NC,L34B6    		;3471 3043	<L34B6>
L3473:	JR   C,L34B9     		;3473 3844	<L34B9>
	INC  (HL)    			;3475 34
	LD   B,E     			;3476 43
	JR   C,L34BC     		;3477 3843	<L34BC>
L3479:	INC  (HL)    			;3479 34
	ADD  HL,SP   			;347A 39
	JR   C,L34B3     		;347B 3836	<L34B3>
L347D:	JR   C,L34B2     		;347D 3833	<L34B2>
	LD   B,L     			;347F 45
	JR   NC,L34BA    		;3480 3038	<L34BA>
	LD   B,E     			;3482 43
	LD   B,E     			;3483 43
	LD   B,H     			;3484 44
L3485:	JR   C,L34CB     		;3485 3844	<L34CB>
	JR   NC,L34CC    		;3487 3043	<L34CC>
L3489:	JR   C,L34D0     		;3489 3845	<L34D0>
	LD   B,C     			;348B 41
	LD   B,L     			;348C 45
	JR   NC,L34D3    		;348D 3044	<L34D3>
L348F:	LD   B,E     			;348F 43
	LD   B,C     			;3490 41
	LD   B,C     			;3491 41
	SCF          			;3492 37
L3493:	LD   B,E     			;3493 43
L3494:	JR   NC,L34C8    		;3494 3032	<L34C8>
	LD   B,D     			;3496 42
	JR   NC,L34D1    		;3497 3038	<L34D1>
	JR   NC,L34D0    		;3499 3035	<L34D0>
L349B:	JR   NC,L34E2    		;349B 3045	<L34E2>
	JR   C,L34E4     		;349D 3845	<L34E4>
L349F:	JR   NC,L34E5    		;349F 3044	<L34E5>
	LD   B,E     			;34A1 43
	LD   B,H     			;34A2 44
	JR   NC,L34E8    		;34A3 3043	<L34E8>
	LD   B,E     			;34A5 43
	LD   B,L     			;34A6 45
	JR   C,L34EB     		;34A7 3842	<L34EB>
	JR   C,L34E3     		;34A9 3838	<L34E3>
	LD   B,E     			;34AB 43
	LD   B,C     			;34AC 41
	JR   C,L34E6     		;34AD 3837	<L34E6>
	LD   B,E     			;34AF 43
	LD   B,D     			;34B0 42
	INC  SP      			;34B1 33
L34B2:	DEC  C       			;34B2 0D
L34B3:	LD   A,(BC)  			;34B3 0A
	LD   A,(M3032)   		;34B4 3A3230	<M3032>
	LD   SP,M4535    		;34B7 313545	<M4535>
L34BA:	JR   NC,L34EC    		;34BA 3030	<L34EC>
L34BC:	JR   NC,L34F4    		;34BC 3036	<L34F4>
	JR   C,L34F3     		;34BE 3833	<L34F3>
	JR   C,L34F2     		;34C0 3830	<L34F2>
	JR   C,L3507     		;34C2 3843	<L3507>
	LD   B,C     			;34C4 41
	INC  SP      			;34C5 33
	JR   NC,L350B    		;34C6 3043	<L350B>
L34C8:	LD   B,E     			;34C8 43
	LD   B,L     			;34C9 45
	JR   C,L3511     		;34CA 3845	<L3511>
L34CC:	JR   NC,L34FE    		;34CC 3030	<L34FE>
	LD   SP,M3839    		;34CE 313938	<M3839>
L34D1:	SCF          			;34D1 37
	JR   NC,L350D    		;34D2 3039	<L350D>
	JR   C,L3519     		;34D4 3843	<L3519>
	JR   NC,L3511    		;34D6 3039	<L3511>
	JR   C,L3510     		;34D8 3836	<L3510>
	JR   NC,L350F    		;34DA 3033	<L350F>
	JR   C,L350E     		;34DC 3830	<L350E>
	JR   NC,L3521    		;34DE 3041	<L3521>
	JR   NC,L351B    		;34E0 3039	<L351B>
L34E2:	JR   NC,L3526    		;34E2 3042	<L3526>
L34E4:	JR   C,L352A     		;34E4 3844	<L352A>
L34E6:	JR   C,L3529     		;34E6 3841	<L3529>
L34E8:	JR   NC,L3523    		;34E8 3039	<L3523>
	JR   C,L3523     		;34EA 3837	<L3523>
L34EC:	JR   NC,L3522    		;34EC 3034	<L3522>
	JR   C,L3522     		;34EE 3832	<L3522>
	JR   NC,L3537    		;34F0 3045	<L3537>
L34F2:	JR   C,L3537     		;34F2 3843	<L3537>
L34F4:	JR   NC,L352F    		;34F4 3039	<L352F>
	JR   C,L353B     		;34F6 3843	<L353B>
	JR   NC,L352A    		;34F8 3030	<L352A>
	LD   (M3834),A   		;34FA 323438	<M3834>
	JR   NC,L3540    		;34FD 3041	<L3540>
	DEC  C       			;34FF 0D
	LD   A,(BC)  			;3500 0A
	LD   A,(M3032)   		;3501 3A3230	<M3032>
	LD   SP,M3036    		;3504 313630	<M3036>
L3507:	JR   NC,L3539    		;3507 3030	<L3539>
	JR   NC,L353C    		;3509 3031	<L353C>
L350B:	JR   C,L3541     		;350B 3834	<L3541>
L350D:	JR   C,L3541     		;350D 3832	<L3541>
L350F:	JR   NC,L354A    		;350F 3039	<L354A>
L3511:	JR   C,L354A     		;3511 3837	<L354A>
	JR   NC,L3548    		;3513 3033	<L3548>
	LD   B,E     			;3515 43
	JR   NC,L3548    		;3516 3030	<L3548>
	LD   B,E     			;3518 43
L3519:	JR   NC,L3554    		;3519 3039	<L3554>
L351B:	JR   C,L3554     		;351B 3837	<L3554>
	JR   NC,L3557    		;351D 3038	<L3557>
	LD   B,E     			;351F 43
	SCF          			;3520 37
L3521:	JR   NC,L3557    		;3521 3034	<L3557>
L3523:	JR   NC,L3557    		;3523 3032	<L3557>
	JR   NC,L355B    		;3525 3034	<L355B>
	JR   C,L355B     		;3527 3832	<L355B>
L3529:	JR   NC,L356F    		;3529 3044	<L356F>
	JR   C,L356F     		;352B 3842	<L356F>
	INC  (HL)    			;352D 34
	ADD  HL,SP   			;352E 39
L352F:	JR   C,L3567     		;352F 3836	<L3567>
M3531:	JR   C,L3563     		;3531 3830	<L3563>
M3533:	LD   SP,M3843    		;3533 314338	<M3843>
	LD   B,L     			;3536 45
L3537:	JR   C,L356F     		;3537 3836	<L356F>
L3539:	JR   C,L356F     		;3539 3834	<L356F>
L353B:	JR   C,L356E     		;353B 3831	<L356E>
	JR   C,L3583     		;353D 3844	<L3583>
	JR   C,L3585     		;353F 3844	<L3585>
L3541:	JR   NC,L3586    		;3541 3043	<L3586>
	JR   C,L358A     		;3543 3845	<L358A>
M3545:	JR   C,L3589     		;3545 3842	<L3589>
	JR   C,L3581     		;3547 3838	<L3581>
	JR   C,L358F     		;3549 3844	<L358F>
	LD   B,H     			;354B 44
	DEC  C       			;354C 0D
	LD   A,(BC)  			;354D 0A
	LD   A,(M3032)   		;354E 3A3230	<M3032>
	LD   SP,M3236    		;3551 313632	<M3236>
L3554:	JR   NC,L3586    		;3554 3030	<L3586>
	JR   NC,L358D    		;3556 3035	<L358D>
	JR   C,L358C     		;3558 3832	<L358C>
	JR   C,L3592     		;355A 3836	<L3592>
	JR   NC,L3591    		;355C 3033	<L3591>
	JR   NC,L3590    		;355E 3030	<L3590>
	JR   NC,L35A7    		;3560 3045	<L35A7>
	JR   C,L3598     		;3562 3834	<L3598>
	JR   C,L35AB     		;3564 3845	<L35AB>
	INC  (HL)    			;3566 34
L3567:	LD   B,H     			;3567 44
	JR   C,L35AE     		;3568 3844	<L35AE>
	JR   NC,L359C    		;356A 3030	<L359C>
	LD   (M3441),A   		;356C 324134	<M3441>
L356F:	ADD  HL,SP   			;356F 39
	JR   C,L35B4     		;3570 3842	<L35B4>
	JR   C,L35AC     		;3572 3838	<L35AC>
	JR   C,L35AB     		;3574 3835	<L35AB>
	LD   B,E     			;3576 43
	LD   (M3238),A   		;3577 323832	<M3238>
	JR   NC,L35C1    		;357A 3045	<L35C1>
	JR   NC,L35C2    		;357C 3044	<L35C2>
	JR   C,L35C1     		;357E 3841	<L35C1>
	LD   B,E     			;3580 43
L3581:	SCF          			;3581 37
	JR   C,L35C9     		;3582 3845	<L35C9>
	JR   C,L35CB     		;3584 3845	<L35CB>
L3586:	JR   NC,L35CC    		;3586 3044	<L35CC>
	JR   C,L35CB     		;3588 3841	<L35CB>
L358A:	LD   B,E     			;358A 43
	SCF          			;358B 37
L358C:	JR   C,L35C3     		;358C 3835	<L35C3>
	JR   NC,L35C4    		;358E 3034	<L35C4>
L3590:	LD   B,E     			;3590 43
L3591:	LD   SP,M4438    		;3591 313844	<M4438>
	JR   C,L35CE     		;3594 3838	<L35CE>
	JR   NC,L35C9    		;3596 3031	<L35C9>
L3598:	JR   NC,L35A7    		;3598 300D	<L35A7>
	LD   A,(BC)  			;359A 0A
	LD   A,(M3032)   		;359B 3A3230	<M3032>
	LD   SP,M3436    		;359E 313634	<M3436>
	JR   NC,L35D3    		;35A1 3030	<L35D3>
	JR   NC,L35D5    		;35A3 3030	<L35D5>
	LD   SP,M3837    		;35A5 313738	<M3837>
	LD   B,E     			;35A8 43
	JR   C,L35F0     		;35A9 3845	<L35F0>
L35AB:	JR   NC,L35F1    		;35AB 3044	<L35F1>
	JR   C,L35F3     		;35AD 3844	<L35F3>
	JR   NC,L35F5    		;35AF 3044	<L35F5>
	JR   NC,L35F6    		;35B1 3043	<L35F6>
	JR   C,L35F7     		;35B3 3842	<L35F7>
	JR   NC,L35F9    		;35B5 3042	<L35F9>
	JR   C,L35FD     		;35B7 3844	<L35FD>
	JR   NC,L35FE    		;35B9 3043	<L35FE>
	JR   C,L35FE     		;35BB 3841	<L35FE>
	JR   NC,L3601    		;35BD 3042	<L3601>
	JR   C,L3602     		;35BF 3841	<L3602>
L35C1:	JR   C,L35FA     		;35C1 3837	<L35FA>
L35C3:	JR   C,L35FA     		;35C3 3835	<L35FA>
	JR   NC,L35F9    		;35C5 3032	<L35F9>
	JR   C,L35FA     		;35C7 3831	<L35FA>
L35C9:	JR   C,L360F     		;35C9 3844	<L360F>
L35CB:	JR   C,L360E     		;35CB 3841	<L360E>
	JR   C,L3610     		;35CD 3841	<L3610>
	JR   C,L3601     		;35CF 3830	<L3601>
	LD   (M3831),A   		;35D1 323138	<M3831>
	LD   B,E     			;35D4 43
L35D5:	JR   C,L361A     		;35D5 3843	<L361A>
	JR   C,L361C     		;35D7 3843	<L361C>
	JR   C,L361D     		;35D9 3842	<L361D>
	JR   NC,L3615    		;35DB 3038	<L3615>
	JR   NC,L3614    		;35DD 3035	<L3614>
	JR   NC,L3615    		;35DF 3034	<L3615>
	JR   NC,L3614    		;35E1 3031	<L3614>
	JR   NC,L3627    		;35E3 3042	<L3627>
	SCF          			;35E5 37
	DEC  C       			;35E6 0D
	LD   A,(BC)  			;35E7 0A
	LD   A,(M3032)   		;35E8 3A3230	<M3032>
	LD   SP,M3636    		;35EB 313636	<M3636>
	JR   NC,L3620    		;35EE 3030	<L3620>
L35F0:	JR   NC,L3622    		;35F0 3030	<L3622>
	JR   C,L3638     		;35F2 3844	<L3638>
	JR   NC,L363B    		;35F4 3045	<L363B>
L35F6:	JR   C,L363D     		;35F6 3845	<L363D>
	JR   NC,L363F    		;35F8 3045	<L363F>
L35FA:	JR   NC,L3640    		;35FA 3044	<L3640>
	JR   C,L3642     		;35FC 3844	<L3642>
L35FE:	JR   C,L3641     		;35FE 3841	<L3641>
	JR   C,L363A     		;3600 3838	<L363A>
L3602:	JR   NC,L363A    		;3602 3036	<L363A>
	JR   NC,L363A    		;3604 3034	<L363A>
	JR   NC,L3639    		;3606 3031	<L3639>
	JR   NC,L363A    		;3608 3030	<L363A>
	INC  SP      			;360A 33
	LD   B,L     			;360B 45
	JR   C,L3653     		;360C 3845	<L3653>
L360E:	JR   C,L3655     		;360E 3845	<L3655>
L3610:	JR   C,L3657     		;3610 3845	<L3657>
	JR   C,L3659     		;3612 3845	<L3659>
L3614:	JR   C,L365B     		;3614 3845	<L365B>
	JR   C,L365D     		;3616 3845	<L365D>
	JR   C,L365F     		;3618 3845	<L365F>
L361A:	JR   C,L3661     		;361A 3845	<L3661>
L361C:	JR   C,L3652     		;361C 3834	<L3652>
	JR   C,L3652     		;361E 3832	<L3652>
L3620:	JR   NC,L3667    		;3620 3045	<L3667>
L3622:	JR   C,L3669     		;3622 3845	<L3669>
	JR   C,L366B     		;3624 3845	<L366B>
	JR   C,L366D     		;3626 3845	<L366D>
	JR   C,L366D     		;3628 3843	<L366D>
	JR   NC,L3665    		;362A 3039	<L3665>
	JR   C,L3665     		;362C 3837	<L3665>
	JR   NC,L3664    		;362E 3034	<L3664>
M3630:	JR   C,L3663     		;3630 3831	<L3663>
M3632:	LD   B,(HL)  			;3632 46
M3633:	DEC  C       			;3633 0D
M3634:	LD   A,(BC)  			;3634 0A
M3635:	LD   A,(M3032)   		;3635 3A3230	<M3032>
L3638:	LD   SP,M3836    		;3638 313638	<M3836>
L363B:	JR   NC,L366D    		;363B 3030	<L366D>
L363D:	JR   NC,L3671    		;363D 3032	<L3671>
L363F:	JR   NC,L3686    		;363F 3045	<L3686>
L3641:	JR   C,L3673     		;3641 3830	<L3673>
M3643:	LD   SP,M3031    		;3643 313130	<M3031>
M3646:	LD   (M4138),A   		;3646 323841	<M4138>
	JR   NC,L3682    		;3649 3037	<L3682>
	JR   C,L368F     		;364B 3842	<L368F>
	JR   NC,L3687    		;364D 3038	<L3687>
	JR   NC,L3686    		;364F 3035	<L3686>
	JR   NC,L3687    		;3651 3034	<L3687>
L3653:	JR   NC,L3686    		;3653 3031	<L3686>
L3655:	JR   NC,L369B    		;3655 3044	<L369B>
L3657:	JR   C,L369C     		;3657 3843	<L369C>
L3659:	JR   C,L369C     		;3659 3841	<L369C>
L365B:	JR   NC,L3694    		;365B 3037	<L3694>
L365D:	JR   C,L36A1     		;365D 3842	<L36A1>
L365F:	JR   NC,L3699    		;365F 3038	<L3699>
L3661:	JR   C,L36A6     		;3661 3843	<L36A6>
L3663:	JR   C,L36A8     		;3663 3843	<L36A8>
L3665:	JR   C,L36AA     		;3665 3843	<L36AA>
L3667:	JR   C,L36AD     		;3667 3844	<L36AD>
L3669:	JR   NC,L36AE    		;3669 3043	<L36AE>
L366B:	JR   C,L36B2     		;366B 3845	<L36B2>
L366D:	JR   NC,L369F    		;366D 3030	<L369F>
	LD   (M3830),A   		;366F 323038	<M3830>
	LD   (M3038),A   		;3672 323830	<M3038>
	JR   C,L36AE     		;3675 3837	<L36AE>
	JR   C,L36BB     		;3677 3842	<L36BB>
	JR   NC,L36BF    		;3679 3044	<L36BF>
	INC  (HL)    			;367B 34
	LD   B,E     			;367C 43
	JR   C,L36B5     		;367D 3836	<L36B5>
	INC  SP      			;367F 33
	DEC  C       			;3680 0D
	LD   A,(BC)  			;3681 0A
L3682:	LD   A,(M3032)   		;3682 3A3230	<M3032>
	LD   SP,M4136    		;3685 313641	<M4136>
	JR   NC,L36BA    		;3688 3030	<L36BA>
	JR   NC,L36D1    		;368A 3045	<L36D1>
	INC  (HL)    			;368C 34
	LD   B,L     			;368D 45
	JR   NC,L36D4    		;368E 3044	<L36D4>
	JR   C,L36D5     		;3690 3843	<L36D5>
	LD   B,L     			;3692 45
	JR   NC,L36C5    		;3693 3030	<L36C5>
	SCF          			;3695 37
	LD   B,E     			;3696 43
	LD   (HL),30H  			;3697 3630	<30H>
L3699:	LD   B,H     			;3699 44
	JR   NC,L36DF    		;369A 3043	<L36DF>
L369C:	JR   C,L36E2     		;369C 3844	<L36E2>
	LD   (HL),41H  			;369E 3641	<41H>
	JR   NC,L36D9    		;36A0 3037	<L36D9>
	LD   B,E     			;36A2 43
	DEC  (HL)    			;36A3 35
	JR   NC,L36D8    		;36A4 3032	<L36D8>
L36A6:	LD   B,L     			;36A6 45
	JR   NC,L36DC    		;36A7 3033	<L36DC>
	LD   B,H     			;36A9 44
L36AA:	JR   NC,L36DE    		;36AA 3032	<L36DE>
	JR   C,L36DE     		;36AC 3830	<L36DE>
L36AE:	JR   C,L36F3     		;36AE 3843	<L36F3>
	JR   C,L36F6     		;36B0 3844	<L36F6>
L36B2:	JR   C,L36F5     		;36B2 3841	<L36F5>
	LD   B,E     			;36B4 43
L36B5:	SCF          			;36B5 37
	JR   C,L36EE     		;36B6 3836	<L36EE>
	LD   B,E     			;36B8 43
	INC  SP      			;36B9 33
L36BA:	JR   C,L36ED     		;36BA 3831	<L36ED>
	JR   NC,L3702    		;36BC 3044	<L3702>
	INC  (HL)    			;36BE 34
L36BF:	JR   NC,L36F1    		;36BF 3030	<L36F1>
	SCF          			;36C1 37
	LD   B,E     			;36C2 43
	LD   (HL),30H  			;36C3 3630	<30H>
L36C5:	INC  SP      			;36C5 33
	JR   NC,L370B    		;36C6 3043	<L370B>
	JR   C,L370B     		;36C8 3841	<L370B>
	LD   B,E     			;36CA 43
	JR   NC,L3711    		;36CB 3044	<L3711>
	DEC  C       			;36CD 0D
	LD   A,(BC)  			;36CE 0A
	LD   A,(M3032)   		;36CF 3A3230	<M3032>
	LD   SP,M4336    		;36D2 313643	<M4336>
L36D5:	JR   NC,L3707    		;36D5 3030	<L3707>
	JR   NC,L371C    		;36D7 3043	<L371C>
L36D9:	JR   C,L371E     		;36D9 3843	<L371E>
	LD   B,E     			;36DB 43
L36DC:	LD   B,E     			;36DC 43
	JR   C,L3722     		;36DD 3843	<L3722>
L36DF:	LD   B,E     			;36DF 43
	JR   NC,L3713    		;36E0 3031	<L3713>
L36E2:	LD   B,H     			;36E2 44
	JR   C,L3729     		;36E3 3844	<L3729>
	JR   NC,L372A    		;36E5 3043	<L372A>
	JR   C,L372E     		;36E7 3845	<L372E>
	JR   NC,L372F    		;36E9 3044	<L372F>
	JR   C,L3731     		;36EB 3844	<L3731>
L36ED:	JR   NC,L3730    		;36ED 3041	<L3730>
	LD   B,E     			;36EF 43
	JR   C,L3722     		;36F0 3830	<L3722>
	DEC  (HL)    			;36F2 35
L36F3:	JR   NC,L3728    		;36F3 3033	<L3728>
L36F5:	JR   C,L3727     		;36F5 3830	<L3727>
	JR   C,L373C     		;36F7 3843	<L373C>
	LD   B,E     			;36F9 43
	LD   B,H     			;36FA 44
	JR   NC,L3740    		;36FB 3043	<L3740>
	JR   C,L3743     		;36FD 3844	<L3743>
	JR   C,L3742     		;36FF 3841	<L3742>
	JR   C,L373A     		;3701 3837	<L373A>
	JR   C,L3749     		;3703 3844	<L3749>
	LD   B,E     			;3705 43
	LD   B,H     			;3706 44
L3707:	JR   NC,L374C    		;3707 3043	<L374C>
	LD   B,L     			;3709 45
	LD   B,L     			;370A 45
L370B:	JR   NC,L373D    		;370B 3030	<L373D>
	LD   (M3037),A   		;370D 323730	<M3037>
	INC  (HL)    			;3710 34
L3711:	INC  (HL)    			;3711 34
	LD   B,D     			;3712 42
L3713:	JR   NC,L374D    		;3713 3038	<L374D>
	JR   NC,L374E    		;3715 3037	<L374E>
	INC  (HL)    			;3717 34
	LD   SP,M0D44    		;3718 31440D	<M0D44>
	LD   A,(BC)  			;371B 0A
L371C:	LD   A,(M3032)   		;371C 3A3230	<M3032>
	LD   SP,M4536    		;371F 313645	<M4536>
L3722:	JR   NC,L3754    		;3722 3030	<L3754>
	JR   NC,L375A    		;3724 3034	<L375A>
	JR   NC,L3759    		;3726 3031	<L3759>
L3728:	JR   NC,L376E    		;3728 3044	<L376E>
L372A:	JR   NC,L3763    		;372A 3037	<L3763>
	JR   C,L3765     		;372C 3837	<L3765>
L372E:	INC  (HL)    			;372E 34
L372F:	INC  (HL)    			;372F 34
L3730:	JR   NC,L3763    		;3730 3031	<L3763>
M3732:	JR   NC,L3778    		;3732 3044	<L3778>
	JR   NC,L377B    		;3734 3045	<L377B>
M3736:	JR   C,L377A     		;3736 3842	<L377A>
	LD   B,E     			;3738 43
M3739:	JR   C,L3773     		;3739 3838	<L3773>
	SCF          			;373B 37
L373C:	JR   NC,L3772    		;373C 3034	<L3772>
	JR   NC,L3771    		;373E 3031	<L3771>
L3740:	INC  (HL)    			;3740 34
	LD   B,C     			;3741 41
L3742:	JR   C,L377B     		;3742 3837	<L377B>
	JR   C,L3776     		;3744 3830	<L3776>
M3746:	LD   SP,M3843    		;3746 314338	<M3843>
L3749:	LD   B,H     			;3749 44
	JR   C,L3790     		;374A 3844	<L3790>
L374C:	JR   NC,L3791    		;374C 3043	<L3791>
L374E:	JR   C,L3793     		;374E 3843	<L3793>
	JR   C,L3795     		;3750 3843	<L3795>
	JR   C,L3799     		;3752 3845	<L3799>
L3754:	JR   NC,L3786    		;3754 3030	<L3786>
	JR   NC,L379B    		;3756 3043	<L379B>
	JR   C,L379D     		;3758 3843	<L379D>
L375A:	JR   C,L37A1     		;375A 3845	<L37A1>
	JR   NC,L37A2    		;375C 3044	<L37A2>
	JR   C,L3790     		;375E 3830	<L3790>
	JR   NC,L37A3    		;3760 3041	<L37A3>
	JR   NC,L37A7    		;3762 3043	<L37A7>
	JR   C,L379B     		;3764 3835	<L379B>
	DEC  (HL)    			;3766 35
	DEC  C       			;3767 0D
	LD   A,(BC)  			;3768 0A
	LD   A,(M3032)   		;3769 3A3230	<M3032>
	LD   SP,M3037    		;376C 313730	<M3037>
	JR   NC,L37A1    		;376F 3030	<L37A1>
L3771:	JR   NC,L37B7    		;3771 3044	<L37B7>
L3773:	JR   NC,L37B8    		;3773 3043	<L37B8>
	JR   C,L37BA     		;3775 3843	<L37BA>
	JR   C,L37BC     		;3777 3843	<L37BC>
	JR   C,L37BE     		;3779 3843	<L37BE>
L377B:	JR   C,L37C0     		;377B 3843	<L37C0>
	JR   C,L37AF     		;377D 3830	<L37AF>
	DEC  (HL)    			;377F 35
	LD   (HL),30H  			;3780 3630	<30H>
	INC  SP      			;3782 33
	INC  (HL)    			;3783 34
	JR   NC,L37B6    		;3784 3030	<L37B6>
L3786:	LD   B,H     			;3786 44
	LD   B,E     			;3787 43
	LD   B,H     			;3788 44
	INC  (HL)    			;3789 34
	LD   B,E     			;378A 43
	JR   C,L37D0     		;378B 3843	<L37D0>
	LD   B,L     			;378D 45
	LD   B,C     			;378E 41
	JR   NC,L37C9    		;378F 3038	<L37C9>
L3791:	JR   NC,L37C9    		;3791 3036	<L37C9>
L3793:	INC  (HL)    			;3793 34
	INC  SP      			;3794 33
L3795:	LD   (M3030),A   		;3795 323030	<M3030>
	LD   B,H     			;3798 44
L3799:	LD   B,E     			;3799 43
	LD   B,H     			;379A 44
L379B:	LD   (M4344),A   		;379B 324443	<M4344>
	LD   B,H     			;379E 44
	DEC  (HL)    			;379F 35
	LD   B,E     			;37A0 43
L37A1:	JR   C,L37E7     		;37A1 3844	<L37E7>
L37A3:	LD   B,L     			;37A3 45
	LD   B,H     			;37A4 44
	JR   NC,L37E8    		;37A5 3041	<L37E8>
L37A7:	LD   SP,M3438    		;37A7 313834	<M3438>
	JR   NC,L37DD    		;37AA 3031	<L37DD>
	LD   B,L     			;37AC 45
	JR   NC,L37F3    		;37AD 3044	<L37F3>
L37AF:	INC  (HL)    			;37AF 34
	LD   B,C     			;37B0 41
	LD   (M4232),A   		;37B1 323242	<M4232>
	DEC  C       			;37B4 0D
	LD   A,(BC)  			;37B5 0A
L37B6:	LD   A,(M3032)   		;37B6 3A3230	<M3032>
	LD   SP,M3237    		;37B9 313732	<M3237>
L37BC:	JR   NC,L37EE    		;37BC 3030	<L37EE>
L37BE:	JR   NC,L37F7    		;37BE 3037	<L37F7>
L37C0:	LD   B,E     			;37C0 43
	DEC  (HL)    			;37C1 35
	JR   NC,L37F7    		;37C2 3033	<L37F7>
	JR   NC,L37F6    		;37C4 3030	<L37F6>
	INC  (HL)    			;37C6 34
	LD   B,H     			;37C7 44
	JR   NC,L380D    		;37C8 3043	<L380D>
	LD   B,E     			;37CA 43
	LD   B,H     			;37CB 44
	JR   C,L3812     		;37CC 3844	<L3812>
	LD   B,E     			;37CE 43
	LD   B,E     			;37CF 43
L37D0:	JR   C,L3816     		;37D0 3844	<L3816>
	LD   B,E     			;37D2 43
	LD   B,H     			;37D3 44
	JR   NC,L3818    		;37D4 3042	<L3818>
	INC  (HL)    			;37D6 34
	JR   C,L380B     		;37D7 3832	<L380B>
	LD   (HL),38H  			;37D9 3638	<38H>
	INC  SP      			;37DB 33
	LD   B,E     			;37DC 43
L37DD:	JR   NC,L3817    		;37DD 3038	<L3817>
	LD   B,E     			;37DF 43
	LD   B,L     			;37E0 45
	LD   B,E     			;37E1 43
	JR   C,L3814     		;37E2 3830	<L3814>
	LD   B,L     			;37E4 45
	LD   B,H     			;37E5 44
	LD   B,L     			;37E6 45
L37E7:	LD   B,E     			;37E7 43
L37E8:	ADD  HL,SP   			;37E8 39
	LD   B,E     			;37E9 43
	JR   C,L3821     		;37EA 3835	<L3821>
	LD   B,E     			;37EC 43
	INC  SP      			;37ED 33
L37EE:	LD   B,C     			;37EE 41
	JR   NC,L3829    		;37EF 3038	<L3829>
	LD   B,E     			;37F1 43
	LD   B,E     			;37F2 43
L37F3:	LD   B,L     			;37F3 45
	JR   NC,L383A    		;37F4 3044	<L383A>
L37F6:	LD   B,E     			;37F6 43
L37F7:	LD   B,H     			;37F7 44
	LD   (M3044),A   		;37F8 324430	<M3044>
	LD   B,E     			;37FB 43
	LD   B,E     			;37FC 43
	LD   B,H     			;37FD 44
	JR   NC,L3838    		;37FE 3038	<L3838>
	LD   B,E     			;3800 43
	DEC  C       			;3801 0D
	LD   A,(BC)  			;3802 0A
	LD   A,(M3032)   		;3803 3A3230	<M3032>
	LD   SP,M3437    		;3806 313734	<M3437>
	JR   NC,L383B    		;3809 3030	<L383B>
L380B:	JR   NC,L384F    		;380B 3042	<L384F>
L380D:	LD   B,C     			;380D 41
	JR   C,L3853     		;380E 3843	<L3853>
	DEC  (HL)    			;3810 35
	LD   B,E     			;3811 43
L3812:	INC  SP      			;3812 33
	JR   C,L3846     		;3813 3831	<L3846>
	LD   (HL),43H  			;3815 3643	<43H>
L3817:	JR   C,L385C     		;3817 3843	<L385C>
	LD   B,H     			;3819 44
	LD   B,L     			;381A 45
	JR   NC,L384D    		;381B 3030	<L384D>
	INC  SP      			;381D 33
	INC  SP      			;381E 33
	LD   B,C     			;381F 41
	JR   NC,L385A    		;3820 3038	<L385A>
	LD   B,E     			;3822 43
	LD   B,E     			;3823 43
	LD   B,L     			;3824 45
	LD   (M4338),A   		;3825 323843	<M4338>
	DEC  (HL)    			;3828 35
L3829:	LD   B,E     			;3829 43
	LD   (M3138),A   		;382A 323831	<M3138>
	LD   (M3444),A   		;382D 324434	<M3444>
M3830:	LD   B,H     			;3830 44
M3831:	LD   B,C     			;3831 41
M3832:	LD   B,H     			;3832 44
M3833:	INC  (HL)    			;3833 34
M3834:	LD   B,E     			;3834 43
M3835:	JR   C,L387B     		;3835 3844	<L387B>
M3837:	LD   B,E     			;3837 43
L3838:	JR   C,L386C     		;3838 3832	<L386C>
L383A:	LD   (HL),34H  			;383A 3634	<34H>
	INC  SP      			;383C 33
	LD   (M4343),A   		;383D 324343	<M4343>
	LD   B,H     			;3840 44
M3841:	JR   C,L3887     		;3841 3844	<L3887>
M3843:	LD   (M3837),A   		;3843 323738	<M3837>
L3846:	LD   (HL),43H  			;3846 3643	<43H>
	JR   NC,L387C    		;3848 3032	<L387C>
	LD   B,H     			;384A 44
	JR   NC,L388E    		;384B 3041	<L388E>
L384D:	DEC  (HL)    			;384D 35
	DEC  C       			;384E 0D
L384F:	LD   A,(BC)  			;384F 0A
	LD   A,(M3032)   		;3850 3A3230	<M3032>
L3853:	LD   SP,M3637    		;3853 313736	<M3637>
	JR   NC,L3888    		;3856 3030	<L3888>
	JR   NC,L389D    		;3858 3043	<L389D>
L385A:	LD   B,E     			;385A 43
	LD   B,H     			;385B 44
L385C:	JR   NC,L38A2    		;385C 3044	<L38A2>
	INC  (HL)    			;385E 34
	LD   B,E     			;385F 43
	LD   B,E     			;3860 43
	LD   B,E     			;3861 43
	JR   C,L38A7     		;3862 3843	<L38A7>
	LD   B,L     			;3864 45
	LD   B,E     			;3865 43
	JR   C,L38AB     		;3866 3843	<L38AB>
	LD   B,E     			;3868 43
	LD   B,H     			;3869 44
	JR   NC,L38AF    		;386A 3043	<L38AF>
L386C:	JR   C,L38AF     		;386C 3841	<L38AF>
	INC  (HL)    			;386E 34
	JR   C,L38A1     		;386F 3830	<L38A1>
	DEC  (HL)    			;3871 35
	JR   NC,L38A7    		;3872 3033	<L38A7>
	INC  (HL)    			;3874 34
	JR   NC,L38AC    		;3875 3035	<L38AC>
	LD   B,H     			;3877 44
	JR   C,L38BE     		;3878 3844	<L38BE>
	LD   B,L     			;387A 45
L387B:	LD   B,H     			;387B 44
L387C:	JR   NC,L38C3    		;387C 3045	<L38C3>
	DEC  (HL)    			;387E 35
	LD   B,H     			;387F 44
	LD   B,C     			;3880 41
	JR   NC,L38B7    		;3881 3034	<L38B7>
	LD   (HL),30H  			;3883 3630	<30H>
	INC  SP      			;3885 33
	INC  (HL)    			;3886 34
L3887:	JR   NC,L38BB    		;3887 3032	<L38BB>
	LD   B,L     			;3889 45
	INC  (HL)    			;388A 34
	LD   B,H     			;388B 44
	LD   B,H     			;388C 44
	LD   B,H     			;388D 44
L388E:	JR   NC,L38D3    		;388E 3043	<L38D3>
	LD   B,C     			;3890 41
	LD   B,H     			;3891 44
	JR   NC,L38CD    		;3892 3039	<L38CD>
	INC  (HL)    			;3894 34
	LD   (HL),32H  			;3895 3632	<32H>
	INC  SP      			;3897 33
	JR   NC,L38D2    		;3898 3038	<L38D2>
	LD   B,L     			;389A 45
	DEC  C       			;389B 0D
	LD   A,(BC)  			;389C 0A
L389D:	LD   A,(M3032)   		;389D 3A3230	<M3032>
	LD   SP,M3837    		;38A0 313738	<M3837>
	JR   NC,L38D5    		;38A3 3030	<L38D5>
	JR   NC,L38D7    		;38A5 3030	<L38D7>
L38A7:	INC  (HL)    			;38A7 34
	LD   B,H     			;38A8 44
	JR   NC,L38F0    		;38A9 3045	<L38F0>
L38AB:	JR   NC,L38E5    		;38AB 3038	<L38E5>
	LD   B,E     			;38AD 43
	DEC  (HL)    			;38AE 35
L38AF:	LD   B,C     			;38AF 41
	LD   (M3138),A   		;38B0 323831	<M3138>
	INC  (HL)    			;38B3 34
	LD   B,H     			;38B4 44
	JR   NC,L38F8    		;38B5 3041	<L38F8>
L38B7:	LD   (M3439),A   		;38B7 323934	<M3439>
	JR   NC,L38F2    		;38BA 3036	<L38F2>
	LD   B,H     			;38BC 44
	LD   SP,M4343    		;38BD 314343	<M4343>
	LD   B,H     			;38C0 44
	LD   (M4337),A   		;38C1 323743	<M4337>
	DEC  (HL)    			;38C4 35
	INC  (HL)    			;38C5 34
	INC  SP      			;38C6 33
	JR   NC,L38F9    		;38C7 3030	<L38F9>
	JR   NC,L390F    		;38C9 3044	<L390F>
	LD   (HL),43H  			;38CB 3643	<43H>
L38CD:	LD   B,H     			;38CD 44
	LD   B,H     			;38CE 44
	INC  (HL)    			;38CF 34
	LD   B,H     			;38D0 44
	JR   C,L3917     		;38D1 3844	<L3917>
L38D3:	LD   (HL),37H  			;38D3 3637	<37H>
L38D5:	ADD  HL,SP   			;38D5 39
	DEC  (HL)    			;38D6 35
L38D7:	JR   NC,L390C    		;38D7 3033	<L390C>
	INC  (HL)    			;38D9 34
	JR   NC,L390E    		;38DA 3032	<L390E>
	DEC  (HL)    			;38DC 35
	JR   C,L3911     		;38DD 3832	<L3911>
	LD   B,E     			;38DF 43
	LD   SP,M4530    		;38E0 313045	<M4530>
	LD   (HL),43H  			;38E3 3643	<43H>
L38E5:	JR   C,L3920     		;38E5 3839	<L3920>
	LD   (M0A0D),A   		;38E7 320D0A	<M0A0D>
	LD   A,(M3032)   		;38EA 3A3230	<M3032>
	LD   SP,M4137    		;38ED 313741	<M4137>
L38F0:	JR   NC,L3922    		;38F0 3030	<L3922>
L38F2:	JR   NC,L3924    		;38F2 3030	<L3924>
	LD   B,C     			;38F4 41
	LD   B,C     			;38F5 41
	LD   B,E     			;38F6 43
	SCF          			;38F7 37
L38F8:	LD   B,L     			;38F8 45
L38F9:	DEC  (HL)    			;38F9 35
	LD   B,E     			;38FA 43
	LD   (M3045),A   		;38FB 324530	<M3045>
	INC  (HL)    			;38FE 34
	LD   B,H     			;38FF 44
	LD   (HL),43H  			;3900 3643	<43H>
	LD   B,E     			;3902 43
	LD   B,E     			;3903 43
	LD   B,E     			;3904 43
	LD   B,E     			;3905 43
	LD   B,L     			;3906 45
	LD   B,C     			;3907 41
	INC  (HL)    			;3908 34
	JR   C,L393F     		;3909 3834	<L393F>
	DEC  (HL)    			;390B 35
L390C:	LD   (HL),32H  			;390C 3632	<32H>
L390E:	LD   B,E     			;390E 43
L390F:	JR   NC,L3956    		;390F 3045	<L3956>
L3911:	LD   B,E     			;3911 43
	LD   B,E     			;3912 43
	LD   B,H     			;3913 44
	LD   B,E     			;3914 43
	LD   B,H     			;3915 44
	LD   B,L     			;3916 45
L3917:	LD   B,H     			;3917 44
	LD   B,E     			;3918 43
	LD   B,H     			;3919 44
	JR   NC,L395F    		;391A 3043	<L395F>
	LD   B,E     			;391C 43
	LD   B,H     			;391D 44
	LD   B,L     			;391E 45
	JR   NC,L3959    		;391F 3038	<L3959>
	LD   B,E     			;3921 43
L3922:	LD   B,E     			;3922 43
	LD   B,C     			;3923 41
L3924:	LD   B,L     			;3924 45
	ADD  HL,SP   			;3925 39
	JR   NC,L395E    		;3926 3036	<L395E>
	INC  (HL)    			;3928 34
	LD   B,H     			;3929 44
	LD   (M3843),A   		;392A 324338	<M3843>
	LD   B,L     			;392D 45
	INC  (HL)    			;392E 34
	LD   B,L     			;392F 45
M3930:	JR   NC,L3976    		;3930 3044	<L3976>
M3932:	LD   B,E     			;3932 43
M3933:	LD   B,L     			;3933 45
	SCF          			;3934 37
	DEC  C       			;3935 0D
	LD   A,(BC)  			;3936 0A
M3937:	LD   A,(M3032)   		;3937 3A3230	<M3032>
	LD   SP,M4337    		;393A 313743	<M4337>
	JR   NC,L396F    		;393D 3030	<L396F>
L393F:	JR   NC,L3985    		;393F 3044	<L3985>
	LD   (M3843),A   		;3941 324338	<M3843>
M3944:	LD   B,L     			;3944 45
	INC  (HL)    			;3945 34
	LD   B,L     			;3946 45
	JR   NC,L398B    		;3947 3042	<L398B>
	JR   NC,L3983    		;3949 3038	<L3983>
	LD   B,E     			;394B 43
	DEC  (HL)    			;394C 35
	ADD  HL,SP   			;394D 39
	LD   (M3043),A   		;394E 324330	<M3043>
	LD   B,C     			;3951 41
	LD   B,L     			;3952 45
	JR   NC,L3999    		;3953 3044	<L3999>
	LD   B,H     			;3955 44
L3956:	LD   B,H     			;3956 44
	JR   NC,L3989    		;3957 3030	<L3989>
L3959:	LD   B,H     			;3959 44
	INC  SP      			;395A 33
	LD   B,C     			;395B 41
	JR   NC,L39A2    		;395C 3044	<L39A2>
L395E:	LD   B,E     			;395E 43
L395F:	LD   B,C     			;395F 41
	LD   B,H     			;3960 44
	JR   NC,L399A    		;3961 3037	<L399A>
	LD   B,E     			;3963 43
	DEC  (HL)    			;3964 35
	LD   (M3832),A   		;3965 323238	<M3832>
	JR   NC,L399E    		;3968 3034	<L399E>
	LD   B,E     			;396A 43
	LD   B,C     			;396B 41
	LD   B,H     			;396C 44
	JR   C,L39B3     		;396D 3844	<L39B3>
L396F:	INC  (HL)    			;396F 34
	LD   B,E     			;3970 43
	JR   C,L39B6     		;3971 3843	<L39B6>
	LD   B,C     			;3973 41
	SCF          			;3974 37
	LD   B,E     			;3975 43
L3976:	DEC  (HL)    			;3976 35
	LD   (M3433),A   		;3977 323334	<M3433>
	JR   NC,L39B2    		;397A 3036	<L39B2>
	LD   B,H     			;397C 44
	JR   C,L39C3     		;397D 3844	<L39C3>
	INC  SP      			;397F 33
	LD   B,D     			;3980 42
	JR   NC,L3990    		;3981 300D	<L3990>
L3983:	LD   A,(BC)  			;3983 0A
	LD   A,(M3032)   		;3984 3A3230	<M3032>
	LD   SP,M4537    		;3987 313745	<M4537>
	JR   NC,L39BC    		;398A 3030	<L39BC>
	JR   NC,L39C5    		;398C 3037	<L39C5>
	JR   C,L39C5     		;398E 3835	<L39C5>
L3990:	INC  (HL)    			;3990 34
	JR   NC,L39CC    		;3991 3039	<L39CC>
	LD   B,L     			;3993 45
	JR   NC,L39DA    		;3994 3044	<L39DA>
	LD   B,E     			;3996 43
	LD   B,H     			;3997 44
	LD   (M4337),A   		;3998 323743	<M4337>
	DEC  (HL)    			;399B 35
	JR   NC,L39D2    		;399C 3034	<L39D2>
L399E:	JR   NC,L39D1    		;399E 3031	<L39D1>
	JR   NC,L39E6    		;39A0 3044	<L39E6>
L39A2:	INC  (HL)    			;39A2 34
	LD   B,E     			;39A3 43
	LD   B,E     			;39A4 43
	LD   B,L     			;39A5 45
	JR   NC,L39EC    		;39A6 3044	<L39EC>
	JR   C,L39EE     		;39A8 3844	<L39EE>
	JR   NC,L39EF    		;39AA 3043	<L39EF>
	LD   B,E     			;39AC 43
	LD   B,E     			;39AD 43
	JR   C,L39F5     		;39AE 3845	<L39F5>
	INC  (HL)    			;39B0 34
	JR   C,L39F4     		;39B1 3841	<L39F4>
L39B3:	DEC  (HL)    			;39B3 35
	JR   C,L39E8     		;39B4 3832	<L39E8>
L39B6:	LD   B,E     			;39B6 43
	LD   SP,M4430    		;39B7 313044	<M4430>
	INC  (HL)    			;39BA 34
	LD   B,E     			;39BB 43
L39BC:	JR   C,L39EE     		;39BC 3830	<L39EE>
	LD   B,D     			;39BE 42
	LD   B,H     			;39BF 44
	LD   SP,M4343    		;39C0 314343	<M4343>
L39C3:	LD   B,H     			;39C3 44
	JR   NC,L3A09    		;39C4 3043	<L3A09>
	LD   B,E     			;39C6 43
	LD   B,H     			;39C7 44
	LD   B,C     			;39C8 41
	LD   B,H     			;39C9 44
	INC  (HL)    			;39CA 34
	LD   B,E     			;39CB 43
L39CC:	LD   B,C     			;39CC 41
	DEC  (HL)    			;39CD 35
	INC  (HL)    			;39CE 34
	DEC  C       			;39CF 0D
	LD   A,(BC)  			;39D0 0A
L39D1:	LD   A,(M3032)   		;39D1 3A3230	<M3032>
	LD   SP,M3038    		;39D4 313830	<M3038>
	JR   NC,L3A09    		;39D7 3030	<L3A09>
	JR   NC,L3A1F    		;39D9 3044	<L3A1F>
	JR   NC,L3A20    		;39DB 3043	<L3A20>
	LD   B,E     			;39DD 43
	LD   B,L     			;39DE 45
	LD   (M3844),A   		;39DF 324438	<M3844>
	LD   B,H     			;39E2 44
	INC  (HL)    			;39E3 34
	LD   B,E     			;39E4 43
	JR   C,L3A28     		;39E5 3841	<L3A28>
	INC  (HL)    			;39E7 34
L39E8:	ADD  HL,SP   			;39E8 39
	LD   (M3036),A   		;39E9 323630	<M3036>
L39EC:	INC  SP      			;39EC 33
	INC  (HL)    			;39ED 34
L39EE:	JR   NC,L3A31    		;39EE 3041	<L3A31>
	LD   B,E     			;39F0 43
	JR   C,L3A37     		;39F1 3844	<L3A37>
	INC  (HL)    			;39F3 34
L39F4:	LD   B,E     			;39F4 43
L39F5:	JR   C,L3A27     		;39F5 3830	<L3A27>
	LD   B,E     			;39F7 43
	LD   (HL),43H  			;39F8 3643	<43H>
	INC  SP      			;39FA 33
	LD   B,C     			;39FB 41
	JR   NC,L3A36    		;39FC 3038	<L3A36>
	LD   B,E     			;39FE 43
	LD   B,E     			;39FF 43
	LD   B,H     			;3A00 44
	LD   B,C     			;3A01 41
	LD   B,H     			;3A02 44
	JR   NC,L3A4A    		;3A03 3045	<L3A4A>
	INC  (HL)    			;3A05 34
	LD   B,H     			;3A06 44
	JR   C,L3A42     		;3A07 3839	<L3A42>
L3A09:	INC  (HL)    			;3A09 34
	LD   (HL),32H  			;3A0A 3632	<32H>
	INC  SP      			;3A0C 33
	JR   NC,L3A3F    		;3A0D 3030	<L3A3F>
	INC  (HL)    			;3A0F 34
	LD   B,H     			;3A10 44
	JR   C,L3A55     		;3A11 3842	<L3A55>
	JR   C,L3A4E     		;3A13 3839	<L3A4E>
	INC  (HL)    			;3A15 34
	LD   (HL),32H  			;3A16 3632	<32H>
	INC  SP      			;3A18 33
	JR   NC,L3A5F    		;3A19 3044	<L3A5F>
	LD   (M0A0D),A   		;3A1B 320D0A	<M0A0D>
	LD   A,(M3032)   		;3A1E 3A3230	<M3032>
	LD   SP,M3238    		;3A21 313832	<M3238>
	JR   NC,L3A56    		;3A24 3030	<L3A56>
	JR   NC,L3A58    		;3A26 3030	<L3A58>
L3A28:	INC  (HL)    			;3A28 34
	LD   B,H     			;3A29 44
	JR   NC,L3A6F    		;3A2A 3043	<L3A6F>
	LD   B,C     			;3A2C 41
	ADD  HL,SP   			;3A2D 39
	JR   NC,L3A60    		;3A2E 3030	<L3A60>
	SCF          			;3A30 37
L3A31:	LD   B,H     			;3A31 44
	JR   C,L3A78     		;3A32 3844	<L3A78>
	INC  (HL)    			;3A34 34
	LD   B,C     			;3A35 41
L3A36:	LD   (M3439),A   		;3A36 323934	<M3439>
	LD   (HL),30H  			;3A39 3630	<30H>
	INC  SP      			;3A3B 33
	INC  (HL)    			;3A3C 34
	LD   SP,M4438    		;3A3D 313844	<M4438>
	JR   C,L3A87     		;3A40 3845	<L3A87>
L3A42:	INC  (HL)    			;3A42 34
	LD   B,L     			;3A43 45
	JR   NC,L3A8A    		;3A44 3044	<L3A8A>
	LD   B,E     			;3A46 43
	LD   B,H     			;3A47 44
	JR   NC,L3A8D    		;3A48 3043	<L3A8D>
L3A4A:	LD   B,E     			;3A4A 43
	LD   B,L     			;3A4B 45
	JR   NC,L3A90    		;3A4C 3042	<L3A90>
L3A4E:	JR   NC,L3A88    		;3A4E 3038	<L3A88>
	JR   NC,L3A88    		;3A50 3036	<L3A88>
	LD   B,E     			;3A52 43
	INC  SP      			;3A53 33
	JR   C,L3A86     		;3A54 3830	<L3A86>
L3A56:	JR   C,L3A9B     		;3A56 3843	<L3A9B>
L3A58:	LD   B,E     			;3A58 43
	LD   B,E     			;3A59 43
	JR   C,L3A8C     		;3A5A 3830	<L3A8C>
	LD   (M4133),A   		;3A5C 323341	<M4133>
L3A5F:	JR   NC,L3A99    		;3A5F 3038	<L3A99>
	SCF          			;3A61 37
	LD   B,E     			;3A62 43
	LD   (HL),41H  			;3A63 3641	<41H>
	ADD  HL,SP   			;3A65 39
	INC  (HL)    			;3A66 34
	LD   B,E     			;3A67 43
	INC  SP      			;3A68 33
	DEC  C       			;3A69 0D
	LD   A,(BC)  			;3A6A 0A
	LD   A,(M3032)   		;3A6B 3A3230	<M3032>
	LD   SP,M3438    		;3A6E 313834	<M3438>
	JR   NC,L3AA3    		;3A71 3030	<L3AA3>
	JR   NC,L3AAB    		;3A73 3036	<L3AAB>
	LD   B,H     			;3A75 44
	LD   (M3038),A   		;3A76 323830	<M3038>
	LD   (M3441),A   		;3A79 324134	<M3441>
	ADD  HL,SP   			;3A7C 39
	LD   (M4335),A   		;3A7D 323543	<M4335>
	LD   (M3038),A   		;3A80 323830	<M3038>
	LD   (HL),37H  			;3A83 3637	<37H>
	ADD  HL,SP   			;3A85 39
L3A86:	DEC  (HL)    			;3A86 35
L3A87:	INC  (HL)    			;3A87 34
L3A88:	INC  SP      			;3A88 33
	LD   (M3430),A   		;3A89 323034	<M3430>
L3A8C:	LD   B,H     			;3A8C 44
L3A8D:	JR   C,L3AD0     		;3A8D 3841	<L3AD0>
	JR   C,L3AC8     		;3A8F 3837	<L3AC8>
	JR   C,L3AC8     		;3A91 3835	<L3AC8>
	INC  (HL)    			;3A93 34
	JR   NC,L3AC7    		;3A94 3031	<L3AC7>
	LD   B,H     			;3A96 44
	JR   NC,L3ADC    		;3A97 3043	<L3ADC>
L3A99:	LD   B,E     			;3A99 43
	LD   B,H     			;3A9A 44
L3A9B:	LD   (M4343),A   		;3A9B 324343	<M4343>
	LD   B,L     			;3A9E 45
	JR   NC,L3AE5    		;3A9F 3044	<L3AE5>
	JR   C,L3AE7     		;3AA1 3844	<L3AE7>
L3AA3:	JR   NC,L3AE8    		;3AA3 3043	<L3AE8>
	LD   B,E     			;3AA5 43
	LD   B,E     			;3AA6 43
	JR   C,L3AEE     		;3AA7 3845	<L3AEE>
	JR   NC,L3AEF    		;3AA9 3044	<L3AEF>
L3AAB:	JR   C,L3AF1     		;3AAB 3844	<L3AF1>
	INC  (HL)    			;3AAD 34
	SCF          			;3AAE 37
	JR   C,L3AE6     		;3AAF 3835	<L3AE6>
	JR   NC,L3AE5    		;3AB1 3032	<L3AE5>
	JR   C,L3AE5     		;3AB3 3830	<L3AE5>
	LD   B,(HL)  			;3AB5 46
	DEC  C       			;3AB6 0D
	LD   A,(BC)  			;3AB7 0A
	LD   A,(M3032)   		;3AB8 3A3230	<M3032>
	LD   SP,M3638    		;3ABB 313836	<M3638>
	JR   NC,L3AF0    		;3ABE 3030	<L3AF0>
	JR   NC,L3AF3    		;3AC0 3031	<L3AF3>
	LD   B,E     			;3AC2 43
	LD   B,H     			;3AC3 44
	JR   C,L3AF9     		;3AC4 3833	<L3AF9>
	JR   NC,L3B0B    		;3AC6 3043	<L3B0B>
L3AC8:	JR   C,L3B0E     		;3AC8 3844	<L3B0E>
	INC  (HL)    			;3ACA 34
	LD   B,E     			;3ACB 43
	JR   C,L3AFE     		;3ACC 3830	<L3AFE>
	LD   (M3035),A   		;3ACE 323530	<M3035>
	ADD  HL,SP   			;3AD1 39
	JR   C,L3B0A     		;3AD2 3836	<L3B0A>
	LD   B,E     			;3AD4 43
	INC  SP      			;3AD5 33
	JR   C,L3B08     		;3AD6 3830	<L3B08>
	JR   C,L3B1D     		;3AD8 3843	<L3B1D>
	JR   C,L3B21     		;3ADA 3845	<L3B21>
L3ADC:	JR   C,L3B20     		;3ADC 3842	<L3B20>
	LD   B,E     			;3ADE 43
	JR   C,L3B19     		;3ADF 3838	<L3B19>
	LD   B,C     			;3AE1 41
	JR   C,L3B1B     		;3AE2 3837	<L3B1B>
	JR   C,L3B1D     		;3AE4 3837	<L3B1D>
L3AE6:	JR   NC,L3B1C    		;3AE6 3034	<L3B1C>
L3AE8:	INC  (HL)    			;3AE8 34
	LD   SP,M3530    		;3AE9 313035	<M3530>
	JR   C,L3B20     		;3AEC 3832	<L3B20>
L3AEE:	LD   B,E     			;3AEE 43
L3AEF:	LD   (M4530),A   		;3AEF 323045	<M4530>
	JR   C,L3B39     		;3AF2 3845	<L3B39>
	JR   NC,L3B38    		;3AF4 3042	<L3B38>
	INC  (HL)    			;3AF6 34
	JR   C,L3B29     		;3AF7 3830	<L3B29>
L3AF9:	JR   NC,L3B2C    		;3AF9 3031	<L3B2C>
	DEC  (HL)    			;3AFB 35
	JR   C,L3B32     		;3AFC 3834	<L3B32>
L3AFE:	JR   NC,L3B31    		;3AFE 3031	<L3B31>
	JR   NC,L3B34    		;3B00 3032	<L3B34>
	ADD  HL,SP   			;3B02 39
	DEC  C       			;3B03 0D
	LD   A,(BC)  			;3B04 0A
	LD   A,(M3032)   		;3B05 3A3230	<M3032>
L3B08:	LD   SP,M3838    		;3B08 313838	<M3838>
L3B0B:	JR   NC,L3B3D    		;3B0B 3030	<L3B3D>
	JR   NC,L3B47    		;3B0D 3038	<L3B47>
	JR   NC,L3B46    		;3B0F 3035	<L3B46>
	JR   NC,L3B46    		;3B11 3033	<L3B46>
	JR   NC,L3B46    		;3B13 3031	<L3B46>
	JR   C,L3B5B     		;3B15 3844	<L3B5B>
	JR   C,L3B5E     		;3B17 3845	<L3B5E>
L3B19:	JR   NC,L3B5E    		;3B19 3043	<L3B5E>
L3B1B:	JR   C,L3B61     		;3B1B 3844	<L3B61>
L3B1D:	JR   NC,L3B64    		;3B1D 3045	<L3B64>
	JR   NC,L3B65    		;3B1F 3044	<L3B65>
L3B21:	JR   C,L3B68     		;3B21 3845	<L3B68>
	JR   NC,L3B5B    		;3B23 3036	<L3B5B>
	JR   NC,L3B5A    		;3B25 3033	<L3B5A>
	JR   NC,L3B59    		;3B27 3030	<L3B59>
L3B29:	JR   NC,L3B5F    		;3B29 3034	<L3B5F>
	JR   NC,L3B5E    		;3B2B 3031	<L3B5E>
	JR   NC,L3B70    		;3B2D 3041	<L3B70>
	JR   C,L3B74     		;3B2F 3843	<L3B74>
L3B31:	JR   C,L3B63     		;3B31 3830	<L3B63>
	LD   (M3844),A   		;3B33 324438	<M3844>
	JR   NC,L3B70    		;3B36 3038	<L3B70>
L3B38:	LD   B,E     			;3B38 43
L3B39:	LD   B,E     			;3B39 43
	LD   B,L     			;3B3A 45
	LD   (M3844),A   		;3B3B 324438	<M3844>
	LD   B,H     			;3B3E 44
	INC  (HL)    			;3B3F 34
	LD   B,C     			;3B40 41
	JR   NC,L3B7B    		;3B41 3038	<L3B7B>
	LD   B,L     			;3B43 45
	LD   (HL),39H  			;3B44 3639	<39H>
L3B46:	INC  SP      			;3B46 33
L3B47:	LD   B,C     			;3B47 41
	JR   NC,L3B8D    		;3B48 3043	<L3B8D>
	LD   B,E     			;3B4A 43
	JR   C,L3B8F     		;3B4B 3842	<L3B8F>
	LD   (HL),36H  			;3B4D 3636	<36H>
	LD   SP,M0A0D    		;3B4F 310D0A	<M0A0D>
	LD   A,(M3032)   		;3B52 3A3230	<M3032>
	LD   SP,M4138    		;3B55 313841	<M4138>
	JR   NC,L3B8A    		;3B58 3030	<L3B8A>
L3B5A:	JR   NC,L3B94    		;3B5A 3038	<L3B94>
	LD   SP,M3036    		;3B5C 313630	<M3036>
L3B5F:	LD   B,C     			;3B5F 41
	LD   B,E     			;3B60 43
L3B61:	SCF          			;3B61 37
	LD   B,C     			;3B62 41
L3B63:	LD   (HL),30H  			;3B63 3630	<30H>
L3B65:	INC  SP      			;3B65 33
	INC  (HL)    			;3B66 34
	JR   NC,L3B99    		;3B67 3030	<L3B99>
	LD   B,H     			;3B69 44
	LD   B,E     			;3B6A 43
	JR   NC,L3BA0    		;3B6B 3033	<L3BA0>
	JR   NC,L3BA8    		;3B6D 3039	<L3BA8>
	LD   (M3043),A   		;3B6F 324330	<M3043>
	LD   B,C     			;3B72 41
	SCF          			;3B73 37
L3B74:	LD   B,H     			;3B74 44
	LD   B,D     			;3B75 42
	JR   NC,L3BB0    		;3B76 3038	<L3BB0>
	JR   NC,L3BAF    		;3B78 3035	<L3BAF>
	INC  (HL)    			;3B7A 34
L3B7B:	INC  SP      			;3B7B 33
	JR   NC,L3BAE    		;3B7C 3030	<L3BAE>
	LD   B,E     			;3B7E 43
	LD   B,E     			;3B7F 43
	LD   B,E     			;3B80 43
	LD   B,H     			;3B81 44
	JR   NC,L3BB9    		;3B82 3035	<L3BB9>
	LD   (HL),38H  			;3B84 3638	<38H>
	JR   C,L3BBD     		;3B86 3835	<L3BBD>
	LD   B,E     			;3B88 43
	LD   (M4443),A   		;3B89 324344	<M4443>
	LD   B,C     			;3B8C 41
L3B8D:	LD   B,H     			;3B8D 44
	LD   SP,M3441    		;3B8E 314134	<M3441>
	JR   C,L3BC3     		;3B91 3830	<L3BC3>
	DEC  (HL)    			;3B93 35
L3B94:	LD   (HL),33H  			;3B94 3633	<33H>
	JR   C,L3BC8     		;3B96 3830	<L3BC8>
	LD   SP,M3044    		;3B98 314430	<M3044>
	JR   NC,L3BCF    		;3B9B 3032	<L3BCF>
	DEC  C       			;3B9D 0D
	LD   A,(BC)  			;3B9E 0A
	LD   A,(M3032)   		;3B9F 3A3230	<M3032>
	LD   SP,M4338    		;3BA2 313843	<M4338>
	JR   NC,L3BD7    		;3BA5 3030	<L3BD7>
	JR   NC,L3BED    		;3BA7 3044	<L3BED>
	LD   B,E     			;3BA9 43
	LD   B,H     			;3BAA 44
	JR   NC,L3BF2    		;3BAB 3045	<L3BF2>
	INC  (HL)    			;3BAD 34
L3BAE:	LD   B,H     			;3BAE 44
L3BAF:	JR   C,L3BF5     		;3BAF 3844	<L3BF5>
	JR   NC,L3BEA    		;3BB1 3037	<L3BEA>
	LD   B,E     			;3BB3 43
	LD   (HL),30H  			;3BB4 3630	<30H>
	INC  SP      			;3BB6 33
	INC  (HL)    			;3BB7 34
	JR   NC,L3BEA    		;3BB8 3030	<L3BEA>
	LD   B,L     			;3BBA 45
	JR   C,L3C02     		;3BBB 3845	<L3C02>
L3BBD:	INC  (HL)    			;3BBD 34
	LD   B,H     			;3BBE 44
	JR   C,L3C05     		;3BBF 3844	<L3C05>
	JR   NC,L3C06    		;3BC1 3043	<L3C06>
L3BC3:	LD   B,E     			;3BC3 43
	LD   B,L     			;3BC4 45
	LD   (M3844),A   		;3BC5 324438	<M3844>
L3BC8:	JR   C,L3BFE     		;3BC8 3834	<L3BFE>
	DEC  (HL)    			;3BCA 35
	JR   NC,L3C01    		;3BCB 3034	<L3C01>
	INC  (HL)    			;3BCD 34
	LD   SP,M3030    		;3BCE 313030	<M3030>
	LD   (M4334),A   		;3BD1 323443	<M4334>
	LD   SP,M3838    		;3BD4 313838	<M3838>
L3BD7:	JR   C,L3C0E     		;3BD7 3835	<L3C0E>
	LD   B,E     			;3BD9 43
	LD   (M3138),A   		;3BDA 323831	<M3138>
	JR   NC,L3C23    		;3BDD 3044	<L3C23>
	JR   C,L3C24     		;3BDF 3843	<L3C24>
	JR   C,L3C26     		;3BE1 3843	<L3C26>
	LD   B,E     			;3BE3 43
	LD   B,L     			;3BE4 45
	JR   NC,L3C2C    		;3BE5 3045	<L3C2C>
	JR   NC,L3C2F    		;3BE7 3046	<L3C2F>
	JR   NC,L3BF8    		;3BE9 300D	<L3BF8>
	LD   A,(BC)  			;3BEB 0A
	LD   A,(M3032)   		;3BEC 3A3230	<M3032>
	LD   SP,M4538    		;3BEF 313845	<M4538>
L3BF2:	JR   NC,L3C24    		;3BF2 3030	<L3C24>
	JR   NC,L3C3A    		;3BF4 3044	<L3C3A>
	JR   NC,L3C3B    		;3BF6 3043	<L3C3B>
L3BF8:	JR   C,L3C3B     		;3BF8 3841	<L3C3B>
	INC  (HL)    			;3BFA 34
	JR   C,L3C35     		;3BFB 3838	<L3C35>
	DEC  (HL)    			;3BFD 35
L3BFE:	JR   C,L3C32     		;3BFE 3832	<L3C32>
	JR   C,L3C33     		;3C00 3831	<L3C33>
L3C02:	INC  (HL)    			;3C02 34
	LD   B,D     			;3C03 42
	JR   NC,L3C3D    		;3C04 3037	<L3C3D>
L3C06:	JR   C,L3C3D     		;3C06 3835	<L3C3D>
	JR   NC,L3C3A    		;3C08 3030	<L3C3A>
	LD   SP,M3843    		;3C0A 314338	<M3843>
	LD   B,L     			;3C0D 45
L3C0E:	JR   NC,L3C55    		;3C0E 3045	<L3C55>
	INC  (HL)    			;3C10 34
	LD   B,H     			;3C11 44
	JR   NC,L3C4C    		;3C12 3038	<L3C4C>
	JR   NC,L3C4B    		;3C14 3035	<L3C4B>
	INC  (HL)    			;3C16 34
	INC  SP      			;3C17 33
	JR   C,L3C4A     		;3C18 3830	<L3C4A>
	JR   C,L3C5D     		;3C1A 3841	<L3C5D>
	JR   C,L3C55     		;3C1C 3837	<L3C55>
	JR   C,L3C56     		;3C1E 3836	<L3C56>
	LD   B,E     			;3C20 43
	INC  SP      			;3C21 33
	JR   C,L3C55     		;3C22 3831	<L3C55>
L3C24:	JR   NC,L3C69    		;3C24 3043	<L3C69>
L3C26:	JR   C,L3C6B     		;3C26 3843	<L3C6B>
	JR   C,L3C6E     		;3C28 3844	<L3C6E>
	LD   B,E     			;3C2A 43
	LD   B,H     			;3C2B 44
L3C2C:	JR   C,L3C71     		;3C2C 3843	<L3C71>
	JR   C,L3C73     		;3C2E 3843	<L3C73>
	JR   C,L3C76     		;3C30 3844	<L3C76>
L3C32:	LD   B,E     			;3C32 43
L3C33:	LD   B,E     			;3C33 43
	JR   C,L3C6B     		;3C34 3835	<L3C6B>
	LD   B,D     			;3C36 42
	DEC  C       			;3C37 0D
	LD   A,(BC)  			;3C38 0A
	LD   A,(M3032)   		;3C39 3A3230	<M3032>
	LD   SP,M3039    		;3C3C 313930	<M3039>
	JR   NC,L3C71    		;3C3F 3030	<L3C71>
	JR   NC,L3C73    		;3C41 3030	<L3C73>
	SCF          			;3C43 37
	SCF          			;3C44 37
	LD   B,L     			;3C45 45
	JR   NC,L3C79    		;3C46 3031	<L3C79>
	LD   (HL),37H  			;3C48 3637	<37H>
L3C4A:	JR   NC,L3C7C    		;3C4A 3030	<L3C7C>
L3C4C:	JR   NC,L3C7E    		;3C4C 3030	<L3C7E>
	JR   NC,L3C82    		;3C4E 3032	<L3C82>
	JR   NC,L3C93    		;3C50 3041	<L3C93>
	SCF          			;3C52 37
	LD   B,L     			;3C53 45
	JR   NC,L3C88    		;3C54 3032	<L3C88>
L3C56:	LD   (HL),37H  			;3C56 3637	<37H>
	JR   NC,L3C8A    		;3C58 3030	<L3C8A>
	JR   NC,L3C8C    		;3C5A 3030	<L3C8C>
	JR   NC,L3CA4    		;3C5C 3046	<L3CA4>
	JR   NC,L3C90    		;3C5E 3030	<L3C90>
	SCF          			;3C60 37
	LD   B,L     			;3C61 45
	JR   NC,L3C98    		;3C62 3034	<L3C98>
	LD   (HL),37H  			;3C64 3637	<37H>
	JR   NC,L3C98    		;3C66 3030	<L3C98>
	JR   NC,L3C9A    		;3C68 3030	<L3C9A>
	JR   NC,L3CAD    		;3C6A 3041	<L3CAD>
	JR   NC,L3C9E    		;3C6C 3030	<L3C9E>
L3C6E:	SCF          			;3C6E 37
	LD   B,L     			;3C6F 45
	JR   NC,L3CAA    		;3C70 3038	<L3CAA>
	LD   (HL),37H  			;3C72 3637	<37H>
	JR   NC,L3CA7    		;3C74 3031	<L3CA7>
L3C76:	JR   NC,L3CA8    		;3C76 3030	<L3CA8>
	JR   NC,L3CAA    		;3C78 3030	<L3CAA>
	JR   NC,L3CAC    		;3C7A 3030	<L3CAC>
L3C7C:	JR   C,L3CB1     		;3C7C 3833	<L3CB1>
L3C7E:	JR   NC,L3CB1    		;3C7E 3031	<L3CB1>
	LD   (HL),39H  			;3C80 3639	<39H>
L3C82:	JR   NC,L3CC5    		;3C82 3041	<L3CC5>
	DEC  C       			;3C84 0D
	LD   A,(BC)  			;3C85 0A
	LD   A,(M3032)   		;3C86 3A3230	<M3032>
	LD   SP,M3239    		;3C89 313932	<M3239>
L3C8C:	JR   NC,L3CBE    		;3C8C 3030	<L3CBE>
	JR   NC,L3CC0    		;3C8E 3030	<L3CC0>
L3C90:	INC  (HL)    			;3C90 34
	JR   NC,L3CC5    		;3C91 3032	<L3CC5>
L3C93:	JR   NC,L3CDB    		;3C93 3046	<L3CDB>
	JR   NC,L3CC7    		;3C95 3030	<L3CC7>
	JR   C,L3CCC     		;3C97 3833	<L3CCC>
	JR   NC,L3CCD    		;3C99 3032	<L3CCD>
	LD   (HL),39H  			;3C9B 3639	<39H>
	JR   NC,L3CD3    		;3C9D 3034	<L3CD3>
	JR   NC,L3CD4    		;3C9F 3033	<L3CD4>
	JR   NC,L3CE9    		;3CA1 3046	<L3CE9>
	JR   NC,L3CD5    		;3CA3 3030	<L3CD5>
	JR   C,L3CDA     		;3CA5 3833	<L3CDA>
L3CA7:	JR   NC,L3CEC    		;3CA7 3043	<L3CEC>
	LD   (HL),39H  			;3CA9 3639	<39H>
	JR   NC,L3CDF    		;3CAB 3032	<L3CDF>
L3CAD:	JR   NC,L3CDF    		;3CAD 3030	<L3CDF>
	JR   NC,L3CF7    		;3CAF 3046	<L3CF7>
L3CB1:	JR   NC,L3CE3    		;3CB1 3030	<L3CE3>
	JR   NC,L3CE9    		;3CB3 3034	<L3CE9>
	SCF          			;3CB5 37
	LD   B,L     			;3CB6 45
	JR   NC,L3CEA    		;3CB7 3031	<L3CEA>
	LD   (HL),37H  			;3CB9 3637	<37H>
	JR   NC,L3CED    		;3CBB 3030	<L3CED>
	JR   NC,L3CEF    		;3CBD 3030	<L3CEF>
	JR   NC,L3CF3    		;3CBF 3032	<L3CF3>
	JR   NC,L3D04    		;3CC1 3041	<L3D04>
	SCF          			;3CC3 37
	LD   B,L     			;3CC4 45
L3CC5:	JR   NC,L3CF9    		;3CC5 3032	<L3CF9>
L3CC7:	LD   (HL),37H  			;3CC7 3637	<37H>
	JR   NC,L3CFB    		;3CC9 3030	<L3CFB>
	JR   NC,L3CFD    		;3CCB 3030	<L3CFD>
L3CCD:	JR   NC,L3D15    		;3CCD 3046	<L3D15>
	ADD  HL,SP   			;3CCF 39
	ADD  HL,SP   			;3CD0 39
	DEC  C       			;3CD1 0D
	LD   A,(BC)  			;3CD2 0A
L3CD3:	LD   A,(M3032)   		;3CD3 3A3230	<M3032>
	LD   SP,M3439    		;3CD6 313934	<M3439>
	JR   NC,L3D0B    		;3CD9 3030	<L3D0B>
L3CDB:	JR   NC,L3D0D    		;3CDB 3030	<L3D0D>
	JR   NC,L3D16    		;3CDD 3037	<L3D16>
L3CDF:	LD   B,L     			;3CDF 45
	JR   NC,L3D16    		;3CE0 3034	<L3D16>
	LD   (HL),37H  			;3CE2 3637	<37H>
	JR   NC,L3D16    		;3CE4 3030	<L3D16>
	JR   NC,L3D18    		;3CE6 3030	<L3D18>
	JR   NC,L3D2B    		;3CE8 3041	<L3D2B>
L3CEA:	JR   NC,L3D1C    		;3CEA 3030	<L3D1C>
L3CEC:	SCF          			;3CEC 37
L3CED:	LD   B,L     			;3CED 45
	JR   NC,L3D28    		;3CEE 3038	<L3D28>
	LD   (HL),37H  			;3CF0 3637	<37H>
	JR   NC,L3D26    		;3CF2 3032	<L3D26>
	JR   NC,L3D26    		;3CF4 3030	<L3D26>
	JR   NC,L3D2C    		;3CF6 3034	<L3D2C>
	JR   NC,L3D2A    		;3CF8 3030	<L3D2A>
	JR   NC,L3D2D    		;3CFA 3031	<L3D2D>
	SCF          			;3CFC 37
L3CFD:	LD   B,L     			;3CFD 45
	LD   SP,M3638    		;3CFE 313836	<M3638>
	SCF          			;3D01 37
	JR   NC,L3D34    		;3D02 3030	<L3D34>
L3D04:	JR   NC,L3D36    		;3D04 3030	<L3D36>
	JR   NC,L3D4E    		;3D06 3046	<L3D4E>
	JR   NC,L3D3A    		;3D08 3030	<L3D3A>
	JR   NC,L3D40    		;3D0A 3034	<L3D40>
	JR   NC,L3D46    		;3D0C 3038	<L3D46>
	JR   NC,L3D42    		;3D0E 3032	<L3D42>
	LD   SP,M3030    		;3D10 313030	<M3030>
	LD   SP,M3030    		;3D13 313030	<M3030>
L3D16:	ADD  HL,SP   			;3D16 39
	LD   (M3038),A   		;3D17 323830	<M3038>
	LD   (M3334),A   		;3D1A 323433	<M3334>
	LD   B,(HL)  			;3D1D 46
	DEC  C       			;3D1E 0D
	LD   A,(BC)  			;3D1F 0A
	LD   A,(M3032)   		;3D20 3A3230	<M3032>
	LD   SP,M3639    		;3D23 313936	<M3639>
L3D26:	JR   NC,L3D58    		;3D26 3030	<L3D58>
L3D28:	JR   NC,L3D5A    		;3D28 3030	<L3D5A>
L3D2A:	JR   NC,L3D60    		;3D2A 3034	<L3D60>
L3D2C:	ADD  HL,SP   			;3D2C 39
L3D2D:	JR   NC,L3D5F    		;3D2D 3030	<L3D5F>
	DEC  (HL)    			;3D2F 35
	INC  (HL)    			;3D30 34
	JR   C,L3D63     		;3D31 3830	<L3D63>
	LD   SP,M3031    		;3D33 313130	<M3031>
L3D36:	JR   NC,L3D68    		;3D36 3030	<L3D68>
	LD   (M3030),A   		;3D38 323030	<M3030>
	JR   NC,L3D71    		;3D3B 3034	<L3D71>
	JR   NC,L3D6F    		;3D3D 3030	<L3D6F>
	JR   NC,L3D72    		;3D3F 3031	<L3D72>
	JR   NC,L3D73    		;3D41 3030	<L3D73>
	JR   NC,L3D79    		;3D43 3034	<L3D79>
	JR   NC,L3D77    		;3D45 3030	<L3D77>
	JR   NC,L3D7A    		;3D47 3031	<L3D7A>
	LD   B,(HL)  			;3D49 46
	LD   SP,M3246    		;3D4A 314632	<M3246>
	LD   B,(HL)  			;3D4D 46
L3D4E:	INC  SP      			;3D4E 33
	LD   B,(HL)  			;3D4F 46
	INC  (HL)    			;3D50 34
	LD   B,(HL)  			;3D51 46
	DEC  (HL)    			;3D52 35
	LD   B,(HL)  			;3D53 46
	LD   (HL),46H  			;3D54 3646	<46H>
	SCF          			;3D56 37
	LD   B,(HL)  			;3D57 46
L3D58:	JR   C,L3DA0     		;3D58 3846	<L3DA0>
L3D5A:	ADD  HL,SP   			;3D5A 39
	LD   SP,M3130    		;3D5B 313031	<M3130>
	LD   SP,M3231    		;3D5E 313132	<M3231>
	LD   SP,M3133    		;3D61 313331	<M3133>
	INC  (HL)    			;3D64 34
	LD   SP,M3135    		;3D65 313531	<M3135>
L3D68:	LD   (HL),30H  			;3D68 3630	<30H>
	LD   B,D     			;3D6A 42
	DEC  C       			;3D6B 0D
	LD   A,(BC)  			;3D6C 0A
	LD   A,(M3032)   		;3D6D 3A3230	<M3032>
	LD   SP,M3839    		;3D70 313938	<M3839>
L3D73:	JR   NC,L3DA5    		;3D73 3030	<L3DA5>
	JR   NC,L3DA8    		;3D75 3031	<L3DA8>
L3D77:	SCF          			;3D77 37
	LD   SP,M3138    		;3D78 313831	<M3138>
	ADD  HL,SP   			;3D7B 39
	LD   (M3230),A   		;3D7C 323032	<M3230>
	LD   SP,M3232    		;3D7F 313232	<M3232>
	LD   (M3233),A   		;3D82 323332	<M3233>
	INC  (HL)    			;3D85 34
	LD   (M3235),A   		;3D86 323532	<M3235>
	LD   (HL),32H  			;3D89 3632	<32H>
	SCF          			;3D8B 37
	LD   (M3238),A   		;3D8C 323832	<M3238>
	ADD  HL,SP   			;3D8F 39
	INC  SP      			;3D90 33
	JR   NC,L3DC9    		;3D91 3036	<L3DC9>
	INC  (HL)    			;3D93 34
	LD   SP,M3133    		;3D94 313331	<M3133>
	INC  (HL)    			;3D97 34
	LD   SP,M3334    		;3D98 313433	<M3334>
	INC  (HL)    			;3D9B 34
	LD   SP,M3434    		;3D9C 313434	<M3434>
	LD   B,D     			;3D9F 42
L3DA0:	LD   SP,M3035    		;3DA0 313530	<M3035>
	JR   NC,L3DD5    		;3DA3 3030	<L3DD5>
L3DA5:	JR   NC,L3DD7    		;3DA5 3030	<L3DD7>
	LD   (M3030),A   		;3DA7 323030	<M3030>
	JR   NC,L3DE4    		;3DAA 3038	<L3DE4>
	JR   NC,L3DE5    		;3DAC 3037	<L3DE5>
	JR   NC,L3DE3    		;3DAE 3033	<L3DE3>
	JR   NC,L3DF7    		;3DB0 3045	<L3DF7>
	JR   NC,L3DED    		;3DB2 3039	<L3DED>
	JR   NC,L3DEE    		;3DB4 3038	<L3DEE>
	LD   B,L     			;3DB6 45
	JR   C,L3DC6     		;3DB7 380D	<L3DC6>
	LD   A,(BC)  			;3DB9 0A
	LD   A,(M3032)   		;3DBA 3A3230	<M3032>
	LD   SP,M4139    		;3DBD 313941	<M4139>
	JR   NC,L3DF2    		;3DC0 3030	<L3DF2>
	JR   NC,L3DF4    		;3DC2 3030	<L3DF4>
	INC  (HL)    			;3DC4 34
	JR   NC,L3E0D    		;3DC5 3046	<L3E0D>
	JR   NC,L3DFF    		;3DC7 3036	<L3DFF>
L3DC9:	JR   NC,L3E04    		;3DC9 3039	<L3E04>
	JR   NC,L3DFD    		;3DCB 3030	<L3DFD>
	JR   NC,L3E12    		;3DCD 3043	<L3E12>
	JR   NC,L3E08    		;3DCF 3037	<L3E08>
	JR   NC,L3E14    		;3DD1 3041	<L3E14>
	JR   NC,L3E0A    		;3DD3 3035	<L3E0A>
L3DD5:	JR   NC,L3E09    		;3DD5 3032	<L3E09>
L3DD7:	JR   NC,L3E0E    		;3DD7 3035	<L3E0E>
	JR   NC,L3E11    		;3DD9 3036	<L3E11>
	JR   NC,L3E0D    		;3DDB 3030	<L3E0D>
	JR   NC,L3E23    		;3DDD 3044	<L3E23>
	JR   NC,L3E12    		;3DDF 3031	<L3E12>
	JR   NC,L3E14    		;3DE1 3031	<L3E14>
L3DE3:	JR   NC,L3E15    		;3DE3 3030	<L3E15>
L3DE5:	JR   NC,L3E20    		;3DE5 3039	<L3E20>
	JR   NC,L3E1D    		;3DE7 3034	<L3E1D>
	JR   NC,L3E20    		;3DE9 3035	<L3E20>
	JR   NC,L3E1D    		;3DEB 3030	<L3E1D>
L3DED:	JR   NC,L3E31    		;3DED 3042	<L3E31>
	JR   NC,L3E21    		;3DEF 3030	<L3E21>
	JR   NC,L3E26    		;3DF1 3033	<L3E26>
	JR   NC,L3E25    		;3DF3 3030	<L3E25>
	JR   NC,L3E38    		;3DF5 3041	<L3E38>
L3DF7:	JR   NC,L3E29    		;3DF7 3030	<L3E29>
	JR   NC,L3E2C    		;3DF9 3031	<L3E2C>
	JR   NC,L3E2E    		;3DFB 3031	<L3E2E>
L3DFD:	JR   NC,L3E38    		;3DFD 3039	<L3E38>
L3DFF:	JR   NC,L3E31    		;3DFF 3030	<L3E31>
	JR   NC,L3E33    		;3E01 3030	<L3E33>
	ADD  HL,SP   			;3E03 39
L3E04:	LD   (M0A0D),A   		;3E04 320D0A	<M0A0D>
	LD   A,(M3032)   		;3E07 3A3230	<M3032>
L3E0A:	LD   SP,M4339    		;3E0A 313943	<M4339>
L3E0D:	JR   NC,L3E3F    		;3E0D 3030	<L3E3F>
	JR   NC,L3E41    		;3E0F 3030	<L3E41>
L3E11:	LD   SP,M3430    		;3E11 313034	<M3430>
L3E14:	JR   NC,L3E46    		;3E14 3030	<L3E46>
	JR   NC,L3E48    		;3E16 3030	<L3E48>
	JR   NC,L3E4A    		;3E18 3030	<L3E4A>
	JR   NC,L3E53    		;3E1A 3037	<L3E53>
	JR   NC,L3E4E    		;3E1C 3030	<L3E4E>
	JR   NC,L3E50    		;3E1E 3030	<L3E50>
L3E20:	JR   NC,L3E52    		;3E20 3030	<L3E52>
	JR   NC,L3E57    		;3E22 3033	<L3E57>
	JR   NC,L3E56    		;3E24 3030	<L3E56>
L3E26:	JR   NC,L3E58    		;3E26 3030	<L3E58>
	JR   NC,L3E5A    		;3E28 3030	<L3E5A>
	JR   NC,L3E61    		;3E2A 3035	<L3E61>
L3E2C:	JR   NC,L3E5E    		;3E2C 3030	<L3E5E>
L3E2E:	JR   NC,L3E60    		;3E2E 3030	<L3E60>
	JR   NC,L3E62    		;3E30 3030	<L3E62>
	JR   NC,L3E6A    		;3E32 3036	<L3E6A>
	JR   NC,L3E69    		;3E34 3033	<L3E69>
	JR   NC,L3E6C    		;3E36 3034	<L3E6C>
L3E38:	JR   NC,L3E6A    		;3E38 3030	<L3E6A>
	JR   NC,L3E6C    		;3E3A 3030	<L3E6C>
	JR   NC,L3E6F    		;3E3C 3031	<L3E6F>
	JR   NC,L3E71    		;3E3E 3031	<L3E71>
	JR   NC,L3E72    		;3E40 3030	<L3E72>
	JR   NC,L3E74    		;3E42 3030	<L3E74>
	JR   NC,L3E76    		;3E44 3030	<L3E76>
L3E46:	JR   NC,L3E78    		;3E46 3030	<L3E78>
L3E48:	JR   NC,L3E7A    		;3E48 3030	<L3E7A>
L3E4A:	JR   NC,L3E84    		;3E4A 3038	<L3E84>
	JR   NC,L3E7E    		;3E4C 3030	<L3E7E>
L3E4E:	JR   NC,L3E80    		;3E4E 3030	<L3E80>
L3E50:	LD   B,H     			;3E50 44
	LD   B,E     			;3E51 43
L3E52:	DEC  C       			;3E52 0D
L3E53:	LD   A,(BC)  			;3E53 0A
	LD   A,(M3032)   		;3E54 3A3230	<M3032>
L3E57:	LD   SP,M4539    		;3E57 313945	<M4539>
L3E5A:	JR   NC,L3E8C    		;3E5A 3030	<L3E8C>
	JR   NC,L3E8E    		;3E5C 3030	<L3E8E>
L3E5E:	LD   (HL),30H  			;3E5E 3630	<30H>
L3E60:	JR   NC,L3E92    		;3E60 3030	<L3E92>
L3E62:	JR   NC,L3E94    		;3E62 3030	<L3E94>
	JR   NC,L3E96    		;3E64 3030	<L3E96>
	SCF          			;3E66 37
	JR   NC,L3E99    		;3E67 3030	<L3E99>
L3E69:	JR   NC,L3E9B    		;3E69 3030	<L3E9B>
	JR   NC,L3E9D    		;3E6B 3030	<L3E9D>
	JR   NC,L3EA7    		;3E6D 3038	<L3EA7>
L3E6F:	JR   NC,L3EA1    		;3E6F 3030	<L3EA1>
L3E71:	JR   NC,L3EA5    		;3E71 3032	<L3EA5>
	JR   NC,L3EA7    		;3E73 3032	<L3EA7>
	JR   NC,L3EA7    		;3E75 3030	<L3EA7>
	LD   SP,M3030    		;3E77 313030	<M3030>
L3E7A:	LD   SP,M3130    		;3E7A 313031	<M3130>
	JR   NC,L3EAF    		;3E7D 3030	<L3EAF>
	JR   NC,L3EB2    		;3E7F 3031	<L3EB2>
	JR   NC,L3EB7    		;3E81 3034	<L3EB7>
	LD   SP,M3041    		;3E83 314130	<M3041>
	DEC  (HL)    			;3E86 35
	LD   SP,M3041    		;3E87 314130	<M3041>
	LD   B,C     			;3E8A 41
	LD   SP,M3141    		;3E8B 314131	<M3141>
L3E8E:	DEC  (HL)    			;3E8E 35
	LD   SP,M3241    		;3E8F 314132	<M3241>
L3E92:	LD   SP,M4131    		;3E92 313141	<M4131>
	INC  SP      			;3E95 33
L3E96:	LD   (HL),31H  			;3E96 3631	<31H>
	LD   B,C     			;3E98 41
L3E99:	INC  (HL)    			;3E99 34
	SCF          			;3E9A 37
L3E9B:	LD   SP,M3341    		;3E9B 314133	<M3341>
	LD   B,(HL)  			;3E9E 46
	DEC  C       			;3E9F 0D
	LD   A,(BC)  			;3EA0 0A
L3EA1:	LD   A,(M3032)   		;3EA1 3A3230	<M3032>
	LD   SP,M3041    		;3EA4 314130	<M3041>
L3EA7:	JR   NC,L3ED9    		;3EA7 3030	<L3ED9>
	JR   NC,L3EE1    		;3EA9 3036	<L3EE1>
	LD   B,C     			;3EAB 41
	LD   SP,M3841    		;3EAC 314138	<M3841>
L3EAF:	ADD  HL,SP   			;3EAF 39
	LD   SP,M3041    		;3EB0 314130	<M3041>
	JR   NC,L3EE5    		;3EB3 3030	<L3EE5>
	LD   SP,M4333    		;3EB5 313343	<M4333>
	LD   B,(HL)  			;3EB8 46
	LD   B,L     			;3EB9 45
	JR   NC,L3EF1    		;3EBA 3035	<L3EF1>
	LD   SP,M3041    		;3EBC 314130	<M3041>
	INC  (HL)    			;3EBF 34
	LD   B,L     			;3EC0 45
	SCF          			;3EC1 37
	JR   NC,L3EF8    		;3EC2 3034	<L3EF8>
	LD   B,H     			;3EC4 44
	LD   B,D     			;3EC5 42
	JR   NC,L3EFC    		;3EC6 3034	<L3EFC>
	LD   B,D     			;3EC8 42
	LD   B,H     			;3EC9 44
	JR   NC,L3F00    		;3ECA 3034	<L3F00>
	SCF          			;3ECC 37
	LD   B,L     			;3ECD 45
	LD   B,(HL)  			;3ECE 46
	LD   B,L     			;3ECF 45
	JR   NC,L3F13    		;3ED0 3041	<L3F13>
	LD   SP,M4641    		;3ED2 314146	<M4641>
	LD   B,E     			;3ED5 43
	JR   NC,L3F0C    		;3ED6 3034	<L3F0C>
	JR   NC,L3F0E    		;3ED8 3034	<L3F0E>
	JR   C,L3F0E     		;3EDA 3832	<L3F0E>
	JR   NC,L3F12    		;3EDC 3034	<L3F12>
	INC  (HL)    			;3EDE 34
	LD   SP,M4446    		;3EDF 314644	<M4446>
	LD   SP,M3137    		;3EE2 313731	<M3137>
L3EE5:	LD   B,C     			;3EE5 41
	JR   NC,L3F2A    		;3EE6 3042	<L3F2A>
	INC  SP      			;3EE8 33
	LD   B,E     			;3EE9 43
	LD   B,H     			;3EEA 44
	LD   (HL),0DH  			;3EEB 360D	<0DH>
	LD   A,(BC)  			;3EED 0A
	LD   A,(M3032)   		;3EEE 3A3230	<M3032>
L3EF1:	LD   SP,M3241    		;3EF1 314132	<M3241>
	JR   NC,L3F26    		;3EF4 3030	<L3F26>
	JR   NC,L3F28    		;3EF6 3030	<L3F28>
L3EF8:	JR   NC,L3F2B    		;3EF8 3031	<L3F2B>
	LD   (M3636),A   		;3EFA 323636	<M3636>
	JR   NC,L3F38    		;3EFD 3039	<L3F38>
	LD   SP,M3038    		;3EFF 313830	<M3038>
	ADD  HL,SP   			;3F02 39
	LD   B,L     			;3F03 45
	SCF          			;3F04 37
	LD   SP,M4142    		;3F05 314241	<M4142>
	LD   B,C     			;3F08 41
	LD   SP,M3542    		;3F09 314235	<M3542>
L3F0C:	DEC  (HL)    			;3F0C 35
	LD   SP,M3942    		;3F0D 314239	<M3942>
	ADD  HL,SP   			;3F10 39
	LD   SP,M3642    		;3F11 314236	<M3642>
	LD   (HL),31H  			;3F14 3631	<31H>
	LD   B,E     			;3F16 43
	LD   B,E     			;3F17 43
	INC  SP      			;3F18 33
	LD   SP,M3343    		;3F19 314333	<M3343>
	LD   B,E     			;3F1C 43
	LD   B,(HL)  			;3F1D 46
	LD   B,L     			;3F1E 45
	LD   (M3137),A   		;3F1F 323731	<M3137>
	LD   B,C     			;3F22 41
	LD   (M4644),A   		;3F23 324446	<M4644>
L3F26:	LD   B,(HL)  			;3F26 46
	LD   (M3544),A   		;3F27 324435	<M3544>
L3F2A:	DEC  (HL)    			;3F2A 35
L3F2B:	LD   (M4145),A   		;3F2B 324541	<M4145>
	LD   B,C     			;3F2E 41
	LD   SP,M3337    		;3F2F 313733	<M3337>
	INC  SP      			;3F32 33
	LD   SP,M4337    		;3F33 313743	<M4337>
	LD   B,E     			;3F36 43
	JR   C,L3F7A     		;3F37 3841	<L3F7A>
	DEC  C       			;3F39 0D
	LD   A,(BC)  			;3F3A 0A
	LD   A,(M3032)   		;3F3B 3A3230	<M3032>
	LD   SP,M3441    		;3F3E 314134	<M3441>
	JR   NC,L3F73    		;3F41 3030	<L3F73>
	JR   NC,L3F76    		;3F43 3031	<L3F76>
	SCF          			;3F45 37
	DEC  (HL)    			;3F46 35
	DEC  (HL)    			;3F47 35
	LD   SP,M4136    		;3F48 313641	<M4136>
	LD   B,C     			;3F4B 41
	LD   B,(HL)  			;3F4C 46
	LD   B,L     			;3F4D 45
	INC  SP      			;3F4E 33
	LD   B,E     			;3F4F 43
	LD   SP,M3041    		;3F50 314130	<M3041>
	LD   B,C     			;3F53 41
	JR   NC,L3F89    		;3F54 3033	<L3F89>
	JR   NC,L3F9A    		;3F56 3042	<L3F9A>
	JR   NC,L3F9D    		;3F58 3043	<L3F9D>
	JR   NC,L3F9D    		;3F5A 3041	<L3F9D>
	INC  SP      			;3F5C 33
	JR   NC,L3F8F    		;3F5D 3030	<L3F8F>
	LD   B,D     			;3F5F 42
	LD   B,E     			;3F60 43
	JR   NC,L3F94    		;3F61 3031	<L3F94>
	DEC  (HL)    			;3F63 35
	JR   NC,L3F9E    		;3F64 3038	<L3F9E>
	LD   SP,M3135    		;3F66 313531	<M3135>
	JR   NC,L3F9C    		;3F69 3031	<L3F9C>
	DEC  (HL)    			;3F6B 35
	JR   NC,L3FB1    		;3F6C 3043	<L3FB1>
	LD   SP,M3335    		;3F6E 313533	<M3335>
	JR   NC,L3FA4    		;3F71 3031	<L3FA4>
L3F73:	DEC  (HL)    			;3F73 35
	JR   NC,L3FAC    		;3F74 3036	<L3FAC>
L3F76:	LD   SP,M3635    		;3F76 313536	<M3635>
	JR   NC,L3FAC    		;3F79 3031	<L3FAC>
	DEC  (HL)    			;3F7B 35
	JR   NC,L3FB5    		;3F7C 3037	<L3FB5>
	LD   SP,M4535    		;3F7E 313545	<M4535>
	JR   NC,L3FB5    		;3F81 3032	<L3FB5>
	LD   B,C     			;3F83 41
	LD   (HL),41H  			;3F84 3641	<41H>
	DEC  C       			;3F86 0D
	LD   A,(BC)  			;3F87 0A
	LD   A,(M3032)   		;3F88 3A3230	<M3032>
	LD   SP,M3641    		;3F8B 314136	<M3641>
	JR   NC,L3FC0    		;3F8E 3030	<L3FC0>
	JR   NC,L3FD5    		;3F90 3043	<L3FD5>
	INC  SP      			;3F92 33
	LD   (M3930),A   		;3F93 323039	<M3930>
	ADD  HL,SP   			;3F96 39
	INC  SP      			;3F97 33
	INC  (HL)    			;3F98 34
	LD   B,L     			;3F99 45
L3F9A:	SCF          			;3F9A 37
	INC  SP      			;3F9B 33
L3F9C:	LD   B,D     			;3F9C 42
L3F9D:	LD   B,(HL)  			;3F9D 46
L3F9E:	LD   B,(HL)  			;3F9E 46
	LD   SP,M4642    		;3F9F 314246	<M4642>
	LD   B,(HL)  			;3FA2 46
	JR   NC,L3FD5    		;3FA3 3030	<L3FD5>
	INC  SP      			;3FA5 33
	JR   C,L3FEE     		;3FA6 3846	<L3FEE>
	LD   B,(HL)  			;3FA8 46
	LD   B,(HL)  			;3FA9 46
	LD   B,E     			;3FAA 43
	JR   NC,L3FE4    		;3FAB 3037	<L3FE4>
	JR   NC,L3FE7    		;3FAD 3038	<L3FE7>
	JR   NC,L3FE4    		;3FAF 3033	<L3FE4>
L3FB1:	JR   NC,L3FEB    		;3FB1 3038	<L3FEB>
	JR   NC,L3FF8    		;3FB3 3043	<L3FF8>
L3FB5:	JR   NC,L3FEF    		;3FB5 3038	<L3FEF>
	INC  SP      			;3FB7 33
	JR   NC,L3FEA    		;3FB8 3030	<L3FEA>
	JR   C,L3FFF     		;3FBA 3843	<L3FFF>
	JR   NC,L3FEE    		;3FBC 3030	<L3FEE>
	JR   C,L3FF3     		;3FBE 3833	<L3FF3>
L3FC0:	JR   NC,L3FF2    		;3FC0 3030	<L3FF2>
	ADD  HL,SP   			;3FC2 39
	JR   NC,L4008    		;3FC3 3043	<L4008>
	LD   B,(HL)  			;3FC5 46
	LD   B,H     			;3FC6 44
	LD   (HL),45H  			;3FC7 3645	<45H>
	LD   SP,M4641    		;3FC9 314146	<M4641>
	LD   B,E     			;3FCC 43
	JR   NC,L4003    		;3FCD 3034	<L4003>
	JR   NC,L4004    		;3FCF 3033	<L4004>
	INC  (HL)    			;3FD1 34
	LD   B,H     			;3FD2 44
	DEC  C       			;3FD3 0D
	LD   A,(BC)  			;3FD4 0A
L3FD5:	LD   A,(M3032)   		;3FD5 3A3230	<M3032>
	LD   SP,M3841    		;3FD8 314138	<M3841>
	JR   NC,L400D    		;3FDB 3030	<L400D>
	JR   NC,L4014    		;3FDD 3035	<L4014>
	DEC  (HL)    			;3FDF 35
	JR   NC,L4016    		;3FE0 3034	<L4016>
	LD   B,C     			;3FE2 41
	LD   B,C     			;3FE3 41
L3FE4:	LD   B,(HL)  			;3FE4 46
	LD   B,H     			;3FE5 44
	SCF          			;3FE6 37
L3FE7:	LD   B,(HL)  			;3FE7 46
	LD   SP,M3141    		;3FE8 314131	<M3141>
L3FEB:	JR   C,L401D     		;3FEB 3830	<L401D>
	JR   NC,L401F    		;3FED 3030	<L401F>
L3FEF:	JR   NC,L4021    		;3FEF 3030	<L4021>
	LD   B,C     			;3FF1 41
L3FF2:	LD   B,E     			;3FF2 43
L3FF3:	INC  SP      			;3FF3 33
	JR   NC,L4037    		;3FF4 3041	<L4037>
	LD   (HL),36H  			;3FF6 3636	<36H>
L3FF8:	JR   NC,L403B    		;3FF8 3041	<L403B>
	INC  SP      			;3FFA 33
	LD   B,E     			;3FFB 43
	JR   NC,L403F    		;3FFC 3041	<L403F>
	LD   (HL),36H  			;3FFE 3636	<36H>
	JR   NC,L4043    		;4000 3041	<L4043>
	LD   B,E     			;4002 43
L4003:	INC  SP      			;4003 33
L4004:	LD   B,(HL)  			;4004 46
	LD   B,E     			;4005 43
	JR   NC,L4049    		;4006 3041	<L4049>
L4008:	JR   NC,L4050    		;4008 3046	<L4050>
	DEC  (HL)    			;400A 35
	DEC  (HL)    			;400B 35
	JR   NC,L4054    		;400C 3046	<L4054>
	LD   B,C     			;400E 41
	LD   B,C     			;400F 41
	LD   B,(HL)  			;4010 46
	LD   B,H     			;4011 44
	ADD  HL,SP   			;4012 39
	DEC  (HL)    			;4013 35
L4014:	LD   SP,M3041    		;4014 314130	<M3041>
	JR   C,L4049     		;4017 3830	<L4049>
	JR   NC,L404B    		;4019 3030	<L404B>
	JR   C,L404E     		;401B 3831	<L404E>
L401D:	JR   C,L4063     		;401D 3844	<L4063>
L401F:	LD   B,L     			;401F 45
	DEC  C       			;4020 0D
L4021:	LD   A,(BC)  			;4021 0A
	LD   A,(M3032)   		;4022 3A3230	<M3032>
	LD   SP,M4141    		;4025 314141	<M4141>
	JR   NC,L405A    		;4028 3030	<L405A>
	JR   NC,L405C    		;402A 3030	<L405C>
	JR   C,L4061     		;402C 3833	<L4061>
	LD   B,E     			;402E 43
	JR   NC,L4069    		;402F 3038	<L4069>
	SCF          			;4031 37
	LD   B,L     			;4032 45
	JR   NC,L406D    		;4033 3038	<L406D>
	LD   B,(HL)  			;4035 46
	LD   B,(HL)  			;4036 46
L4037:	JR   NC,L4069    		;4037 3030	<L4069>
	LD   B,D     			;4039 42
	LD   B,D     			;403A 42
L403B:	LD   SP,M4241    		;403B 314142	<M4241>
	LD   B,E     			;403E 43
L403F:	LD   SP,M4341    		;403F 314143	<M4341>
	LD   SP,M4131    		;4042 313141	<M4131>
	LD   B,E     			;4045 43
	LD   B,H     			;4046 44
	LD   SP,M4441    		;4047 314144	<M4441>
	LD   (HL),31H  			;404A 3631	<31H>
	LD   B,C     			;404C 41
	LD   B,L     			;404D 45
L404E:	LD   (M4131),A   		;404E 323141	<M4131>
	LD   B,(HL)  			;4051 46
	LD   SP,M4131    		;4052 313141	<M4131>
	LD   B,(HL)  			;4055 46
	LD   B,(HL)  			;4056 46
	LD   SP,M3141    		;4057 314131	<M3141>
L405A:	LD   SP,M4231    		;405A 313142	<M4231>
	LD   SP,M3145    		;405D 314531	<M3145>
	LD   B,D     			;4060 42
L4061:	JR   NC,L4093    		;4061 3030	<L4093>
L4063:	JR   NC,L4096    		;4063 3031	<L4096>
	LD   B,L     			;4065 45
	JR   NC,L40AE    		;4066 3046	<L40AE>
	LD   B,L     			;4068 45
L4069:	LD   B,D     			;4069 42
	LD   B,E     			;406A 43
	LD   B,H     			;406B 44
	JR   C,L407B     		;406C 380D	<L407B>
	LD   A,(BC)  			;406E 0A
	LD   A,(M3032)   		;406F 3A3230	<M3032>
	LD   SP,M4341    		;4072 314143	<M4341>
	JR   NC,L40A7    		;4075 3030	<L40A7>
	JR   NC,L40AA    		;4077 3031	<L40AA>
	LD   B,C     			;4079 41
	LD   SP,M4341    		;407A 314143	<M4341>
	JR   NC,L40C5    		;407D 3046	<L40C5>
	LD   B,E     			;407F 43
	JR   NC,L40B7    		;4080 3035	<L40B7>
	JR   NC,L40BC    		;4082 3038	<L40BC>
	LD   (M3030),A   		;4084 323030	<M3030>
	JR   C,L40B9     		;4087 3830	<L40B9>
	JR   NC,L40D1    		;4089 3046	<L40D1>
	LD   B,H     			;408B 44
	LD   B,E     			;408C 43
	DEC  (HL)    			;408D 35
	LD   SP,M3041    		;408E 314130	<M3041>
	JR   NC,L40C3    		;4091 3030	<L40C3>
L4093:	INC  (HL)    			;4093 34
	INC  (HL)    			;4094 34
	JR   NC,L40C7    		;4095 3030	<L40C7>
	INC  (HL)    			;4097 34
	LD   B,C     			;4098 41
	JR   NC,L40CB    		;4099 3030	<L40CB>
	INC  (HL)    			;409B 34
	JR   NC,L40CE    		;409C 3030	<L40CE>
	LD   B,(HL)  			;409E 46
	LD   B,L     			;409F 45
	LD   B,E     			;40A0 43
	LD   B,H     			;40A1 44
	LD   SP,M4641    		;40A2 314146	<M4641>
	LD   B,E     			;40A5 43
	JR   NC,L40DC    		;40A6 3034	<L40DC>
	JR   NC,L40DE    		;40A8 3034	<L40DE>
L40AA:	INC  (HL)    			;40AA 34
	JR   NC,L40DD    		;40AB 3030	<L40DD>
	INC  (HL)    			;40AD 34
L40AE:	LD   B,C     			;40AE 41
	JR   NC,L40F7    		;40AF 3046	<L40F7>
	LD   B,H     			;40B1 44
	LD   B,H     			;40B2 44
	JR   C,L40E6     		;40B3 3831	<L40E6>
	LD   B,C     			;40B5 41
	JR   NC,L40FA    		;40B6 3042	<L40FA>
	DEC  (HL)    			;40B8 35
L40B9:	LD   (M0A0D),A   		;40B9 320D0A	<M0A0D>
L40BC:	LD   A,(M3032)   		;40BC 3A3230	<M3032>
	LD   SP,M4541    		;40BF 314145	<M4541>
	JR   NC,L40F4    		;40C2 3030	<L40F4>
	JR   NC,L410B    		;40C4 3045	<L410B>
	JR   NC,L40F8    		;40C6 3030	<L40F8>
	JR   NC,L40FB    		;40C8 3031	<L40FB>
	LD   (M3041),A   		;40CA 324130	<M3041>
	LD   SP,M3432    		;40CD 313234	<M3432>
	JR   NC,L4103    		;40D0 3031	<L4103>
	LD   B,D     			;40D2 42
	INC  (HL)    			;40D3 34
	JR   NC,L4107    		;40D4 3031	<L4107>
	LD   B,D     			;40D6 42
	LD   B,C     			;40D7 41
	JR   NC,L410B    		;40D8 3031	<L410B>
	LD   B,D     			;40DA 42
	JR   NC,L410D    		;40DB 3030	<L410D>
L40DD:	LD   SP,M4143    		;40DD 314341	<M4143>
	JR   NC,L4128    		;40E0 3046	<L4128>
	LD   B,L     			;40E2 45
	LD   B,L     			;40E3 45
	LD   (HL),31H  			;40E4 3631	<31H>
L40E6:	LD   B,C     			;40E6 41
	LD   B,(HL)  			;40E7 46
	LD   B,E     			;40E8 43
	JR   NC,L4123    		;40E9 3038	<L4123>
	LD   SP,M3632    		;40EB 313236	<M3632>
	JR   NC,L4121    		;40EE 3031	<L4121>
	LD   (M3043),A   		;40F0 324330	<M3043>
	LD   SP,M4131    		;40F3 313141	<M4131>
	JR   NC,L413E    		;40F6 3046	<L413E>
L40F8:	LD   B,H     			;40F8 44
	LD   B,(HL)  			;40F9 46
L40FA:	INC  SP      			;40FA 33
L40FB:	LD   SP,M3141    		;40FB 314131	<M3141>
	LD   B,D     			;40FE 42
	JR   NC,L4131    		;40FF 3030	<L4131>
	JR   NC,L4133    		;4101 3030	<L4133>
L4103:	LD   SP,M4539    		;4103 313945	<M4539>
	JR   NC,L4115    		;4106 300D	<L4115>
	LD   A,(BC)  			;4108 0A
	LD   A,(M3032)   		;4109 3A3230	<M3032>
	LD   SP,M3042    		;410C 314230	<M3042>
	JR   NC,L4141    		;410F 3030	<L4141>
	JR   NC,L4158    		;4111 3045	<L4158>
	JR   NC,L4146    		;4113 3031	<L4146>
L4115:	ADD  HL,SP   			;4115 39
	JR   NC,L4148    		;4116 3030	<L4148>
	LD   B,(HL)  			;4118 46
	LD   B,E     			;4119 43
	JR   NC,L4151    		;411A 3035	<L4151>
	LD   SP,M3645    		;411C 314536	<M3645>
	JR   NC,L4152    		;411F 3031	<L4152>
L4121:	LD   B,L     			;4121 45
	LD   B,E     			;4122 43
L4123:	JR   NC,L416B    		;4123 3046	<L416B>
	LD   B,H     			;4125 44
	JR   NC,L415D    		;4126 3035	<L415D>
L4128:	LD   SP,M3242    		;4128 314232	<M3242>
	JR   NC,L415D    		;412B 3030	<L415D>
	JR   NC,L415F    		;412D 3030	<L415F>
	JR   C,L4176     		;412F 3845	<L4176>
L4131:	JR   NC,L4163    		;4131 3030	<L4163>
L4133:	JR   NC,L4168    		;4133 3033	<L4168>
M4135:	LD   B,D     			;4135 42
M4136:	LD   B,L     			;4136 45
M4137:	JR   NC,L416C    		;4137 3033	<L416C>
M4139:	LD   B,D     			;4139 42
	LD   B,L     			;413A 45
	JR   NC,L416E    		;413B 3031	<L416E>
	LD   (M3045),A   		;413D 324530	<M3045>
	LD   (M4145),A   		;4140 324541	<M4145>
M4143:	JR   NC,L4177    		;4143 3032	<L4177>
M4145:	LD   B,H     			;4145 44
L4146:	INC  (HL)    			;4146 34
	JR   NC,L418F    		;4147 3046	<L418F>
	LD   B,L     			;4149 45
	LD   SP,M3137    		;414A 313731	<M3137>
	LD   B,D     			;414D 42
	LD   (M4541),A   		;414E 324145	<M4541>
L4151:	JR   NC,L4194    		;4151 3041	<L4194>
	LD   B,H     			;4153 44
	DEC  C       			;4154 0D
	LD   A,(BC)  			;4155 0A
	LD   A,(M3032)   		;4156 3A3230	<M3032>
	LD   SP,M3242    		;4159 314232	<M3242>
	JR   NC,L418E    		;415C 3030	<L418E>
	JR   NC,L41A6    		;415E 3046	<L41A6>
	LD   B,E     			;4160 43
	JR   NC,L419B    		;4161 3038	<L419B>
L4163:	JR   NC,L419C    		;4163 3037	<L419C>
	LD   (M3030),A   		;4165 323030	<M3030>
L4168:	SCF          			;4168 37
	INC  (HL)    			;4169 34
	JR   NC,L419C    		;416A 3030	<L419C>
L416C:	SCF          			;416C 37
	JR   C,L419F     		;416D 3830	<L419F>
	LD   B,(HL)  			;416F 46
	LD   B,H     			;4170 44
	LD   (M3132),A   		;4171 323231	<M3132>
	LD   B,D     			;4174 42
	LD   B,(HL)  			;4175 46
L4176:	LD   B,E     			;4176 43
L4177:	JR   NC,L41AB    		;4177 3032	<L41AB>
	LD   SP,M4135    		;4179 313541	<M4135>
	JR   NC,L41AF    		;417C 3031	<L41AF>
	DEC  (HL)    			;417E 35
	JR   NC,L41B1    		;417F 3030	<L41B1>
	LD   SP,M3435    		;4181 313534	<M3435>
	JR   NC,L41B7    		;4184 3031	<L41B7>
	DEC  (HL)    			;4186 35
	JR   NC,L41B9    		;4187 3030	<L41B9>
	LD   B,(HL)  			;4189 46
	LD   B,H     			;418A 44
	LD   (M3144),A   		;418B 324431	<M3144>
L418E:	LD   B,D     			;418E 42
L418F:	LD   (M4543),A   		;418F 324345	<M4543>
	JR   NC,L41C4    		;4192 3030	<L41C4>
L4194:	JR   NC,L41CA    		;4194 3034	<L41CA>
	LD   B,D     			;4196 42
	LD   SP,M3442    		;4197 314234	<M3442>
	LD   B,E     			;419A 43
L419B:	LD   SP,M3742    		;419B 314237	<M3742>
	INC  SP      			;419E 33
L419F:	LD   B,C     			;419F 41
	LD   B,(HL)  			;41A0 46
	DEC  C       			;41A1 0D
	LD   A,(BC)  			;41A2 0A
	LD   A,(M3032)   		;41A3 3A3230	<M3032>
L41A6:	LD   SP,M3442    		;41A6 314234	<M3442>
	JR   NC,L41DB    		;41A9 3030	<L41DB>
L41AB:	JR   NC,L41DE    		;41AB 3031	<L41DE>
	LD   B,D     			;41AD 42
	JR   C,L41F6     		;41AE 3846	<L41F6>
	LD   SP,M4142    		;41B0 314241	<M4142>
	INC  SP      			;41B3 33
	LD   SP,M4342    		;41B4 314243	<M4342>
L41B7:	SCF          			;41B7 37
	LD   SP,M4342    		;41B8 314243	<M4342>
	LD   B,C     			;41BB 41
	LD   SP,M4442    		;41BC 314244	<M4442>
	LD   (HL),31H  			;41BF 3631	<31H>
	LD   B,D     			;41C1 42
	LD   B,(HL)  			;41C2 46
	LD   B,(HL)  			;41C3 46
L41C4:	SCF          			;41C4 37
	LD   B,D     			;41C5 42
	JR   NC,L41FC    		;41C6 3034	<L41FC>
	INC  (HL)    			;41C8 34
	JR   C,L41FB     		;41C9 3830	<L41FB>
	INC  (HL)    			;41CB 34
	SCF          			;41CC 37
	LD   B,D     			;41CD 42
	INC  (HL)    			;41CE 34
	JR   NC,L4205    		;41CF 3034	<L4205>
	JR   C,L4207     		;41D1 3834	<L4207>
	JR   NC,L420C    		;41D3 3037	<L420C>
	LD   B,D     			;41D5 42
	LD   SP,M3430    		;41D6 313034	<M3430>
	JR   C,L420C     		;41D9 3831	<L420C>
L41DB:	JR   NC,L4214    		;41DB 3037	<L4214>
	LD   B,D     			;41DD 42
L41DE:	JR   NC,L4212    		;41DE 3032	<L4212>
	INC  (HL)    			;41E0 34
	JR   C,L4213     		;41E1 3830	<L4213>
	LD   (M4246),A   		;41E3 324642	<M4246>
	JR   NC,L4218    		;41E6 3030	<L4218>
	LD   B,E     			;41E8 43
	JR   C,L421B     		;41E9 3830	<L421B>
	JR   NC,L4231    		;41EB 3044	<L4231>
	JR   NC,L41FC    		;41ED 300D	<L41FC>
	LD   A,(BC)  			;41EF 0A
	LD   A,(M3032)   		;41F0 3A3230	<M3032>
	LD   SP,M3642    		;41F3 314236	<M3642>
L41F6:	JR   NC,L4228    		;41F6 3030	<L4228>
	JR   NC,L4231    		;41F8 3037	<L4231>
	LD   B,D     			;41FA 42
L41FB:	LD   (M3430),A   		;41FB 323034	<M3430>
	JR   C,L4232     		;41FE 3832	<L4232>
	JR   NC,L4239    		;4200 3037	<L4239>
	LD   B,D     			;4202 42
	JR   NC,L4236    		;4203 3031	<L4236>
L4205:	INC  (HL)    			;4205 34
	JR   C,L4238     		;4206 3830	<L4238>
	LD   SP,M4237    		;4208 313742	<M4237>
	JR   C,L423D     		;420B 3830	<L423D>
	INC  (HL)    			;420D 34
	JR   C,L4248     		;420E 3838	<L4248>
	JR   NC,L4249    		;4210 3037	<L4249>
L4212:	LD   B,D     			;4212 42
L4213:	JR   NC,L424D    		;4213 3038	<L424D>
	INC  (HL)    			;4215 34
	JR   C,L4248     		;4216 3830	<L4248>
L4218:	JR   C,L4260     		;4218 3846	<L4260>
	LD   B,L     			;421A 45
L421B:	INC  (HL)    			;421B 34
	LD   B,E     			;421C 43
	LD   SP,M4642    		;421D 314246	<M4642>
	LD   B,E     			;4220 43
	JR   NC,L4265    		;4221 3042	<L4265>
	INC  (HL)    			;4223 34
	INC  (HL)    			;4224 34
	INC  (HL)    			;4225 34
	JR   NC,L425C    		;4226 3034	<L425C>
L4228:	INC  (HL)    			;4228 34
	LD   B,E     			;4229 43
	JR   C,L426F     		;422A 3843	<L426F>
	INC  SP      			;422C 33
	ADD  HL,SP   			;422D 39
	ADD  HL,SP   			;422E 39
	LD   B,E     			;422F 43
M4230:	INC  (HL)    			;4230 34
L4231:	INC  SP      			;4231 33
L4232:	INC  SP      			;4232 33
M4233:	INC  (HL)    			;4233 34
	INC  (HL)    			;4234 34
	LD   (M4336),A   		;4235 323643	<M4336>
L4238:	INC  SP      			;4238 33
L4239:	JR   C,L427D     		;4239 3842	<L427D>
	DEC  C       			;423B 0D
	LD   A,(BC)  			;423C 0A
L423D:	LD   A,(M3032)   		;423D 3A3230	<M3032>
	LD   SP,M3842    		;4240 314238	<M3842>
M4243:	JR   NC,L4275    		;4243 3030	<L4275>
	JR   NC,L4277    		;4245 3030	<L4277>
	INC  (HL)    			;4247 34
L4248:	LD   B,E     			;4248 43
L4249:	INC  (HL)    			;4249 34
	LD   B,C     			;424A 41
	JR   NC,L4281    		;424B 3034	<L4281>
L424D:	INC  (HL)    			;424D 34
	LD   B,(HL)  			;424E 46
	INC  (HL)    			;424F 34
	INC  (HL)    			;4250 34
	INC  SP      			;4251 33
	DEC  (HL)    			;4252 35
	LD   B,L     			;4253 45
	INC  (HL)    			;4254 34
	INC  (HL)    			;4255 34
	JR   NC,L429A    		;4256 3042	<L429A>
	INC  (HL)    			;4258 34
	INC  (HL)    			;4259 34
	JR   NC,L428D    		;425A 3031	<L428D>
L425C:	LD   B,(HL)  			;425C 46
	LD   B,H     			;425D 44
	SCF          			;425E 37
	DEC  (HL)    			;425F 35
L4260:	LD   SP,M4642    		;4260 314246	<M4642>
	LD   B,(HL)  			;4263 46
	LD   B,(HL)  			;4264 46
L4265:	LD   B,E     			;4265 43
	JR   NC,L42A9    		;4266 3041	<L42A9>
	INC  (HL)    			;4268 34
	LD   (HL),31H  			;4269 3631	<31H>
	LD   (M3634),A   		;426B 323436	<M3634>
	ADD  HL,SP   			;426E 39
L426F:	JR   NC,L42B4    		;426F 3043	<L42B4>
	LD   (HL),43H  			;4271 3643	<43H>
	JR   NC,L42B8    		;4273 3043	<L42B8>
L4275:	LD   (HL),36H  			;4275 3636	<36H>
L4277:	JR   C,L42AD     		;4277 3834	<L42AD>
	LD   (HL),32H  			;4279 3632	<32H>
	LD   B,H     			;427B 44
	INC  (HL)    			;427C 34
L427D:	LD   (HL),30H  			;427D 3630	<30H>
	SCF          			;427F 37
	LD   B,(HL)  			;4280 46
L4281:	LD   B,H     			;4281 44
	ADD  HL,SP   			;4282 39
	LD   SP,M4231    		;4283 313142	<M4231>
	ADD  HL,SP   			;4286 39
	INC  SP      			;4287 33
	DEC  C       			;4288 0D
	LD   A,(BC)  			;4289 0A
	LD   A,(M3032)   		;428A 3A3230	<M3032>
L428D:	LD   SP,M4142    		;428D 314241	<M4142>
	JR   NC,L42C2    		;4290 3030	<L42C2>
	JR   NC,L42D8    		;4292 3044	<L42D8>
	LD   B,L     			;4294 45
	LD   B,(HL)  			;4295 46
	LD   B,(HL)  			;4296 46
	LD   B,(HL)  			;4297 46
	LD   B,(HL)  			;4298 46
	LD   B,(HL)  			;4299 46
L429A:	LD   B,E     			;429A 43
	JR   NC,L42D0    		;429B 3033	<L42D0>
	INC  (HL)    			;429D 34
	LD   B,C     			;429E 41
	INC  (HL)    			;429F 34
	ADD  HL,SP   			;42A0 39
	INC  (HL)    			;42A1 34
	LD   B,C     			;42A2 41
	JR   NC,L42E7    		;42A3 3042	<L42E7>
	INC  (HL)    			;42A5 34
	LD   B,C     			;42A6 41
	LD   SP,M3433    		;42A7 313334	<M3433>
	LD   B,C     			;42AA 41
	ADD  HL,SP   			;42AB 39
	LD   (M4134),A   		;42AC 323441	<M4134>
	LD   B,H     			;42AF 44
	JR   NC,L42E6    		;42B0 3034	<L42E6>
	LD   B,C     			;42B2 41
	LD   B,E     			;42B3 43
L42B4:	JR   C,L42EA     		;42B4 3834	<L42EA>
	LD   B,C     			;42B6 41
	INC  (HL)    			;42B7 34
L42B8:	ADD  HL,SP   			;42B8 39
	INC  (HL)    			;42B9 34
	LD   B,C     			;42BA 41
	JR   NC,L42FF    		;42BB 3042	<L42FF>
	INC  (HL)    			;42BD 34
	LD   B,C     			;42BE 41
	JR   NC,L42F8    		;42BF 3037	<L42F8>
	INC  (HL)    			;42C1 34
L42C2:	LD   B,C     			;42C2 41
	LD   (M4336),A   		;42C3 323643	<M4336>
	LD   B,C     			;42C6 41
	LD   (M4334),A   		;42C7 323443	<M4334>
	LD   B,C     			;42CA 41
	LD   B,C     			;42CB 41
	JR   NC,L4311    		;42CC 3043	<L4311>
	LD   B,C     			;42CE 41
	LD   B,E     			;42CF 43
L42D0:	JR   NC,L4306    		;42D0 3034	<L4306>
	LD   B,C     			;42D2 41
	LD   (M0D38),A   		;42D3 32380D	<M0D38>
	LD   A,(BC)  			;42D6 0A
	LD   A,(M3032)   		;42D7 3A3230	<M3032>
	LD   SP,M4342    		;42DA 314243	<M4342>
	JR   NC,L430F    		;42DD 3030	<L430F>
	JR   NC,L4324    		;42DF 3043	<L4324>
	JR   C,L4329     		;42E1 3846	<L4329>
	LD   B,H     			;42E3 44
	LD   B,C     			;42E4 41
	DEC  (HL)    			;42E5 35
L42E6:	LD   SP,M3442    		;42E6 314234	<M3442>
	LD   (M3030),A   		;42E9 323030	<M3030>
	LD   B,(HL)  			;42EC 46
	LD   B,(HL)  			;42ED 46
	INC  (HL)    			;42EE 34
	LD   B,C     			;42EF 41
	JR   NC,L4322    		;42F0 3030	<L4322>
	LD   B,(HL)  			;42F2 46
	LD   B,(HL)  			;42F3 46
	LD   B,(HL)  			;42F4 46
	LD   B,E     			;42F5 43
	JR   NC,L432A    		;42F6 3032	<L432A>
L42F8:	LD   B,E     			;42F8 43
	INC  SP      			;42F9 33
	LD   B,(HL)  			;42FA 46
	JR   C,L4340     		;42FB 3843	<L4340>
	INC  SP      			;42FD 33
	LD   B,E     			;42FE 43
L42FF:	SCF          			;42FF 37
	INC  (HL)    			;4300 34
	INC  SP      			;4301 33
	INC  SP      			;4302 33
	LD   B,(HL)  			;4303 46
	LD   B,(HL)  			;4304 46
	LD   B,H     			;4305 44
L4306:	LD   B,E     			;4306 43
	LD   B,E     			;4307 43
	LD   SP,M4642    		;4308 314246	<M4642>
	LD   B,(HL)  			;430B 46
	LD   B,E     			;430C 43
	INC  SP      			;430D 33
	LD   B,D     			;430E 42
L430F:	LD   B,(HL)  			;430F 46
	LD   B,E     			;4310 43
L4311:	INC  SP      			;4311 33
	LD   B,(HL)  			;4312 46
	SCF          			;4313 37
	LD   B,E     			;4314 43
	INC  SP      			;4315 33
	LD   B,(HL)  			;4316 46
	LD   B,L     			;4317 45
	LD   B,E     			;4318 43
	INC  SP      			;4319 33
	LD   B,(HL)  			;431A 46
	LD   B,H     			;431B 44
	LD   B,E     			;431C 43
	INC  SP      			;431D 33
	LD   B,(HL)  			;431E 46
	LD   B,D     			;431F 42
	LD   B,H     			;4320 44
	INC  SP      			;4321 33
L4322:	DEC  C       			;4322 0D
	LD   A,(BC)  			;4323 0A
L4324:	LD   A,(M3032)   		;4324 3A3230	<M3032>
	LD   SP,M4542    		;4327 314245	<M4542>
L432A:	JR   NC,L435C    		;432A 3030	<L435C>
	JR   NC,L4371    		;432C 3043	<L4371>
	INC  SP      			;432E 33
	LD   B,H     			;432F 44
M4330:	LD   B,(HL)  			;4330 46
M4331:	INC  (HL)    			;4331 34
M4332:	INC  SP      			;4332 33
M4333:	LD   B,(HL)  			;4333 46
M4334:	LD   B,(HL)  			;4334 46
M4335:	LD   B,E     			;4335 43
M4336:	INC  SP      			;4336 33
M4337:	SCF          			;4337 37
M4338:	LD   B,(HL)  			;4338 46
M4339:	LD   B,(HL)  			;4339 46
	LD   B,(HL)  			;433A 46
	LD   SP,M3044    		;433B 314430	<M3044>
	JR   NC,L4370    		;433E 3030	<L4370>
L4340:	JR   NC,L4372    		;4340 3030	<L4372>
M4342:	JR   NC,L4374    		;4342 3030	<L4374>
M4344:	JR   NC,L4376    		;4344 3030	<L4376>
M4346:	JR   NC,L4378    		;4346 3030	<L4378>
	JR   NC,L437A    		;4348 3030	<L437A>
	JR   NC,L437C    		;434A 3030	<L437C>
	JR   NC,L437E    		;434C 3030	<L437E>
	JR   NC,L4380    		;434E 3030	<L4380>
	JR   NC,L4382    		;4350 3030	<L4382>
	JR   NC,L4384    		;4352 3030	<L4384>
	JR   NC,L4386    		;4354 3030	<L4386>
	JR   NC,L4388    		;4356 3030	<L4388>
	JR   NC,L438A    		;4358 3030	<L438A>
	JR   NC,L438C    		;435A 3030	<L438C>
L435C:	JR   NC,L438E    		;435C 3030	<L438E>
	JR   NC,L4390    		;435E 3030	<L4390>
	JR   NC,L4392    		;4360 3030	<L4392>
	JR   NC,L4394    		;4362 3030	<L4394>
	JR   NC,L4396    		;4364 3030	<L4396>
	JR   NC,L4398    		;4366 3030	<L4398>
	JR   NC,L439A    		;4368 3030	<L439A>
	JR   NC,L439C    		;436A 3030	<L439C>
	JR   NC,L43AF    		;436C 3041	<L43AF>
	INC  SP      			;436E 33
	DEC  C       			;436F 0D
L4370:	LD   A,(BC)  			;4370 0A
L4371:	LD   A,(M3032)   		;4371 3A3230	<M3032>
L4374:	LD   SP,M3043    		;4374 314330	<M3043>
	JR   NC,L43A9    		;4377 3030	<L43A9>
	JR   NC,L43BD    		;4379 3042	<L43BD>
	LD   (HL),41H  			;437B 3641	<41H>
	LD   B,(HL)  			;437D 46
L437E:	LD   B,E     			;437E 43
	LD   B,C     			;437F 41
L4380:	LD   B,H     			;4380 44
	LD   B,(HL)  			;4381 46
L4382:	LD   B,C     			;4382 41
	LD   B,(HL)  			;4383 46
L4384:	LD   B,E     			;4384 43
	LD   B,C     			;4385 41
L4386:	LD   B,H     			;4386 44
	LD   B,(HL)  			;4387 46
L4388:	JR   NC,L43BA    		;4388 3030	<L43BA>
L438A:	JR   NC,L43BC    		;438A 3030	<L43BC>
	JR   NC,L43BE    		;438C 3030	<L43BE>
	JR   NC,L43C0    		;438E 3030	<L43C0>
	JR   NC,L43C2    		;4390 3030	<L43C2>
	JR   NC,L43C4    		;4392 3030	<L43C4>
	JR   NC,L43C6    		;4394 3030	<L43C6>
	JR   NC,L43C8    		;4396 3030	<L43C8>
	JR   NC,L43CA    		;4398 3030	<L43CA>
	LD   B,D     			;439A 42
	LD   B,D     			;439B 42
	LD   B,H     			;439C 44
	JR   NC,L43E1    		;439D 3042	<L43E1>
	JR   NC,L43D3    		;439F 3032	<L43D3>
	JR   NC,L43E5    		;43A1 3042	<L43E5>
	LD   (HL),43H  			;43A3 3643	<43H>
	LD   B,E     			;43A5 43
	LD   B,H     			;43A6 44
	LD   B,L     			;43A7 45
	LD   B,D     			;43A8 42
	LD   B,E     			;43A9 43
	LD   B,D     			;43AA 42
	SCF          			;43AB 37
	LD   B,D     			;43AC 42
	LD   (HL),44H  			;43AD 3644	<44H>
	LD   B,L     			;43AF 45
	LD   B,D     			;43B0 42
	LD   (M4342),A   		;43B1 324243	<M4342>
	LD   B,C     			;43B4 41
	LD   B,E     			;43B5 43
	JR   NC,L43E8    		;43B6 3030	<L43E8>
	JR   NC,L43EA    		;43B8 3030	<L43EA>
	JR   C,L43EE     		;43BA 3832	<L43EE>
	DEC  C       			;43BC 0D
	LD   A,(BC)  			;43BD 0A
	LD   A,(M3032)   		;43BE 3A3230	<M3032>
	LD   SP,M3243    		;43C1 314332	<M3243>
	JR   NC,L43F6    		;43C4 3030	<L43F6>
	JR   NC,L43F8    		;43C6 3030	<L43F8>
	JR   NC,L43FA    		;43C8 3030	<L43FA>
	JR   NC,L43FC    		;43CA 3030	<L43FC>
	JR   NC,L43FE    		;43CC 3030	<L43FE>
	JR   NC,L4400    		;43CE 3030	<L4400>
	JR   NC,L4402    		;43D0 3030	<L4402>
	JR   NC,L4404    		;43D2 3030	<L4404>
	JR   NC,L4406    		;43D4 3030	<L4406>
	JR   NC,L4408    		;43D6 3030	<L4408>
	JR   NC,L440A    		;43D8 3030	<L440A>
	JR   NC,L440C    		;43DA 3030	<L440C>
	JR   NC,L440E    		;43DC 3030	<L440E>
	JR   NC,L4410    		;43DE 3030	<L4410>
	JR   NC,L4412    		;43E0 3030	<L4412>
	JR   NC,L4414    		;43E2 3030	<L4414>
	JR   NC,L4416    		;43E4 3030	<L4416>
	JR   NC,L442B    		;43E6 3043	<L442B>
	DEC  (HL)    			;43E8 35
	LD   B,D     			;43E9 42
	LD   (HL),43H  			;43EA 3643	<43H>
	ADD  HL,SP   			;43EC 39
	LD   B,H     			;43ED 44
	LD   B,E     			;43EE 43
	LD   B,E     			;43EF 43
	JR   NC,L4436    		;43F0 3044	<L4436>
	JR   C,L4426     		;43F2 3832	<L4426>
	JR   NC,L4439    		;43F4 3043	<L4439>
	JR   NC,L443A    		;43F6 3042	<L443A>
	JR   C,L443E     		;43F8 3844	<L443E>
	INC  (HL)    			;43FA 34
	JR   NC,L442D    		;43FB 3030	<L442D>
	JR   NC,L442F    		;43FD 3030	<L442F>
	JR   NC,L4431    		;43FF 3030	<L4431>
	JR   NC,L4433    		;4401 3030	<L4433>
	JR   NC,L4435    		;4403 3030	<L4435>
	JR   NC,L4437    		;4405 3030	<L4437>
	JR   C,L4439     		;4407 3830	<L4439>
	DEC  C       			;4409 0D
	LD   A,(BC)  			;440A 0A
	LD   A,(M3032)   		;440B 3A3230	<M3032>
	LD   SP,M3443    		;440E 314334	<M3443>
	JR   NC,L4443    		;4411 3030	<L4443>
	JR   NC,L4448    		;4413 3033	<L4448>
	LD   SP,M3933    		;4415 313339	<M3933>
	INC  SP      			;4418 33
	ADD  HL,SP   			;4419 39
	INC  SP      			;441A 33
	JR   C,L444F     		;441B 3832	<L444F>
	LD   B,(HL)  			;441D 46
	INC  SP      			;441E 33
	JR   NC,L4454    		;441F 3033	<L4454>
	INC  SP      			;4421 33
	LD   (M3346),A   		;4422 324633	<M3346>
	JR   NC,L445A    		;4425 3033	<L445A>
	DEC  (HL)    			;4427 35
	JR   NC,L445A    		;4428 3030	<L445A>
	JR   NC,L445C    		;442A 3030	<L445C>
	JR   NC,L445E    		;442C 3030	<L445E>
	JR   NC,L4460    		;442E 3030	<L4460>
M4430:	JR   NC,L4462    		;4430 3030	<L4462>
M4432:	JR   NC,L4464    		;4432 3030	<L4464>
	JR   NC,L4466    		;4434 3030	<L4466>
M4436:	JR   NC,L4468    		;4436 3030	<L4468>
M4438:	JR   NC,L446A    		;4438 3030	<L446A>
	JR   NC,L446C    		;443A 3030	<L446C>
	JR   NC,L446E    		;443C 3030	<L446E>
	JR   NC,L4470    		;443E 3030	<L4470>
	JR   NC,L4472    		;4440 3030	<L4472>
M4442:	JR   NC,L4474    		;4442 3030	<L4474>
	JR   NC,L4476    		;4444 3030	<L4476>
M4446:	JR   NC,L4478    		;4446 3030	<L4478>
	JR   NC,L447A    		;4448 3030	<L447A>
	JR   NC,L447C    		;444A 3030	<L447C>
	JR   NC,L447E    		;444C 3030	<L447E>
	JR   NC,L4480    		;444E 3030	<L4480>
	JR   NC,L4482    		;4450 3030	<L4482>
	JR   NC,L4484    		;4452 3030	<L4484>
	JR   C,L4489     		;4454 3833	<L4489>
	DEC  C       			;4456 0D
	LD   A,(BC)  			;4457 0A
	LD   A,(M3032)   		;4458 3A3230	<M3032>
	LD   SP,M3643    		;445B 314336	<M3643>
	JR   NC,L4490    		;445E 3030	<L4490>
	JR   NC,L4492    		;4460 3030	<L4492>
	JR   NC,L4494    		;4462 3030	<L4494>
	JR   NC,L4496    		;4464 3030	<L4496>
	JR   NC,L4498    		;4466 3030	<L4498>
	JR   NC,L449A    		;4468 3030	<L449A>
	JR   NC,L449C    		;446A 3030	<L449C>
	JR   NC,L449E    		;446C 3030	<L449E>
	JR   NC,L44A0    		;446E 3030	<L44A0>
	JR   NC,L44A2    		;4470 3030	<L44A2>
	JR   NC,L44A4    		;4472 3030	<L44A4>
	JR   NC,L44A6    		;4474 3030	<L44A6>
	JR   NC,L44A8    		;4476 3030	<L44A8>
	JR   NC,L44AA    		;4478 3030	<L44AA>
	JR   NC,L44AC    		;447A 3030	<L44AC>
	JR   NC,L44AE    		;447C 3030	<L44AE>
	JR   NC,L44B0    		;447E 3030	<L44B0>
	JR   NC,L44B2    		;4480 3030	<L44B2>
	JR   NC,L44B4    		;4482 3030	<L44B4>
	JR   NC,L44B6    		;4484 3030	<L44B6>
	JR   NC,L44B8    		;4486 3030	<L44B8>
	JR   NC,L44BA    		;4488 3030	<L44BA>
	JR   NC,L44BC    		;448A 3030	<L44BC>
	JR   NC,L44BE    		;448C 3030	<L44BE>
	JR   NC,L44C0    		;448E 3030	<L44C0>
	JR   NC,L44C2    		;4490 3030	<L44C2>
	JR   NC,L44C4    		;4492 3030	<L44C4>
	JR   NC,L44C6    		;4494 3030	<L44C6>
	JR   NC,L44C8    		;4496 3030	<L44C8>
	JR   NC,L44CA    		;4498 3030	<L44CA>
	JR   NC,L44CC    		;449A 3030	<L44CC>
	JR   NC,L44CE    		;449C 3030	<L44CE>
	JR   NC,L44D0    		;449E 3030	<L44D0>
	JR   NC,L44D8    		;44A0 3036	<L44D8>
	INC  (HL)    			;44A2 34
	DEC  C       			;44A3 0D
	LD   A,(BC)  			;44A4 0A
	LD   A,(M3032)   		;44A5 3A3230	<M3032>
	LD   SP,M3843    		;44A8 314338	<M3843>
	JR   NC,L44DD    		;44AB 3030	<L44DD>
	JR   NC,L44DF    		;44AD 3030	<L44DF>
	JR   NC,L44E1    		;44AF 3030	<L44E1>
	JR   NC,L44E3    		;44B1 3030	<L44E3>
	JR   NC,L44E5    		;44B3 3030	<L44E5>
	JR   NC,L44E7    		;44B5 3030	<L44E7>
	JR   NC,L44E9    		;44B7 3030	<L44E9>
	JR   NC,L44EB    		;44B9 3030	<L44EB>
	JR   NC,L44ED    		;44BB 3030	<L44ED>
	JR   NC,L44EF    		;44BD 3030	<L44EF>
	JR   NC,L44F1    		;44BF 3030	<L44F1>
	JR   NC,L44F3    		;44C1 3030	<L44F3>
	JR   NC,L44F5    		;44C3 3030	<L44F5>
	JR   NC,L44F7    		;44C5 3030	<L44F7>
	JR   NC,L44F9    		;44C7 3030	<L44F9>
	JR   NC,L44FB    		;44C9 3030	<L44FB>
	JR   NC,L44FD    		;44CB 3030	<L44FD>
	JR   NC,L44FF    		;44CD 3030	<L44FF>
	JR   NC,L4501    		;44CF 3030	<L4501>
	JR   NC,L4503    		;44D1 3030	<L4503>
	JR   NC,L4505    		;44D3 3030	<L4505>
	JR   NC,L4507    		;44D5 3030	<L4507>
	JR   NC,L4509    		;44D7 3030	<L4509>
	JR   NC,L450B    		;44D9 3030	<L450B>
	JR   NC,L450D    		;44DB 3030	<L450D>
	JR   NC,L450F    		;44DD 3030	<L450F>
	JR   NC,L4511    		;44DF 3030	<L4511>
	JR   NC,L4513    		;44E1 3030	<L4513>
	JR   NC,L4515    		;44E3 3030	<L4515>
	JR   NC,L4517    		;44E5 3030	<L4517>
	JR   NC,L4519    		;44E7 3030	<L4519>
	JR   NC,L451B    		;44E9 3030	<L451B>
	JR   NC,L451D    		;44EB 3030	<L451D>
	JR   NC,L4523    		;44ED 3034	<L4523>
	INC  (HL)    			;44EF 34
	DEC  C       			;44F0 0D
	LD   A,(BC)  			;44F1 0A
	LD   A,(M3032)   		;44F2 3A3230	<M3032>
	LD   SP,M4143    		;44F5 314341	<M4143>
	JR   NC,L452A    		;44F8 3030	<L452A>
	JR   NC,L452C    		;44FA 3030	<L452C>
	JR   NC,L452E    		;44FC 3030	<L452E>
	JR   NC,L4530    		;44FE 3030	<L4530>
	JR   NC,L4532    		;4500 3030	<L4532>
	JR   NC,L4534    		;4502 3030	<L4534>
	JR   NC,L4536    		;4504 3030	<L4536>
	JR   NC,L4538    		;4506 3030	<L4538>
	JR   NC,L453A    		;4508 3030	<L453A>
	JR   NC,L453C    		;450A 3030	<L453C>
	JR   NC,L453E    		;450C 3030	<L453E>
	JR   NC,L4540    		;450E 3030	<L4540>
	JR   NC,L4542    		;4510 3030	<L4542>
	JR   NC,L4544    		;4512 3030	<L4544>
	JR   NC,L4546    		;4514 3030	<L4546>
	JR   NC,L4548    		;4516 3030	<L4548>
	JR   NC,L454A    		;4518 3030	<L454A>
	JR   NC,L454C    		;451A 3030	<L454C>
	JR   NC,L454E    		;451C 3030	<L454E>
	JR   NC,L4550    		;451E 3030	<L4550>
	JR   NC,L4552    		;4520 3030	<L4552>
	JR   NC,L4554    		;4522 3030	<L4554>
	JR   NC,L4556    		;4524 3030	<L4556>
	JR   NC,L4558    		;4526 3030	<L4558>
	JR   NC,L455A    		;4528 3030	<L455A>
	JR   NC,L455C    		;452A 3030	<L455C>
	JR   NC,L455E    		;452C 3030	<L455E>
	JR   NC,L4560    		;452E 3030	<L4560>
M4530:	JR   NC,L4562    		;4530 3030	<L4562>
M4532:	JR   NC,L4564    		;4532 3030	<L4564>
M4534:	JR   NC,L4566    		;4534 3030	<L4566>
M4536:	JR   NC,L4568    		;4536 3030	<L4568>
M4538:	JR   NC,L456A    		;4538 3030	<L456A>
	JR   NC,L456E    		;453A 3032	<L456E>
	INC  (HL)    			;453C 34
	DEC  C       			;453D 0D
	LD   A,(BC)  			;453E 0A
	LD   A,(M3032)   		;453F 3A3230	<M3032>
M4542:	LD   SP,M4343    		;4542 314343	<M4343>
M4545:	JR   NC,L4577    		;4545 3030	<L4577>
	JR   NC,L4579    		;4547 3030	<L4579>
	JR   NC,L457B    		;4549 3030	<L457B>
	JR   NC,L457D    		;454B 3030	<L457D>
	JR   NC,L457F    		;454D 3030	<L457F>
	JR   NC,L4581    		;454F 3030	<L4581>
	JR   NC,L4583    		;4551 3030	<L4583>
	JR   NC,L4585    		;4553 3030	<L4585>
	JR   NC,L4587    		;4555 3030	<L4587>
	JR   NC,L4589    		;4557 3030	<L4589>
	JR   NC,L458B    		;4559 3030	<L458B>
	JR   NC,L458D    		;455B 3030	<L458D>
	JR   NC,L458F    		;455D 3030	<L458F>
	JR   NC,L4591    		;455F 3030	<L4591>
	JR   NC,L4593    		;4561 3030	<L4593>
	JR   NC,L4595    		;4563 3030	<L4595>
	JR   NC,L4597    		;4565 3030	<L4597>
	JR   NC,L4599    		;4567 3030	<L4599>
	JR   NC,L459B    		;4569 3030	<L459B>
	JR   NC,L459D    		;456B 3030	<L459D>
	JR   NC,L459F    		;456D 3030	<L459F>
	JR   NC,L45A1    		;456F 3030	<L45A1>
	JR   NC,L45A3    		;4571 3030	<L45A3>
	JR   NC,L45A5    		;4573 3030	<L45A5>
	JR   NC,L45A7    		;4575 3030	<L45A7>
	JR   NC,L45A9    		;4577 3030	<L45A9>
	JR   NC,L45AB    		;4579 3030	<L45AB>
	JR   NC,L45AD    		;457B 3030	<L45AD>
	JR   NC,L45AF    		;457D 3030	<L45AF>
	JR   NC,L45B1    		;457F 3030	<L45B1>
	JR   NC,L45B3    		;4581 3030	<L45B3>
	JR   NC,L45B5    		;4583 3030	<L45B5>
	JR   NC,L45B7    		;4585 3030	<L45B7>
	JR   NC,L45B9    		;4587 3030	<L45B9>
	INC  (HL)    			;4589 34
	DEC  C       			;458A 0D
	LD   A,(BC)  			;458B 0A
	LD   A,(M3032)   		;458C 3A3230	<M3032>
	LD   SP,M4543    		;458F 314345	<M4543>
	JR   NC,L45C4    		;4592 3030	<L45C4>
	JR   NC,L45C6    		;4594 3030	<L45C6>
	JR   NC,L45C8    		;4596 3030	<L45C8>
	JR   NC,L45CA    		;4598 3030	<L45CA>
	JR   NC,L45CC    		;459A 3030	<L45CC>
	JR   NC,L45CE    		;459C 3030	<L45CE>
	JR   NC,L45D0    		;459E 3030	<L45D0>
	JR   NC,L45D2    		;45A0 3030	<L45D2>
	JR   NC,L45D4    		;45A2 3030	<L45D4>
	JR   NC,L45D6    		;45A4 3030	<L45D6>
	JR   NC,L45D8    		;45A6 3030	<L45D8>
	JR   NC,L45DA    		;45A8 3030	<L45DA>
	JR   NC,L45DC    		;45AA 3030	<L45DC>
	JR   NC,L45DE    		;45AC 3030	<L45DE>
	JR   NC,L45E0    		;45AE 3030	<L45E0>
	JR   NC,L45E2    		;45B0 3030	<L45E2>
	JR   NC,L45E4    		;45B2 3030	<L45E4>
	JR   NC,L45E6    		;45B4 3030	<L45E6>
	JR   NC,L45E8    		;45B6 3030	<L45E8>
	JR   NC,L45EA    		;45B8 3030	<L45EA>
	JR   NC,L45EC    		;45BA 3030	<L45EC>
	JR   NC,L45EE    		;45BC 3030	<L45EE>
	JR   NC,L45F0    		;45BE 3030	<L45F0>
	JR   NC,L45F2    		;45C0 3030	<L45F2>
	JR   NC,L45F4    		;45C2 3030	<L45F4>
	JR   NC,L45F6    		;45C4 3030	<L45F6>
	JR   NC,L45F8    		;45C6 3030	<L45F8>
	JR   NC,L45FA    		;45C8 3030	<L45FA>
	JR   NC,L45FC    		;45CA 3030	<L45FC>
	JR   NC,L45FE    		;45CC 3030	<L45FE>
	JR   NC,L4600    		;45CE 3030	<L4600>
	JR   NC,L4602    		;45D0 3030	<L4602>
	JR   NC,L4604    		;45D2 3030	<L4604>
	JR   NC,L461B    		;45D4 3045	<L461B>
	INC  (HL)    			;45D6 34
	DEC  C       			;45D7 0D
	LD   A,(BC)  			;45D8 0A
	LD   A,(M3032)   		;45D9 3A3230	<M3032>
	LD   SP,M3044    		;45DC 314430	<M3044>
	JR   NC,L4611    		;45DF 3030	<L4611>
	JR   NC,L4613    		;45E1 3030	<L4613>
	JR   NC,L4615    		;45E3 3030	<L4615>
	JR   NC,L4617    		;45E5 3030	<L4617>
	JR   NC,L4619    		;45E7 3030	<L4619>
	JR   NC,L461B    		;45E9 3030	<L461B>
	JR   NC,L461D    		;45EB 3030	<L461D>
	JR   NC,L461F    		;45ED 3030	<L461F>
	JR   NC,L4621    		;45EF 3030	<L4621>
	JR   NC,L4623    		;45F1 3030	<L4623>
	JR   NC,L4625    		;45F3 3030	<L4625>
	JR   NC,L4627    		;45F5 3030	<L4627>
	JR   NC,L4629    		;45F7 3030	<L4629>
	JR   NC,L462B    		;45F9 3030	<L462B>
	JR   NC,L462D    		;45FB 3030	<L462D>
	JR   NC,L462F    		;45FD 3030	<L462F>
	JR   NC,L4631    		;45FF 3030	<L4631>
	JR   NC,L4633    		;4601 3030	<L4633>
	JR   NC,L4635    		;4603 3030	<L4635>
	JR   NC,L4637    		;4605 3030	<L4637>
	JR   NC,L4639    		;4607 3030	<L4639>
	JR   NC,L463B    		;4609 3030	<L463B>
	JR   NC,L463D    		;460B 3030	<L463D>
	JR   NC,L463F    		;460D 3030	<L463F>
	JR   NC,L4641    		;460F 3030	<L4641>
	JR   NC,L4643    		;4611 3030	<L4643>
	JR   NC,L4645    		;4613 3030	<L4645>
	JR   NC,L4647    		;4615 3030	<L4647>
	JR   NC,L4649    		;4617 3030	<L4649>
	JR   NC,L464B    		;4619 3030	<L464B>
	JR   NC,L464D    		;461B 3030	<L464D>
	JR   NC,L464F    		;461D 3030	<L464F>
	JR   NC,L4651    		;461F 3030	<L4651>
	JR   NC,L4666    		;4621 3043	<L4666>
	INC  SP      			;4623 33
	DEC  C       			;4624 0D
	LD   A,(BC)  			;4625 0A
	LD   A,(M3032)   		;4626 3A3230	<M3032>
	LD   SP,M3244    		;4629 314432	<M3244>
	JR   NC,L465E    		;462C 3030	<L465E>
	JR   NC,L4660    		;462E 3030	<L4660>
M4630:	JR   NC,L4662    		;4630 3030	<L4662>
M4632:	JR   NC,L4664    		;4632 3030	<L4664>
M4634:	JR   NC,L4666    		;4634 3030	<L4666>
M4636:	JR   NC,L4668    		;4636 3030	<L4668>
M4638:	JR   NC,L466A    		;4638 3030	<L466A>
	JR   NC,L466C    		;463A 3030	<L466C>
	JR   NC,L466E    		;463C 3030	<L466E>
	JR   NC,L4670    		;463E 3030	<L4670>
	JR   NC,L4672    		;4640 3030	<L4672>
M4642:	JR   NC,L4674    		;4642 3030	<L4674>
M4644:	JR   NC,L4676    		;4644 3030	<L4676>
M4646:	JR   NC,L4678    		;4646 3030	<L4678>
	JR   NC,L467A    		;4648 3030	<L467A>
	JR   NC,L467C    		;464A 3030	<L467C>
	JR   NC,L467E    		;464C 3030	<L467E>
	JR   NC,L4680    		;464E 3030	<L4680>
	JR   NC,L4682    		;4650 3030	<L4682>
	JR   NC,L4684    		;4652 3030	<L4684>
	JR   NC,L4686    		;4654 3030	<L4686>
	JR   NC,L4688    		;4656 3030	<L4688>
	JR   NC,L468A    		;4658 3030	<L468A>
	JR   NC,L468C    		;465A 3030	<L468C>
	JR   NC,L468E    		;465C 3030	<L468E>
	JR   NC,L4690    		;465E 3030	<L4690>
	JR   NC,L4692    		;4660 3030	<L4692>
	JR   NC,L4694    		;4662 3030	<L4694>
	JR   NC,L4696    		;4664 3030	<L4696>
	JR   NC,L4698    		;4666 3030	<L4698>
	JR   NC,L469A    		;4668 3030	<L469A>
	JR   NC,L469C    		;466A 3030	<L469C>
	JR   NC,L469E    		;466C 3030	<L469E>
	JR   NC,L46B1    		;466E 3041	<L46B1>
	INC  SP      			;4670 33
	DEC  C       			;4671 0D
	LD   A,(BC)  			;4672 0A
	LD   A,(M3032)   		;4673 3A3230	<M3032>
	LD   SP,M3444    		;4676 314434	<M3444>
	JR   NC,L46AB    		;4679 3030	<L46AB>
	JR   NC,L46AD    		;467B 3030	<L46AD>
	JR   NC,L46AF    		;467D 3030	<L46AF>
	JR   NC,L46B1    		;467F 3030	<L46B1>
	JR   NC,L46B3    		;4681 3030	<L46B3>
	JR   NC,L46B5    		;4683 3030	<L46B5>
	JR   NC,L46B7    		;4685 3030	<L46B7>
	JR   NC,L46B9    		;4687 3030	<L46B9>
	JR   NC,L46BB    		;4689 3030	<L46BB>
	JR   NC,L46BD    		;468B 3030	<L46BD>
	JR   NC,L46BF    		;468D 3030	<L46BF>
	JR   NC,L46C1    		;468F 3030	<L46C1>
	JR   NC,L46C3    		;4691 3030	<L46C3>
	JR   NC,L46C5    		;4693 3030	<L46C5>
	JR   NC,L46C7    		;4695 3030	<L46C7>
	JR   NC,L46C9    		;4697 3030	<L46C9>
	JR   NC,L46CB    		;4699 3030	<L46CB>
	JR   NC,L46CD    		;469B 3030	<L46CD>
	JR   NC,L46CF    		;469D 3030	<L46CF>
	JR   NC,L46D1    		;469F 3030	<L46D1>
	JR   NC,L46D3    		;46A1 3030	<L46D3>
	JR   NC,L46D5    		;46A3 3030	<L46D5>
	JR   NC,L46D7    		;46A5 3030	<L46D7>
	JR   NC,L46D9    		;46A7 3030	<L46D9>
	JR   NC,L46DB    		;46A9 3030	<L46DB>
	JR   NC,L46DD    		;46AB 3030	<L46DD>
	JR   NC,L46DF    		;46AD 3030	<L46DF>
	JR   NC,L46E1    		;46AF 3030	<L46E1>
	JR   NC,L46E3    		;46B1 3030	<L46E3>
	JR   NC,L46E5    		;46B3 3030	<L46E5>
	JR   NC,L46E7    		;46B5 3030	<L46E7>
	JR   NC,L46E9    		;46B7 3030	<L46E9>
	JR   NC,L46EB    		;46B9 3030	<L46EB>
	JR   NC,L46F5    		;46BB 3038	<L46F5>
	INC  SP      			;46BD 33
	DEC  C       			;46BE 0D
	LD   A,(BC)  			;46BF 0A
	LD   A,(M3032)   		;46C0 3A3230	<M3032>
	LD   SP,M3644    		;46C3 314436	<M3644>
	JR   NC,L46F8    		;46C6 3030	<L46F8>
	JR   NC,L46FA    		;46C8 3030	<L46FA>
	JR   NC,L46FC    		;46CA 3030	<L46FC>
	JR   NC,L46FE    		;46CC 3030	<L46FE>
	JR   NC,L4700    		;46CE 3030	<L4700>
	JR   NC,L4702    		;46D0 3030	<L4702>
	JR   NC,L4704    		;46D2 3030	<L4704>
	JR   NC,L4706    		;46D4 3030	<L4706>
	JR   NC,L4708    		;46D6 3030	<L4708>
	JR   NC,L470A    		;46D8 3030	<L470A>
	JR   NC,L470C    		;46DA 3030	<L470C>
	JR   NC,L470E    		;46DC 3030	<L470E>
	JR   NC,L4710    		;46DE 3030	<L4710>
	JR   NC,L4712    		;46E0 3030	<L4712>
	JR   NC,L4714    		;46E2 3030	<L4714>
	JR   NC,L4716    		;46E4 3030	<L4716>
	JR   NC,L4718    		;46E6 3030	<L4718>
	JR   NC,L471A    		;46E8 3030	<L471A>
	JR   NC,L471C    		;46EA 3030	<L471C>
	JR   NC,L471E    		;46EC 3030	<L471E>
	JR   NC,L4720    		;46EE 3030	<L4720>
	JR   NC,L4722    		;46F0 3030	<L4722>
	JR   NC,L4724    		;46F2 3030	<L4724>
	JR   NC,L4726    		;46F4 3030	<L4726>
	JR   NC,L4728    		;46F6 3030	<L4728>
	JR   NC,L472A    		;46F8 3030	<L472A>
	JR   NC,L472C    		;46FA 3030	<L472C>
	JR   NC,L472E    		;46FC 3030	<L472E>
	JR   NC,L4730    		;46FE 3030	<L4730>
	JR   NC,L4732    		;4700 3030	<L4732>
	JR   NC,L4734    		;4702 3030	<L4734>
	JR   NC,L4736    		;4704 3030	<L4736>
	JR   NC,L4738    		;4706 3030	<L4738>
	JR   NC,L4740    		;4708 3036	<L4740>
	INC  SP      			;470A 33
	DEC  C       			;470B 0D
	LD   A,(BC)  			;470C 0A
	LD   A,(M3032)   		;470D 3A3230	<M3032>
	LD   SP,M3844    		;4710 314438	<M3844>
	JR   NC,L4745    		;4713 3030	<L4745>
	JR   NC,L4747    		;4715 3030	<L4747>
	JR   NC,L4749    		;4717 3030	<L4749>
	JR   NC,L474B    		;4719 3030	<L474B>
	JR   NC,L474D    		;471B 3030	<L474D>
	JR   NC,L474F    		;471D 3030	<L474F>
	JR   NC,L4751    		;471F 3030	<L4751>
	JR   NC,L4753    		;4721 3030	<L4753>
	JR   NC,L4755    		;4723 3030	<L4755>
	JR   NC,L4757    		;4725 3030	<L4757>
	JR   NC,L4759    		;4727 3030	<L4759>
	JR   NC,L475B    		;4729 3030	<L475B>
	JR   NC,L475D    		;472B 3030	<L475D>
	JR   NC,L475F    		;472D 3030	<L475F>
	JR   NC,L4761    		;472F 3030	<L4761>
	JR   NC,L4763    		;4731 3030	<L4763>
	JR   NC,L4765    		;4733 3030	<L4765>
	JR   NC,L4767    		;4735 3030	<L4767>
	JR   NC,L4769    		;4737 3030	<L4769>
	JR   NC,L476B    		;4739 3030	<L476B>
	JR   NC,L476D    		;473B 3030	<L476D>
	JR   NC,L476F    		;473D 3030	<L476F>
	JR   NC,L4771    		;473F 3030	<L4771>
	JR   NC,L4773    		;4741 3030	<L4773>
	JR   NC,L4775    		;4743 3030	<L4775>
	JR   NC,L4777    		;4745 3030	<L4777>
	JR   NC,L4779    		;4747 3030	<L4779>
	JR   NC,L477B    		;4749 3030	<L477B>
	JR   NC,L477D    		;474B 3030	<L477D>
	JR   NC,L477F    		;474D 3030	<L477F>
	JR   NC,L4781    		;474F 3030	<L4781>
	JR   NC,L4783    		;4751 3030	<L4783>
	JR   NC,L4785    		;4753 3030	<L4785>
	JR   NC,L478B    		;4755 3034	<L478B>
	INC  SP      			;4757 33
	DEC  C       			;4758 0D
	LD   A,(BC)  			;4759 0A
	LD   A,(M3032)   		;475A 3A3230	<M3032>
	LD   SP,M4144    		;475D 314441	<M4144>
	JR   NC,L4792    		;4760 3030	<L4792>
	JR   NC,L4794    		;4762 3030	<L4794>
	JR   NC,L4796    		;4764 3030	<L4796>
	JR   NC,L4798    		;4766 3030	<L4798>
	JR   NC,L479A    		;4768 3030	<L479A>
	JR   NC,L479C    		;476A 3030	<L479C>
	JR   NC,L479E    		;476C 3030	<L479E>
	JR   NC,L47A0    		;476E 3030	<L47A0>
	JR   NC,L47A2    		;4770 3030	<L47A2>
	JR   NC,L47A4    		;4772 3030	<L47A4>
	JR   NC,L47A6    		;4774 3030	<L47A6>
	JR   NC,L47A8    		;4776 3030	<L47A8>
	JR   NC,L47AA    		;4778 3030	<L47AA>
	JR   NC,L47AC    		;477A 3030	<L47AC>
	JR   NC,L47AE    		;477C 3030	<L47AE>
	JR   NC,L47B0    		;477E 3030	<L47B0>
	JR   NC,L47B2    		;4780 3030	<L47B2>
	JR   NC,L47B4    		;4782 3030	<L47B4>
	JR   NC,L47B6    		;4784 3030	<L47B6>
	JR   NC,L47B8    		;4786 3030	<L47B8>
	JR   NC,L47BA    		;4788 3030	<L47BA>
	JR   NC,L47BC    		;478A 3030	<L47BC>
	JR   NC,L47BE    		;478C 3030	<L47BE>
	JR   NC,L47C0    		;478E 3030	<L47C0>
	JR   NC,L47C2    		;4790 3030	<L47C2>
	JR   NC,L47C4    		;4792 3030	<L47C4>
	JR   NC,L47C6    		;4794 3030	<L47C6>
	JR   NC,L47C8    		;4796 3030	<L47C8>
	JR   NC,L47CA    		;4798 3030	<L47CA>
	JR   NC,L47CC    		;479A 3030	<L47CC>
	JR   NC,L47CE    		;479C 3030	<L47CE>
	JR   NC,L47D0    		;479E 3030	<L47D0>
	JR   NC,L47D2    		;47A0 3030	<L47D2>
	JR   NC,L47D6    		;47A2 3032	<L47D6>
	INC  SP      			;47A4 33
	DEC  C       			;47A5 0D
	LD   A,(BC)  			;47A6 0A
	LD   A,(M3032)   		;47A7 3A3230	<M3032>
	LD   SP,M4344    		;47AA 314443	<M4344>
	JR   NC,L47DF    		;47AD 3030	<L47DF>
	JR   NC,L47E1    		;47AF 3030	<L47E1>
	JR   NC,L47E3    		;47B1 3030	<L47E3>
	JR   NC,L47E5    		;47B3 3030	<L47E5>
	JR   NC,L47E7    		;47B5 3030	<L47E7>
	JR   NC,L47E9    		;47B7 3030	<L47E9>
	JR   NC,L47EB    		;47B9 3030	<L47EB>
	JR   NC,L47ED    		;47BB 3030	<L47ED>
	JR   NC,L47EF    		;47BD 3030	<L47EF>
	JR   NC,L47F1    		;47BF 3030	<L47F1>
	JR   NC,L47F3    		;47C1 3030	<L47F3>
	JR   NC,L47F5    		;47C3 3030	<L47F5>
	JR   NC,L47F7    		;47C5 3030	<L47F7>
	JR   NC,L47F9    		;47C7 3030	<L47F9>
	JR   NC,L47FB    		;47C9 3030	<L47FB>
	JR   NC,L47FD    		;47CB 3030	<L47FD>
	JR   NC,L47FF    		;47CD 3030	<L47FF>
	JR   NC,L4801    		;47CF 3030	<L4801>
	JR   NC,L4803    		;47D1 3030	<L4803>
	JR   NC,L4805    		;47D3 3030	<L4805>
	JR   NC,L4807    		;47D5 3030	<L4807>
	JR   NC,L4809    		;47D7 3030	<L4809>
	JR   NC,L480B    		;47D9 3030	<L480B>
	JR   NC,L480D    		;47DB 3030	<L480D>
	JR   NC,L480F    		;47DD 3030	<L480F>
	JR   NC,L4811    		;47DF 3030	<L4811>
	JR   NC,L4813    		;47E1 3030	<L4813>
	JR   NC,L4815    		;47E3 3030	<L4815>
	JR   NC,L4817    		;47E5 3030	<L4817>
	JR   NC,L4819    		;47E7 3030	<L4819>
	JR   NC,L481B    		;47E9 3030	<L481B>
	JR   NC,L481D    		;47EB 3030	<L481D>
	JR   NC,L481F    		;47ED 3030	<L481F>
	JR   NC,L4821    		;47EF 3030	<L4821>
	INC  SP      			;47F1 33
	DEC  C       			;47F2 0D
	LD   A,(BC)  			;47F3 0A
	LD   A,(M3032)   		;47F4 3A3230	<M3032>
	LD   SP,M4544    		;47F7 314445	<M4544>
	JR   NC,L482C    		;47FA 3030	<L482C>
	JR   NC,L482E    		;47FC 3030	<L482E>
	JR   NC,L4830    		;47FE 3030	<L4830>
	JR   NC,L4832    		;4800 3030	<L4832>
	JR   NC,L4834    		;4802 3030	<L4834>
	JR   NC,L4836    		;4804 3030	<L4836>
	JR   NC,L4838    		;4806 3030	<L4838>
	JR   NC,L483A    		;4808 3030	<L483A>
	JR   NC,L483C    		;480A 3030	<L483C>
	JR   NC,L483E    		;480C 3030	<L483E>
	JR   NC,L4840    		;480E 3030	<L4840>
	JR   NC,L4842    		;4810 3030	<L4842>
	JR   NC,L4844    		;4812 3030	<L4844>
	JR   NC,L4846    		;4814 3030	<L4846>
	JR   NC,L4848    		;4816 3030	<L4848>
	JR   NC,L484A    		;4818 3030	<L484A>
	JR   NC,L484C    		;481A 3030	<L484C>
	JR   NC,L484E    		;481C 3030	<L484E>
	JR   NC,L4850    		;481E 3030	<L4850>
	JR   NC,L4852    		;4820 3030	<L4852>
	JR   NC,L4854    		;4822 3030	<L4854>
	JR   NC,L4856    		;4824 3030	<L4856>
	JR   NC,L4858    		;4826 3030	<L4858>
	JR   NC,L485A    		;4828 3030	<L485A>
	JR   NC,L485C    		;482A 3030	<L485C>
	JR   NC,L485E    		;482C 3030	<L485E>
	JR   NC,L4860    		;482E 3030	<L4860>
	JR   NC,L4862    		;4830 3030	<L4862>
	JR   NC,L4864    		;4832 3030	<L4864>
	JR   NC,L4866    		;4834 3030	<L4866>
	JR   NC,L4868    		;4836 3030	<L4868>
	JR   NC,L486A    		;4838 3030	<L486A>
	JR   NC,L486C    		;483A 3030	<L486C>
	JR   NC,L4883    		;483C 3045	<L4883>
	INC  SP      			;483E 33
	DEC  C       			;483F 0D
	LD   A,(BC)  			;4840 0A
	LD   A,(M3032)   		;4841 3A3230	<M3032>
	LD   SP,M3045    		;4844 314530	<M3045>
	JR   NC,L4879    		;4847 3030	<L4879>
	JR   NC,L487B    		;4849 3030	<L487B>
	JR   NC,L487D    		;484B 3030	<L487D>
	JR   NC,L487F    		;484D 3030	<L487F>
	JR   NC,L4881    		;484F 3030	<L4881>
	JR   NC,L4883    		;4851 3030	<L4883>
	JR   NC,L4885    		;4853 3030	<L4885>
	JR   NC,L4887    		;4855 3030	<L4887>
	JR   NC,L4889    		;4857 3030	<L4889>
	JR   NC,L488B    		;4859 3030	<L488B>
	JR   NC,L488D    		;485B 3030	<L488D>
	JR   NC,L488F    		;485D 3030	<L488F>
	JR   NC,L4891    		;485F 3030	<L4891>
	JR   NC,L4893    		;4861 3030	<L4893>
	JR   NC,L4895    		;4863 3030	<L4895>
	JR   NC,L4897    		;4865 3030	<L4897>
	JR   NC,L4899    		;4867 3030	<L4899>
	JR   NC,L489B    		;4869 3030	<L489B>
	JR   NC,L489D    		;486B 3030	<L489D>
	JR   NC,L489F    		;486D 3030	<L489F>
	JR   NC,L48A1    		;486F 3030	<L48A1>
	JR   NC,L48A3    		;4871 3030	<L48A3>
	JR   NC,L48A5    		;4873 3030	<L48A5>
	JR   NC,L48A7    		;4875 3030	<L48A7>
	JR   NC,L48A9    		;4877 3030	<L48A9>
	JR   NC,L48AB    		;4879 3030	<L48AB>
	JR   NC,L48AD    		;487B 3030	<L48AD>
	JR   NC,L48AF    		;487D 3030	<L48AF>
	JR   NC,L48B1    		;487F 3030	<L48B1>
	JR   NC,L48B3    		;4881 3030	<L48B3>
	JR   NC,L48B5    		;4883 3030	<L48B5>
	JR   NC,L48B7    		;4885 3030	<L48B7>
	JR   NC,L48B9    		;4887 3030	<L48B9>
	JR   NC,L48CE    		;4889 3043	<L48CE>
	LD   (M0A0D),A   		;488B 320D0A	<M0A0D>
	LD   A,(M3032)   		;488E 3A3230	<M3032>
	LD   SP,M3245    		;4891 314532	<M3245>
	JR   NC,L48C6    		;4894 3030	<L48C6>
	JR   NC,L48C8    		;4896 3030	<L48C8>
	JR   NC,L48CA    		;4898 3030	<L48CA>
	JR   NC,L48CC    		;489A 3030	<L48CC>
	JR   NC,L48CE    		;489C 3030	<L48CE>
	JR   NC,L48D0    		;489E 3030	<L48D0>
	JR   NC,L48D2    		;48A0 3030	<L48D2>
	JR   NC,L48D4    		;48A2 3030	<L48D4>
	JR   NC,L48D6    		;48A4 3030	<L48D6>
	JR   NC,L48D8    		;48A6 3030	<L48D8>
	JR   NC,L48DA    		;48A8 3030	<L48DA>
	JR   NC,L48DC    		;48AA 3030	<L48DC>
	JR   NC,L48DE    		;48AC 3030	<L48DE>
	JR   NC,L48E0    		;48AE 3030	<L48E0>
	JR   NC,L48E2    		;48B0 3030	<L48E2>
	JR   NC,L48E4    		;48B2 3030	<L48E4>
	JR   NC,L48E6    		;48B4 3030	<L48E6>
	JR   NC,L48E8    		;48B6 3030	<L48E8>
	JR   NC,L48EA    		;48B8 3030	<L48EA>
	JR   NC,L48EC    		;48BA 3030	<L48EC>
	JR   NC,L48EE    		;48BC 3030	<L48EE>
	JR   NC,L48F0    		;48BE 3030	<L48F0>
	JR   NC,L48F2    		;48C0 3030	<L48F2>
	JR   NC,L48F4    		;48C2 3030	<L48F4>
	JR   NC,L48F6    		;48C4 3030	<L48F6>
	JR   NC,L48F8    		;48C6 3030	<L48F8>
	JR   NC,L48FA    		;48C8 3030	<L48FA>
	JR   NC,L48FC    		;48CA 3030	<L48FC>
	JR   NC,L48FE    		;48CC 3030	<L48FE>
	JR   NC,L4900    		;48CE 3030	<L4900>
	JR   NC,L4902    		;48D0 3030	<L4902>
	JR   NC,L4904    		;48D2 3030	<L4904>
	JR   NC,L4906    		;48D4 3030	<L4906>
	JR   NC,L4919    		;48D6 3041	<L4919>
	LD   (M0A0D),A   		;48D8 320D0A	<M0A0D>
	LD   A,(M3032)   		;48DB 3A3230	<M3032>
	LD   SP,M3445    		;48DE 314534	<M3445>
	JR   NC,L4913    		;48E1 3030	<L4913>
	JR   NC,L4915    		;48E3 3030	<L4915>
	JR   NC,L4917    		;48E5 3030	<L4917>
	JR   NC,L4919    		;48E7 3030	<L4919>
	JR   NC,L491B    		;48E9 3030	<L491B>
	JR   NC,L491D    		;48EB 3030	<L491D>
	JR   NC,L491F    		;48ED 3030	<L491F>
	JR   NC,L4921    		;48EF 3030	<L4921>
	JR   NC,L4923    		;48F1 3030	<L4923>
	JR   NC,L4925    		;48F3 3030	<L4925>
	JR   NC,L4927    		;48F5 3030	<L4927>
	JR   NC,L4929    		;48F7 3030	<L4929>
	JR   NC,L492B    		;48F9 3030	<L492B>
	JR   NC,L492D    		;48FB 3030	<L492D>
	JR   NC,L492F    		;48FD 3030	<L492F>
	JR   NC,L4931    		;48FF 3030	<L4931>
	JR   NC,L4933    		;4901 3030	<L4933>
	JR   NC,L4935    		;4903 3030	<L4935>
	JR   NC,L4937    		;4905 3030	<L4937>
	JR   NC,L4939    		;4907 3030	<L4939>
	JR   NC,L493B    		;4909 3030	<L493B>
	JR   NC,L493D    		;490B 3030	<L493D>
	JR   NC,L493F    		;490D 3030	<L493F>
	JR   NC,L4941    		;490F 3030	<L4941>
	JR   NC,L4943    		;4911 3030	<L4943>
	JR   NC,L4945    		;4913 3030	<L4945>
	JR   NC,L4947    		;4915 3030	<L4947>
	JR   NC,L4949    		;4917 3030	<L4949>
	JR   NC,L494B    		;4919 3030	<L494B>
	JR   NC,L494D    		;491B 3030	<L494D>
	JR   NC,L494F    		;491D 3030	<L494F>
	JR   NC,L4951    		;491F 3030	<L4951>
	JR   NC,L4953    		;4921 3030	<L4953>
	JR   NC,L495D    		;4923 3038	<L495D>
	LD   (M0A0D),A   		;4925 320D0A	<M0A0D>
	LD   A,(M3032)   		;4928 3A3230	<M3032>
	LD   SP,M3645    		;492B 314536	<M3645>
	JR   NC,L4960    		;492E 3030	<L4960>
	JR   NC,L4962    		;4930 3030	<L4962>
	JR   NC,L4964    		;4932 3030	<L4964>
	JR   NC,L4966    		;4934 3030	<L4966>
	JR   NC,L4968    		;4936 3030	<L4968>
	JR   NC,L496A    		;4938 3030	<L496A>
	JR   NC,L496C    		;493A 3030	<L496C>
	JR   NC,L496E    		;493C 3030	<L496E>
	JR   NC,L4970    		;493E 3030	<L4970>
	JR   NC,L4972    		;4940 3030	<L4972>
	JR   NC,L4974    		;4942 3030	<L4974>
	JR   NC,L4976    		;4944 3030	<L4976>
	JR   NC,L4978    		;4946 3030	<L4978>
	JR   NC,L497A    		;4948 3030	<L497A>
	JR   NC,L497C    		;494A 3030	<L497C>
	JR   NC,L497E    		;494C 3030	<L497E>
	JR   NC,L4980    		;494E 3030	<L4980>
	JR   NC,L4982    		;4950 3030	<L4982>
	JR   NC,L4984    		;4952 3030	<L4984>
	JR   NC,L4986    		;4954 3030	<L4986>
	JR   NC,L4988    		;4956 3030	<L4988>
	JR   NC,L498A    		;4958 3030	<L498A>
	JR   NC,L498C    		;495A 3030	<L498C>
	JR   NC,L498E    		;495C 3030	<L498E>
	JR   NC,L4990    		;495E 3030	<L4990>
	JR   NC,L4992    		;4960 3030	<L4992>
	JR   NC,L4994    		;4962 3030	<L4994>
	JR   NC,L4996    		;4964 3030	<L4996>
	JR   NC,L4998    		;4966 3030	<L4998>
	JR   NC,L499A    		;4968 3030	<L499A>
	JR   NC,L499C    		;496A 3030	<L499C>
	JR   NC,L499E    		;496C 3030	<L499E>
	JR   NC,L49A0    		;496E 3030	<L49A0>
	JR   NC,L49A8    		;4970 3036	<L49A8>
	LD   (M0A0D),A   		;4972 320D0A	<M0A0D>
	LD   A,(M3032)   		;4975 3A3230	<M3032>
	LD   SP,M3845    		;4978 314538	<M3845>
	JR   NC,L49AD    		;497B 3030	<L49AD>
	JR   NC,L49AF    		;497D 3030	<L49AF>
	JR   NC,L49B1    		;497F 3030	<L49B1>
	JR   NC,L49B3    		;4981 3030	<L49B3>
	JR   NC,L49B5    		;4983 3030	<L49B5>
	JR   NC,L49B7    		;4985 3030	<L49B7>
	JR   NC,L49B9    		;4987 3030	<L49B9>
	JR   NC,L49BB    		;4989 3030	<L49BB>
	JR   NC,L49BD    		;498B 3030	<L49BD>
	JR   NC,L49BF    		;498D 3030	<L49BF>
	JR   NC,L49C1    		;498F 3030	<L49C1>
	JR   NC,L49C3    		;4991 3030	<L49C3>
	JR   NC,L49C5    		;4993 3030	<L49C5>
	JR   NC,L49C7    		;4995 3030	<L49C7>
	JR   NC,L49C9    		;4997 3030	<L49C9>
	JR   NC,L49CB    		;4999 3030	<L49CB>
	JR   NC,L49CD    		;499B 3030	<L49CD>
	JR   NC,L49CF    		;499D 3030	<L49CF>
	JR   NC,L49D1    		;499F 3030	<L49D1>
	JR   NC,L49D3    		;49A1 3030	<L49D3>
	JR   NC,L49D5    		;49A3 3030	<L49D5>
	JR   NC,L49D7    		;49A5 3030	<L49D7>
	JR   NC,L49D9    		;49A7 3030	<L49D9>
	JR   NC,L49DB    		;49A9 3030	<L49DB>
	JR   NC,L49DD    		;49AB 3030	<L49DD>
	JR   NC,L49DF    		;49AD 3030	<L49DF>
	JR   NC,L49E1    		;49AF 3030	<L49E1>
	JR   NC,L49E3    		;49B1 3030	<L49E3>
	JR   NC,L49E5    		;49B3 3030	<L49E5>
	JR   NC,L49E7    		;49B5 3030	<L49E7>
	JR   NC,L49E9    		;49B7 3030	<L49E9>
	JR   NC,L49EB    		;49B9 3030	<L49EB>
	JR   NC,L49ED    		;49BB 3030	<L49ED>
	JR   NC,L49F3    		;49BD 3034	<L49F3>
	LD   (M0A0D),A   		;49BF 320D0A	<M0A0D>
	LD   A,(M3032)   		;49C2 3A3230	<M3032>
	LD   SP,M4145    		;49C5 314541	<M4145>
	JR   NC,L49FA    		;49C8 3030	<L49FA>
	JR   NC,L49FC    		;49CA 3030	<L49FC>
	JR   NC,L49FE    		;49CC 3030	<L49FE>
	JR   NC,L4A00    		;49CE 3030	<L4A00>
	JR   NC,L4A02    		;49D0 3030	<L4A02>
	JR   NC,L4A04    		;49D2 3030	<L4A04>
	JR   NC,L4A06    		;49D4 3030	<L4A06>
	JR   NC,L4A08    		;49D6 3030	<L4A08>
	JR   NC,L4A0A    		;49D8 3030	<L4A0A>
	JR   NC,L4A0C    		;49DA 3030	<L4A0C>
	JR   NC,L4A0E    		;49DC 3030	<L4A0E>
	JR   NC,L4A10    		;49DE 3030	<L4A10>
	JR   NC,L4A12    		;49E0 3030	<L4A12>
	JR   NC,L4A14    		;49E2 3030	<L4A14>
	JR   NC,L4A16    		;49E4 3030	<L4A16>
	JR   NC,L4A18    		;49E6 3030	<L4A18>
	JR   NC,L4A1A    		;49E8 3030	<L4A1A>
	JR   NC,L4A1C    		;49EA 3030	<L4A1C>
	JR   NC,L4A1E    		;49EC 3030	<L4A1E>
	JR   NC,L4A20    		;49EE 3030	<L4A20>
	JR   NC,L4A22    		;49F0 3030	<L4A22>
	JR   NC,L4A24    		;49F2 3030	<L4A24>
	JR   NC,L4A26    		;49F4 3030	<L4A26>
	JR   NC,L4A28    		;49F6 3030	<L4A28>
	JR   NC,L4A2A    		;49F8 3030	<L4A2A>
	JR   NC,L4A2C    		;49FA 3030	<L4A2C>
	JR   NC,L4A2E    		;49FC 3030	<L4A2E>
	JR   NC,L4A30    		;49FE 3030	<L4A30>
	JR   NC,L4A32    		;4A00 3030	<L4A32>
	JR   NC,L4A34    		;4A02 3030	<L4A34>
	JR   NC,L4A36    		;4A04 3030	<L4A36>
	JR   NC,L4A38    		;4A06 3030	<L4A38>
	JR   NC,L4A3A    		;4A08 3030	<L4A3A>
	JR   NC,L4A3E    		;4A0A 3032	<L4A3E>
	LD   (M0A0D),A   		;4A0C 320D0A	<M0A0D>
	LD   A,(M3032)   		;4A0F 3A3230	<M3032>
	LD   SP,M4345    		;4A12 314543	<M4345>
	JR   NC,L4A47    		;4A15 3030	<L4A47>
	JR   NC,L4A49    		;4A17 3030	<L4A49>
	JR   NC,L4A4B    		;4A19 3030	<L4A4B>
	JR   NC,L4A4D    		;4A1B 3030	<L4A4D>
	JR   NC,L4A4F    		;4A1D 3030	<L4A4F>
	JR   NC,L4A51    		;4A1F 3030	<L4A51>
	JR   NC,L4A53    		;4A21 3030	<L4A53>
	JR   NC,L4A55    		;4A23 3030	<L4A55>
	JR   NC,L4A57    		;4A25 3030	<L4A57>
	JR   NC,L4A59    		;4A27 3030	<L4A59>
	JR   NC,L4A5B    		;4A29 3030	<L4A5B>
	JR   NC,L4A5D    		;4A2B 3030	<L4A5D>
	JR   NC,L4A5F    		;4A2D 3030	<L4A5F>
	JR   NC,L4A61    		;4A2F 3030	<L4A61>
	JR   NC,L4A63    		;4A31 3030	<L4A63>
	JR   NC,L4A65    		;4A33 3030	<L4A65>
	JR   NC,L4A67    		;4A35 3030	<L4A67>
	JR   NC,L4A69    		;4A37 3030	<L4A69>
	JR   NC,L4A6B    		;4A39 3030	<L4A6B>
	JR   NC,L4A6D    		;4A3B 3030	<L4A6D>
	JR   NC,L4A6F    		;4A3D 3030	<L4A6F>
	JR   NC,L4A71    		;4A3F 3030	<L4A71>
	JR   NC,L4A73    		;4A41 3030	<L4A73>
	JR   NC,L4A75    		;4A43 3030	<L4A75>
	JR   NC,L4A77    		;4A45 3030	<L4A77>
	JR   NC,L4A79    		;4A47 3030	<L4A79>
	JR   NC,L4A7B    		;4A49 3030	<L4A7B>
	JR   NC,L4A7D    		;4A4B 3030	<L4A7D>
	JR   NC,L4A7F    		;4A4D 3030	<L4A7F>
	JR   NC,L4A81    		;4A4F 3030	<L4A81>
	JR   NC,L4A83    		;4A51 3030	<L4A83>
	JR   NC,L4A85    		;4A53 3030	<L4A85>
	JR   NC,L4A87    		;4A55 3030	<L4A87>
	JR   NC,L4A89    		;4A57 3030	<L4A89>
	LD   (M0A0D),A   		;4A59 320D0A	<M0A0D>
	LD   A,(M3032)   		;4A5C 3A3230	<M3032>
	LD   SP,M4545    		;4A5F 314545	<M4545>
	JR   NC,L4A94    		;4A62 3030	<L4A94>
	JR   NC,L4A96    		;4A64 3030	<L4A96>
	JR   NC,L4A98    		;4A66 3030	<L4A98>
	JR   NC,L4A9A    		;4A68 3030	<L4A9A>
	JR   NC,L4A9C    		;4A6A 3030	<L4A9C>
	JR   NC,L4A9E    		;4A6C 3030	<L4A9E>
	JR   NC,L4AA0    		;4A6E 3030	<L4AA0>
	JR   NC,L4AA2    		;4A70 3030	<L4AA2>
	JR   NC,L4AA4    		;4A72 3030	<L4AA4>
	JR   NC,L4AA6    		;4A74 3030	<L4AA6>
	JR   NC,L4AA8    		;4A76 3030	<L4AA8>
	JR   NC,L4AAA    		;4A78 3030	<L4AAA>
	JR   NC,L4AAC    		;4A7A 3030	<L4AAC>
	JR   NC,L4AAE    		;4A7C 3030	<L4AAE>
	JR   NC,L4AB0    		;4A7E 3030	<L4AB0>
	JR   NC,L4AB2    		;4A80 3030	<L4AB2>
	JR   NC,L4AB4    		;4A82 3030	<L4AB4>
	JR   NC,L4AB6    		;4A84 3030	<L4AB6>
	JR   NC,L4AB8    		;4A86 3030	<L4AB8>
	JR   NC,L4ABA    		;4A88 3030	<L4ABA>
	JR   NC,L4ABC    		;4A8A 3030	<L4ABC>
	JR   NC,L4ABE    		;4A8C 3030	<L4ABE>
	JR   NC,L4AC0    		;4A8E 3030	<L4AC0>
	JR   NC,L4AC2    		;4A90 3030	<L4AC2>
	JR   NC,L4AC4    		;4A92 3030	<L4AC4>
	JR   NC,L4AC6    		;4A94 3030	<L4AC6>
	JR   NC,L4AC8    		;4A96 3030	<L4AC8>
	JR   NC,L4ACA    		;4A98 3030	<L4ACA>
	JR   NC,L4ACC    		;4A9A 3030	<L4ACC>
	JR   NC,L4ACE    		;4A9C 3030	<L4ACE>
	JR   NC,L4AD0    		;4A9E 3030	<L4AD0>
	JR   NC,L4AD2    		;4AA0 3030	<L4AD2>
	JR   NC,L4AD4    		;4AA2 3030	<L4AD4>
	JR   NC,L4AEB    		;4AA4 3045	<L4AEB>
	LD   (M0A0D),A   		;4AA6 320D0A	<M0A0D>
	LD   A,(M3032)   		;4AA9 3A3230	<M3032>
	LD   SP,M3046    		;4AAC 314630	<M3046>
	JR   NC,L4AE1    		;4AAF 3030	<L4AE1>
	JR   NC,L4AE9    		;4AB1 3036	<L4AE9>
	JR   C,L4AEB     		;4AB3 3836	<L4AEB>
	INC  SP      			;4AB5 33
	LD   (HL),35H  			;4AB6 3635	<35H>
	DEC  (HL)    			;4AB8 35
	INC  (HL)    			;4AB9 34
	LD   (M3445),A   		;4ABA 324534	<M3445>
	DEC  (HL)    			;4ABD 35
	LD   (M3445),A   		;4ABE 324534	<M3445>
	LD   B,E     			;4AC1 43
	JR   NC,L4AF4    		;4AC2 3030	<L4AF4>
	JR   NC,L4AF6    		;4AC4 3030	<L4AF6>
	LD   B,(HL)  			;4AC6 46
	INC  (HL)    			;4AC7 34
	JR   NC,L4B10    		;4AC8 3046	<L4B10>
	JR   NC,L4AFC    		;4ACA 3030	<L4AFC>
	JR   NC,L4AFE    		;4ACC 3030	<L4AFE>
	JR   NC,L4B00    		;4ACE 3030	<L4B00>
	JR   NC,L4B02    		;4AD0 3030	<L4B02>
	JR   NC,L4B04    		;4AD2 3030	<L4B04>
	JR   NC,L4B06    		;4AD4 3030	<L4B06>
	JR   NC,L4B08    		;4AD6 3030	<L4B08>
	JR   NC,L4B0A    		;4AD8 3030	<L4B0A>
	JR   NC,L4B0C    		;4ADA 3030	<L4B0C>
	JR   NC,L4B0E    		;4ADC 3030	<L4B0E>
	JR   NC,L4B10    		;4ADE 3030	<L4B10>
	JR   NC,L4B12    		;4AE0 3030	<L4B12>
	JR   NC,L4B14    		;4AE2 3030	<L4B14>
	JR   NC,L4B16    		;4AE4 3030	<L4B16>
	JR   NC,L4B18    		;4AE6 3030	<L4B18>
	JR   NC,L4B1A    		;4AE8 3030	<L4B1A>
	JR   NC,L4B1C    		;4AEA 3030	<L4B1C>
	JR   NC,L4B1E    		;4AEC 3030	<L4B1E>
	JR   NC,L4B20    		;4AEE 3030	<L4B20>
	JR   NC,L4B22    		;4AF0 3030	<L4B22>
	INC  (HL)    			;4AF2 34
	LD   B,H     			;4AF3 44
	DEC  C       			;4AF4 0D
	LD   A,(BC)  			;4AF5 0A
	LD   A,(M3032)   		;4AF6 3A3230	<M3032>
	LD   SP,M3246    		;4AF9 314632	<M3246>
	JR   NC,L4B2E    		;4AFC 3030	<L4B2E>
	JR   NC,L4B30    		;4AFE 3030	<L4B30>
	JR   NC,L4B32    		;4B00 3030	<L4B32>
	JR   NC,L4B34    		;4B02 3030	<L4B34>
	JR   NC,L4B36    		;4B04 3030	<L4B36>
	JR   NC,L4B38    		;4B06 3030	<L4B38>
	JR   NC,L4B3A    		;4B08 3030	<L4B3A>
	JR   NC,L4B3C    		;4B0A 3030	<L4B3C>
	JR   NC,L4B3E    		;4B0C 3030	<L4B3E>
	JR   NC,L4B40    		;4B0E 3030	<L4B40>
	JR   NC,L4B42    		;4B10 3030	<L4B42>
	JR   NC,L4B44    		;4B12 3030	<L4B44>
	JR   NC,L4B46    		;4B14 3030	<L4B46>
	JR   NC,L4B48    		;4B16 3030	<L4B48>
	JR   NC,L4B4A    		;4B18 3030	<L4B4A>
	JR   NC,L4B4C    		;4B1A 3030	<L4B4C>
	JR   NC,L4B4E    		;4B1C 3030	<L4B4E>
	JR   NC,L4B50    		;4B1E 3030	<L4B50>
	JR   NC,L4B52    		;4B20 3030	<L4B52>
	JR   NC,L4B54    		;4B22 3030	<L4B54>
	JR   NC,L4B56    		;4B24 3030	<L4B56>
	JR   NC,L4B58    		;4B26 3030	<L4B58>
	JR   NC,L4B5A    		;4B28 3030	<L4B5A>
	JR   NC,L4B5C    		;4B2A 3030	<L4B5C>
	JR   NC,L4B5E    		;4B2C 3030	<L4B5E>
	JR   NC,L4B60    		;4B2E 3030	<L4B60>
	JR   NC,L4B62    		;4B30 3030	<L4B62>
	JR   NC,L4B64    		;4B32 3030	<L4B64>
	JR   NC,L4B66    		;4B34 3030	<L4B66>
	JR   NC,L4B68    		;4B36 3030	<L4B68>
	JR   NC,L4B6A    		;4B38 3030	<L4B6A>
	JR   NC,L4B6C    		;4B3A 3030	<L4B6C>
	JR   NC,L4B6E    		;4B3C 3030	<L4B6E>
	JR   NC,L4B81    		;4B3E 3041	<L4B81>
	LD   SP,M0A0D    		;4B40 310D0A	<M0A0D>
	LD   A,(M3032)   		;4B43 3A3230	<M3032>
	LD   SP,M3446    		;4B46 314634	<M3446>
	JR   NC,L4B7B    		;4B49 3030	<L4B7B>
	JR   NC,L4B7D    		;4B4B 3030	<L4B7D>
	JR   NC,L4B7F    		;4B4D 3030	<L4B7F>
	JR   NC,L4B81    		;4B4F 3030	<L4B81>
	JR   NC,L4B83    		;4B51 3030	<L4B83>
	JR   NC,L4B85    		;4B53 3030	<L4B85>
	JR   NC,L4B87    		;4B55 3030	<L4B87>
	JR   NC,L4B89    		;4B57 3030	<L4B89>
	JR   NC,L4B8B    		;4B59 3030	<L4B8B>
	JR   NC,L4B8D    		;4B5B 3030	<L4B8D>
	JR   NC,L4B8F    		;4B5D 3030	<L4B8F>
	JR   NC,L4B91    		;4B5F 3030	<L4B91>
	JR   NC,L4B93    		;4B61 3030	<L4B93>
	JR   NC,L4B95    		;4B63 3030	<L4B95>
	JR   NC,L4B97    		;4B65 3030	<L4B97>
	JR   NC,L4B99    		;4B67 3030	<L4B99>
	JR   NC,L4B9B    		;4B69 3030	<L4B9B>
	JR   NC,L4B9D    		;4B6B 3030	<L4B9D>
	JR   NC,L4B9F    		;4B6D 3030	<L4B9F>
	JR   NC,L4BA1    		;4B6F 3030	<L4BA1>
	JR   NC,L4BA3    		;4B71 3030	<L4BA3>
	JR   NC,L4BA5    		;4B73 3030	<L4BA5>
	JR   NC,L4BA7    		;4B75 3030	<L4BA7>
	JR   NC,L4BA9    		;4B77 3030	<L4BA9>
	JR   NC,L4BAB    		;4B79 3030	<L4BAB>
	JR   NC,L4BAD    		;4B7B 3030	<L4BAD>
	JR   NC,L4BAF    		;4B7D 3030	<L4BAF>
	JR   NC,L4BB1    		;4B7F 3030	<L4BB1>
	JR   NC,L4BB3    		;4B81 3030	<L4BB3>
	JR   NC,L4BB5    		;4B83 3030	<L4BB5>
	JR   NC,L4BB7    		;4B85 3030	<L4BB7>
	JR   NC,L4BB9    		;4B87 3030	<L4BB9>
	JR   NC,L4BBB    		;4B89 3030	<L4BBB>
	JR   NC,L4BC5    		;4B8B 3038	<L4BC5>
	LD   SP,M0A0D    		;4B8D 310D0A	<M0A0D>
	LD   A,(M3032)   		;4B90 3A3230	<M3032>
	LD   SP,M3646    		;4B93 314636	<M3646>
	JR   NC,L4BC8    		;4B96 3030	<L4BC8>
	JR   NC,L4BCA    		;4B98 3030	<L4BCA>
	JR   NC,L4BCC    		;4B9A 3030	<L4BCC>
	JR   NC,L4BCE    		;4B9C 3030	<L4BCE>
	JR   NC,L4BD0    		;4B9E 3030	<L4BD0>
	JR   NC,L4BD2    		;4BA0 3030	<L4BD2>
	JR   NC,L4BD4    		;4BA2 3030	<L4BD4>
	JR   NC,L4BD6    		;4BA4 3030	<L4BD6>
	JR   NC,L4BD8    		;4BA6 3030	<L4BD8>
	JR   NC,L4BDA    		;4BA8 3030	<L4BDA>
	JR   NC,L4BDC    		;4BAA 3030	<L4BDC>
	JR   NC,L4BDE    		;4BAC 3030	<L4BDE>
	JR   NC,L4BE0    		;4BAE 3030	<L4BE0>
	JR   NC,L4BE2    		;4BB0 3030	<L4BE2>
	JR   NC,L4BE4    		;4BB2 3030	<L4BE4>
	JR   NC,L4BE6    		;4BB4 3030	<L4BE6>
	JR   NC,L4BE8    		;4BB6 3030	<L4BE8>
	JR   NC,L4BEA    		;4BB8 3030	<L4BEA>
	JR   NC,L4BEC    		;4BBA 3030	<L4BEC>
	JR   NC,L4BEE    		;4BBC 3030	<L4BEE>
	JR   NC,L4BF0    		;4BBE 3030	<L4BF0>
	JR   NC,L4BF2    		;4BC0 3030	<L4BF2>
	JR   NC,L4BF4    		;4BC2 3030	<L4BF4>
	JR   NC,L4BF6    		;4BC4 3030	<L4BF6>
	JR   NC,L4BF8    		;4BC6 3030	<L4BF8>
	JR   NC,L4BFA    		;4BC8 3030	<L4BFA>
	JR   NC,L4BFC    		;4BCA 3030	<L4BFC>
	JR   NC,L4BFE    		;4BCC 3030	<L4BFE>
	JR   NC,L4C00    		;4BCE 3030	<L4C00>
	JR   NC,L4C02    		;4BD0 3030	<L4C02>
	JR   NC,L4C04    		;4BD2 3030	<L4C04>
	JR   NC,L4C06    		;4BD4 3030	<L4C06>
	JR   NC,L4C08    		;4BD6 3030	<L4C08>
	JR   NC,L4C10    		;4BD8 3036	<L4C10>
	LD   SP,M0A0D    		;4BDA 310D0A	<M0A0D>
	LD   A,(M3032)   		;4BDD 3A3230	<M3032>
	LD   SP,M3846    		;4BE0 314638	<M3846>
	JR   NC,L4C15    		;4BE3 3030	<L4C15>
	JR   NC,L4C17    		;4BE5 3030	<L4C17>
	JR   NC,L4C19    		;4BE7 3030	<L4C19>
	JR   NC,L4C1B    		;4BE9 3030	<L4C1B>
	JR   NC,L4C1D    		;4BEB 3030	<L4C1D>
	JR   NC,L4C1F    		;4BED 3030	<L4C1F>
	JR   NC,L4C21    		;4BEF 3030	<L4C21>
	JR   NC,L4C23    		;4BF1 3030	<L4C23>
	JR   NC,L4C25    		;4BF3 3030	<L4C25>
	JR   NC,L4C27    		;4BF5 3030	<L4C27>
	JR   NC,L4C29    		;4BF7 3030	<L4C29>
	JR   NC,L4C2B    		;4BF9 3030	<L4C2B>
	JR   NC,L4C2D    		;4BFB 3030	<L4C2D>
	JR   NC,L4C2F    		;4BFD 3030	<L4C2F>
	JR   NC,L4C31    		;4BFF 3030	<L4C31>
	JR   NC,L4C33    		;4C01 3030	<L4C33>
	JR   NC,L4C35    		;4C03 3030	<L4C35>
	JR   NC,L4C37    		;4C05 3030	<L4C37>
	JR   NC,L4C39    		;4C07 3030	<L4C39>
	JR   NC,L4C3B    		;4C09 3030	<L4C3B>
	JR   NC,L4C3D    		;4C0B 3030	<L4C3D>
	JR   NC,L4C3F    		;4C0D 3030	<L4C3F>
	JR   NC,L4C41    		;4C0F 3030	<L4C41>
	JR   NC,L4C43    		;4C11 3030	<L4C43>
	JR   NC,L4C45    		;4C13 3030	<L4C45>
	JR   NC,L4C47    		;4C15 3030	<L4C47>
	JR   NC,L4C49    		;4C17 3030	<L4C49>
	JR   NC,L4C4B    		;4C19 3030	<L4C4B>
	JR   NC,L4C4D    		;4C1B 3030	<L4C4D>
	JR   NC,L4C4F    		;4C1D 3030	<L4C4F>
	JR   NC,L4C51    		;4C1F 3030	<L4C51>
	JR   NC,L4C53    		;4C21 3030	<L4C53>
	JR   NC,L4C55    		;4C23 3030	<L4C55>
	JR   NC,L4C5B    		;4C25 3034	<L4C5B>
	LD   SP,M0A0D    		;4C27 310D0A	<M0A0D>
	LD   A,(M3032)   		;4C2A 3A3230	<M3032>
	LD   SP,M4146    		;4C2D 314641	<M4146>
	JR   NC,L4C62    		;4C30 3030	<L4C62>
	JR   NC,L4C64    		;4C32 3030	<L4C64>
	JR   NC,L4C66    		;4C34 3030	<L4C66>
	JR   NC,L4C68    		;4C36 3030	<L4C68>
	JR   NC,L4C6A    		;4C38 3030	<L4C6A>
	JR   NC,L4C6C    		;4C3A 3030	<L4C6C>
	JR   NC,L4C6E    		;4C3C 3030	<L4C6E>
	JR   NC,L4C70    		;4C3E 3030	<L4C70>
	JR   NC,L4C72    		;4C40 3030	<L4C72>
	JR   NC,L4C74    		;4C42 3030	<L4C74>
	JR   NC,L4C76    		;4C44 3030	<L4C76>
	JR   NC,L4C78    		;4C46 3030	<L4C78>
	JR   NC,L4C7A    		;4C48 3030	<L4C7A>
	JR   NC,L4C7C    		;4C4A 3030	<L4C7C>
	JR   NC,L4C7E    		;4C4C 3030	<L4C7E>
	JR   NC,L4C80    		;4C4E 3030	<L4C80>
	JR   NC,L4C82    		;4C50 3030	<L4C82>
	JR   NC,L4C84    		;4C52 3030	<L4C84>
	JR   NC,L4C86    		;4C54 3030	<L4C86>
	JR   NC,L4C88    		;4C56 3030	<L4C88>
	JR   NC,L4C8A    		;4C58 3030	<L4C8A>
	JR   NC,L4C8C    		;4C5A 3030	<L4C8C>
	JR   NC,L4C8E    		;4C5C 3030	<L4C8E>
	JR   NC,L4C90    		;4C5E 3030	<L4C90>
	JR   NC,L4C92    		;4C60 3030	<L4C92>
	JR   NC,L4C94    		;4C62 3030	<L4C94>
	JR   NC,L4C96    		;4C64 3030	<L4C96>
	JR   NC,L4C98    		;4C66 3030	<L4C98>
	JR   NC,L4C9A    		;4C68 3030	<L4C9A>
	JR   NC,L4C9C    		;4C6A 3030	<L4C9C>
	JR   NC,L4C9E    		;4C6C 3030	<L4C9E>
	JR   NC,L4CA0    		;4C6E 3030	<L4CA0>
	JR   NC,L4CA2    		;4C70 3030	<L4CA2>
	JR   NC,L4CA6    		;4C72 3032	<L4CA6>
	LD   SP,M0A0D    		;4C74 310D0A	<M0A0D>
	LD   A,(M3032)   		;4C77 3A3230	<M3032>
	LD   SP,M4346    		;4C7A 314643	<M4346>
	JR   NC,L4CAF    		;4C7D 3030	<L4CAF>
	JR   NC,L4CB1    		;4C7F 3030	<L4CB1>
	JR   NC,L4CB3    		;4C81 3030	<L4CB3>
	JR   NC,L4CB5    		;4C83 3030	<L4CB5>
	JR   NC,L4CB7    		;4C85 3030	<L4CB7>
	JR   NC,L4CB9    		;4C87 3030	<L4CB9>
	JR   NC,L4CBB    		;4C89 3030	<L4CBB>
	JR   NC,L4CBD    		;4C8B 3030	<L4CBD>
	JR   NC,L4CBF    		;4C8D 3030	<L4CBF>
	JR   NC,L4CC1    		;4C8F 3030	<L4CC1>
	JR   NC,L4CC3    		;4C91 3030	<L4CC3>
	JR   NC,L4CC5    		;4C93 3030	<L4CC5>
	JR   NC,L4CC7    		;4C95 3030	<L4CC7>
	JR   NC,L4CC9    		;4C97 3030	<L4CC9>
	JR   NC,L4CCB    		;4C99 3030	<L4CCB>
	JR   NC,L4CCD    		;4C9B 3030	<L4CCD>
	JR   NC,L4CCF    		;4C9D 3030	<L4CCF>
	JR   NC,L4CD1    		;4C9F 3030	<L4CD1>
	JR   NC,L4CD3    		;4CA1 3030	<L4CD3>
	JR   NC,L4CD5    		;4CA3 3030	<L4CD5>
	JR   NC,L4CD7    		;4CA5 3030	<L4CD7>
	JR   NC,L4CD9    		;4CA7 3030	<L4CD9>
	JR   NC,L4CDB    		;4CA9 3030	<L4CDB>
	JR   NC,L4CDD    		;4CAB 3030	<L4CDD>
	JR   NC,L4CDF    		;4CAD 3030	<L4CDF>
	JR   NC,L4CE1    		;4CAF 3030	<L4CE1>
	JR   NC,L4CE3    		;4CB1 3030	<L4CE3>
	JR   NC,L4CE5    		;4CB3 3030	<L4CE5>
	JR   NC,L4CE7    		;4CB5 3030	<L4CE7>
	JR   NC,L4CE9    		;4CB7 3030	<L4CE9>
	JR   NC,L4CEB    		;4CB9 3030	<L4CEB>
	JR   NC,L4CED    		;4CBB 3030	<L4CED>
	JR   NC,L4CEF    		;4CBD 3030	<L4CEF>
	JR   NC,L4CF1    		;4CBF 3030	<L4CF1>
	LD   SP,M0A0D    		;4CC1 310D0A	<M0A0D>
	LD   A,(M3032)   		;4CC4 3A3230	<M3032>
	LD   SP,M4546    		;4CC7 314645	<M4546>
	JR   NC,L4CFC    		;4CCA 3030	<L4CFC>
	JR   NC,L4CFE    		;4CCC 3030	<L4CFE>
	JR   NC,L4D00    		;4CCE 3030	<L4D00>
	JR   NC,L4D02    		;4CD0 3030	<L4D02>
	JR   NC,L4D04    		;4CD2 3030	<L4D04>
	JR   NC,L4D06    		;4CD4 3030	<L4D06>
	JR   NC,L4D08    		;4CD6 3030	<L4D08>
	JR   NC,L4D0A    		;4CD8 3030	<L4D0A>
	JR   NC,L4D0C    		;4CDA 3030	<L4D0C>
	JR   NC,L4D0E    		;4CDC 3030	<L4D0E>
	JR   NC,L4D10    		;4CDE 3030	<L4D10>
	JR   NC,L4D12    		;4CE0 3030	<L4D12>
	JR   NC,L4D14    		;4CE2 3030	<L4D14>
	JR   NC,L4D16    		;4CE4 3030	<L4D16>
	JR   NC,L4D18    		;4CE6 3030	<L4D18>
	JR   NC,L4D1A    		;4CE8 3030	<L4D1A>
	JR   NC,L4D1C    		;4CEA 3030	<L4D1C>
	JR   NC,L4D1E    		;4CEC 3030	<L4D1E>
	JR   NC,L4D20    		;4CEE 3030	<L4D20>
	JR   NC,L4D22    		;4CF0 3030	<L4D22>
	JR   NC,L4D24    		;4CF2 3030	<L4D24>
	JR   NC,L4D26    		;4CF4 3030	<L4D26>
	JR   NC,L4D28    		;4CF6 3030	<L4D28>
	JR   NC,L4D2A    		;4CF8 3030	<L4D2A>
	JR   NC,L4D2C    		;4CFA 3030	<L4D2C>
	JR   NC,L4D2E    		;4CFC 3030	<L4D2E>
	JR   NC,L4D30    		;4CFE 3030	<L4D30>
	JR   NC,L4D32    		;4D00 3030	<L4D32>
	JR   NC,L4D34    		;4D02 3030	<L4D34>
	JR   NC,L4D36    		;4D04 3030	<L4D36>
	JR   NC,L4D38    		;4D06 3030	<L4D38>
	JR   NC,L4D3A    		;4D08 3030	<L4D3A>
	JR   NC,L4D3C    		;4D0A 3030	<L4D3C>
	JR   NC,L4D53    		;4D0C 3045	<L4D53>
	LD   SP,M0A0D    		;4D0E 310D0A	<M0A0D>
	LD   A,(M3030)   		;4D11 3A3030	<M3030>
	JR   NC,L4D46    		;4D14 3030	<L4D46>
	JR   NC,L4D48    		;4D16 3030	<L4D48>
	JR   NC,L4D4B    		;4D18 3031	<L4D4B>
	LD   B,(HL)  			;4D1A 46
	LD   B,(HL)  			;4D1B 46
	DEC  C       			;4D1C 0D
	LD   A,(BC)  			;4D1D 0A

;----------------------------------------------------------------------
L0035	EQU  0035H			;
L0037	EQU  0037H			;
L003D	EQU  003DH			;
L006A	EQU  006AH			;
L007A	EQU  007AH			;
L0093	EQU  0093H			;
L00AD	EQU  00ADH			;
L00AF	EQU  00AFH			;
L0102	EQU  0102H			;
L013B	EQU  013BH			;
L013D	EQU  013DH			;
L0169	EQU  0169H			;
L017A	EQU  017AH			;
L0193	EQU  0193H			;
L0196	EQU  0196H			;
L01B4	EQU  01B4H			;
L01BE	EQU  01BEH			;
L01C7	EQU  01C7H			;
L01CE	EQU  01CEH			;
L01D2	EQU  01D2H			;
L01E8	EQU  01E8H			;
L01ED	EQU  01EDH			;
L020C	EQU  020CH			;
L021F	EQU  021FH			;
L0225	EQU  0225H			;
L0230	EQU  0230H			;
L0233	EQU  0233H			;
L0235	EQU  0235H			;
L024E	EQU  024EH			;
L0253	EQU  0253H			;
L025C	EQU  025CH			;
L025E	EQU  025EH			;
L027B	EQU  027BH			;
L028F	EQU  028FH			;
L02AF	EQU  02AFH			;
L02B0	EQU  02B0H			;
L02E1	EQU  02E1H			;
L030E	EQU  030EH			;
L031C	EQU  031CH			;
L0332	EQU  0332H			;
L0399	EQU  0399H			;
L03C7	EQU  03C7H			;
L03D1	EQU  03D1H			;
L03DA	EQU  03DAH			;
L03E4	EQU  03E4H			;
L03FC	EQU  03FCH			;
L0403	EQU  0403H			;
L0416	EQU  0416H			;
L0426	EQU  0426H			;
L0432	EQU  0432H			;
L0434	EQU  0434H			;
L047D	EQU  047DH			;
L047E	EQU  047EH			;
L0491	EQU  0491H			;
L04CC	EQU  04CCH			;
L04EF	EQU  04EFH			;
L0518	EQU  0518H			;
L051A	EQU  051AH			;
L0543	EQU  0543H			;
L055B	EQU  055BH			;
L056F	EQU  056FH			;
L05B2	EQU  05B2H			;
L05F3	EQU  05F3H			;
L05FF	EQU  05FFH			;
L060D	EQU  060DH			;
L062A	EQU  062AH			;
L0640	EQU  0640H			;
L0648	EQU  0648H			;
L064E	EQU  064EH			;
L0651	EQU  0651H			;
L0672	EQU  0672H			;
L06B1	EQU  06B1H			;
L06D0	EQU  06D0H			;
L06D3	EQU  06D3H			;
L06E7	EQU  06E7H			;
L071A	EQU  071AH			;
L0733	EQU  0733H			;
L0734	EQU  0734H			;
L0744	EQU  0744H			;
L074A	EQU  074AH			;
L074B	EQU  074BH			;
L0775	EQU  0775H			;
L0776	EQU  0776H			;
L0780	EQU  0780H			;
L079F	EQU  079FH			;
L07A8	EQU  07A8H			;
L07D4	EQU  07D4H			;
L07D9	EQU  07D9H			;
L07E4	EQU  07E4H			;
L080A	EQU  080AH			;
L0834	EQU  0834H			;
L0844	EQU  0844H			;
L0856	EQU  0856H			;
L0868	EQU  0868H			;
L0879	EQU  0879H			;
L087F	EQU  087FH			;
L0887	EQU  0887H			;
L089B	EQU  089BH			;
L08B4	EQU  08B4H			;
L08E4	EQU  08E4H			;
L08EA	EQU  08EAH			;
L0908	EQU  0908H			;
L0919	EQU  0919H			;
L0924	EQU  0924H			;
L094A	EQU  094AH			;
L0954	EQU  0954H			;
L095B	EQU  095BH			;
L0968	EQU  0968H			;
L0973	EQU  0973H			;
L098A	EQU  098AH			;
L0994	EQU  0994H			;
L099A	EQU  099AH			;
L099E	EQU  099EH			;
L09B7	EQU  09B7H			;
L09BE	EQU  09BEH			;
L09C0	EQU  09C0H			;
L09CC	EQU  09CCH			;
L09E8	EQU  09E8H			;
L09F1	EQU  09F1H			;
L0A0E	EQU  0A0EH			;
L0A64	EQU  0A64H			;
L0A6C	EQU  0A6CH			;
L0A84	EQU  0A84H			;
L0A91	EQU  0A91H			;
L0A9E	EQU  0A9EH			;
L0AA6	EQU  0AA6H			;
L0AB1	EQU  0AB1H			;
L0AB2	EQU  0AB2H			;
L0AC2	EQU  0AC2H			;
L0ADB	EQU  0ADBH			;
L0ADD	EQU  0ADDH			;
L0B11	EQU  0B11H			;
L0B1E	EQU  0B1EH			;
L0B25	EQU  0B25H			;
L0B2F	EQU  0B2FH			;
L0B40	EQU  0B40H			;
L0B49	EQU  0B49H			;
L0B4B	EQU  0B4BH			;
L0B56	EQU  0B56H			;
L0B6B	EQU  0B6BH			;
L0B6F	EQU  0B6FH			;
L0B71	EQU  0B71H			;
L0B75	EQU  0B75H			;
L0B95	EQU  0B95H			;
L0BB8	EQU  0BB8H			;
L0BCE	EQU  0BCEH			;
L0BD0	EQU  0BD0H			;
L0BEC	EQU  0BECH			;
L0BF4	EQU  0BF4H			;
L0BFC	EQU  0BFCH			;
L0C04	EQU  0C04H			;
L0C0F	EQU  0C0FH			;
L0C21	EQU  0C21H			;
L0C52	EQU  0C52H			;
L0C77	EQU  0C77H			;
L0C8E	EQU  0C8EH			;
L0C90	EQU  0C90H			;
L0CAC	EQU  0CACH			;
L0CCE	EQU  0CCEH			;
L0CE6	EQU  0CE6H			;
L0CED	EQU  0CEDH			;
L0CFD	EQU  0CFDH			;
L0D08	EQU  0D08H			;
L0D1A	EQU  0D1AH			;
L0D1E	EQU  0D1EH			;
L0D1F	EQU  0D1FH			;
L0D23	EQU  0D23H			;
L0D29	EQU  0D29H			;
L0D3C	EQU  0D3CH			;
L0D3D	EQU  0D3DH			;
L0D40	EQU  0D40H			;
L0D4E	EQU  0D4EH			;
L0D53	EQU  0D53H			;
L0D55	EQU  0D55H			;
L0D5A	EQU  0D5AH			;
L0D5D	EQU  0D5DH			;
L0D71	EQU  0D71H			;
L0DA1	EQU  0DA1H			;
L0DA9	EQU  0DA9H			;
L0DB0	EQU  0DB0H			;
L0E11	EQU  0E11H			;
L0E26	EQU  0E26H			;
L0E52	EQU  0E52H			;
L0E5A	EQU  0E5AH			;
L0E6C	EQU  0E6CH			;
L0E6E	EQU  0E6EH			;
L0E76	EQU  0E76H			;
L0E83	EQU  0E83H			;
L0E8B	EQU  0E8BH			;
L0EA2	EQU  0EA2H			;
L0EBC	EQU  0EBCH			;
L0EC8	EQU  0EC8H			;
L0EEF	EQU  0EEFH			;
L0F09	EQU  0F09H			;
L0F0E	EQU  0F0EH			;
L0F53	EQU  0F53H			;
L0F56	EQU  0F56H			;
L0F5B	EQU  0F5BH			;
L0F6A	EQU  0F6AH			;
L0F8A	EQU  0F8AH			;
L0FA1	EQU  0FA1H			;
L0FA3	EQU  0FA3H			;
L0FC0	EQU  0FC0H			;
L0FCC	EQU  0FCCH			;
L0FDB	EQU  0FDBH			;
L1009	EQU  1009H			;
L103D	EQU  103DH			;
L1048	EQU  1048H			;
L1051	EQU  1051H			;
L106C	EQU  106CH			;
L106E	EQU  106EH			;
L108C	EQU  108CH			;
L1091	EQU  1091H			;
L10AA	EQU  10AAH			;
L10AB	EQU  10ABH			;
L10C6	EQU  10C6H			;
L10CA	EQU  10CAH			;
L10D8	EQU  10D8H			;
L10DB	EQU  10DBH			;
L10EA	EQU  10EAH			;
L10F3	EQU  10F3H			;
L1122	EQU  1122H			;
L119B	EQU  119BH			;
L119F	EQU  119FH			;
L11F3	EQU  11F3H			;
L11FA	EQU  11FAH			;
L1209	EQU  1209H			;
L120C	EQU  120CH			;
L1216	EQU  1216H			;
L1240	EQU  1240H			;
L1254	EQU  1254H			;
L1258	EQU  1258H			;
L1264	EQU  1264H			;
L1276	EQU  1276H			;
L12A6	EQU  12A6H			;
L12B9	EQU  12B9H			;
L12C4	EQU  12C4H			;
L12D6	EQU  12D6H			;
L12F3	EQU  12F3H			;
L12FF	EQU  12FFH			;
L1305	EQU  1305H			;
L130F	EQU  130FH			;
L1310	EQU  1310H			;
L1324	EQU  1324H			;
L132B	EQU  132BH			;
L132E	EQU  132EH			;
L1361	EQU  1361H			;
L137D	EQU  137DH			;
L1391	EQU  1391H			;
L1394	EQU  1394H			;
L1396	EQU  1396H			;
L13C0	EQU  13C0H			;
L13C7	EQU  13C7H			;
L13E4	EQU  13E4H			;
L1413	EQU  1413H			;
L1423	EQU  1423H			;
L1427	EQU  1427H			;
L1428	EQU  1428H			;
L1434	EQU  1434H			;
L1444	EQU  1444H			;
L1449	EQU  1449H			;
L1471	EQU  1471H			;
L148B	EQU  148BH			;
L1492	EQU  1492H			;
L14B4	EQU  14B4H			;
L14C4	EQU  14C4H			;
L14DB	EQU  14DBH			;
L14F3	EQU  14F3H			;
L14FD	EQU  14FDH			;
L150A	EQU  150AH			;
L153F	EQU  153FH			;
L1540	EQU  1540H			;
L1546	EQU  1546H			;
L1557	EQU  1557H			;
L155F	EQU  155FH			;
L1573	EQU  1573H			;
L157A	EQU  157AH			;
L157E	EQU  157EH			;
L1592	EQU  1592H			;
L159E	EQU  159EH			;
L15B4	EQU  15B4H			;
L15BD	EQU  15BDH			;
L15F2	EQU  15F2H			;
L1601	EQU  1601H			;
L162E	EQU  162EH			;
L1638	EQU  1638H			;
L163A	EQU  163AH			;
L1643	EQU  1643H			;
L1654	EQU  1654H			;
L1657	EQU  1657H			;
L168B	EQU  168BH			;
L16A6	EQU  16A6H			;
L16B3	EQU  16B3H			;
L16C2	EQU  16C2H			;
L16D9	EQU  16D9H			;
L16E2	EQU  16E2H			;
L16F9	EQU  16F9H			;
L170E	EQU  170EH			;
L1715	EQU  1715H			;
L172B	EQU  172BH			;
L173B	EQU  173BH			;
L1746	EQU  1746H			;
L175B	EQU  175BH			;
L175D	EQU  175DH			;
L1774	EQU  1774H			;
L177F	EQU  177FH			;
L1792	EQU  1792H			;
L180C	EQU  180CH			;
L1814	EQU  1814H			;
L1827	EQU  1827H			;
L1849	EQU  1849H			;
L1858	EQU  1858H			;
L1863	EQU  1863H			;
L1874	EQU  1874H			;
L1884	EQU  1884H			;
L1892	EQU  1892H			;
L18BC	EQU  18BCH			;
L18F3	EQU  18F3H			;
L18F5	EQU  18F5H			;
L1901	EQU  1901H			;
L1909	EQU  1909H			;
L1912	EQU  1912H			;
L192A	EQU  192AH			;
L193A	EQU  193AH			;
L1941	EQU  1941H			;
L1970	EQU  1970H			;
L198C	EQU  198CH			;
L198E	EQU  198EH			;
L19B4	EQU  19B4H			;
L19B6	EQU  19B6H			;
L19DA	EQU  19DAH			;
L19DD	EQU  19DDH			;
L19E8	EQU  19E8H			;
L19F1	EQU  19F1H			;
L1A19	EQU  1A19H			;
L1A1D	EQU  1A1DH			;
L1A27	EQU  1A27H			;
L1A4F	EQU  1A4FH			;
L1A63	EQU  1A63H			;
L1A74	EQU  1A74H			;
L1A76	EQU  1A76H			;
L1A82	EQU  1A82H			;
L1A8F	EQU  1A8FH			;
L1AA7	EQU  1AA7H			;
L1AB2	EQU  1AB2H			;
L1B00	EQU  1B00H			;
L1B02	EQU  1B02H			;
L1B0F	EQU  1B0FH			;
L1B25	EQU  1B25H			;
L1B27	EQU  1B27H			;
L1B50	EQU  1B50H			;
L1B5E	EQU  1B5EH			;
L1B5F	EQU  1B5FH			;
L1B61	EQU  1B61H			;
L1B6B	EQU  1B6BH			;
L1B6E	EQU  1B6EH			;
L1B78	EQU  1B78H			;
L1BA9	EQU  1BA9H			;
L1BC9	EQU  1BC9H			;
L1BD2	EQU  1BD2H			;
L1BD9	EQU  1BD9H			;
L1BF4	EQU  1BF4H			;
L1BF6	EQU  1BF6H			;
L1BF9	EQU  1BF9H			;
L1BFC	EQU  1BFCH			;
L1BFF	EQU  1BFFH			;
L1C1D	EQU  1C1DH			;
L1C4C	EQU  1C4CH			;
L1C52	EQU  1C52H			;
L1C7D	EQU  1C7DH			;
L1C8F	EQU  1C8FH			;
L1C9E	EQU  1C9EH			;
L1CA5	EQU  1CA5H			;
L1CC7	EQU  1CC7H			;
L1CCD	EQU  1CCDH			;
L1CE1	EQU  1CE1H			;
L1CEC	EQU  1CECH			;
L1CEE	EQU  1CEEH			;
L1CF3	EQU  1CF3H			;
L1D17	EQU  1D17H			;
L1D28	EQU  1D28H			;
L1D3F	EQU  1D3FH			;
L1D6A	EQU  1D6AH			;
L1DAC	EQU  1DACH			;
L1DB3	EQU  1DB3H			;
L1DBE	EQU  1DBEH			;
L1DC3	EQU  1DC3H			;
L1DC9	EQU  1DC9H			;
L1DD9	EQU  1DD9H			;
L1DDE	EQU  1DDEH			;
L1DF8	EQU  1DF8H			;
L1E11	EQU  1E11H			;
L1E18	EQU  1E18H			;
L1E20	EQU  1E20H			;
L1E46	EQU  1E46H			;
L1E47	EQU  1E47H			;
L1E4E	EQU  1E4EH			;
L1E52	EQU  1E52H			;
L1E5C	EQU  1E5CH			;
L1E5E	EQU  1E5EH			;
L1E6E	EQU  1E6EH			;
L1EB8	EQU  1EB8H			;
L1EBA	EQU  1EBAH			;
L1EC1	EQU  1EC1H			;
L1EC6	EQU  1EC6H			;
L1EF1	EQU  1EF1H			;
L1F0E	EQU  1F0EH			;
L1F1E	EQU  1F1EH			;
L1F2D	EQU  1F2DH			;
L1F46	EQU  1F46H			;
L1F75	EQU  1F75H			;
L1F7F	EQU  1F7FH			;
L1F86	EQU  1F86H			;
L1FA0	EQU  1FA0H			;
L1FAF	EQU  1FAFH			;
L1FCA	EQU  1FCAH			;
L1FCF	EQU  1FCFH			;
L1FDF	EQU  1FDFH			;
L1FEF	EQU  1FEFH			;
L2002	EQU  2002H			;
L2007	EQU  2007H			;
L2020	EQU  2020H			;
L202D	EQU  202DH			;
L203C	EQU  203CH			;
L204E	EQU  204EH			;
L2066	EQU  2066H			;
L206F	EQU  206FH			;
L208F	EQU  208FH			;
L20A7	EQU  20A7H			;
L20A9	EQU  20A9H			;
L20AB	EQU  20ABH			;
L20B5	EQU  20B5H			;
L20C4	EQU  20C4H			;
L20C6	EQU  20C6H			;
L20DC	EQU  20DCH			;
L20DE	EQU  20DEH			;
L20E3	EQU  20E3H			;
L2112	EQU  2112H			;
L211C	EQU  211CH			;
L2123	EQU  2123H			;
L2124	EQU  2124H			;
L213E	EQU  213EH			;
L2146	EQU  2146H			;
L218A	EQU  218AH			;
L21DC	EQU  21DCH			;
L2201	EQU  2201H			;
L2215	EQU  2215H			;
L221A	EQU  221AH			;
L2236	EQU  2236H			;
L2238	EQU  2238H			;
L223A	EQU  223AH			;
L2248	EQU  2248H			;
L2252	EQU  2252H			;
L225C	EQU  225CH			;
L227F	EQU  227FH			;
L2281	EQU  2281H			;
L22AC	EQU  22ACH			;
L22C7	EQU  22C7H			;
L22E1	EQU  22E1H			;
L22EF	EQU  22EFH			;
L22F2	EQU  22F2H			;
L22F9	EQU  22F9H			;
L2319	EQU  2319H			;
L2321	EQU  2321H			;
L2322	EQU  2322H			;
L232E	EQU  232EH			;
L2340	EQU  2340H			;
L2341	EQU  2341H			;
L236C	EQU  236CH			;
L237A	EQU  237AH			;
L2389	EQU  2389H			;
L23CC	EQU  23CCH			;
L240E	EQU  240EH			;
L2414	EQU  2414H			;
L2417	EQU  2417H			;
L2441	EQU  2441H			;
L2447	EQU  2447H			;
L2454	EQU  2454H			;
L2460	EQU  2460H			;
L2462	EQU  2462H			;
L247C	EQU  247CH			;
L249D	EQU  249DH			;
L249E	EQU  249EH			;
L24C1	EQU  24C1H			;
L24E7	EQU  24E7H			;
L24F3	EQU  24F3H			;
L24FB	EQU  24FBH			;
L250E	EQU  250EH			;
L2516	EQU  2516H			;
L2518	EQU  2518H			;
L251C	EQU  251CH			;
L2528	EQU  2528H			;
L2576	EQU  2576H			;
L2583	EQU  2583H			;
L258A	EQU  258AH			;
L25A0	EQU  25A0H			;
L25A8	EQU  25A8H			;
L25BE	EQU  25BEH			;
L25C6	EQU  25C6H			;
L25CE	EQU  25CEH			;
L25D2	EQU  25D2H			;
L25D5	EQU  25D5H			;
L25F3	EQU  25F3H			;
L2606	EQU  2606H			;
L2637	EQU  2637H			;
L263A	EQU  263AH			;
L2652	EQU  2652H			;
L265B	EQU  265BH			;
L2664	EQU  2664H			;
L267C	EQU  267CH			;
L267E	EQU  267EH			;
L269A	EQU  269AH			;
L26A9	EQU  26A9H			;
L26AB	EQU  26ABH			;
L26AD	EQU  26ADH			;
L26AF	EQU  26AFH			;
L26B1	EQU  26B1H			;
L26B3	EQU  26B3H			;
L26BD	EQU  26BDH			;
L26C9	EQU  26C9H			;
L26CC	EQU  26CCH			;
L26CE	EQU  26CEH			;
L26DF	EQU  26DFH			;
L26E2	EQU  26E2H			;
L26EE	EQU  26EEH			;
L26F9	EQU  26F9H			;
L2709	EQU  2709H			;
L270E	EQU  270EH			;
L2716	EQU  2716H			;
L2747	EQU  2747H			;
L274B	EQU  274BH			;
L2751	EQU  2751H			;
L2763	EQU  2763H			;
L2765	EQU  2765H			;
L276B	EQU  276BH			;
L276D	EQU  276DH			;
L2773	EQU  2773H			;
L277A	EQU  277AH			;
L277F	EQU  277FH			;
L2786	EQU  2786H			;
L278E	EQU  278EH			;
L2790	EQU  2790H			;
L2791	EQU  2791H			;
L2794	EQU  2794H			;
L27B0	EQU  27B0H			;
L27B2	EQU  27B2H			;
L27B4	EQU  27B4H			;
L27E1	EQU  27E1H			;
L27E7	EQU  27E7H			;
L27EF	EQU  27EFH			;
L27F1	EQU  27F1H			;
L27F3	EQU  27F3H			;
L27F9	EQU  27F9H			;
L27FD	EQU  27FDH			;
L27FF	EQU  27FFH			;
L281B	EQU  281BH			;
L281E	EQU  281EH			;
L2826	EQU  2826H			;
L282D	EQU  282DH			;
L283F	EQU  283FH			;
L284A	EQU  284AH			;
L284C	EQU  284CH			;
L2856	EQU  2856H			;
L2864	EQU  2864H			;
L2866	EQU  2866H			;
L287A	EQU  287AH			;
L2897	EQU  2897H			;
L2899	EQU  2899H			;
L289F	EQU  289FH			;
L28A5	EQU  28A5H			;
L28AD	EQU  28ADH			;
L28B8	EQU  28B8H			;
L28BA	EQU  28BAH			;
L28BE	EQU  28BEH			;
L28C0	EQU  28C0H			;
L28C4	EQU  28C4H			;
L28C6	EQU  28C6H			;
L28C8	EQU  28C8H			;
L28CA	EQU  28CAH			;
L28CC	EQU  28CCH			;
L28D0	EQU  28D0H			;
L28D2	EQU  28D2H			;
L28D6	EQU  28D6H			;
L28D8	EQU  28D8H			;
L28E4	EQU  28E4H			;
L28E6	EQU  28E6H			;
L28F7	EQU  28F7H			;
L28FB	EQU  28FBH			;
L28FD	EQU  28FDH			;
L2913	EQU  2913H			;
L2915	EQU  2915H			;
L2919	EQU  2919H			;
L291B	EQU  291BH			;
L291D	EQU  291DH			;
L2921	EQU  2921H			;
L2923	EQU  2923H			;
L2925	EQU  2925H			;
L2931	EQU  2931H			;
L2933	EQU  2933H			;
L2935	EQU  2935H			;
L2937	EQU  2937H			;
L2939	EQU  2939H			;
L293D	EQU  293DH			;
L2948	EQU  2948H			;
L2952	EQU  2952H			;
L2954	EQU  2954H			;
L2958	EQU  2958H			;
L295E	EQU  295EH			;
L2960	EQU  2960H			;
L2962	EQU  2962H			;
L2966	EQU  2966H			;
L2967	EQU  2967H			;
L296B	EQU  296BH			;
L2980	EQU  2980H			;
L298C	EQU  298CH			;
L29B9	EQU  29B9H			;
L29BB	EQU  29BBH			;
L29BD	EQU  29BDH			;
L29BF	EQU  29BFH			;
L29C5	EQU  29C5H			;
L29C9	EQU  29C9H			;
L29CD	EQU  29CDH			;
L29CF	EQU  29CFH			;
L29D2	EQU  29D2H			;
L29EE	EQU  29EEH			;
L29F2	EQU  29F2H			;
L29F6	EQU  29F6H			;
L2A06	EQU  2A06H			;
L2A12	EQU  2A12H			;
L2A16	EQU  2A16H			;
L2A1A	EQU  2A1AH			;
L2A1C	EQU  2A1CH			;
L2A1F	EQU  2A1FH			;
L2A3B	EQU  2A3BH			;
L2A3F	EQU  2A3FH			;
L2A43	EQU  2A43H			;
L2A53	EQU  2A53H			;
L2A5F	EQU  2A5FH			;
L2A63	EQU  2A63H			;
L2A67	EQU  2A67H			;
L2A69	EQU  2A69H			;
L2A6C	EQU  2A6CH			;
L2A88	EQU  2A88H			;
L2A8C	EQU  2A8CH			;
L2A90	EQU  2A90H			;
L2A94	EQU  2A94H			;
L2AA0	EQU  2AA0H			;
L2AAC	EQU  2AACH			;
L2AB0	EQU  2AB0H			;
L2AB4	EQU  2AB4H			;
L2AB6	EQU  2AB6H			;
L2AB9	EQU  2AB9H			;
L2AD5	EQU  2AD5H			;
L2AD9	EQU  2AD9H			;
L2ADB	EQU  2ADBH			;
L2ADD	EQU  2ADDH			;
L2AED	EQU  2AEDH			;
L2AF9	EQU  2AF9H			;
L2AFD	EQU  2AFDH			;
L2B01	EQU  2B01H			;
L2B03	EQU  2B03H			;
L2B06	EQU  2B06H			;
L2B22	EQU  2B22H			;
L2B26	EQU  2B26H			;
L2B2A	EQU  2B2AH			;
L2B3A	EQU  2B3AH			;
L2B46	EQU  2B46H			;
L2B4A	EQU  2B4AH			;
L2B50	EQU  2B50H			;
L2B72	EQU  2B72H			;
L2B77	EQU  2B77H			;
L2B88	EQU  2B88H			;
L2B9F	EQU  2B9FH			;
L2BA3	EQU  2BA3H			;
L2BB7	EQU  2BB7H			;
L2BBC	EQU  2BBCH			;
L2BE0	EQU  2BE0H			;
L2BF0	EQU  2BF0H			;
L2C0F	EQU  2C0FH			;
L2C2D	EQU  2C2DH			;
L2C3D	EQU  2C3DH			;
L2C5C	EQU  2C5CH			;
L2C7A	EQU  2C7AH			;
L2C8A	EQU  2C8AH			;
L2CA9	EQU  2CA9H			;
L2CC7	EQU  2CC7H			;
L2CD7	EQU  2CD7H			;
L2CF6	EQU  2CF6H			;
L2D14	EQU  2D14H			;
L2D1F	EQU  2D1FH			;
L2D21	EQU  2D21H			;
L2D24	EQU  2D24H			;
L2D41	EQU  2D41H			;
L2D61	EQU  2D61H			;
L2D66	EQU  2D66H			;
L2D6E	EQU  2D6EH			;
L2D8A	EQU  2D8AH			;
L2D8E	EQU  2D8EH			;
L2DAE	EQU  2DAEH			;
L2DBB	EQU  2DBBH			;
L2DD7	EQU  2DD7H			;
L2DDB	EQU  2DDBH			;
L2DFB	EQU  2DFBH			;
L2E08	EQU  2E08H			;
L2E13	EQU  2E13H			;
L2E24	EQU  2E24H			;
L2E28	EQU  2E28H			;
L2E55	EQU  2E55H			;
L2E75	EQU  2E75H			;
L2E86	EQU  2E86H			;
L2E95	EQU  2E95H			;
L2EA2	EQU  2EA2H			;
L2EB5	EQU  2EB5H			;
L2EC2	EQU  2EC2H			;
L2EE2	EQU  2EE2H			;
L2EEF	EQU  2EEFH			;
L2EFA	EQU  2EFAH			;
L2F0F	EQU  2F0FH			;
L2F15	EQU  2F15H			;
L2F25	EQU  2F25H			;
L2F35	EQU  2F35H			;
L2F37	EQU  2F37H			;
L2F3A	EQU  2F3AH			;
L2F3D	EQU  2F3DH			;
L2F43	EQU  2F43H			;
L2F46	EQU  2F46H			;
L2F4C	EQU  2F4CH			;
L2F4E	EQU  2F4EH			;
L2F51	EQU  2F51H			;
L2F56	EQU  2F56H			;
L2F63	EQU  2F63H			;
L2F66	EQU  2F66H			;
L2F7A	EQU  2F7AH			;
L2F7B	EQU  2F7BH			;
L2F7E	EQU  2F7EH			;
L2F82	EQU  2F82H			;
L2F86	EQU  2F86H			;
L2F92	EQU  2F92H			;
L2F98	EQU  2F98H			;
L2F9C	EQU  2F9CH			;
L2FA9	EQU  2FA9H			;
L2FCF	EQU  2FCFH			;
L2FE1	EQU  2FE1H			;
L2FE8	EQU  2FE8H			;
L2FED	EQU  2FEDH			;
L2FF6	EQU  2FF6H			;
L300A	EQU  300AH			;
L3024	EQU  3024H			;
L3026	EQU  3026H			;
L302A	EQU  302AH			;
L3032	EQU  3032H			;
L3035	EQU  3035H			;
L304E	EQU  304EH			;
L305D	EQU  305DH			;
L306A	EQU  306AH			;
L306B	EQU  306BH			;
L3080	EQU  3080H			;
L3087	EQU  3087H			;
L3094	EQU  3094H			;
L30B6	EQU  30B6H			;
L30B8	EQU  30B8H			;
L30D0	EQU  30D0H			;
L30D4	EQU  30D4H			;
L30D9	EQU  30D9H			;
L30E1	EQU  30E1H			;
L30E2	EQU  30E2H			;
L30F1	EQU  30F1H			;
L3103	EQU  3103H			;
L3106	EQU  3106H			;
L310B	EQU  310BH			;
L3127	EQU  3127H			;
L312A	EQU  312AH			;
L313B	EQU  313BH			;
L3141	EQU  3141H			;
L3143	EQU  3143H			;
L3144	EQU  3144H			;
L315F	EQU  315FH			;
L316A	EQU  316AH			;
L317C	EQU  317CH			;
L3188	EQU  3188H			;
L3191	EQU  3191H			;
L3194	EQU  3194H			;
L31A3	EQU  31A3H			;
L31AB	EQU  31ABH			;
L31B4	EQU  31B4H			;
L31C9	EQU  31C9H			;
L31CF	EQU  31CFH			;
L31D3	EQU  31D3H			;
L320A	EQU  320AH			;
L321A	EQU  321AH			;
L3230	EQU  3230H			;
L3232	EQU  3232H			;
L3244	EQU  3244H			;
L3250	EQU  3250H			;
L325F	EQU  325FH			;
L3267	EQU  3267H			;
L3269	EQU  3269H			;
L3285	EQU  3285H			;
L328C	EQU  328CH			;
L32A0	EQU  32A0H			;
L32A4	EQU  32A4H			;
L32A8	EQU  32A8H			;
L32AE	EQU  32AEH			;
L32C9	EQU  32C9H			;
L32E0	EQU  32E0H			;
L32E7	EQU  32E7H			;
L32E8	EQU  32E8H			;
L32F1	EQU  32F1H			;
L3303	EQU  3303H			;
L3309	EQU  3309H			;
L330B	EQU  330BH			;
L3311	EQU  3311H			;
L332F	EQU  332FH			;
L3332	EQU  3332H			;
L3340	EQU  3340H			;
L3342	EQU  3342H			;
L334A	EQU  334AH			;
L3350	EQU  3350H			;
L3382	EQU  3382H			;
L3384	EQU  3384H			;
L3389	EQU  3389H			;
L3391	EQU  3391H			;
L3399	EQU  3399H			;
L33C9	EQU  33C9H			;
L33CF	EQU  33CFH			;
L33D1	EQU  33D1H			;
L33DC	EQU  33DCH			;
L33E0	EQU  33E0H			;
L33E2	EQU  33E2H			;
L33E8	EQU  33E8H			;
L3400	EQU  3400H			;
L3405	EQU  3405H			;
L340C	EQU  340CH			;
L341E	EQU  341EH			;
L341F	EQU  341FH			;
L3423	EQU  3423H			;
L3425	EQU  3425H			;
L3433	EQU  3433H			;
L3437	EQU  3437H			;
L3441	EQU  3441H			;
L3459	EQU  3459H			;
L345C	EQU  345CH			;
L346B	EQU  346BH			;
L347E	EQU  347EH			;
L3486	EQU  3486H			;
L3495	EQU  3495H			;
L349A	EQU  349AH			;
L349E	EQU  349EH			;
L34B5	EQU  34B5H			;
L34B6	EQU  34B6H			;
L34B9	EQU  34B9H			;
L34CB	EQU  34CBH			;
L34D0	EQU  34D0H			;
L34D3	EQU  34D3H			;
L34E3	EQU  34E3H			;
L34E5	EQU  34E5H			;
L34EB	EQU  34EBH			;
L34F3	EQU  34F3H			;
L34FE	EQU  34FEH			;
L350E	EQU  350EH			;
L3510	EQU  3510H			;
L3522	EQU  3522H			;
L3526	EQU  3526H			;
L352A	EQU  352AH			;
L353C	EQU  353CH			;
L3540	EQU  3540H			;
L3548	EQU  3548H			;
L354A	EQU  354AH			;
L3557	EQU  3557H			;
L355B	EQU  355BH			;
L3563	EQU  3563H			;
L356E	EQU  356EH			;
L3583	EQU  3583H			;
L3585	EQU  3585H			;
L3589	EQU  3589H			;
L358D	EQU  358DH			;
L358F	EQU  358FH			;
L3592	EQU  3592H			;
L359C	EQU  359CH			;
L35A7	EQU  35A7H			;
L35AC	EQU  35ACH			;
L35AE	EQU  35AEH			;
L35B4	EQU  35B4H			;
L35C2	EQU  35C2H			;
L35C4	EQU  35C4H			;
L35CC	EQU  35CCH			;
L35CE	EQU  35CEH			;
L35D3	EQU  35D3H			;
L35F1	EQU  35F1H			;
L35F3	EQU  35F3H			;
L35F5	EQU  35F5H			;
L35F7	EQU  35F7H			;
L35F9	EQU  35F9H			;
L35FD	EQU  35FDH			;
L3601	EQU  3601H			;
L360F	EQU  360FH			;
L3615	EQU  3615H			;
L361D	EQU  361DH			;
L3627	EQU  3627H			;
L3639	EQU  3639H			;
L363A	EQU  363AH			;
L3640	EQU  3640H			;
L3642	EQU  3642H			;
L3652	EQU  3652H			;
L3664	EQU  3664H			;
L3671	EQU  3671H			;
L3673	EQU  3673H			;
L3686	EQU  3686H			;
L3687	EQU  3687H			;
L368F	EQU  368FH			;
L3694	EQU  3694H			;
L369B	EQU  369BH			;
L369F	EQU  369FH			;
L36A1	EQU  36A1H			;
L36A8	EQU  36A8H			;
L36AD	EQU  36ADH			;
L36BB	EQU  36BBH			;
L36D1	EQU  36D1H			;
L36D4	EQU  36D4H			;
L36D8	EQU  36D8H			;
L36DE	EQU  36DEH			;
L36EE	EQU  36EEH			;
L36F1	EQU  36F1H			;
L36F6	EQU  36F6H			;
L3702	EQU  3702H			;
L371E	EQU  371EH			;
L3727	EQU  3727H			;
L3729	EQU  3729H			;
L3731	EQU  3731H			;
L373A	EQU  373AH			;
L373D	EQU  373DH			;
L3743	EQU  3743H			;
L374D	EQU  374DH			;
L3759	EQU  3759H			;
L3763	EQU  3763H			;
L3765	EQU  3765H			;
L376E	EQU  376EH			;
L3772	EQU  3772H			;
L3776	EQU  3776H			;
L3778	EQU  3778H			;
L377A	EQU  377AH			;
L3790	EQU  3790H			;
L379D	EQU  379DH			;
L37A2	EQU  37A2H			;
L37B7	EQU  37B7H			;
L37B8	EQU  37B8H			;
L37BA	EQU  37BAH			;
L37C9	EQU  37C9H			;
L3814	EQU  3814H			;
L3816	EQU  3816H			;
L3818	EQU  3818H			;
L3821	EQU  3821H			;
L383B	EQU  383BH			;
L3888	EQU  3888H			;
L38A1	EQU  38A1H			;
L38A2	EQU  38A2H			;
L38AC	EQU  38ACH			;
L38BB	EQU  38BBH			;
L38BE	EQU  38BEH			;
L38C3	EQU  38C3H			;
L38D2	EQU  38D2H			;
L3920	EQU  3920H			;
L3985	EQU  3985H			;
L3989	EQU  3989H			;
L398B	EQU  398BH			;
L3999	EQU  3999H			;
L399A	EQU  399AH			;
L39B2	EQU  39B2H			;
L39C5	EQU  39C5H			;
L39D2	EQU  39D2H			;
L39DA	EQU  39DAH			;
L39E6	EQU  39E6H			;
L39EF	EQU  39EFH			;
L3A1F	EQU  3A1FH			;
L3A20	EQU  3A20H			;
L3A27	EQU  3A27H			;
L3A37	EQU  3A37H			;
L3A3F	EQU  3A3FH			;
L3A55	EQU  3A55H			;
L3A60	EQU  3A60H			;
L3A6F	EQU  3A6FH			;
L3A78	EQU  3A78H			;
L3A8A	EQU  3A8AH			;
L3A90	EQU  3A90H			;
L3AC7	EQU  3AC7H			;
L3AD0	EQU  3AD0H			;
L3AE5	EQU  3AE5H			;
L3AE7	EQU  3AE7H			;
L3AF0	EQU  3AF0H			;
L3AF1	EQU  3AF1H			;
L3AF3	EQU  3AF3H			;
L3B0A	EQU  3B0AH			;
L3B0E	EQU  3B0EH			;
L3B1C	EQU  3B1CH			;
L3B20	EQU  3B20H			;
L3B2C	EQU  3B2CH			;
L3B32	EQU  3B32H			;
L3B34	EQU  3B34H			;
L3B3D	EQU  3B3DH			;
L3B59	EQU  3B59H			;
L3B5B	EQU  3B5BH			;
L3B5E	EQU  3B5EH			;
L3B64	EQU  3B64H			;
L3B68	EQU  3B68H			;
L3B70	EQU  3B70H			;
L3B8A	EQU  3B8AH			;
L3B8F	EQU  3B8FH			;
L3B99	EQU  3B99H			;
L3BA0	EQU  3BA0H			;
L3BA8	EQU  3BA8H			;
L3BB0	EQU  3BB0H			;
L3BB9	EQU  3BB9H			;
L3BCF	EQU  3BCFH			;
L3BEA	EQU  3BEAH			;
L3BED	EQU  3BEDH			;
L3BF5	EQU  3BF5H			;
L3C01	EQU  3C01H			;
L3C05	EQU  3C05H			;
L3C23	EQU  3C23H			;
L3C2F	EQU  3C2FH			;
L3C35	EQU  3C35H			;
L3C3A	EQU  3C3AH			;
L3C3B	EQU  3C3BH			;
L3C3D	EQU  3C3DH			;
L3C4B	EQU  3C4BH			;
L3C55	EQU  3C55H			;
L3C5D	EQU  3C5DH			;
L3C69	EQU  3C69H			;
L3C6B	EQU  3C6BH			;
L3C71	EQU  3C71H			;
L3C73	EQU  3C73H			;
L3C79	EQU  3C79H			;
L3C88	EQU  3C88H			;
L3C8A	EQU  3C8AH			;
L3C98	EQU  3C98H			;
L3C9A	EQU  3C9AH			;
L3C9E	EQU  3C9EH			;
L3CA4	EQU  3CA4H			;
L3CA8	EQU  3CA8H			;
L3CAA	EQU  3CAAH			;
L3CAC	EQU  3CACH			;
L3CBE	EQU  3CBEH			;
L3CC0	EQU  3CC0H			;
L3CCC	EQU  3CCCH			;
L3CD4	EQU  3CD4H			;
L3CD5	EQU  3CD5H			;
L3CDA	EQU  3CDAH			;
L3CE3	EQU  3CE3H			;
L3CE9	EQU  3CE9H			;
L3CEF	EQU  3CEFH			;
L3CF3	EQU  3CF3H			;
L3CF7	EQU  3CF7H			;
L3CF9	EQU  3CF9H			;
L3CFB	EQU  3CFBH			;
L3D0B	EQU  3D0BH			;
L3D0D	EQU  3D0DH			;
L3D15	EQU  3D15H			;
L3D18	EQU  3D18H			;
L3D1C	EQU  3D1CH			;
L3D2B	EQU  3D2BH			;
L3D34	EQU  3D34H			;
L3D3A	EQU  3D3AH			;
L3D40	EQU  3D40H			;
L3D42	EQU  3D42H			;
L3D46	EQU  3D46H			;
L3D5F	EQU  3D5FH			;
L3D60	EQU  3D60H			;
L3D63	EQU  3D63H			;
L3D6F	EQU  3D6FH			;
L3D71	EQU  3D71H			;
L3D72	EQU  3D72H			;
L3D79	EQU  3D79H			;
L3D7A	EQU  3D7AH			;
L3DA8	EQU  3DA8H			;
L3DC6	EQU  3DC6H			;
L3DE4	EQU  3DE4H			;
L3DEE	EQU  3DEEH			;
L3DF2	EQU  3DF2H			;
L3DF4	EQU  3DF4H			;
L3E08	EQU  3E08H			;
L3E09	EQU  3E09H			;
L3E0E	EQU  3E0EH			;
L3E12	EQU  3E12H			;
L3E15	EQU  3E15H			;
L3E1D	EQU  3E1DH			;
L3E21	EQU  3E21H			;
L3E23	EQU  3E23H			;
L3E25	EQU  3E25H			;
L3E29	EQU  3E29H			;
L3E31	EQU  3E31H			;
L3E33	EQU  3E33H			;
L3E3F	EQU  3E3FH			;
L3E41	EQU  3E41H			;
L3E56	EQU  3E56H			;
L3E58	EQU  3E58H			;
L3E61	EQU  3E61H			;
L3E6A	EQU  3E6AH			;
L3E6C	EQU  3E6CH			;
L3E72	EQU  3E72H			;
L3E74	EQU  3E74H			;
L3E76	EQU  3E76H			;
L3E78	EQU  3E78H			;
L3E7E	EQU  3E7EH			;
L3E80	EQU  3E80H			;
L3E84	EQU  3E84H			;
L3E8C	EQU  3E8CH			;
L3E94	EQU  3E94H			;
L3E9D	EQU  3E9DH			;
L3EA5	EQU  3EA5H			;
L3EB2	EQU  3EB2H			;
L3EB7	EQU  3EB7H			;
L3ED9	EQU  3ED9H			;
L3EE1	EQU  3EE1H			;
L3EFC	EQU  3EFCH			;
L3F00	EQU  3F00H			;
L3F0E	EQU  3F0EH			;
L3F12	EQU  3F12H			;
L3F13	EQU  3F13H			;
L3F28	EQU  3F28H			;
L3F38	EQU  3F38H			;
L3F7A	EQU  3F7AH			;
L3F89	EQU  3F89H			;
L3F8F	EQU  3F8FH			;
L3F94	EQU  3F94H			;
L3FA4	EQU  3FA4H			;
L3FAC	EQU  3FACH			;
L3FEA	EQU  3FEAH			;
L3FEE	EQU  3FEEH			;
L3FFF	EQU  3FFFH			;
L400D	EQU  400DH			;
L4016	EQU  4016H			;
L4043	EQU  4043H			;
L4049	EQU  4049H			;
L404B	EQU  404BH			;
L4050	EQU  4050H			;
L4054	EQU  4054H			;
L405C	EQU  405CH			;
L406D	EQU  406DH			;
L407B	EQU  407BH			;
L4096	EQU  4096H			;
L40A7	EQU  40A7H			;
L40B7	EQU  40B7H			;
L40C3	EQU  40C3H			;
L40C5	EQU  40C5H			;
L40C7	EQU  40C7H			;
L40CB	EQU  40CBH			;
L40CE	EQU  40CEH			;
L40D1	EQU  40D1H			;
L40DC	EQU  40DCH			;
L40DE	EQU  40DEH			;
L40F4	EQU  40F4H			;
L40F7	EQU  40F7H			;
L4107	EQU  4107H			;
L410B	EQU  410BH			;
L410D	EQU  410DH			;
L413E	EQU  413EH			;
L4141	EQU  4141H			;
L4148	EQU  4148H			;
L4152	EQU  4152H			;
L4158	EQU  4158H			;
L415D	EQU  415DH			;
L415F	EQU  415FH			;
L416B	EQU  416BH			;
L416E	EQU  416EH			;
L419C	EQU  419CH			;
L41AF	EQU  41AFH			;
L41B1	EQU  41B1H			;
L41B9	EQU  41B9H			;
L41CA	EQU  41CAH			;
L41FC	EQU  41FCH			;
L4207	EQU  4207H			;
L420C	EQU  420CH			;
L4214	EQU  4214H			;
L4236	EQU  4236H			;
L42A9	EQU  42A9H			;
L42AD	EQU  42ADH			;
L42D8	EQU  42D8H			;
L42E7	EQU  42E7H			;
L42EA	EQU  42EAH			;
L4329	EQU  4329H			;
L4372	EQU  4372H			;
L4376	EQU  4376H			;
L4378	EQU  4378H			;
L437A	EQU  437AH			;
L437C	EQU  437CH			;
;----------------------------------------------------------------------
M0A0D	EQU  0A0DH			;
M0D33	EQU  0D33H			;
M0D34	EQU  0D34H			;
M0D39	EQU  0D39H			;
M0D42	EQU  0D42H			;
M0D43	EQU  0D43H			;
M3032	EQU  3032H			;
M3033	EQU  3033H			;
M3035	EQU  3035H			;
M3036	EQU  3036H			;
M3037	EQU  3037H			;
M3038	EQU  3038H			;
M3039	EQU  3039H			;
M3042	EQU  3042H			;
M3043	EQU  3043H			;
M3045	EQU  3045H			;
M3136	EQU  3136H			;
M3137	EQU  3137H			;
M3139	EQU  3139H			;
M3141	EQU  3141H			;
M3144	EQU  3144H			;
M3145	EQU  3145H			;
M3146	EQU  3146H			;
M3230	EQU  3230H			;
M3231	EQU  3231H			;
M3232	EQU  3232H			;
M3233	EQU  3233H			;
M3234	EQU  3234H			;
M3237	EQU  3237H			;
M3238	EQU  3238H			;
M3239	EQU  3239H			;
M3241	EQU  3241H			;
M3244	EQU  3244H			;
M3331	EQU  3331H			;
M3332	EQU  3332H			;
M3334	EQU  3334H			;
M3335	EQU  3335H			;
M3337	EQU  3337H			;
M3338	EQU  3338H			;
M3342	EQU  3342H			;
M3343	EQU  3343H			;
M3346	EQU  3346H			;
M3430	EQU  3430H			;
M3433	EQU  3433H			;
M3436	EQU  3436H			;
M3437	EQU  3437H			;
M3441	EQU  3441H			;
M3445	EQU  3445H			;
M3530	EQU  3530H			;
M3532	EQU  3532H			;
M3534	EQU  3534H			;
M3535	EQU  3535H			;
M3538	EQU  3538H			;
M3541	EQU  3541H			;
M3542	EQU  3542H			;
M3544	EQU  3544H			;
M3631	EQU  3631H			;
M3636	EQU  3636H			;
M3637	EQU  3637H			;
M3638	EQU  3638H			;
M3639	EQU  3639H			;
M3641	EQU  3641H			;
M3642	EQU  3642H			;
M3644	EQU  3644H			;
M3645	EQU  3645H			;
M3730	EQU  3730H			;
M3731	EQU  3731H			;
M3733	EQU  3733H			;
M3735	EQU  3735H			;
M3737	EQU  3737H			;
M3742	EQU  3742H			;
M3743	EQU  3743H			;
M3745	EQU  3745H			;
M3836	EQU  3836H			;
M3838	EQU  3838H			;
M3839	EQU  3839H			;
M3842	EQU  3842H			;
M3844	EQU  3844H			;
M3845	EQU  3845H			;
M3846	EQU  3846H			;
M3931	EQU  3931H			;
M3942	EQU  3942H			;
M3943	EQU  3943H			;
M4130	EQU  4130H			;
M4131	EQU  4131H			;
M4132	EQU  4132H			;
M4133	EQU  4133H			;
M4134	EQU  4134H			;
M4138	EQU  4138H			;
M4141	EQU  4141H			;
M4142	EQU  4142H			;
M4144	EQU  4144H			;
M4146	EQU  4146H			;
M4231	EQU  4231H			;
M4232	EQU  4232H			;
M4237	EQU  4237H			;
M4238	EQU  4238H			;
M4239	EQU  4239H			;
M4241	EQU  4241H			;
M4244	EQU  4244H			;
M4246	EQU  4246H			;
M4341	EQU  4341H			;
M4343	EQU  4343H			;
M4345	EQU  4345H			;
M4431	EQU  4431H			;
M4433	EQU  4433H			;
M4435	EQU  4435H			;
M4437	EQU  4437H			;
M4439	EQU  4439H			;
M4441	EQU  4441H			;
M4443	EQU  4443H			;
M4445	EQU  4445H			;
M4531	EQU  4531H			;
M4533	EQU  4533H			;
M4535	EQU  4535H			;
M4537	EQU  4537H			;
M4539	EQU  4539H			;
M4541	EQU  4541H			;
M4543	EQU  4543H			;
M4544	EQU  4544H			;
M4546	EQU  4546H			;
M4631	EQU  4631H			;
M4633	EQU  4633H			;
M4635	EQU  4635H			;
M4637	EQU  4637H			;
M4641	EQU  4641H			;
M4645	EQU  4645H			;

	END
