struct physics_object{
	struct vector velocity;
	struct vector position;
	float mass;
};
struct vector *gravity_vector;
int num_physics_objects = 0;
struct physics_object *physics_object_list[100];
	
void physics_init(){
	gravity_vector = malloc(sizeof(struct vector)); 
	gravity_vector->y = 10;
	gravity_vector->x = 0;
}
struct physics_object* physics_object_init(){
	struct physics_object* obj = malloc(sizeof(struct physics_object));
	obj->velocity.x = 0;
	obj->velocity.y = 0;
	obj->position.x = 0;
	obj->position.y = 0;
	obj->mass = 1;
	return obj;
	physics_object_list[num_physics_objects] = obj;
}
void physics_apply_gravity(struct physics_object* obj,float delta){
	obj->velocity.y += gravity_vector->y * delta;
	num_physics_objects++;
}

