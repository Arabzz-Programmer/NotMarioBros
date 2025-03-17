#include <allegro.h>
#include <time.h>

int coll(int ax,int ay, int bx, int by, int ah, int aw, int bh, int bw) {
if(ax + aw > bx && ax < bx + bw && ay + ah > by && ay < by + bh){
return 1;
} else {
return 0;
}
}

int main() {
    allegro_init();
    install_timer();
    install_keyboard();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 600, 480, 0, 0);
    set_window_title("Not Mario Bros");
    
    int cx_0 = 0, cx_1 = 0;
    int afps = 0, kfps = 0, gfps = 0;
    int rolls = 80;
    int direction = 0;
    int x = 300, y = 332, x1 = 190, y1 = 175, x2 = 254, y2 = 175, x3 = 318, y3 = 175, h = 32, w = 32, h1 = 32, w1 = 32, bh = 32, bw = 32, h2 = 32, w2 = 32, h3 = 32, w3 = 32, gx = 100, gy = 332, gh = 32, gw = 32;
    int bx = 95, by = 250;
    int i, yv = 0;
    int isJumping = 0;    
    int jumpHeight = 0;   
    int maxJumpHeight = 75; 
    int sused1 = 0, sused = 0, sused2 = 0;
    int coin = 0;
    int turn = 0;

    BITMAP *background = load_bitmap("Background.bmp", NULL);
    BITMAP *a0 = load_bitmap("a0.bmp", NULL);
    BITMAP *a1 = load_bitmap("a1.bmp", NULL);
    BITMAP *a2 = load_bitmap("a2.bmp", NULL);
    BITMAP *a3 = load_bitmap("a3.bmp", NULL);
    BITMAP *a4 = load_bitmap("a4.bmp", NULL);
    BITMAP *aa0 = load_bitmap("aa0.bmp", NULL);
    BITMAP *aa1 = load_bitmap("aa1.bmp", NULL);
    BITMAP *aa2 = load_bitmap("aa2.bmp", NULL);
    BITMAP *aa3 = load_bitmap("aa3.bmp", NULL);
    BITMAP *aa4 = load_bitmap("aa4.bmp", NULL);
    BITMAP *a = load_bitmap("a0.bmp", NULL);
    BITMAP *g0 = load_bitmap("g0.bmp", NULL);
    BITMAP *g1 = load_bitmap("g1.bmp", NULL);
    BITMAP *g2 = load_bitmap("g2.bmp", NULL);
    BITMAP *g = load_bitmap("g0.bmp", NULL);
    BITMAP *s_block = load_bitmap("s_block0.bmp", NULL);
    BITMAP *s_block0 = load_bitmap("s_block0.bmp", NULL);
    BITMAP *s_block1 = load_bitmap("s_block1.bmp", NULL);
    BITMAP *s1_block = load_bitmap("s_block0.bmp", NULL);
    BITMAP *s2_block = load_bitmap("s_block0.bmp", NULL);
    BITMAP *bricks1 = load_bitmap("bricks.bmp", NULL);
    BITMAP *buffer = create_bitmap(600, 480);

    SAMPLE *music = load_sample("music.wav");
    SAMPLE *jump = load_sample("jump.wav");
    SAMPLE *ssblock = load_sample("s_block.wav");
    SAMPLE *bump = load_sample("bump.wav");

    while(!key[KEY_ESC]) {
           if (afps == 600) {
            afps = 0;
            rolls++;
        }
        if(gx <= 568 && turn == 0) {
        gx++;
        } else if (gx > 568) {
        turn = 1;
        }
        if (turn == 1 && gx > 0) {
        gx--;
        } else if (gx == 0) {
        turn = 0;
        }
        
        if(gfps == 100) {
        g = g1;
        } else if(gfps == 200) {
        g = g0;
        gfps = 0;
        }
        
        if(rolls >= 80) {
            play_sample(music, 255, 128, 1000, FALSE);
            rolls = 0;
        }
        afps++;
        gfps++;
        
        if(key[KEY_D] && !key[KEY_SPACE] && x != 570) {
            direction = 0;
            kfps++;
            if(kfps == 1){
                a = a1;
            } else if (kfps == 50) {
                a = a2; 
            } else if (kfps == 100) { 
                a = a3; 
            } else if (kfps == 150) { 
                kfps = 0;
            }
            x++;
        } else if(key[KEY_A] && !key[KEY_SPACE] && x != 0) {
            direction = 1;
            kfps++;
            if(kfps == 1){
                a = aa1;
            } else if (kfps == 50) {
                a = aa2; 
            } else if (kfps == 100) { 
                a = aa3; 
            } else if (kfps == 150) { 
                kfps = 0;
            }
            x--;
        } else if(key[KEY_SPACE] && !isJumping) {
            play_sample(jump, 255, 128, 1000, FALSE);
            isJumping = 1;
            jumpHeight = 0; 
            if (direction == 0) {
                a = a4;
            } else {
                a = aa4;
            }
        }
        
        if (isJumping) {
            if (jumpHeight < maxJumpHeight) {
                    y -= 2; 
                    jumpHeight++;
                if(coll(x, y, x1, y1, h, w, h1, w1)) {
                    s_block = s_block1;
                    if(sused == 0) {
                play_sample(ssblock, 255, 128, 1000, FALSE);
                y += 32;
                coin++;
                }
                    sused = 1;
                    if(sused2 == 1) {
                    y += 32;
                    }
                }
                if(coll(x, y, x2, y2, h, w, h2, w2)) {
                    s1_block = s_block1;
                    if(sused1 == 0) {
                play_sample(ssblock, 255, 128, 1000, FALSE);
                y += 32;
                coin++;
                }
                    sused1 = 1;
                    if(sused2 == 1) {
                    y += 32;
                    }
                }
                if(coll(x, y, x3, y3, h, w, h3, w3)) {
                    s2_block = s_block1;
                    if(sused2 == 0) {
                play_sample(ssblock, 255, 128, 1000, FALSE);
                y += 32;
                coin++;
                }
                    sused2 = 1;
                    if(sused2 == 1) {
                    y += 32;
                    }
                
                }
                if(coll(x, y, bx, by, h, w, bh, bw)) {
                play_sample(bump, 255, 128, 1000, FALSE);
                y += 32;
                }
                
            } else if (x > bx + bw || y > by + bh || bx > x + w || by > y + h) {
                y += 2;
                } else if (x < bx + bw || bx < x + w) {
                isJumping = 1; 
                }
                if (y >= 332) { 
                    y = 332;
                    isJumping = 0; 
                }
            
        } else if(!key[KEY_A] && !key[KEY_D]) {
            if (direction == 0) {
                a = a0;
            } else {
                a = aa0;
            }
            kfps++;
            if(kfps == 1){
                a = a;
            } else if (kfps == 50) {
                a = a; 
            } else if (kfps == 100) { 
                a = a; 
            } else if (kfps == 150) { 
                kfps = 0;
            }
        }

        clear_to_color(buffer, makecol(0,0,0));
        draw_sprite(buffer, background, 0, 0);
        draw_sprite(buffer, g, gx, gy);
        draw_sprite(buffer, a, x, y);
        draw_sprite(buffer, s_block, x1, y1);
        draw_sprite(buffer, s1_block, x2, y2);
        draw_sprite(buffer, s2_block, x3, y3);
        draw_sprite(buffer, bricks1, bx, by);
        
        if(font) {
            textout_ex(buffer, font, "Coins:", 10, 10, makecol(255,255,255), -1);
            textprintf_ex(buffer, font, 80, 10, makecol(255,255,255), -1, "%d", coin);
        }
        
        draw_sprite(screen, buffer, 0, 0);
    }

    destroy_bitmap(background);
    destroy_bitmap(buffer);
    destroy_bitmap(a0);
    destroy_bitmap(a1);
    destroy_bitmap(a2);
    destroy_bitmap(a3);
    destroy_bitmap(a4);
    destroy_bitmap(aa0);
    destroy_bitmap(aa1);
    destroy_bitmap(aa2);
    destroy_bitmap(aa3);
    destroy_bitmap(aa4);
    destroy_bitmap(a);
    destroy_bitmap(s_block);
    destroy_bitmap(s_block0);
    destroy_bitmap(s_block1);
    destroy_bitmap(s1_block);
    destroy_bitmap(s2_block);
    destroy_bitmap(bricks1);
    destroy_bitmap(g0);
    destroy_bitmap(g1);
    destroy_bitmap(g2);
    destroy_bitmap(g);
    destroy_sample(ssblock);
    destroy_sample(jump);
    destroy_sample(music);
    destroy_sample(bump);
    return 0;
}
END_OF_MAIN();
