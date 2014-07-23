#include <settings.h>
#include <iostream>
using namespace std;
void Settings::readConfig(){
  mKleBlogUrl = Settings()::kleBlogUrl();
  mKleUser = Settings()::kleUser();
  mKlePassword = Settings()::klePassword();
  cout << "LEU CONFIG " << mKleUser;
}

void Settings::saveSettings(){
  Settings()::kleBlogUrl(mKleBlogUrl );
  Settings()::kleUser( mKleUser);
  Settings()::klePassword(mKlePassword);
  cout << "SALVOU CONFIG " << mKleBlogUrl;
}