import { NativeModules, Platform } from 'react-native';
const LINKING_ERROR = `The package 'vision-camera-dynamsoft-document-normalizer' doesn't seem to be linked. Make sure: \n\n` + Platform.select({
  ios: "- You have run 'pod install'\n",
  default: ''
}) + '- You rebuilt the app after installing the package\n' + '- You are not using Expo managed workflow\n';
const VisionCameraDynamsoftDocumentNormalizer = NativeModules.VisionCameraDynamsoftDocumentNormalizer ? NativeModules.VisionCameraDynamsoftDocumentNormalizer : new Proxy({}, {
  get() {
    throw new Error(LINKING_ERROR);
  }
});

/**
 * Init the license of Dynamsoft Document Normalizer
 */
export function initLicense(license) {
  return VisionCameraDynamsoftDocumentNormalizer.initLicense(license);
}

/**
 * Init the runtime settings from a JSON template
 */
export function initRuntimeSettingsFromString(template) {
  return VisionCameraDynamsoftDocumentNormalizer.initRuntimeSettingsFromString(template);
}

/**
 * Detect documents from the camera preview
 */
export function detect(frame) {
  'worklet';

  // @ts-ignore
  // eslint-disable-next-line no-undef
  return __detect(frame, {});
}

/**
 * Detect documents from the the camera preview and return the normalized image of the first detected result
 */
export function detectAndNormalize(frame, config) {
  // 'worklet'
  // @ts-ignore
  // eslint-disable-next-line no-undef
  return __detectAndNormalize(frame, config);
}

/**
 * Detect documents in an image file
 */
export function detectFile(url) {
  return VisionCameraDynamsoftDocumentNormalizer.detectFile(url);
}

/**
 * Normalize an image file
 */
export function normalizeFile(url, quad, config) {
  return VisionCameraDynamsoftDocumentNormalizer.normalizeFile(url, quad, config);
}

/**
 * Rotate an image file. Android only.
 */
export function rotateFile(url, degrees) {
  return VisionCameraDynamsoftDocumentNormalizer.rotateFile(url, degrees);
}

/**
 * Config of whether to save the normalized as a file and base64.
 */
//# sourceMappingURL=index.js.map