struct vector *camera_position;
float camera_scale = 0.1;

void camera_init(){
    camera_position = malloc(sizeof(struct vector));
    camera_position->x = 0;
    camera_position->y = 0;
}
void camera_draw_arc(struct vector* world_position, float radius, float start_angle, float end_angle){
    glBegin(GL_POLYGON);
    double transformed_x = camera_scale * (world_position->x - camera_position->x);
    double transformed_y = camera_scale * (world_position->y - camera_position->y);
    float transformed_radius = radius * camera_scale;
	for(float angle = start_angle; angle < end_angle; angle += 0.1){
		float x = transformed_radius * cos(angle) + transformed_x;
		float y = transformed_radius * sin(angle) + transformed_y;
		glVertex2d(x, y);
	}
	glEnd();
}
void camera_draw_circle(struct vector* world_position, float radius){
    camera_draw_arc(world_position, radius, 0, M_PI * 2);
}