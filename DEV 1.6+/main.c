#include <allegro.h>
#include <time.h>

int coll(int ax,int ay, int bx, int by, int ah, int aw, int bh, int bw) {
if(ax + aw > bx && ax < bx + bw && ay + ah > by && ay < by + bh){
return 1;
} else {
return 0;
}
}
#define MAX_CODE_LENGTH 50

volatile int exit_flag = 0;
volatile int code_mode = 0;
char current_code[MAX_CODE_LENGTH] = "";
int code_pos = 0;

int main() {
    allegro_init();
    install_timer();
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 600, 480, 0, 0);
    set_window_title("Not Mario Bros");
    
    int mouse_was_pressed = 0;
    int putting_code = 0;
    int level = 1;
    int noption = 1;
    int cx_0 = 0, cx_1 = 0;
    int framelimiter = 0;
    int afps = 0, kfps = 0, gfps = 0, mfps = 0;
    int rolls = 100;
    int direction = 0;
    int x = 300, y = 332, x1 = 190, y1 = 176, x2 = 254, y2 = 176, x3 = 318, y3 = 176, h = 32, w = 32, h1 = 32, w1 = 32, bh = 32, bw = 32, h2 = 32, w2 = 32, h3 = 32, w3 = 32, gx = 100, gy = 332, gh = 32, gw = 32,bh1 = 32, bw1 = 32;
    int bx = 80, by = 248, bx1 = 670, by1 = 248, backx = 0, backy = 0;
    int i = 1000, yv = 0;
    int realx, realy;
    int isJumping = 0, isGround = 1;   
    int goalx = bx1-16, goaly = by1-64;
    int ioB1 = 0, ioB2 = 0, ioB3 = 0, ioB4 = 0, ioB5 = 0;
    int jumpHeight = 0;   
    int maxJumpHeight = 75;
    int sused1 = 0, sused = 0, sused2 = 0;
    int coin = 0;
    int turn = 0;
    int spacepressed = 0;
    int gameover = 0;
    int gk1 = 0;
    int sp1 = 0;
    char start;
    char code[50];
    int started = 0;
    int skinn = 1;
    int closesc = 0;
