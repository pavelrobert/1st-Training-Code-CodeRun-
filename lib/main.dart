import 'package:flutter/material.dart';
import 'package:persona_arrk/constants/colors.dart';

import 'constants/strings.dart';
import 'features/home/ui/home_page.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: kAppTitle,
      home: Container(
        color: kBlackColor,
        child: const Scaffold(
          backgroundColor: Colors.transparent,
          body: HomePage(),
        ),
      ),
    );
  }
}
