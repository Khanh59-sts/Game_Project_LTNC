#include "App.hpp" // quản lý trạng thái và logic của cả Game
// Start, Update, End

#include "Core/Context.hpp" // quản lý vòng lặp chính và trạng thái out,...

int main(int, char**) 
{
    auto context = Core::Context::GetInstance();
    App app;

    while (!context->GetExit()) 
    {
        switch (app.GetCurrentState()) 
        {
            case App::State::START:
                app.Start();
                break;

            case App::State::UPDATE:
                app.Update();
                break;

            case App::State::END:
                app.End();
                context->SetExit(true);
                break;
        }
        context->Update();
    }
    return 0;
}
