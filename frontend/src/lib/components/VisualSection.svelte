<script lang="ts">
	import globals from "$lib/globals";
	import utils from "$lib/utils";
	import { onMount } from "svelte";

	const { readings } = $props();

	const showing = $state(Array(readings.length).fill(0));

	let container = $state();
	let colors = $state(Array(readings.length).fill({}));

	const adjustCircles = () => {
		for (let circle of document.getElementsByClassName("reading-circle")) {
			circle.style.width = `${(1 / 3) * container.clientWidth}px`;
		}
	};

	const getCircleColors = () => {
		for (let i = 0; i < colors.length; i++) {
			const { low, high } = globals.COLORS[showing[i]];
			const { min, max } = globals.EXTREMES[showing[i]];
			const p = utils.findP(min, max, readings[i][globals.OPTIONS[showing[i]]]);
			const color = [...utils.colorP(low, high, p), globals.ALPHA];
			colors[i] = {
				fg: "white",
				bg: utils.rgbaToHex(color)
			};
		}
	};

	$effect(() => showing && getCircleColors());

	const nextReading = (i: number) => {
		if (++showing[i] >= globals.OPTIONS.length) showing[i] = 0;
	};
	const getNextReadingFunc = (i: number) => () => nextReading(i);

	onMount(() => {
		adjustCircles();
		addEventListener("resize", adjustCircles);
	});
</script>

<div id="visual-container" bind:this={container}>
	{#each readings as _, i}
		{@const { bg, fg } = colors[i]}
		{@const opt = globals.OPTIONS[showing[i]]}
		{@const onclick = getNextReadingFunc(i)}
		<div class="cluster-reading" style={i === readings.length - 1 ? "grid-column: span 2" : ""}>
			<div class="reading-circle" style:background-color={bg} {onclick}>
				<p style:color={fg}>
					Cluster {i + 1}<br />
					{opt[0].toUpperCase() + opt.slice(1)}
				</p>
			</div>
		</div>
	{/each}
</div>

<style>
	#visual-container {
		display: grid;
		grid-template-columns: 1fr 1fr;

		background-image: url("$lib/assets/soil.png");
		background-size: cover;

		font-family: "Parkinsans", sans-serif;
	}

	.cluster-reading {
		display: flex;
		align-items: center;
		justify-content: center;
	}

	.reading-circle {
		display: flex;
		align-items: center;
		justify-content: center;

		aspect-ratio: 1;

		border-radius: 50%;
	}

	.reading-circle > p {
		text-align: center;
		text-shadow:
			-1px -1px 0 #000,
			1px -1px 0 #000,
			-1px 1px 0 #000,
			1px 1px 0 #000;
	}
</style>