// Imagens ----------------------------------------------
    BITMAP *background = load_bitmap("resources/Background.bmp", NULL);
    BITMAP *mousee = load_bitmap("resources/mouse.bmp", NULL);
    BITMAP *options = load_bitmap("resources/options.bmp", NULL);
    BITMAP *code_menu = load_bitmap("resources/code_menu.bmp", NULL);
    BITMAP *finish = load_bitmap("resources/finish.bmp", NULL);
    BITMAP *a0 = load_bitmap("resources/skins/a0.bmp", NULL);
    BITMAP *a1 = load_bitmap("resources/skins/a1.bmp", NULL);
    BITMAP *a2 = load_bitmap("resources/skins/a2.bmp", NULL);
    BITMAP *a3 = load_bitmap("resources/skins/a3.bmp", NULL);
    BITMAP *a4 = load_bitmap("resources/skins/a4.bmp", NULL);
    BITMAP *aa0 = load_bitmap("resources/skins/aa0.bmp", NULL);
    BITMAP *aa1 = load_bitmap("resources/skins/aa1.bmp", NULL);
    BITMAP *aa2 = load_bitmap("resources/skins/aa2.bmp", NULL);
    BITMAP *aa3 = load_bitmap("resources/skins/aa3.bmp", NULL);
    BITMAP *aa4 = load_bitmap("resources/skins/aa4.bmp", NULL);
    BITMAP *a = load_bitmap("resources/skins/a0.bmp", NULL);
    BITMAP *a0a = load_bitmap("resources/skins/a0a.bmp", NULL);
    BITMAP *skin = load_bitmap("resources/skins/a0.bmp", NULL);
    BITMAP *skin_a = load_bitmap("resources/a_skin.bmp", NULL);
    BITMAP *skin_b = load_bitmap("resources/b_skin.bmp", NULL);
    BITMAP *skin_c = load_bitmap("resources/c_skin.bmp", NULL);
    BITMAP *skin_d = load_bitmap("resources/d_skin.bmp", NULL);
    BITMAP *b0 = load_bitmap("resources/skins/b0.bmp", NULL);
    BITMAP *b1 = load_bitmap("resources/skins/b1.bmp", NULL);
    BITMAP *b2 = load_bitmap("resources/skins/b2.bmp", NULL);
    BITMAP *b3 = load_bitmap("resources/skins/b3.bmp", NULL);
    BITMAP *b4 = load_bitmap("resources/skins/b4.bmp", NULL);
    BITMAP *bb0 = load_bitmap("resources/skins/bb0.bmp", NULL);
    BITMAP *bb1 = load_bitmap("resources/skins/bb1.bmp", NULL);
    BITMAP *bb2 = load_bitmap("resources/skins/bb2.bmp", NULL);
    BITMAP *bb3 = load_bitmap("resources/skins/bb3.bmp", NULL);
    BITMAP *bb4 = load_bitmap("resources/skins/bb4.bmp", NULL);
    BITMAP *b = load_bitmap("resources/skins/b0.bmp", NULL);
    BITMAP *b0b = load_bitmap("resources/skins/b0b.bmp", NULL);
    BITMAP *c0 = load_bitmap("resources/skins/c0.bmp", NULL);
    BITMAP *c1 = load_bitmap("resources/skins/c1.bmp", NULL);
    BITMAP *c2 = load_bitmap("resources/skins/c2.bmp", NULL);
    BITMAP *c3 = load_bitmap("resources/skins/c3.bmp", NULL);
    BITMAP *c4 = load_bitmap("resources/skins/c4.bmp", NULL);
    BITMAP *cc0 = load_bitmap("resources/skins/cc0.bmp", NULL);
    BITMAP *cc1 = load_bitmap("resources/skins/cc1.bmp", NULL);
    BITMAP *cc2 = load_bitmap("resources/skins/cc2.bmp", NULL);
    BITMAP *cc3 = load_bitmap("resources/skins/cc3.bmp", NULL);
    BITMAP *cc4 = load_bitmap("resources/skins/cc4.bmp", NULL);
    BITMAP *c = load_bitmap("resources/skins/c0.bmp", NULL);
    BITMAP *c0c = load_bitmap("resources/skins/c0c.bmp", NULL);
    BITMAP *d0 = load_bitmap("resources/skins/d0.bmp", NULL);
    BITMAP *d1 = load_bitmap("resources/skins/d1.bmp", NULL);
    BITMAP *d2 = load_bitmap("resources/skins/d2.bmp", NULL);
    BITMAP *d3 = load_bitmap("resources/skins/d3.bmp", NULL);
    BITMAP *d4 = load_bitmap("resources/skins/d4.bmp", NULL);
    BITMAP *dd0 = load_bitmap("resources/skins/dd0.bmp", NULL);
    BITMAP *dd1 = load_bitmap("resources/skins/dd1.bmp", NULL);
    BITMAP *dd2 = load_bitmap("resources/skins/dd2.bmp", NULL);
    BITMAP *dd3 = load_bitmap("resources/skins/dd3.bmp", NULL);
    BITMAP *dd4 = load_bitmap("resources/skins/dd4.bmp", NULL);
    BITMAP *d = load_bitmap("resources/skins/d0.bmp", NULL);
    BITMAP *d0d = load_bitmap("resources/skins/d0d.bmp", NULL);
    BITMAP *e0 = load_bitmap("resources/skins/e0.bmp", NULL);
    BITMAP *e1 = load_bitmap("resources/skins/e1.bmp", NULL);
    BITMAP *e2 = load_bitmap("resources/skins/e2.bmp", NULL);
    BITMAP *e3 = load_bitmap("resources/skins/e3.bmp", NULL);
    BITMAP *e4 = load_bitmap("resources/skins/e4.bmp", NULL);
    BITMAP *ee0 = load_bitmap("resources/skins/ee0.bmp", NULL);
    BITMAP *ee1 = load_bitmap("resources/skins/ee1.bmp", NULL);
    BITMAP *ee2 = load_bitmap("resources/skins/ee2.bmp", NULL);
    BITMAP *ee3 = load_bitmap("resources/skins/ee3.bmp", NULL);
    BITMAP *ee4 = load_bitmap("resources/skins/ee4.bmp", NULL);
    BITMAP *e = load_bitmap("resources/skins/e0.bmp", NULL);
    BITMAP *e0e = load_bitmap("resources/skins/e0e.bmp", NULL);
    BITMAP *g0 = load_bitmap("resources/g0.bmp", NULL);
    BITMAP *g1 = load_bitmap("resources/g1.bmp", NULL);
    BITMAP *g2 = load_bitmap("resources/g2.bmp", NULL);
    BITMAP *g = load_bitmap("resources/g0.bmp", NULL);
    BITMAP *s_block = load_bitmap("resources/s_block0.bmp", NULL);
    BITMAP *s_block0 = load_bitmap("resources/s_block0.bmp", NULL);
    BITMAP *s_block1 = load_bitmap("resources/s_block1.bmp", NULL);
    BITMAP *s1_block = load_bitmap("resources/s_block0.bmp", NULL);
    BITMAP *s2_block = load_bitmap("resources/s_block0.bmp", NULL);
    BITMAP *bricks1 = load_bitmap("resources/bricks.bmp", NULL);
    BITMAP *menu = load_bitmap("resources/menu.bmp", NULL);
    BITMAP *goal = load_bitmap("resources/goal.bmp", NULL);
    BITMAP *skin_menu = load_bitmap("resources/skin_menu.bmp", NULL);
    BITMAP *buffer = create_bitmap(600, 480);
