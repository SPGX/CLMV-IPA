const path = require('path');
const pak = require('../package.json');

module.exports = {
	presets: ['module:metro-react-native-babel-preset'],
	plugins: [
		[
			'module-resolver',
			{
				extensions: ['.ios.js', '.android.js', '.js', '.ts', '.tsx', '.json'],
				alias: {
					[pak.name]: path.join(__dirname, '..', pak.source),
				},
			},
		],
		[
			'react-native-reanimated/plugin',
			{
				globals: ['__scanCodes', '__detect', '__detectAndNormalize'],
			},
		],
	],
};
