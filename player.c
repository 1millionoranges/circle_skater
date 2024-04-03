struct physics_object *player_physics_obj;
float player_size = .2;
void player_init(){
	player_physics_obj = physics_object_init();
}
void player_draw(){
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	for(float angle = 0; angle < 2 * M_PI; angle += 0.2){
		float x = player_size * cos(angle) + player_physics_obj->position.x;
		float y = player_size * sin(angle) + player_physics_obj->position.y;
		glVertex2d(x, y);
	}
	glEnd();
	glBegin(GL_POINTS);
	glVertex2d(0,0);
	glEnd();
}