// Músicas ----------------------------------------------
    SAMPLE *music = load_sample("resources/samples/music.wav");
    SAMPLE *jump = load_sample("resources/samples/jump.wav");
    SAMPLE *ssblock = load_sample("resources/samples/s_block.wav");
    SAMPLE *bump = load_sample("resources/samples/bump.wav");
    SAMPLE *die = load_sample("resources/samples/die.wav");
    SAMPLE *select = load_sample("resources/samples/select.wav");
    SAMPLE *goomba_stomp = load_sample("resources/samples/goomba_stomp.wav");
    SAMPLE *menu_song = load_sample("resources/samples/menu_song.wav");
realx = x;
    while(1) {
    if(started != 1 && started != 3 && started != 5) {
    mfps++;
    if(mfps == 1) {
    play_sample(menu_song, 255, 128, 1000, FALSE);
} else if (mfps >= 7150) {
mfps = 0;
}

}
    if(framelimiter == 1) {
    rest(4);
}
    if(closesc == 1) {
    if(key[KEY_ESC]) {
    break;
}
} else if (closesc == 0) {

}
    
if(framelimiter == 1) {
maxJumpHeight = 35; 
} else if(framelimiter == 0) {
maxJumpHeight = 75;
}
    if(gameover == 0 && started == 0) {
    
// Menu
if(key[KEY_1]) {
started = 1;
play_sample(select, 255, 128, 1000, FALSE);
} else if(key[KEY_2]) {
started = 2;
play_sample(select, 255, 128, 1000, FALSE);
} else if(key[KEY_3]) {
started = 4;
} else if(key[KEY_4]) {
started = 6;
} else if(key[KEY_5]) {
break;
}
} else if (gameover == 0 && started == 1) {
       stop_sample(menu_song);
           if (afps == 600) {
            afps = 0;
            rolls++;
            if(gk1 == 1) {
            gy = 1000;
            }
        }
        // Inimigo
        if(gk1 == 0) {
        if(gx <= 568 && turn == 0 && g != g2) {
        if(framelimiter == 1) {
        gx += 2;
        } else if (framelimiter == 0) {
        gx++;
        }
        } else if (gx > 568) {
        turn = 1;
        }
        if (turn == 1 && gx > 0) {
        if(framelimiter == 1) {
        gx -= 2;
        } else if (framelimiter == 0) {
        gx--;
        }
        } else if (gx == 0) {
        turn = 0;
        }
         }
        if(framelimiter == 1) {
        if(gfps == 50 && g != g2) {
        g = g1;
        } else if(gfps == 100 && g != g2) {
        g = g0;
        gfps = 0;
        }
        } else if (framelimiter == 0) {
        if(gfps == 100 && g != g2) {
        g = g1;
        } else if(gfps == 200 && g != g2) {
        g = g0;
        gfps = 0;
        }
        }
        if(x > gx-29 && x < gx+29 && y > gy-16 && y < gy+32 && gk1 == 0) {
        gameover = 1;
        stop_sample(music);
        }
        if(x > gx-29 && x < gx+29 && y > gy-32 && y < gy-15 && gk1 == 0) {
        afps = 0;
        y -= 32;
        gy += 16;
        g = g2;
        gk1 = 1;
        if(sp1 == 0) {
        sp1 = 1;
        play_sample(goomba_stomp, 255, 128, 1000, FALSE);
        }
        }
// Música de fundo
        if(rolls >= 100) {
            play_sample(music, 255, 128, 1000, FALSE);
            rolls = 0;
        }
        afps++;
        gfps++;
// Controles
        if(key[KEY_D] && !key[KEY_SPACE] && !isJumping && x < 570) {
            direction = 0;
            kfps++;
            if(framelimiter == 1) {
            if(kfps == 1){
                if(skinn == 1) {
                a = a1;
            } else if (skinn == 2) {
                a = b1;
            } else if (skinn == 3) {
                a = c1;
            } else if (skinn == 4) {
                a = d1;
            } else if (skinn == 5) {
                a = e1;
            }
            } else if (kfps == 25) {
                if(skinn == 1) {
                a = a2;
            } else if (skinn == 2) {
                a = b2;
            } else if (skinn == 3) {
                a = c2;
            } else if (skinn == 4) {
                a = d2;
            } else if (skinn == 5) {
                a = e2;
            }
            } else if (kfps == 50) { 
                if(skinn == 1) {
                a = a3;
            } else if (skinn == 2) {
                a = b3;
            } else if (skinn == 3) {
                a = c3;
            } else if (skinn == 4) {
                a = d3;
            } else if (skinn == 5) {
                a = e3;
            }
            } else if (kfps == 75) { 
                kfps = 0;
            }
            if(realx <= 1168) {
            realx += 2;
            }
            if(x <= 538) {
            x += 2;
            } else if(backx > -600) {
            backx -= 2;
            x1 -= 2;
            x2 -= 2;
            x3 -= 2;
            bx -= 2;
            bx1 -= 2;
            gx -= 2;
            }
            } else if (framelimiter == 0) {
            if(kfps == 1){
                if(skinn == 1) {
                a = a1;
            } else if (skinn == 2) {
                a = b1;
            } else if (skinn == 3) {
                a = c1;
            } else if (skinn == 4) {
                a = d1;
            } else if (skinn == 5) {
                a = e1;
            }
            } else if (kfps == 50) {
                if(skinn == 1) {
                a = a2;
            } else if (skinn == 2) {
                a = b2;
            } else if (skinn == 3) {
                a = c2;
            } else if (skinn == 4) {
                a = d2;
            } else if (skinn == 5) {
                a = e2;
            }
            } else if (kfps == 100) { 
                if(skinn == 1) {
                a = a3;
            } else if (skinn == 2) {
                a = b3;
            } else if (skinn == 3) {
                a = c3;
            } else if (skinn == 4) {
                a = d3;
            } else if (skinn == 5) {
                a = e3;
            }
            } else if (kfps == 150) { 
                kfps = 0;
            }
            if(realx <= 1168) {
            realx++;
            }
            if(x <= 538) {
            x++;
            } else if(backx > -600) {
            backx--;
            x1--;
            x2--;
            x3--;
            bx--;
            bx1--;
            gx--;
            }
            }
        } else if(key[KEY_A] && !key[KEY_SPACE] && !isJumping && x != 0) {
            direction = 1;
            kfps++;
            if(framelimiter == 1) {
            if(kfps == 1){
                if(skinn == 1) {
                a = aa1;
            } else if (skinn == 2) {
                a = bb1;
            } else if (skinn == 3) {
                a = cc1;
            } else if (skinn == 4) {
                a = dd1;
            } else if (skinn == 5) {
                a = ee1;
            }
            } else if (kfps == 25) {
                if(skinn == 1) {
                a = aa2;
            } else if (skinn == 2) {
                a = bb2;
            } else if (skinn == 3) {
                a = cc2;
            } else if (skinn == 4) {
                a = dd2;
            } else if (skinn == 5) {
                a = ee2;
            }
            } else if (kfps == 50) { 
                if(skinn == 1) {
                a = aa3;
            } else if (skinn == 2) {
                a = bb3;
            } else if (skinn == 3) {
                a = cc3;
            } else if (skinn == 4) {
                a = dd3;
            } else if (skinn == 5) {
                a = ee3;
            }
            } else if (kfps == 75) { 
                kfps = 0;
            }
            if(realx > 32) {
            realx -= 2;
            }
            if(x >= 32) {
            x -= 2;
            } else if(backx < 0) {
            backx += 2;
            x1 += 2;
            x2 += 2;
            x3 += 2;
            bx += 2;
            bx1 += 2;
            gx += 2;
            
            }
            } else if (framelimiter == 0) {
            if(kfps == 1){
                if(skinn == 1) {
                a = aa1;
            } else if (skinn == 2) {
                a = bb1;
            } else if (skinn == 3) {
                a = cc1;
            } else if (skinn == 4) {
                a = dd1;
            } else if (skinn == 5) {
                a = ee1;
            }
            } else if (kfps == 50) {
                if(skinn == 1) {
                a = aa2;
            } else if (skinn == 2) {
                a = bb2;
            } else if (skinn == 3) {
                a = cc2;
            } else if (skinn == 4) {
                a = dd2;
            } else if (skinn == 5) {
                a = ee2;
            }
            } else if (kfps == 100) { 
                if(skinn == 1) {
                a = aa3;
            } else if (skinn == 2) {
                a = bb3;
            } else if (skinn == 3) {
                a = cc3;
            } else if (skinn == 4) {
                a = dd3;
            } else if (skinn == 5) {
                a = ee3;
            }
            } else if (kfps == 150) { 
                kfps = 0;
                }
                if(realx > 32) {
            realx--;
            }
            if(x >= 32) {
            x--;
            } else if(backx < 0) {
            backx++;
            x1++;
            x2++;
            x3++;
            bx++;
            bx1++;
            gx++;
            }
            }
        } else if(key[KEY_SPACE] && !isJumping) {
            play_sample(jump, 255, 128, 1000, FALSE);
            isJumping = 1;
            jumpHeight = 0; 
            isGround = 0;
            spacepressed = 1;
            if (direction == 0) {
                if(skinn == 1) {
                a = a4;
            } else if (skinn == 2) {
                a = b4;
            } else if (skinn == 3) {
                a = c4;
            } else if (skinn == 4) {
                a = d4;
            } else if (skinn == 5) {
                a = e4;
            }
            } else {
                if(skinn == 1) {
                a = aa4;
            } else if (skinn == 2) {
                a = bb4;
            } else if (skinn == 3) {
                a = cc4;
            } else if (skinn == 4) {
                a = dd4;
            } else if (skinn == 5) {
                a = ee4;
            }
            }
        }
// Colisão/Pulo
        if (isJumping) {
    if (jumpHeight < maxJumpHeight) {
    if(framelimiter == 1) {
    if(key[KEY_A] && x > 32) {
    x -= 2;
    realx -= 2;
} else if (key[KEY_D] && x < 536) {
x += 2;
realx += 2;
       }
        y -= 4;
        } else if (framelimiter == 0) {
        if(key[KEY_A] && x > 32) {
    x--;
    realx--;
} else if (key[KEY_D] && x < 536) {
x++;
realx++;
       }
        y -= 2;
        }
        jumpHeight++;
        
        if (coll(x, y, x1, y1, h, w, h1, w1)) {
            if (sused == 0) {
                      s_block = s_block1;
                play_sample(ssblock, 255, 128, 1000, FALSE);
                y += 32;
                coin++;
            }
            sused = 1;
        }
        
        if (coll(x, y, x2, y2, h, w, h2, w2)) {
            
            if (sused1 == 0) {
                       s1_block = s_block1;
                play_sample(ssblock, 255, 128, 1000, FALSE);
                y += 32;
                coin++;
            }
            sused1 = 1;
        }
        
        if (coll(x, y, x3, y3, h, w, h3, w3)) {
            
            if (sused2 == 0) {
                       s2_block = s_block1;
                play_sample(ssblock, 255, 128, 1000, FALSE);
                y += 32;
                coin++;
            }
            sused2 = 1;
        }
        
        if (coll(x, y, bx, by, h, w, bh, bw)) {
            play_sample(bump, 255, 128, 1000, FALSE);
            y += 32;
        }
        if (coll(x, y, bx1, by1, h, w, bh1, bw1)) {
            play_sample(bump, 255, 128, 1000, FALSE);
            y += 32;
        }
    } else {
    if(framelimiter == 1) {
    if(key[KEY_A] && x > 32) {
    x -= 2;
    realx -= 2;
} else if (key[KEY_D] && x < 536) {
x += 2;
realx += 2;
}
        y += 4;
        } else if(framelimiter == 0) {
        if(key[KEY_A] && x > 32) {
    x--;
    realx--;
} else if (key[KEY_D] && x < 536) {
x++;
realx++;
}
        y += 2;
        }
    }
    
    if (y >= 332) { 
        y = 332;
        isJumping = 0; 
        isGround = 1;
    }
} else if (!key[KEY_A] && !key[KEY_D]) {
    if (direction == 0) {
        if (skinn == 1) {
            a = a0;
        } else if (skinn == 2) {
            a = b0;
        } else if (skinn == 3) {
            a = c0;
        } else if (skinn == 4) {
            a = d0;
        } else if (skinn == 5) {
        a = e0;
        }
    } else if (direction == 1) {
        if (skinn == 1) {
            a = aa0;
        } else if (skinn == 2) {
            a = bb0;
        } else if (skinn == 3) {
            a = cc0;
        } else if (skinn == 4) {
            a = dd0;
        } else if (skinn == 5) {
                a = ee0;
        }
    }
}
// Gravidade
                            //Tijolo
        if (x > bx-29 && x < bx+29 && y > by-29 && y < by) {
                isJumping = 0;
                ioB1 = 1;
                } else if (x <= bx-29 || x >= bx+29) {
                ioB1 = 0;
                }
                //Tijolo 2
        if (x > bx1-29 && x < bx1+29 && y == by1-29 && y > by1-29 && y < by1) {
                isJumping = 0;
                ioB5 = 1;
                } else if (x <= bx1-29 || x >= bx1+29) {
                ioB5 = 0;
                }
                       // Interrogação 1
        if (x > x1-29 && x < x1+29 && y == 144) {
                isJumping = 0;
                ioB2 = 1;
                } else if (x < x1-29 || x > x1+29 && y > y1-29 && y < y1) {
                ioB2 = 0;  
                       }
                       // Interrogação 2
        if (x > x2-29 && x < x2+29 && y > y2-29 && y < y2) {
                isJumping = 0;
                ioB3 = 1;
                } else if (x < x2-29 || x > x2+29) {
                ioB3 = 0;  
                       }
                       // Interrogação 3
        if (x > x3-29 && x < x3+29 && y > y3-29 && y < y3) {
                isJumping = 0;
                ioB4 = 1;
                } else if (x < x3-29 || x > x3+29) {
                ioB4 = 0;  
                       }
                
                // Gravidade ao sair do bloco
        if(isJumping == 0 && isGround == 0 && ioB1 == 0 && ioB2 == 0 && ioB3 == 0 && ioB4 == 0 && ioB5 == 0) {
                isJumping = 1;
                }
        // Impedir de ficar dentro do bloco


if (realx > goalx - 29 && realx < goalx + 29 && y > goaly && y < goaly + 64) {
coin++;
    started = 3;
}
// Tijolo
if (x > bx - 29 && x < bx + 29 && y < by + 32 && y > by - 32) {
    if (y <= by) {
        y--;
    } else if (y > by) {
        y++;
    }
}
// Tijolo 2
if (x > bx1 - 29 && x < bx1 + 29 && y < by1 + 32 && y > by1 - 32) {
    if (y <= by1) {
        y--;
    } else if (y > by1) {
        y++;
    }
}

// Interrogação 1
if (x > x1 - 29 && x < x1 + 29 && y < y1 + 32 && y > y1 - 32) {
        if (y <= y1) {
            y--;
        } else if (y > y1) {
            y++;
        }
    }


// Interrogação 2
if (x > x2 - 29 && x < x2 + 29 && y < y2 + 32 && y > y2 - 32) {
   
        if (y <= y2) {
            y--;
        } else if (y > y2) {
            y++;
        }
    }


// Interrogação 3
if (x > x3 - 29 && x < x3 + 29 && y < y3 + 32 && y > y3 - 32) {
        if (y <= y3) {
            y--;
        } else if (y > y3) {
            y++;
        }
    }

// Não pulo
if(!key[KEY_SPACE]) {
spacepressed = 0;
}
} else if (gameover == 1) {
if(skinn == 1) {
a = a0a;
} else if (skinn == 2) {
a = b0b;
} else if (skinn == 3) {
a = c0c;
} else if (skinn == 4) {
a = d0d;
} else if (skinn == 5) {
a = e0e;
}
if(i == 1000) {
i = 0;
play_sample(die, 255, 128, 1000, FALSE);
}
if(i <= 100) {
y -= 1;
i++;
} 
if(i <= 150 && i > 100) {
y -= 2;
i++;
} 
if(i > 150 && i <= 250) {
y += 1;
i++;
} if (i > 250 && i <= 400) {
y += 2;
i++;
}
if(i > 400) {
rest(2000);
break;
}
}

        clear_to_color(buffer, makecol(0,0,0));
        if(started == 1 || started == 0) {
        draw_sprite(buffer, background, backx, backy);
        } else if (started == 2) {
        draw_sprite(buffer, skin_menu, 0, 0);
// Skin
if(key[KEY_D] && skinn != 4) {
play_sample(select, 255, 128, 1000, FALSE);
skinn++;
rest(100);
} else if(key[KEY_A] && skinn != 1) {
play_sample(select, 255, 128, 1000, FALSE);
skinn--;
rest(100);
}
if(skinn == 1) {
draw_sprite(buffer, skin_a, 235, 200);
} else if (skinn == 2) {
draw_sprite(buffer, skin_b, 235, 200);
} else if (skinn == 3) {
draw_sprite(buffer, skin_c, 235, 200);
} else if (skinn == 4) {
draw_sprite(buffer, skin_d, 235, 200);
}
if(key[KEY_B]) {
play_sample(select, 255, 128, 1000, FALSE);
started = 0;
}
}
// Colocando as imagens na tela
        if(started == 1) {
        draw_sprite(buffer, g, gx, gy);
        draw_sprite(buffer, a, x, y);
        draw_sprite(buffer, s_block, x1, y1);
        draw_sprite(buffer, s1_block, x2, y2);
        draw_sprite(buffer, s2_block, x3, y3);
        draw_sprite(buffer, bricks1, bx, by);
        draw_sprite(buffer, bricks1, bx1, by1);
        draw_sprite(buffer, goal, bx1-16, by1-64);
        }
// Imprimindo
        if(font) {
        if(started == 1) {
            textout_ex(buffer, font, "Coins:", 10, 10, makecol(255,255,255), -1);
            textprintf_ex(buffer, font, 80, 10, makecol(255,255,255), -1, "%d", coin);
            // debug
            /*
            textprintf_ex(buffer, font, 100, 10, makecol(255,255,255), -1, "%d", x);
            textprintf_ex(buffer, font, 150, 10, makecol(255,255,255), -1, "%d", y);
            textprintf_ex(buffer, font, 200, 10, makecol(255,255,255), -1, "%d", bx);
            textprintf_ex(buffer, font, 250, 10, makecol(255,255,255), -1, "%d", by);
            textprintf_ex(buffer, font, 300, 10, makecol(255,255,255), -1, "%d", isJumping);
            textprintf_ex(buffer, font, 350, 10, makecol(255,255,255), -1, "%d", isGround);
            textprintf_ex(buffer, font, 400, 10, makecol(255,255,255), -1, "%d", ioB1);
            textprintf_ex(buffer, font, 450, 10, makecol(255,255,255), -1, "%d", ioB2);
            textprintf_ex(buffer, font, 500, 10, makecol(255,255,255), -1, "%d", ioB3);
            textprintf_ex(buffer, font, 550, 10, makecol(255,255,255), -1, "%d", ioB4);
            textprintf_ex(buffer, font, 570, 10, makecol(255,255,255), -1, "%d", ioB5);
            textprintf_ex(buffer, font, 100, 20, makecol(255,255,255), -1, "%d", spacepressed);
            textprintf_ex(buffer, font, 150, 20, makecol(255,255,255), -1, "%d", gameover);
            textprintf_ex(buffer, font, 200, 20, makecol(255,255,255), -1, "%d", i);
            textprintf_ex(buffer, font, 100, 30, makecol(255,255,255), -1, "%d", goaly);
            textprintf_ex(buffer, font, 150, 30, makecol(255,255,255), -1, "%d", goaly);
            textprintf_ex(buffer, font, 200, 30, makecol(255,255,255), -1, "%d", goaly + 128);
            textprintf_ex(buffer, font, 250, 30, makecol(255,255,255), -1, "%d", goalx);
            textprintf_ex(buffer, font, 300, 30, makecol(255,255,255), -1, "%d", realx);
            textprintf_ex(buffer, font, 350, 30, makecol(255,255,255), -1, "%d", mouse_x);
            textprintf_ex(buffer, font, 400, 30, makecol(255,255,255), -1, "%d", mouse_y);
            */
            // debug end
            } else if(started == 0) {
            textout_ex(buffer, font, "1. start", 200, 280, makecol(255,255,255), -1);
            textout_ex(buffer, font, "2. change skin", 200, 290, makecol(255,255,255), -1);
            textout_ex(buffer, font, "3. options", 200, 300, makecol(255,255,255), -1);
            textout_ex(buffer, font, "4. put codes", 200, 310, makecol(255,255,255), -1);
            textout_ex(buffer, font, "5. exit", 200, 320, makecol(255,255,255), -1);
            draw_sprite(buffer, menu, 125, 100);
} else if(started == 3) {
    draw_sprite(buffer, finish, 0, 0);
    draw_sprite(buffer, mousee, mouse_x, mouse_y);
    stop_sample(music);
    
    if (mouse_b & 1) {
        mouse_was_pressed = 1;
    } 
    else if (mouse_was_pressed && !(mouse_b & 1)) {
        if(mouse_x > 200 && mouse_x < 400 && mouse_y > 300 && mouse_y < 400) {
            s_block = s_block0;
            s1_block = s_block0; 
            s2_block = s_block0;
            sused = 0;
            sused1 = 0;
            sused2 = 0;
            x = 300;
            y = 332;
            realx = 300;
            backx = 0;
            g = g0;
            gk1 = 0;
            if(level == 1) {
                gy = 332;
                gx = 33;
                x1 = 222;
                x2 = 254;
                x3 = 286;
                bx = 112;
                bx1 = 702;
                goalx += 32;
                gfps = 0;
                if(coin > 0) coin--;
            }
            level++;
            play_sample(music, 255, 128, 1000, FALSE);
            play_sample(select, 255, 128, 1000, FALSE);
            
            started = 1;
        }
        mouse_was_pressed = 0;
    }
if(key[KEY_ESC]) {
break;
}
} else if(started == 4) {

if(key[KEY_S]) {
if(noption != 2) {
noption++;
}
} else if (key[KEY_W]) {
if(noption != 1) {
noption--;
}
}

draw_sprite(buffer, options, 0, 0);
if(noption == 1) {
textout_ex(buffer, font, "> Frame Limiter: ", 100, 200, makecol(255,255,255), -1);
textout_ex(buffer, font, "  Close the game by pressing ESC: ", 100, 225, makecol(255,255,255), -1);
} else if (noption == 2) {
textout_ex(buffer, font, "  Frame Limiter: ", 100, 200, makecol(255,255,255), -1);
textout_ex(buffer, font, "> Close the game by pressing ESC: ", 100, 225, makecol(255,255,255), -1);
}
if(framelimiter == 0) {
if(key[KEY_ENTER] && noption == 1) {
rest(32);
framelimiter = 1;
}
textout_ex(buffer, font, "False", 250, 200, makecol(255,255,255), -1);
} else if (framelimiter == 1) {
if(key[KEY_ENTER] && noption == 1) {
rest(32);
framelimiter = 0;
}
textout_ex(buffer, font, "True", 250, 200, makecol(255,255,255), -1);
}
if(closesc == 0) {
if(key[KEY_ENTER] && noption == 2) {
rest(32);
closesc = 1;
}
textout_ex(buffer, font, "False", 375, 225, makecol(255,255,255), -1);
} else if (closesc == 1) {
if(key[KEY_ENTER] && noption == 2) {
rest(32);
closesc = 0;
}
textout_ex(buffer, font, "True", 375, 225, makecol(255,255,255), -1);
}
if(key[KEY_B]) {
started = 0;
}
} else if (started == 6) {
    while (!exit_flag) {
        clear_to_color(buffer, makecol(0, 0, 0));
        draw_sprite(buffer, code_menu, 0, 0);
        
        if (keypressed()) {
            int key = readkey() >> 8;
            
            if (key == KEY_ESC) {
                if (code_mode) {
                    code_mode = 0;
                    code_pos = 0;
                    current_code[0] = '\0';
                } else {
                    started = 0;
                    break;
                }
            }
            if (key == KEY_ENTER && !code_mode) {
                code_mode = 1;
                code_pos = 0;
                current_code[0] = '\0';
                play_sample(select, 255, 128, 1000, FALSE);
            }
            
            if (key == KEY_INSERT && code_mode) {
                play_sample(select, 255, 128, 1000, FALSE);
                
                if (strcmp(current_code, "billiejean") == 0) {
                    textout_ex(buffer, font, "VALID CODE!", SCREEN_W/2 - 50, SCREEN_H/2 + 30, makecol(0, 255, 0), -1);
                    skinn = 5;
                } else {
                    textout_ex(buffer, font, "INVALID CODE!", SCREEN_W/2 - 60, SCREEN_H/2 + 30, makecol(255, 0, 0), -1);
                }
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(1000);
                
                code_mode = 0;
                code_pos = 0;
                current_code[0] = '\0';
            }
            if (code_mode && key >= KEY_A && key <= KEY_Z && code_pos < MAX_CODE_LENGTH - 1) {
                current_code[code_pos++] = 'a' + (key - KEY_A);
                current_code[code_pos] = '\0';
                play_sample(select, 255, 128, 1000, FALSE);
            }
        }
        if (!code_mode) {
            textout_ex(buffer, font, "Press ENTER to enter code mode", SCREEN_W/2 - 120, 90, makecol(255, 255, 255), -1);
            textout_ex(buffer, font, "Press ESC to return to menu", SCREEN_W/2 - 110, 100, makecol(255, 255, 255), -1);
        } else {
            textout_ex(buffer, font, "Type code and press INSERT", SCREEN_W/2 - 100, 100, makecol(255, 255, 0), -1);
            textout_ex(buffer, font, "Press ESC to cancel", SCREEN_W/2 - 80, 110, makecol(255, 255, 0), -1);
            
            if (code_pos > 0) {
                textout_ex(buffer, font, current_code, SCREEN_W/2 - (code_pos * 4), 200, makecol(255, 255, 0), -1);
            }
            }
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        rest(10);
    }
}
}
        draw_sprite(screen, buffer, 0, 0);
        
    }
