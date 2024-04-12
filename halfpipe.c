struct halfpipe_object{
    struct vector position;
    float radius;
    float width;
};

struct halfpipe_object ** halfpipe_list;
int num_halfpipes = 0;
struct halfpipe_object* halfpipe_object_init(struct vector *position, float radius, float width){
    struct halfpipe_object* new_halfpipe_obj = malloc(sizeof(struct halfpipe_object));
    new_halfpipe_obj->position.x = position->x;
    new_halfpipe_obj->position.y = position->y;
    new_halfpipe_obj->radius = radius;
    new_halfpipe_obj->width = width;

    halfpipe_list[num_halfpipes++] = new_halfpipe_obj;
    return new_halfpipe_obj;
}
void make_halfpipe(){
    struct vector new_pos;
    new_pos.x = 0;
    new_pos.y = 0;
    struct halfpipe_object* new_halfpipe = halfpipe_object_init(&new_pos, 3.0, 3.0);
}

void halfpipe_init(){
    halfpipe_list = malloc(100 * sizeof(struct halfpipe_object*));
    make_halfpipe();
}

int is_colliding(struct halfpipe_object* halfpipe_obj, struct physics_object* physics_obj){
    double min_distance = halfpipe_obj->radius - physics_obj->radius;
    double max_distance = halfpipe_obj->radius + halfpipe_obj->width + physics_obj->radius;
    double x_diff = physics_obj->position.x - halfpipe_obj->position.x; 
    double y_diff = physics_obj->position.y - halfpipe_obj->position.y; 
    double distance = sqrt(x_diff * x_diff + y_diff * y_diff);
    if(distance > min_distance && distance < max_distance && y_diff - physics_obj->radius < 0){
        return 1;
    }
    return 0;
}

struct vector* halfpipe_get_inner_radius_normal(struct halfpipe_object* hp, struct vector* pos){
    struct vector* translated_pos = malloc(sizeof(struct vector));
    translated_pos->x = -(pos->x - hp->position.x);
    translated_pos->y = -(pos->y - hp->position.y);
    vector_normalize(translated_pos);
    return translated_pos;
}

void halfpipe_draw(){
    for(int i = 0; i < num_halfpipes; i++){
        struct halfpipe_object* halfpipe_obj = halfpipe_list[i];
        glColor3f(1.0,0,0);
        camera_draw_arc(&halfpipe_obj->position, halfpipe_obj->radius+halfpipe_obj->width, M_PI, 2*M_PI);
        glColor3f(0.0,0.0,0.0);
        camera_draw_arc(&halfpipe_obj->position, halfpipe_obj->radius, M_PI, 2*M_PI);
    }
}
void halfpipe_update(float delta){
    int* phys_object_count = malloc(sizeof(int));
    struct physics_object ** phys_objects = get_physics_objects(phys_object_count);
    for(int i = 0; i < num_halfpipes; i++){
        struct halfpipe_object* halfpipe_obj = halfpipe_list[i];
        for(int j = 0; j < *phys_object_count; j++){
            if(is_colliding(halfpipe_obj, phys_objects[j])){
                struct collision* coll = collision_init();
                coll->position.x = phys_objects[j]->position.x;
                coll->position.y = phys_objects[j]->position.y;
                struct vector* normal_vector = halfpipe_get_inner_radius_normal(halfpipe_obj, &coll->position);                
                coll->normal.x = normal_vector->x;
                coll->normal.y = normal_vector->y;
                vector_set_length(normal_vector, halfpipe_obj->radius - phys_objects[j]->radius);
                vector_reverse(normal_vector);
                vector_add(normal_vector, &halfpipe_obj->position);
                coll->position.x = normal_vector->x;
                coll->position.y = normal_vector->y;
                free(normal_vector);
                physics_collide(phys_objects[j], coll);
                free(coll);
            }
        }
    }
}
int is_point_inside(struct halfpipe_object* halfpipe_obj, double x, double y){
    return 0;
}