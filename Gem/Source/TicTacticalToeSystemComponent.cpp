
#include <AzCore/Serialization/SerializeContext.h>

#include "TicTacticalToeSystemComponent.h"

#include <TicTacticalToe/TicTacticalToeTypeIds.h>

namespace TicTacticalToe
{
    AZ_COMPONENT_IMPL(TicTacticalToeSystemComponent, "TicTacticalToeSystemComponent",
        TicTacticalToeSystemComponentTypeId);

    void TicTacticalToeSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<TicTacticalToeSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void TicTacticalToeSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("TicTacticalToeService"));
    }

    void TicTacticalToeSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("TicTacticalToeService"));
    }

    void TicTacticalToeSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void TicTacticalToeSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    TicTacticalToeSystemComponent::TicTacticalToeSystemComponent()
    {
        if (TicTacticalToeInterface::Get() == nullptr)
        {
            TicTacticalToeInterface::Register(this);
        }
    }

    TicTacticalToeSystemComponent::~TicTacticalToeSystemComponent()
    {
        if (TicTacticalToeInterface::Get() == this)
        {
            TicTacticalToeInterface::Unregister(this);
        }
    }

    void TicTacticalToeSystemComponent::Init()
    {
    }

    void TicTacticalToeSystemComponent::Activate()
    {
        TicTacticalToeRequestBus::Handler::BusConnect();
    }

    void TicTacticalToeSystemComponent::Deactivate()
    {
        TicTacticalToeRequestBus::Handler::BusDisconnect();
    }
}
