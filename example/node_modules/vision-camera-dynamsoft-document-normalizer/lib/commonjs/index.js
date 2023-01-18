"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.detect = detect;
exports.detectAndNormalize = detectAndNormalize;
exports.detectFile = detectFile;
exports.initLicense = initLicense;
exports.initRuntimeSettingsFromString = initRuntimeSettingsFromString;
exports.normalizeFile = normalizeFile;
exports.rotateFile = rotateFile;
var _reactNative = require("react-native");
const LINKING_ERROR = `The package 'vision-camera-dynamsoft-document-normalizer' doesn't seem to be linked. Make sure: \n\n` + _reactNative.Platform.select({
  ios: "- You have run 'pod install'\n",
  default: ''
}) + '- You rebuilt the app after installing the package\n' + '- You are not using Expo managed workflow\n';
const VisionCameraDynamsoftDocumentNormalizer = _reactNative.NativeModules.VisionCameraDynamsoftDocumentNormalizer ? _reactNative.NativeModules.VisionCameraDynamsoftDocumentNormalizer : new Proxy({}, {
  get() {
    throw new Error(LINKING_ERROR);
  }
});

/**
 * Init the license of Dynamsoft Document Normalizer
 */
function initLicense(license) {
  return VisionCameraDynamsoftDocumentNormalizer.initLicense(license);
}

/**
 * Init the runtime settings from a JSON template
 */
function initRuntimeSettingsFromString(template) {
  return VisionCameraDynamsoftDocumentNormalizer.initRuntimeSettingsFromString(template);
}

/**
 * Detect documents from the camera preview
 */
function detect(frame) {
  'worklet';

  // @ts-ignore
  // eslint-disable-next-line no-undef
  return __detect(frame, {});
}

/**
 * Detect documents from the the camera preview and return the normalized image of the first detected result
 */
function detectAndNormalize(frame, config) {
  // 'worklet'
  // @ts-ignore
  // eslint-disable-next-line no-undef
  return __detectAndNormalize(frame, config);
}

/**
 * Detect documents in an image file
 */
function detectFile(url) {
  return VisionCameraDynamsoftDocumentNormalizer.detectFile(url);
}

/**
 * Normalize an image file
 */
function normalizeFile(url, quad, config) {
  return VisionCameraDynamsoftDocumentNormalizer.normalizeFile(url, quad, config);
}

/**
 * Rotate an image file. Android only.
 */
function rotateFile(url, degrees) {
  return VisionCameraDynamsoftDocumentNormalizer.rotateFile(url, degrees);
}

/**
 * Config of whether to save the normalized as a file and base64.
 */
//# sourceMappingURL=index.js.map