// Destruindo
    destroy_bitmap(background);
    destroy_bitmap(mousee);
    destroy_bitmap(finish);
    destroy_bitmap(options);
    destroy_bitmap(code_menu);
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
    destroy_bitmap(b);
    destroy_bitmap(b0);
    destroy_bitmap(b1);
    destroy_bitmap(b2);
    destroy_bitmap(b3);
    destroy_bitmap(b4);
    destroy_bitmap(bb0);
    destroy_bitmap(bb1);
    destroy_bitmap(bb2);
    destroy_bitmap(bb3);
    destroy_bitmap(bb4);
    destroy_bitmap(a);
    destroy_bitmap(c0);
    destroy_bitmap(c1);
    destroy_bitmap(c2);
    destroy_bitmap(c3);
    destroy_bitmap(c4);
    destroy_bitmap(cc0);
    destroy_bitmap(cc1);
    destroy_bitmap(cc2);
    destroy_bitmap(cc3);
    destroy_bitmap(cc4);
    destroy_bitmap(c);
    destroy_bitmap(d0);
    destroy_bitmap(d1);
    destroy_bitmap(d2);
    destroy_bitmap(d3);
    destroy_bitmap(d4);
    destroy_bitmap(dd0);
    destroy_bitmap(dd1);
    destroy_bitmap(dd2);
    destroy_bitmap(dd3);
    destroy_bitmap(dd4);
    destroy_bitmap(d);
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
    destroy_bitmap(goal);
    destroy_bitmap(menu);
    destroy_sample(ssblock);
    destroy_sample(jump);
    destroy_sample(music);
    destroy_sample(bump);
    destroy_sample(die);
    destroy_sample(goomba_stomp);
    destroy_sample(menu_song);
    exit(1);
}
END_OF_MAIN();
