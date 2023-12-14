#include "SavableType.h"

uint8_t SavableTypeContainer::GetFlags()
{
    return m_flags;
}

void SavableTypeContainer::SetFlags(uint8_t flags)
{
    m_flags = flags;
}

void SavableTypeContainer::DisableFlags(uint8_t flags)
{
    m_flags = m_flags & ~flags;
}

void SavableTypeContainer::EnableFlags(uint8_t flags)
{
    m_flags = m_flags | flags;
}
