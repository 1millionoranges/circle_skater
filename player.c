struct physics_object *player_physics_obj;
void player_init(){
	player_physics_obj = physics_object_init();
}
void player_draw(){
	glColor3f(1.0, 1.0, 1.0);
	camera_draw_circle(&(player_physics_obj->position), player_physics_obj->radius);
}
