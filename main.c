#include<stdlib.h>
#include<stdio.h>
#include "vector.c"
#include "physics.c"



int main(){
	physics_init();
	struct physics_object* my_object;
	my_object = physics_object_init(my_object);
	physics_apply_gravity(my_object, 1.0);
	printf("\n velocity: %f\n", my_object->velocity.y);
}
