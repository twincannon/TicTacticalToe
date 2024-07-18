
#pragma once

#include <AzCore/Component/Component.h>

#include <TicTacticalToe/TicTacticalToeBus.h>

namespace TicTacticalToe
{
    class TicTacticalToeSystemComponent
        : public AZ::Component
        , protected TicTacticalToeRequestBus::Handler
    {
    public:
        AZ_COMPONENT_DECL(TicTacticalToeSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        TicTacticalToeSystemComponent();
        ~TicTacticalToeSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // TicTacticalToeRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
