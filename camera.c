struct vector *camera_position;
float camera_scale = 0.1;

void camera_init(){
    camera_position = malloc(sizeof(struct vector));
    camera_position->x = 0;
    camera_position->y = 0;
}
void camera_draw_circle(struct vector* world_position, float radius){
    glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
    double transformed_x = camera_scale * (world_position->x - camera_position->x);
    double transformed_y = camera_scale * (world_position->y - camera_position->y);
    float transformed_radius = radius * camera_scale;
	for(float angle = 0; angle < 2 * M_PI; angle += 0.2){
		float x = transformed_radius * cos(angle) + transformed_x;
		float y = transformed_radius * sin(angle) + transformed_y;
		glVertex2d(x, y);
	}
	glEnd();
 
}