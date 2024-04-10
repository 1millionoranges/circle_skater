#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include<time.h>
#include "vector.c"
#include "collision.c"
#include "physics.c"
#include "camera.c"
#include "halfpipe.c"
#include "player.c"
char keys_pressed[256];
struct timespec *current_time;
struct timespec *last_time;

void draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	halfpipe_draw();
	player_draw();
	glFlush();
}
void update(float delta, char* keys_pressed){
	if(delta > 0.2){
		printf("low fr\n");
	}
	player_update(delta, keys_pressed);
	physics_update(delta);
	halfpipe_update(delta);
}
void display(){
    clock_gettime(CLOCK_MONOTONIC, current_time);
    int current_nanoseconds = current_time->tv_nsec;
    int current_seconds = current_time->tv_sec;
    int last_nanoseconds = last_time->tv_nsec;
    int last_seconds = last_time->tv_sec;
    float delta = (current_seconds - last_seconds) + 0.000000001 * (current_nanoseconds - last_nanoseconds);
	if(delta < 0.01667){return;}
	draw();
	update(delta, keys_pressed);
	clock_gettime(CLOCK_MONOTONIC, last_time);
//	last_time = current_time;
}

void on_idle(){
//	glutPostRedisplay();
}

void timer_loop(int a){
	glutPostRedisplay();
	glutTimerFunc(16.668, timer_loop, 0);
}

void init(){
	//&keys_pressed = malloc(4 * 20);
	last_time = malloc(sizeof(struct timespec));
	current_time = malloc(sizeof(struct timespec));
    clock_gettime(CLOCK_MONOTONIC, last_time);
	physics_init();
	camera_init();
	halfpipe_init();
    	player_init();
	glutTimerFunc(16.668, timer_loop, 0);
}

void remove_key(unsigned char key, int x, int y){
	keys_pressed[key] = 0;
}

void print_keys(){
	printf("keys: ");
	for(int i = 0; i < 256; i++){
		if(keys_pressed[i]){
			printf(" %c", i);
		}
	}
	printf("\n");
}

void add_key(unsigned char key, int x, int y){
	if(key == 27)
	exit(0);
	keys_pressed[key] = 1;
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	init();
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(500,500);
	glutCreateWindow("Fireswinger");
	glutDisplayFunc(display);
	glutKeyboardFunc(add_key);
	glutIdleFunc(on_idle);
	glutKeyboardUpFunc(remove_key);
	glutMainLoop();
	return 0;
}
	
