#include <stdio.h>
#include <Windows.h>

#define BGR2RGB(c) (c & 0xFF000000) | ((c & 0xFF0000) >> 16) | (c & 0x00FF00) | ((c & 0x0000FF) << 16)

int main(int argc, char* argv[]) {
    HDC dc = GetDC(NULL);
    int key = VK_RCONTROL;

    if (argc == 2)
    {
        key = atoi(argv[1]);
        printf("Key is %X", key);
    }

    do
    {
        if (GetKeyState(key) & 0x8000)
        {
            POINT p;
            if (GetCursorPos(&p))
            {
                p.x = p.x * 5 / 4;
                p.y = p.y * 5 / 4;

                COLORREF color = GetPixel(dc, p.x, p.y);
                color = BGR2RGB(color);
                printf("Color of (%d, %d): %X\n", p.x, p.y, color);
            }
        }
    } while (!(GetKeyState(VK_ESCAPE) & 0x8000));
}
