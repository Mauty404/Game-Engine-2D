class TransformableObject {
public:
    virtual void Translate(int x, int y) {}
    virtual void Rotate(float alpha) {}
    virtual void Rotate(int x, int y, float alpha) {}
    virtual void Scale(float k) {}
    virtual void Scale(int x, int y, float k) {}
};