RANDOMIZE TIMER
10 COLOR 15, 1: SCREEN 9: CLS : KEY OFF: sc = 1000
15 FOR r = 1 TO 400 STEP 3
rn = INT(RND * 15)
20 CIRCLE (320, 170), r, rn
30 NEXT r
40 FOR x = 320 TO 30 STEP -1
rn = INT(RND * 15)
50 LINE (x, 0)-(640 - x, 350), rn
51 LINE (640 - x, 0)-(x, 350), rn
52 LINE (x + 320, 0)-(x + 320, 350), rn
53 LINE (320 - x, 0)-(320 - x, 350), rn
60 NEXT x
999 um = INT(RND * 1000)
1000 b = INT(RND * 15): b1 = INT(RND * 15): IF b = b1 THEN 1000
COLOR b, b1: LOCATE 5, 10: PRINT "G u e s s    G a m e    V2.00"
1010 b = INT(RND * 15): b1 = INT(RND * 15): IF b = b1 THEN 1010
COLOR b, b1: LOCATE 7, 10: PRINT "M a k i n g : X i e J i l e i"
1020 b = INT(RND * 15): b1 = INT(RND * 15): IF b = b1 THEN 1020
COLOR b, b1: LOCATE 3, 60: PRINT "Score = "; USING "##########"; sc
1030 b = INT(RND * 15): b1 = INT(RND * 15): IF b = b1 THEN 1030
COLOR b, b1: LOCATE 12, 20: INPUT "What's me?(0~1000)", n
1040 b = I��"HL��g� ! g�c'�'�@��HL��g� ! g�g�g�'�c'���g�#���8Ig�g�g� '���g�� �'�  ��c�g��g�`��c gPRINT "T o o   B i g....": sc = sc - 10
IF n < um THEN LOCATE 15, 20: COLOR b, b1: PRINT "T o o   Small....": sc = sc - 10
IF n = um THEN LOCATE 15, 20: COLOR b, b1: PRINT "Ha!You're right!!": sc = sc + 500: GOTO 999
IF sc <= 0 THEN LOCATE 15, 20: COLOR b, b1: PRINT "Ha!Yor're Fail!!!": END
GOTO 1000

SUB colo
b = INT(RND * 15): b1 = INT(RND * 15)
END SUB

