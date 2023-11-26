import 'package:flutter/material.dart';

import '../../constants/styles.dart';

class AdditionalButton extends StatefulWidget {
  final String iconName;

  const AdditionalButton({Key? key, required this.iconName}) : super(key: key);

  @override
  State<AdditionalButton> createState() => _AdditionalButtonState();
}

class _AdditionalButtonState extends State<AdditionalButton> {
  @override
  Widget build(BuildContext context) {
    return Container(padding: kSmallPaddingAll, decoration: kCircleBoxDecoration, child: Image.asset('images/${widget.iconName}.png'));
  }
}
