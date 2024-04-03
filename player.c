struct physics_object *player_physics_obj;
float player_size = .2;
void player_init(){
	player_physics_obj = physics_object_init();
}
void player_draw(){
	camera_draw_circle(&player_physics_obj->position, player_size);
}
