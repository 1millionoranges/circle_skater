struct collision{
    struct vector normal;
    struct vector position;
};
struct collision* collision_init(){
    struct collision* new_collision = malloc(sizeof(struct collision));
    new_collision->normal.x = 0;
    new_collision->normal.y = 0;
    new_collision->position.x = 0;
    new_collision->position.y = 0;
    return new_collision;
}