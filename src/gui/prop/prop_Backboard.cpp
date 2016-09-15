#include "gui/prop/prop_Backboard.h"

namespace
{
static const int kDefaultWidth = 360;
static const int kDefaultHeight = 32;
}

namespace gui {
namespace prop {

Backboard::Backboard(QWidget* aParent)
    : QWidget(aParent)
    , mProject()
    , mLayout(new QVBoxLayout())
    , mProjectPanel()
    , mObjectPanel()
{
    mLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    this->setLayout(mLayout);
    this->resize(kDefaultWidth, kDefaultHeight);
}

void Backboard::setProject(core::Project* aProject)
{
    mProjectPanel.reset();
    mObjectPanel.reset();

    mProject = aProject;

    if (mProject)
    {
        mObjectPanel.reset(new ObjectPanel(*mProject, "Null", this));
        mLayout->addWidget(mObjectPanel.data());
    }
}

void Backboard::setTarget(core::ObjectNode* aNode)
{
    if (mObjectPanel)
    {
        mObjectPanel->setTarget(aNode);
    }
}

void Backboard::updateAttribute()
{
    if (mObjectPanel)
    {
        mObjectPanel->updateAttribute();
    }
}

void Backboard::updateKey()
{
    if (mObjectPanel)
    {
        mObjectPanel->updateKey();
    }
}

void Backboard::updateFrame()
{
    if (mObjectPanel)
    {
        mObjectPanel->updateFrame();
    }
}

} // namespace prop
} // namespace gui