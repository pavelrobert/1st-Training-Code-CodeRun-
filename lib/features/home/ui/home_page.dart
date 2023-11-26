import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:persona_arrk/constants/styles.dart';
import 'package:persona_arrk/utils/widgets/additional_button.dart';
import 'package:persona_arrk/utils/widgets/custom_widgets.dart';

import '../../navigation/ui/navigation_page.dart';

class HomePage extends StatefulWidget {
  const HomePage({Key? key}) : super(key: key);

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  @override
  Widget build(BuildContext context) {
    final screenWidth = MediaQuery.of(context).size.width;
    final screenHeight = MediaQuery.of(context).size.height;
    return Column(
      children: [
        getTitleWidgets(),
        addVerticalSpace(12),
        getCarAlertsWidgets(screenHeight / 3.5, screenWidth),
        addVerticalSpace(24),
        getBatteryInfoWidgets(screenWidth / 1.8),
        addVerticalSpace(32),
        getAdditionalWidgets(),
        addVerticalSpace(24),
        getFavoritesWidgets(screenWidth / 2.3)
      ],
    );
  }

  getTitleWidgets() {
    return Column(
      children: [
        addVerticalSpace(24),
        Image.asset('images/Logo.png'),
        addVerticalSpace(4),
        const Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text(
              "Hello ",
              style: kMediumWhiteTextStyle,
            ),
            Text(
              'Andrei',
              style: kMediumGreenTextStyle,
            )
          ],
        )
      ],
    );
  }

  getCarAlertsWidgets(double height, double width) {
    return Column(
      children: [
        SizedBox(
            height: height,
            width: width,
            child: Image.asset(
              'images/Vehicle.png',
              fit: BoxFit.fill,
            )),
      ],
    );
  }

  getBatteryInfoWidgets(double width) {
    return Container(
      decoration: const BoxDecoration(image: DecorationImage(image: AssetImage('images/Batterie_Info.png'))),
      padding: const EdgeInsets.only(left: 48), // EdgeInsets.symmetric(horizontal: 48)
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceEvenly,
        children: [
          Container(padding: kSmallPaddingAll, child: Image.asset('images/66_percentage.png')),
          Container(padding: kSmallPaddingAll, child: Image.asset('images/257km.png')),
          Container(padding: kSmallPaddingAll, child: Image.asset('images/Button_lightning.png')),
        ],
      ),
    );
  }

  getAdditionalWidgets() {
    return const Row(
      mainAxisAlignment: MainAxisAlignment.spaceEvenly,
      children: [
        AdditionalButton(
          iconName: 'Light',
        ),
        AdditionalButton(
          iconName: 'Lock',
        ),
        AdditionalButton(
          iconName: 'Horn',
        ),
        AdditionalButton(
          iconName: 'Park',
        )
      ],
    );
  }

  getFavoritesWidgets(double width) {
    return Padding(
      padding: const EdgeInsets.symmetric(horizontal: 24),
      child: Column(
        children: [
          const Row(
            mainAxisAlignment: MainAxisAlignment.start,
            children: [
              Text(
                'Your favorites',
                style: kMediumWhiteTextStyle,
              ),
            ],
          ),
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              Container(
                height: width,
                width: width,
                decoration: const BoxDecoration(image: DecorationImage(image: AssetImage('images/WidgetBackground.png'))),
                child: Stack(
                  children: [
                    Positioned.fill(
                        child: Align(
                            alignment: AlignmentDirectional.center,
                            child: Image.asset(
                              'images/Fan.png',
                              scale: 0.7,
                            ))),
                    Column(
                      mainAxisAlignment: MainAxisAlignment.spaceBetween,
                      crossAxisAlignment: CrossAxisAlignment.center,
                      children: [
                        addVerticalSpace(1),
                        Row(
                          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                          children: [
                            Image.asset(
                              'images/SeatHeater.png',
                              scale: 0.8,
                            ),
                            Image.asset('images/steeringWheel.png', scale: 0.8)
                          ],
                        ),
                        Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                            Image.asset('images/-.png'),
                            addHorizontalSpace(12),
                            Image.asset('images/21temp.png'),
                            addHorizontalSpace(12),
                            Image.asset('images/+.png'),
                          ],
                        ),
                        Image.asset('images/Climate.png'),
                        addVerticalSpace(1)
                      ],
                    )
                  ],
                ),
              ),

              //TODO: Implement Navigation Favorite Button
              GestureDetector(
                onTap: (){
                  Navigator.push(context, MaterialPageRoute(builder: (context) => const NavigationPage()));
                },
                child: Container(
                  height: width,
                  width: width,
                  decoration: const BoxDecoration(image: DecorationImage(image: AssetImage('images/WidgetBackground.png'))),
                  child: Stack(
                    children: [
                      Positioned.fill(child: Align(alignment: AlignmentDirectional.center, child: Image.asset('images/map.png', scale: 1.05))),
                      Positioned.fill(child: Image.asset('images/NavigationBackground.png')),
                      Positioned(bottom: 24, left: width/4, child: Image.asset('images/Navigation.png'))
                    ],
                  ),
                ),
              )
            ],
          )
        ],
      ),
    );
  }
}
