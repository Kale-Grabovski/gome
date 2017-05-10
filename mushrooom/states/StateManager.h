#pragma once

#include "BaseState.h"

class BaseState;
enum class StateType;
struct SharedContext;

using StateContainer = std::vector<std::pair<StateType, BaseState*>>;
using TypeContainer = std::vector<StateType>;
using StateFactory = std::map<StateType, std::function<BaseState*(void)>>;

class StateManager {
public:
    StateManager(SharedContext* l_shared);
    virtual ~StateManager();
    
    void Update(const sf::Time& l_time);
    void Draw();
    void ProcessRequests();
    SharedContext* GetContext();
    bool HasState(const StateType& l_type);
    void SwitchTo(const StateType& l_type);
    void Remove(const StateType& l_type);

private:
    void CreateState(const StateType& l_type);
    void RemoveState(const StateType& l_type);

    template<class T>
    void RegisterState(const StateType& l_type) {
        m_stateFactory[l_type] = [this]() -> BaseState* {
            return new T(this);
        };
    }

    SharedContext* m_shared;
    StateContainer m_states;
    TypeContainer m_toRemove;
    StateFactory m_stateFactory;
};
