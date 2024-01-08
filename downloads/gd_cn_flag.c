void draw_star(gdImagePtr img, int x, int y, int size, int color, int rotation);
void draw_proc_flag(gdImagePtr img);

int main() {

    int width = 1200;

    int height = (int)(width * 2.0 / 3.0);

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_proc_flag(img);

    FILE *outputFile = fopen("Y:/tmp/c_ex/proc01.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }
    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);
    return 0;
}

void draw_star(gdImagePtr img, int x, int y, int size, int color, int rotation) {
    double deg = M_PI / 180.0;
    gdPoint points[10]; 
    int num_points = 10;

    for (int i = 0; i < num_points; i++) {

        double angle = M_PI / 2 + i * 2 * M_PI / 10 + rotation * deg;
        int radius = (i % 2 == 0) ? size : size * sin(18 * deg) / cos(36 * deg);
        points[i].x = x + radius * cos(angle);
        points[i].y = y - radius * sin(angle);
    }

    gdImageFilledPolygon(img, points, num_points, color);
}

void draw_proc_flag(gdImagePtr img) {
    double deg = M_PI / 180.0;
    int width = gdImageSX(img);
    int height = gdImageSY(img);
    int red, yellow;
    double angle;

    int center_x = (int)(width / 6);
    int center_y = (int)(height / 4);

    int big_star_radius = (int)(width / 10);

    int small_star_radius = (int)(width / 30);

    red = gdImageColorAllocate(img, 238, 28, 37); 
    yellow = gdImageColorAllocate(img, 255, 255, 0); 

    gdImageFilledRectangle(img, 0, 0, width, height, red);

    draw_star(img, center_x, center_y, big_star_radius, yellow, 0);

    center_x = (int) width/3;
    center_y = (int) width/15;

    angle = 180 - atan(5/3)/deg;
    draw_star(img, center_x, center_y, small_star_radius, yellow, angle);
    // the second small star
    center_x = (int) 2*width/5;
    center_y = (int) 2*width/15;

    angle = 180 - atan(7/1)/deg;
    draw_star(img, center_x, center_y, small_star_radius, yellow, angle);
    // the third small star
    center_x = (int) 2*width/5;
    center_y = (int) 7*width/30;

    angle = atan(7/2)/deg;
    draw_star(img, center_x, center_y, small_star_radius, yellow, angle);
    // the fourth small star
    center_x = (int) width/3;
    center_y = (int) 3*width/10;
    angle = atan(5/4)/deg;
    draw_star(img, center_x, center_y, small_star_radius, yellow, angle);
}