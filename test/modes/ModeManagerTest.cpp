//
// Created by Fedorov, Alex on 1/28/18.
//

#include "ModeManagerTest.h"

TEST_F(ModeManagerTest, basicTest) {
    modeManager->onModeChange(ModeName::NONE);
    ASSERT_EQ(modeManager->getCurrentMode().getModeName(), ModeName::NONE);

   /* modeManager->onModeChange(ModeName::FREE_RUN);
    ASSERT_EQ(modeManager->getCurrentMode().getModeName(), ModeName::FREE_RUN);

    modeManager->onModeChange(ModeName::NONE);
    ASSERT_EQ(modeManager->getCurrentMode().getModeName(), ModeName::NONE);*/
}

