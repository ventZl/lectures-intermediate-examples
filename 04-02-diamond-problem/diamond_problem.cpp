class Scene {};
class Shader {};
class Texture {};
class Rectangle2D {};
class MouseButton {};

class Drawable {
public:
    void on_draw_scene(Scene & scene) { /* implement render operation given the configured shader and texture */ }
    void set_shader(Shader & shader) {}
    void set_texture(Texture & texture) {}

    bool is_visible() const { return m_visible; }

protected:
    bool m_visible {false};
};

class Clickable {
public:
    virtual ~Clickable() {}

    void on_mouse_button_event(MouseButton button, bool clicked) { /* implement click / release, doubleclick, drag features */ }
    Rectangle2D get_extents() const { /* return clickable coordinates */ return {}; }

    virtual void on_click() {}
    virtual void on_release() {}
    virtual void on_double_click() {}
    virtual void on_drag_start() {}
    virtual void on_drag_stop() {}

};

class ActionButton: public Clickable, public Drawable {

};

int main(int, char **)
{
    auto instance = new ActionButton();
    delete instance;
    return 0;
}
