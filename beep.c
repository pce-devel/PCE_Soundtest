/*
 *
 * beep - try to manipulate the 4 settings for volume in order to see
 *        which ones (or whether all) cause a "pop" style volume spike
 *
*/


#include "huc.h"

#define STATUS_LINE   3


   char glb_bal;
   char chn_bal;
   char ctrl;

#asm

_beepsetup:
    lda #2
    sta psg_ch
    lda #$FF
    sta psg_mainvol
    lda #$1C	; 4KHz
    sta psg_freqlo
    stz psg_freqhi
    lda	#$0
    sta psg_ctrl
    lda #$1F
    ldx #16
.loop:
    sta psg_wavebuf
    dex
    bne .loop
    lda #$0
    ldx #16
.loop1:
    sta psg_wavebuf
    dex
    bne .loop1
    lda #$FF
    sta psg_pan
    lda #$9f
    sta psg_ctrl
    rts

_beepoff:
    lda #$0
    sta psg_ctrl
    rts

_beepon:
    lda #$9f
    sta psg_ctrl
    rts

#endasm



char a;


main()
{
   set_color(0,0);
   set_color(1,511);

   beepsetup();
   beepoff();

   while (1) {
      vsync(0);
      a = joy(0);

      if (a & JOY_DOWN) {
         put_string("D", 1, STATUS_LINE);
	 ctrl = (ctrl & 0x80);
      } else {
         put_string(" ", 1, STATUS_LINE);
	 ctrl = (ctrl & 0x80) | 0x1f;
      }

      if (a & JOY_SEL) {
         put_string("S", 2, STATUS_LINE);
	 ctrl = (ctrl & 0x1f);
      } else {
         put_string(" ", 2, STATUS_LINE);
	 ctrl = (ctrl & 0x1f) | 0x80;
      }

      if (a & JOY_II) {
         put_string("2", 3, STATUS_LINE);
	 glb_bal = 0;
      } else {
         put_string(" ", 3, STATUS_LINE);
	 glb_bal = 255;
      }

      if (a & JOY_I) {
         put_string("1", 4, STATUS_LINE);
	 chn_bal = 0;
      } else {
         put_string(" ", 4, STATUS_LINE);
	 chn_bal = 255;
      }
#asm
      lda _glb_bal
      sta psg_mainvol
      lda _chn_bal
      sta psg_pan
      lda _ctrl
      sta psg_ctrl

#endasm
   }

   return;
}
