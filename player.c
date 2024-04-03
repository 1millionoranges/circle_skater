struct physics_object *player_physics_obj;
float player_boost_magnitude = 5;
void player_init(){
	player_physics_obj = physics_object_init();
}
void player_draw(){
	glColor3f(1.0, 1.0, 1.0);
	camera_draw_circle(&(player_physics_obj->position), player_physics_obj->radius);
}
void player_update(float delta, char* player_keys_pressed){
	struct vector boost_direction;
	boost_direction.x = 0;
	boost_direction.y = 0;
	if(player_keys_pressed['a']){
		boost_direction.x -= 1;
	}
	if(player_keys_pressed['s']){
		boost_direction.y -= 1;
	}
	if(player_keys_pressed['d']){
		boost_direction.x += 1;
	}
	if(player_keys_pressed['w']){
		boost_direction.y += 1;
	}
	if(vector_length(&boost_direction) > 0.01){
	vector_normalize(&boost_direction);
	vector_scale(&boost_direction, player_boost_magnitude * delta);
	vector_add(&player_physics_obj->velocity, &boost_direction);
	}
}