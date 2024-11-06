#include <set>
#include <iostream>

class Scene {};
class Shader {};
class Texture {};
class Rectangle2D {};
class MouseButton {};

class Object {
public:
    Object() { add_instance(this); }
    virtual ~Object() { remove_instance(this); }

    void add_instance(Object * ptr) { s_instances.insert(ptr); }
    void remove_instance(Object * ptr) { auto it = s_instances.find(ptr); if (it != s_instances.end()) { s_instances.erase(it); } }

    static std::set<Object *> instances() { return s_instances; }

protected:
    static std::set<Object *> s_instances;
};

std::set<Object *> Object::s_instances;

class Drawable: virtual public Object {
public:
    void on_draw_scene(Scene & scene) { /* implement render operation given the configured shader and texture */ }
    void set_shader(Shader & shader) {}
    void set_texture(Texture & texture) {}

    bool is_visible() const { return m_visible; }

protected:
    bool m_visible {false};
};

class Clickable: virtual public Object {
public:
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
    auto ok_button = new ActionButton();

    std::cout << "There is " << Object::instances().size() << " object instance" << std::endl;

    delete ok_button;



    return 0;
}
