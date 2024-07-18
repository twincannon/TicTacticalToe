
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "TicTacticalToeSystemComponent.h"

#include <TicTacticalToe/TicTacticalToeTypeIds.h>

namespace TicTacticalToe
{
    class TicTacticalToeModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(TicTacticalToeModule, TicTacticalToeModuleTypeId, AZ::Module);
        AZ_CLASS_ALLOCATOR(TicTacticalToeModule, AZ::SystemAllocator);

        TicTacticalToeModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                TicTacticalToeSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<TicTacticalToeSystemComponent>(),
            };
        }
    };
}// namespace TicTacticalToe

AZ_DECLARE_MODULE_CLASS(Gem_TicTacticalToe, TicTacticalToe::TicTacticalToeModule)
