

struct GLFWwindow;

class window {

private:
    GLFWwindow* m_window = nullptr;

public:
    window();
    ~window();

    bool create();
    void update();

    bool shouldClose() const;
};