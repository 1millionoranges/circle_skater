struct physics_object{
	struct vector velocity;
	struct vector position;
	float mass;
	float radius;
};
struct vector *gravity_vector;
int num_physics_objects = 0;
struct physics_object **physics_object_list;
	
void physics_init(){
	physics_object_list = malloc(100 * sizeof(struct physics_object*));
	gravity_vector = malloc(sizeof(struct vector)); 
	gravity_vector->y = 0;
	gravity_vector->x = 0;
}
struct physics_object* physics_object_init(){
	struct physics_object* obj = malloc(sizeof(struct physics_object));
	obj->velocity.x = 0;
	obj->velocity.y = 0;
	obj->position.x = 0;
	obj->position.y = 0;
	obj->radius = 0.2;
	obj->mass = 1;
	physics_object_list[num_physics_objects++] = obj;
	return obj;
}
void physics_apply_gravity(struct physics_object* obj,float delta){	
	obj->velocity.y += gravity_vector->y * delta;
}
void physics_move(struct physics_object* obj, float delta){
	obj->position.x += obj->velocity.x * delta;
	obj->position.y += obj->velocity.y * delta;
}
void physics_update(float delta){
	for(int i = 0; i < num_physics_objects; i++){
		physics_apply_gravity(physics_object_list[i], delta);
		physics_move(physics_object_list[i], delta);
	}
}

struct physics_object ** get_physics_objects(int* phys_obj_count){
	*phys_obj_count = num_physics_objects;
	return physics_object_list;
}