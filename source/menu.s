
@{{BLOCK(menu)

@=======================================================================
@
@	menu, 256x256@4, 
@	+ palette 13 entries, not compressed
@	+ 125 tiles (t|f|p reduced) not compressed
@	+ regular map (in SBBs), not compressed, 32x32 
@	Total size: 26 + 4000 + 2048 = 6074
@
@	Time-stamp: 2024-11-02, 03:47:31
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global menuTiles		@ 4000 unsigned chars
	.hidden menuTiles
menuTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xAAAAAAAA,0x9A9A9A9A,0xA9A9A9A9,0x9A9A9A9A,0xA9A9A9A9,0x9A9A9A9A,0xA9A9A9A9,0x9A9A9A9A
	.word 0xAAAAAAAA,0xAAAA9A9A,0xA9A9A9A9,0x9A9A9A9A,0xA9A9A9A9,0x9A9A9A9A,0xA9A9A9A9,0x9A9A9A9A
	.word 0xAAAAAAAA,0xAAAAAAAA,0xA9A9A9A9,0x9A9A9A9A,0xA9A9A9A9,0x9A9A9A9A,0xA9A9A9A9,0x9A9A9A9A
	.word 0xAAAAAAAA,0x9A9AAAAA,0xAAAAA9A9,0x9A9A9A9A,0xA9A9A9A9,0x9A9A9A9A,0xA9A9A9A9,0x9A9A9A9A
	.word 0xAAAAAAAA,0x9A9A9A9A,0xAAAAAAAA,0x9A9A9A9A,0xA9A9A9A9,0x9A9A9A9A,0xA9A9A9A9,0x9A9A9A9A
	.word 0xAAAAAAAA,0x9A9A9A9A,0xA9A9A9AA,0x9A9A9A9A,0xA9A9A9A9,0x9A9A9A9A,0xA9A9A9A9,0x9A9A9A9A
	.word 0xC9C9C9C9,0x9A9A9A9A,0xC9C9C9C9,0x9A9A9A9A,0xC9C9C9C9,0x9A9A9A9A,0xC9C9C9C9,0x9A9A9A9A

	.word 0xC9C9C9C9,0xC9C99A9A,0x9A9AC9C9,0xC9C99A9A,0x9A9AC9C9,0xC9C99A9A,0x9A9AC9C9,0xC9C99A9A
	.word 0xC9C9C9C9,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0x888888BB,0x11111BBB,0x11115BBB
	.word 0xC9C9C9C9,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xB7777BB7,0x22223B72,0x22227B72
	.word 0xC9C9C9C9,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0x888BBBBB,0x111BBBBB,0x115BBBB8
	.word 0xC9C9C9C9,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0x8BB88888,0x1BB51111,0x1BB51111
	.word 0xC9C9C9C9,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0x77777777,0x22222222,0x22227722
	.word 0xC9C9C9C9,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBB88888,0xBB811111,0xBBB111B5
	.word 0xC9C9C9C9,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0x8888BBBB,0x1115BBBB,0x1115BBBB

	.word 0xC9C9C9C9,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0x88BBBB88,0x111BB511,0x111B8111
	.word 0xC9C9C9C9,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBB888,0xBBBBB811,0xBBBBB811
	.word 0xC9C9C9C9,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBB3BB,0x222322BB,0x222223BB
	.word 0xC9C9C9C9,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCC66466,0xCC222222,0xC4222222
	.word 0xC9C9C9C9,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0x8888BBBB,0x11118BBB,0x11118BBB
	.word 0xC9C9C9C9,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBB888,0xBBBBB111,0xBBBBB111
	.word 0xC9C9C9C9,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xB8858BBB,0x1111118B,0x11111118
	.word 0xC9C9C9C9,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0x64CC66CC,0x222C2224,0x22264222

	.word 0xC9C9C9C9,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0x64CCCCC6,0x2224CCC4,0x22224CC2
	.word 0xC9C9C9C9,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xC66CCCC4,0xC6224222,0xC6222222
	.word 0xC9C9C9C9,0xC9C9C9C9,0x9A9A9A9A,0xC9C9C9C9,0x9A9A9A9A,0xC9C9C9C9,0x9A9A9A9A,0xC9C9C9C9
	.word 0x9A9AC9C9,0xC9C99A9A,0x9A9AC9C9,0xC9C99A9A,0x9A9AC9C9,0xC9C99A9A,0x9A9AC9C9,0xC9C99A9A
	.word 0x11111BBB,0x22223BBB,0x32222BBB,0xB3223BBB,0x6B622BBB,0x26B63BBB,0x62232BBB,0x32323BBB
	.word 0x22223B72,0x622226C4,0xC42222CC,0xCC62224C,0xCCCC4224,0xCCCCCC64,0xCCC6446C,0xCCC22222
	.word 0x111BBBBB,0x4426CCCC,0x6C46CCCC,0xCC64CCCC,0xCC44CCCC,0xCC42CCCC,0xCC226CCC,0xC6226CCC
	.word 0x1BB51111,0x2CC22222,0x2CC22222,0x2CC22222,0x4C422224,0xCC422226,0xCC22222C,0xC622224C

	.word 0x22227B32,0x11118B81,0x11118BB1,0x11118BB5,0x11118BBB,0x11118BBB,0x11118BBB,0x11118BBB
	.word 0xBB8115B5,0xBBB118B5,0xBB811BB5,0xBBB18BB5,0xBBB5BBB5,0xBBBBBBB5,0xBBBBBBB5,0xBBBBBBB5
	.word 0x1118BBBB,0x2424CCCC,0x4C46CCCC,0x6C44CCCC,0xCC26CCCC,0xCC24CCCC,0xC626CCCC,0xC424CCCC
	.word 0x111B1111,0x11881111,0x15B51111,0x18B11111,0x5B811111,0xBB811115,0xBB111118,0xB811111B
	.word 0xBBBBBB11,0xBBBBB811,0xBBBBBB11,0xBBBBB811,0xBBBBBB11,0xBBBBB811,0xBBBBBB15,0xBBBBB815
	.word 0x222227BB,0x11115BBB,0xB858BBBB,0xBBBBBBBB,0x8BBBBBBB,0x15BBBBBB,0x1118BBBB,0x11118BBB
	.word 0xC4464422,0xC46CCC62,0xCC26CCCC,0xCC6224CC,0xCCC42224,0xCCCC6222,0xCCCCC422,0xCCCCC642
	.word 0x11115BBB,0x22646CCC,0x24C64CCC,0x24CC2CCC,0x2CCC26CC,0x4CC624CC,0x4CC624CC,0x6CC422CC

	.word 0xBBBB8111,0x6BBB6222,0x2BBB3222,0x26BB3222,0x26BB2222,0x23B62222,0x26B62222,0x23B32222
	.word 0x11115851,0x2246CCC2,0x6CCCCCC4,0x6CCCCCC4,0x246CCCC4,0x2246CCC2,0x2226CC62,0x2224CC42
	.word 0x22266222,0x223BB322,0x27BBBB32,0x33BBBBB2,0xBBBBBBB7,0xBBBBBBB7,0xBBBBBB32,0xBBBBB722
	.word 0x24462662,0x7BBB72B2,0xBBBB32B3,0xB77222B7,0x222222BB,0x222223BB,0x22223BBB,0x2233BBBB
	.word 0xCC422222,0xBBB22222,0xBBBB366B,0xBBBBBBBB,0xBBBB6332,0xBBB22222,0xBB222222,0xB6222222
	.word 0x6BB62BBB,0xBBB63BBB,0xBB632BBB,0xB3323BBB,0x62222BBB,0x22223BBB,0x22222BBB,0x323236BB
	.word 0xCC422222,0xBB511115,0xBB11111B,0xB511118B,0xB111118B,0x811111B8,0x511115B8,0x515158BB
	.word 0x64224CCC,0x81115BBB,0x81111BBB,0x511115BB,0x111115BB,0x111111BB,0x1111115B,0x51515158

	.word 0xC6222246,0xB3222233,0xB222226B,0xB22222BB,0x622222BB,0x322222B6,0x222222BB,0x323232BB
	.word 0x11118BBB,0x11118BBB,0x11118BBB,0x11118BBB,0x11118BBB,0x11118BBB,0x11115BBB,0x51518BB5
	.word 0xBBBBBBB5,0xBBBBBBB5,0xBBBBBBB5,0xBBBBBBB5,0xBBBBBBB5,0xBBBBBBB5,0xBBBBBBB5,0xBBBBBBB5
	.word 0xC226CCCC,0x8115BBBB,0x1118BBBB,0x1115BBBB,0x1118BBBB,0x1115BBBB,0x1118BBBB,0x5155BBBB
	.word 0xB511115B,0xB322227B,0x722222BB,0x722223B3,0x22222772,0x22223B32,0x22227B22,0x3233BB72
	.word 0xBBBBBB1B,0xBBBBB81B,0xBBBBBB1B,0xBBBBB81B,0xBBBBBB15,0xBBBBB811,0xBBBBBB11,0xBBBBB551
	.word 0x111118BB,0x422222CC,0x6222226C,0xC622226C,0xCC62224C,0xCCC4226C,0x26C622CC,0x424244CC
	.word 0xCCCCCC62,0xBBBBBBB6,0xBBBBBBBB,0xB63266BB,0xB222226B,0xB2222223,0xB2222222,0x63323232

	.word 0x4662226C,0x6442226C,0xCC42224C,0xC622224C,0xC6222226,0xC4222224,0xC4222222,0xC6424242
	.word 0x26B22222,0x15B11111,0x1B511115,0x5B511115,0x5B111118,0xB8111115,0xB5111118,0xB1515155
	.word 0x222CC622,0x55BBB111,0xBBBB5111,0xB8811111,0x11111111,0x11111111,0x1111111B,0x111155BB
	.word 0xBBBBBB32,0xBBBB77B3,0xBBBB23BB,0xBBBB3237,0xBBBB7222,0xBBBBB322,0xBBBBBB22,0xBBBBBBB3
	.word 0x37BBBBBB,0xB377BBBB,0x72223BBB,0xB22222BB,0xB222227B,0x722223BB,0x22222BBB,0x2233BBBB
	.word 0xB3222222,0xC422226C,0xC4224CCC,0xC622CCCC,0xCC22CCCC,0xCC626CCC,0xCCC42466,0xCCCC6222
	.word 0xBBBBBBBB,0xC9C9C9C9,0x9A9A9A9A,0xC9C9C9C9,0x9A9A9A9A,0xC9C9C9C9,0x9A9A9A9A,0xC9C9C9C9
	.word 0xBBBBBBBB,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0x4CCCCCCC,0x4CCCCCCC,0xCCCCCCCC

	.word 0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0x33B73333,0x27BB2222,0x2BBB2222
	.word 0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0x51588151,0x11188111,0x1118B111
	.word 0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0x3223B733,0x22222B32,0x22777372
	.word 0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0x51558185,0x11155111,0x1115B111
	.word 0xBBBBBBBB,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCC642,0x6CCC4266,0x4CC622C6
	.word 0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0x23732237,0x22222222,0x72222277
	.word 0xCCCCCCCC,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0x51515158,0x1115511B,0x1115B118
	.word 0xBBBBBBBB,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0x42446244,0x2224422C,0x2224626C

	.word 0xCCCCCCCC,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0x77333337,0x3B22223B,0x7B222277
	.word 0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0x33B23333,0x22B72222,0x22BB2222
	.word 0xBB8BBBBB,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0x6CCC6242,0x4CCC4222,0x6CCC4222
	.word 0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBB85151,0xBBB51111,0xBBB51111
	.word 0x77BBBBBB,0xC9C9C9C9,0x9A9A9A9A,0xC9C9C9C9,0x9A9A9A9A,0xC9C9C9C9,0x9A9A9A9A,0xC9C9C9C9
	.word 0xCCCCCCCC,0xC9C9C9C9,0x9A9A9A9A,0xC9C9C9C9,0x9A9A9A9A,0xC9C9C9C9,0x9A9A9A9A,0xC9C9C9C9
	.word 0x3BBB2222,0x8BB81115,0x8BB81118,0x8BB51118,0x8BB1111B,0x8BB1115B,0x5B51115B,0x5B5111BB
	.word 0x111B5111,0x226B6222,0x226B3222,0x23BB3222,0x26BB2222,0x36B32222,0x66B32226,0x63B2222B

	.word 0x7BBBB2B2,0xC666C264,0x42224246,0x22266266,0x226C424C,0x66C6226C,0xCC62226C,0xC42222CC
	.word 0x1115B855,0x1115BBBB,0x1115BB58,0x1115B811,0x1115BB51,0x1115BBB8,0x111558BB,0x11158188
	.word 0x26C224CC,0x158115BB,0x1B5115BB,0x8B5115BB,0xBB1115BB,0xB81115BB,0x8B1115BB,0x181111BB
	.word 0xB7337BBB,0xBBBBB772,0xB7322222,0x72222222,0x22222227,0x222233BB,0x223BB323,0x22BBB322
	.word 0x1115B81B,0x1115BB58,0x1115BB8B,0x1115BBBB,0x1115BBBB,0x1115BBB8,0x1115BBB8,0x1115BBB8
	.word 0x222442CC,0x111585BB,0x11158BBB,0x1115BBBB,0x1115BBBB,0x1115BBBB,0x1115BBBB,0x1115BBBB
	.word 0x7B2222BB,0xB81115B8,0xB81118BB,0xB51118B8,0xB1111BBB,0xB1115BB8,0x51115BBB,0x51118BB8
	.word 0x777B3222,0xC66C6222,0xC64C6224,0xC42CC226,0xC426C44C,0x6224C44C,0x4224C64C,0x4222CC4C

	.word 0x4CCC2222,0x6CC62222,0x4CC62224,0x6CC42226,0x4CC4222C,0x6CC22224,0x4C62224C,0x6C62226C
	.word 0xBBBB5111,0xBBBBB111,0xB85BBB11,0x5111BB81,0x11118BB1,0x8511BBB1,0xBB15BBB5,0xB55BBBB1
	.word 0x9A9A9A9A,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCC4,0xCCCCCCC4,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC
	.word 0x111111BB,0x322222BB,0x322223BB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB
	.word 0xB222222B,0xC222226C,0xC422224C,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC
	.word 0x222224CC,0x222237BB,0x2223BBBB,0xB7BBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB
	.word 0x11158111,0x2223B322,0x2223BB62,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB
	.word 0x181115BB,0x466222C6,0x6CC64224,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC

	.word 0x33BBB722,0xC26CC222,0xCC422224,0xCCCCC6CC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC
	.word 0x1115BBBB,0x2222BBBB,0x2223BBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB
	.word 0x1115BBBB,0x2223BBBB,0x2223BBB7,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB
	.word 0x1111BBBB,0x2222BBB7,0x2223BBB7,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB
	.word 0x22226C24,0x22226B32,0x22222B32,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB
	.word 0x4C42226C,0x77222277,0x3722227B,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB
	.word 0x11BBBB51,0x22BBB322,0x22233222,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB
	.word 0xCCCCCCC6,0xBBBBBBB1,0xBBBBBBB5,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB

	.word 0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xB555BBBB,0x11B55BBB,0x15B518BB
	.word 0xBBBBBBBB,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xC46466CC,0x426C626C,0x42CC6264
	.word 0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0x6266CCCC,0x24C26CCC,0x26C24CCC
	.word 0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xC66446CC,0x46CC4266,0x44C64262
	.word 0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0x6333BBBB,0xBB623BBB,0xBB623BBB
	.word 0xBBBBBBBB,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xC6446CC6,0x624C46C4,0x426C4262
	.word 0xBBBBBBBB,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCCCCCCCC,0xCC64646C,0xC64CC626,0x6446C424
	.word 0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBB23333,0xBBB32222,0xBBB77377

	.word 0x18B518BB,0x2CC424CC,0x2CC226CC,0x2CC226CC,0x46426CCC,0xC666CCCC,0xCCCCCCCC,0xCCCCCCCC
	.word 0x624C4264,0xC44446C2,0x426C4264,0x426C6244,0x624C426C,0xC6646CCC,0xCCCCCCCC,0xCCCCCCCC
	.word 0x4CC22CCC,0x6CC24664,0x4C622CCC,0x6C626CCC,0x2622CCCC,0xC46CCCCC,0xCCCCCCCC,0xCCCCCCCC
	.word 0x42464462,0xC2226C62,0xC6442462,0x4224C4C2,0x622244C6,0xCCC666CC,0xCCCCCCCC,0xCCCCCCCC
	.word 0x26636BBB,0x2236B366,0x63226BBB,0x22B66BBB,0x32266BBB,0xBBB6BBBB,0xBBBBBBBB,0xBBBBBBBB
	.word 0x22CC4262,0x22BB32B3,0x23BB22BB,0x73B323B2,0x73722BB2,0xB777BBB7,0xBBBBBBBB,0xBBBBBBBB
	.word 0x6622644C,0xC64224CC,0x6C66422C,0x44224C66,0x66242446,0xCCCCC6CC,0xCCCCCCCC,0xCCCCCCCC
	.word 0xBBB32237,0xCCC226CC,0xCCC22C64,0xCCC426C2,0xCCCC4462,0xCCCCC666,0xCCCCCCCC,0xCCCCCCCC

	.word 0x9A9AC9C9,0xC9C99A9A,0x9A9AC9C9,0x9A9A9A9A,0xC9C9C9C9,0x9A9A9A9A,0xC9C9C9C9,0x9A9A9A9A
	.word 0x9A9A9A9A,0xC9C9C9C9,0x9A9A9A9A,0x9A9A9A9A,0xC9C9C9C9,0x9A9A9A9A,0xC9C9C9C9,0x9A9A9A9A
	.word 0xCCCCCCCC,0xC9C9C9C9,0x9A9A9A9A,0x9A9A9A9A,0xC9C9C9C9,0x9A9A9A9A,0xC9C9C9C9,0x9A9A9A9A
	.word 0xBBBBBBBB,0xC9C9C9C9,0x9A9A9A9A,0x9A9A9A9A,0xC9C9C9C9,0x9A9A9A9A,0xC9C9C9C9,0x9A9A9A9A
	.word 0xA9A9A9A9,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global menuMap		@ 2048 unsigned chars
	.hidden menuMap
menuMap:
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0003,0x0003
	.hword 0x0003,0x0003,0x0003,0x0003,0x0003,0x0003,0x0004,0x0005
	.hword 0x0005,0x0005,0x0005,0x0006,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000

	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000

	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0008,0x0009,0x000A
	.hword 0x000B,0x000C,0x000D,0x000E,0x000F,0x0010,0x0011,0x0012
	.hword 0x0013,0x0014,0x0015,0x0016,0x0017,0x0018,0x0019,0x001A
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000

	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x001B,0x001C,0x001D
	.hword 0x001E,0x001F,0x0020,0x0021,0x0022,0x0023,0x0024,0x0025
	.hword 0x0026,0x0027,0x0028,0x0029,0x002A,0x002B,0x002C,0x0807
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x001B,0x002D,0x002E
	.hword 0x002F,0x0030,0x0031,0x0032,0x0033,0x0034,0x0035,0x0036
	.hword 0x0037,0x0038,0x0039,0x003A,0x003B,0x003C,0x003D,0x0807
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000

	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x001B,0x003E,0x003E
	.hword 0x003F,0x0040,0x0041,0x0042,0x0043,0x0044,0x0045,0x0046
	.hword 0x0047,0x0048,0x0049,0x004A,0x004B,0x004C,0x004D,0x0807
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x001B,0x0807,0x0807
	.hword 0x004D,0x004E,0x004F,0x0050,0x0051,0x0052,0x0053,0x0054
	.hword 0x0055,0x0056,0x0057,0x0058,0x0059,0x005A,0x0807,0x0807
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000

	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x001B,0x0807,0x0807
	.hword 0x0807,0x005B,0x005C,0x005D,0x005E,0x005F,0x0060,0x0061
	.hword 0x0062,0x0063,0x0064,0x0065,0x0066,0x0067,0x0807,0x0807
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x001B,0x0807,0x0807
	.hword 0x0807,0x003E,0x004D,0x0068,0x0069,0x006A,0x006B,0x006C
	.hword 0x006D,0x006E,0x006F,0x003E,0x003E,0x003E,0x0807,0x0807
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000

	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x001B,0x0807,0x0807
	.hword 0x0807,0x0807,0x0807,0x0070,0x0071,0x0072,0x0073,0x0074
	.hword 0x0075,0x0076,0x0077,0x0807,0x0807,0x0807,0x0807,0x0807
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0078,0x0079,0x0079
	.hword 0x0079,0x0079,0x0079,0x007A,0x007A,0x007A,0x007A,0x007B
	.hword 0x007B,0x007A,0x007A,0x0079,0x0079,0x0079,0x0079,0x0079
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000

	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000

	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000

	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000

	.hword 0x007C,0x007C,0x007C,0x007C,0x007C,0x007C,0x007C,0x007C
	.hword 0x007C,0x007C,0x007C,0x007C,0x007C,0x007C,0x007C,0x007C
	.hword 0x007C,0x007C,0x007C,0x007C,0x007C,0x007C,0x007C,0x007C
	.hword 0x007C,0x007C,0x007C,0x007C,0x007C,0x007C,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.section .rodata
	.align	2
	.global menuPal		@ 28 unsigned chars
	.hidden menuPal
menuPal:
	.hword 0x0000,0x1184,0x11A4,0x262B,0x2E4D,0x324F,0x4AF7,0x4EF7
	.hword 0x5318,0x637F,0x677F,0x639F,0x679F

@}}BLOCK(menu)
