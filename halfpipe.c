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
    struct halfpipe_object* new_halfpipe = halfpipe_object_init(&new_pos, 3.0, 1.0);
}
void halfpipe_init(){
    halfpipe_list = malloc(100 * sizeof(struct halfpipe_object*));
    make_halfpipe();
}

void halfpipe_draw(){
    glColor3f(1.0, 0.0, 0.0);
    for(int i = 0; i < num_halfpipes; i++){
        struct halfpipe_object* halfpipe_obj = halfpipe_list[i];

        camera_draw_circle(&halfpipe_obj->position, halfpipe_obj->radius);
    }
}

