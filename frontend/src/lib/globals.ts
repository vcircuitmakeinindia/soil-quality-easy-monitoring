export const SOIL_COLOR = [0x3d, 0x26, 0x1f];

export const OPTIONS = ["temperature", "humidity", "moisture"];

export const EXTREMES = [
    { min: 10, max: 35, inverse: false }, // temperature
    { min: 0, max: 100, inverse: false }, // humidity
    { min: 500, max: 1000, inverse: true }, // moisture
].map(({ min, max, inverse }) => ({ min, max, inverse, rng: max - min }));

export const COLORS = [
    { low: [255, 255, 240], high: [255, 255, 0] }, // temperature
    { low: [240, 240, 255], high: [0, 0, 255] }, // humidity
    { low: [240, 255, 240], high: [0, 255, 0] }, // moisture
];

export const ALPHA = 192;

export default {
    SOIL_COLOR,
    OPTIONS,
    EXTREMES,
    COLORS,
    ALPHA,
};
