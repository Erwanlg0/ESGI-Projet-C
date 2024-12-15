#include "config/config.h"

int main() {
  Settings settings;
  if (!LoadSettings(&settings, "config/settings.cfg")) {
    return 1;
  }
}
