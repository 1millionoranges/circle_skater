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

void halfpipe_draw(){
    int* phys_object_count = malloc(sizeof(int));
    struct physics_object ** phys_objects = get_physics_objects(phys_object_count);
    for(int i = 0; i < num_halfpipes; i++){
        struct halfpipe_object* halfpipe_obj = halfpipe_list[i];
        for(int j = 0; j < *phys_object_count; j++){
            if(is_colliding(halfpipe_obj, phys_objects[j])){
                glColor3f(1.0, 0.0, 0.0);
            }else{
                glColor3f(0.0, 1.0, 0.0);
            }
        }

        camera_draw_circle(&halfpipe_obj->position, halfpipe_obj->radius);
    }
}
int is_point_inside(struct halfpipe_object* halfpipe_obj, double x, double y){
    return 0;
}

