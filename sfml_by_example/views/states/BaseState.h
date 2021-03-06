#pragma once 

#include <vector>
#include "../EventManager.h"
#include "../Window.h"

enum class StateType {
    Intro = 1, MainMenu, Game, Paused, GameOver, Credits
};

class Window;
class EventManager;
struct SharedContext {
    SharedContext(): m_wind(nullptr), m_eventManager(nullptr) {}
    Window* m_wind;
    EventManager* m_eventManager;
};

class StateManager;
class BaseState {
friend class StateManager;
public:
    BaseState(StateManager* l_stateManager)
        : m_stateMgr(l_stateManager), m_transparent(false), m_transcendent(false) {}

    virtual ~BaseState() {}
    virtual void OnCreate() = 0;
    virtual void OnDestroy() = 0;
    virtual void Activate() = 0;
    virtual void Deactivate() = 0;
    virtual void Update(const sf::Time& l_time) = 0;
    virtual void Draw() = 0;

    sf::View& GetView(){ return m_view; }
    void SetTransparent(const bool& l_transparent) { m_transparent = l_transparent; }
    bool IsTransparent() const { return m_transparent; }
    void SetTranscendent(const bool& l_transcendence) { m_transcendent = l_transcendence; }
    bool IsTranscendent()const { return m_transcendent; }
    StateManager* GetStateManager() { return m_stateMgr; }

protected:
    StateManager* m_stateMgr;
    bool m_transparent;
    bool m_transcendent;
    sf::View m_view;
};

using StateContainer = std::vector<std::pair<StateType, BaseState*>>;
using TypeContainer = std::vector<StateType>;
using StateFactory = std::map<StateType, std::function<BaseState*(void)>>;
