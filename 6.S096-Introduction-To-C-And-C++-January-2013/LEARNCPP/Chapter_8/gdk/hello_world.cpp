
#include <gtk/gtk.h>
#include <cairo/cairo.h>
#include <vector>

// Structure to represent a point
struct Point {
    double x;
    double y;
    bool out_of_tolerance;
};

// Structure to represent a graph
struct Graph {
    std::vector<Point> points;
    double scale;
    double x_offset;
    double y_offset;
};

// Callback function for menu item activation
static void on_menu_item_activate(GtkMenuItem* menu_item, gpointer user_data) {
    g_print("%s\n", (char*)user_data);
}

// Callback for drawing on the GtkDrawingArea
static gboolean on_draw(GtkWidget* widget, cairo_t* cr, gpointer user_data) {
    Graph* graph = static_cast<Graph*>(user_data);

    // Set the background color to gray
    cairo_set_source_rgb(cr, 0.8, 0.8, 0.8); // Gray
    cairo_paint(cr);

    // Scale the drawing
    cairo_scale(cr, graph->scale, graph->scale);

    // Draw horizontal tolerance zone lines
    cairo_set_source_rgb(cr, 0.0, 0.0, 1.0); // Blue
    double tolerance_line_y = 300; // Adjust the y-coordinate as needed
    tolerance_line_y /= graph->scale;
    cairo_set_line_width(cr, 2.0);
    cairo_move_to(cr, 0, tolerance_line_y);
    cairo_line_to(cr, 800 / graph->scale, tolerance_line_y);
    cairo_stroke(cr);

    // Draw the bounding box
    cairo_set_source_rgb(cr, 0.0, 0.0, 0.0); // Black
    double x1 = graph->x_offset / graph->scale;
    double y1 = graph->y_offset / graph->scale;
    double x2 = (graph->x_offset + 800) / graph->scale;
    double y2 = (graph->y_offset + 600) / graph->scale;
    cairo_rectangle(cr, x1, y1, x2 - x1, y2 - y1);
    cairo_stroke(cr);

    // Draw each point and out-of-tolerance lines
    for (const Point& point : graph->points) {
        if (point.out_of_tolerance) {
            // Draw an out-of-tolerance line (red)
            cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); // Red
            cairo_move_to(cr, point.x, point.y);
            cairo_line_to(cr, point.x, point.y - 10); // Adjust the length of the line as needed
            cairo_stroke(cr);
        }

        // Draw the point
        cairo_set_source_rgb(cr, 0.0, 0.0, 0.0); // Black
        cairo_arc(cr, point.x, point.y, 5, 0, 2 * G_PI); // Draw a circle for each point
        cairo_fill(cr);
    }

    return TRUE;
}

int main(int argc, char* argv[]) {
    gtk_init(&argc, &argv);

    // Create a vector of graphs
    std::vector<Graph> graphs;

    // Create a graph with some example points
    Graph graph1;
    graph1.points.push_back({50, 50, false});
    graph1.points.push_back({100, 300, true});
    graph1.points.push_back({150, 50, false});
    graph1.scale = 0.5; // Adjust the scale as needed
    graph1.x_offset = 0;
    graph1.y_offset = 0;
    graphs.push_back(graph1);

    // Create another graph with different points
    Graph graph2;
    graph2.points.push_back({50, 200, false});
    graph2.points.push_back({200, 100, true});
    graph2.points.push_back({250, 250, false});
    graph2.scale = 0.5; // Adjust the scale as needed
    graph2.x_offset = 400; // Adjust the x-offset as needed
    graph2.y_offset = 0;
    graphs.push_back(graph2);

    // Create the main window
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Multiple Scaled Graphs with Bounding Box Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a vertical box to organize the menu bar and content
    GtkWidget* vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Create a top-level menu bar
    GtkWidget* menubar = gtk_menu_bar_new();
    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

    // Create a "File" menu
    GtkWidget* file_menu = gtk_menu_new();
    GtkWidget* file_menu_item = gtk_menu_item_new_with_label("File");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_menu_item), file_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file_menu_item);

    // Create "Open" and "Exit" menu items under "File"
    GtkWidget* open_menu_item = gtk_menu_item_new_with_label("Open");
    g_signal_connect(G_OBJECT(open_menu_item), "activate", G_CALLBACK(on_menu_item_activate), (gpointer)"Open file dialog");
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), open_menu_item);

    GtkWidget* exit_menu_item = gtk_menu_item_new_with_label("Exit");
    g_signal_connect(G_OBJECT(exit_menu_item), "activate", G_CALLBACK(gtk_main_quit), NULL);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), exit_menu_item);

    // Create a drawing area for each graph
    for (Graph& graph : graphs) {
        GtkWidget* drawing_area = gtk_drawing_area_new();
        g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(on_draw), &graph);
        gtk_box_pack_start(GTK_BOX(vbox), drawing_area, TRUE, TRUE, 0);
    }

    // Create a status bar
    GtkWidget* status_bar = gtk_statusbar_new();
    gtk_box_pack_start(GTK_BOX(vbox), status_bar, FALSE, FALSE, 0);

    // Show all widgets
    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
